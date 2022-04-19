#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#define MAXARGS 5
#define MAXLINE 8192
#define COMMANDS_NUMBER 4
// Put command names here
char* commands[] = {"cd", "help", "exit", "game"};

void* cd(char* input) {
  // Implement cd
  if (input == NULL) {
      return;
  }
  chdir(input);
}

void* help(char* input) {
  printf("-----------------\n");
  printf("The commands supported in K-SEA shell: \n");
  printf("-cd <path> : changes the current path to a given path.\n");
  printf("-help : prints out all the commands provided in K-SEA shell.\n");
  printf("-exit : terminates and exits the K-SEA shell\n");
  printf("-game : tell a random joke.\n");
  printf("------------------\n");
}

// use exit_ksea avoid name conflix with exit
void* exit_ksea(char* input) {
    printf("Successfully exit K-SEA sheel!\n");
    exit(0);
}

void* game(char* input) {
    int lower = 1;
    int upper = 100;
    const char *JOKE01 =
    "I have an inferiority complex, "
    "but it's not a very good one.";
    const char* JOKE02 =
    "They all laughed when I said "
    "I wanted to be a comedian; Well, they're not laughing now.";
    const char* JOKE03 =
    "I feel bad for the homeless guy, "
    "but I feel really bad the homeless guy's dog, "
    "because he must be thinking 'Man, this is the longest walk ever.'";
    const char* JOKE04 =
    "On the other hand, you have different fingers.";
    const char* JOKE05 =
    "You're not completely useless,"
    "you can always serve as a bad example.";
    int number;
    // get random number between 1 to 100
    srand(time(0));
    number = (rand() % (upper - lower + 1)) + lower;
    if (number >= 1 && number < 20) {
        printf("%s\n", JOKE01);
    } else if (number >= 20 && number < 40) {
        printf("%s\n", JOKE02);
    } else if (number >= 40 && number < 60) {
        printf("%s\n", JOKE03);
    } else if (number >= 60 && number < 80) {
        printf("%s\n", JOKE04);
    } else {
        printf("%s\n", JOKE05);
    }
}

// Put command function pointers here
void* (*command_functions[])(char* input) = {cd, help, exit_ksea, game};

/***
 **  Wrapper of fork(). Checks for fork errors, quits on error. 
 **/
pid_t Fork(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
    exit(0);
  }
  return pid;
}

/***
 **  Wrapper of fgets. Checks and quits on Unix error. 
 **/
char* Fgets(char *ptr, int n, FILE *stream) {
  char *rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}

// Is the command one built into the shell?
// That is, that the *shell* has implemented?
// If so, execute it here
int builtin_command(char** argv) {
  // Loop through the command functions
  int i;
  i = 0;
  while (i < COMMANDS_NUMBER) {
    int res = strcmp(commands[i], argv[0]);
    // if command[i] equals argv[0]
    if (res == 0) {
    // call the right function.
    command_functions[i](argv[1]);   // some argument
    return 1;   // 1 means True, exist
    }
    i++;
  }
  return 0;   // 0 means False, not exist
}

// split buf into args
void parser(char* buf, char* args[]) {
    char *token;
    char space[2] = " ";
    // get the first token
    token = strtok(buf, space);
    // walk through other tokens
    int i = 0;
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, space);
        i++;
    }
}


void eval(char *cmdline) {
  char *argv[MAXARGS]; /* Argument list execve() */
  char buf[MAXLINE]; /* Holds modified command line */
  pid_t pid; /* Process id */

  strcpy(buf, cmdline);
  // Split buf into args
  parser(buf, argv);
  if (argv[0] == NULL)
    return; /* Ignore empty lines */

  if (!builtin_command(argv)) {
    // Check that the command/program exists in Unix (ie /bin/) OR (see below)
    argv[0] = "/bin/";
    // Create a child process
    pid = Fork();
    // Run the program/command (execve...)--
    // what is the result of exec if the command is bogus?
    if (pid == 0) {
        int res = execve(argv[0], argv, NULL);
        // see run_ls.c for an example
        if (res < 0) {
        // print error message
        printf("Error happened, no such kind of command,"
        "do you foget input something after command eg 'game abc'?\n");
        }
        printf("Child: Should never get here\n");
        exit(1);
    } else {
    // What do we do if it *IS* a command built into the shell?
        wait(NULL);
  }

  // Be sure to wait for the child process to terminate
  return;
  }
}



int main() {
  char cmdline[MAXLINE]; /* command line buffer */
  while (1) {
    // Print command prompt
    printf("ksesh> ");
    // Read input from user
    Fgets(cmdline, MAXLINE, stdin);
    // If we get the eof, quit the program/shell
    if (feof(stdin)) {
      exit(0);
    }
    // Otherwise, evaluate the input and execute.
    eval(cmdline);
  }
}
