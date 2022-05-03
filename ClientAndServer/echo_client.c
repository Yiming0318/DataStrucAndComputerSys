#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 999

void PrintBlue(char* str) {
  printf("\033[1;94m%s\033[0m", str);
}

void PrintYellow(char* str) {
  printf("\033[1;93m%s\033[0m", str);
}

char* Fgets(char *ptr, int n, FILE *stream) {
  char *rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}

// send message
void send_message(char* msg, int sock_fd) {
    write(sock_fd, msg, strlen(msg));
}

// read respond
void read_response(int sock_fd){
    // Response
    char resp[1000];
    int len = read(sock_fd, resp, 999);
    resp[len] = '\0';
    PrintBlue("FROM SERVER: ");
    printf("%s\n", resp);
  
}

int main() {

  struct addrinfo hints, *result;

  // Allows "global"
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET; /* IPv4 only */
  hints.ai_socktype = SOCK_STREAM; /* TCP */
  
  int s;

  s = getaddrinfo("localhost", // 127.0.0.1
                  "1234", // port
                  &hints,
                  &result);

  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  connect(sock_fd, result->ai_addr, result->ai_addrlen);

  while (1) {
    //  char *buffer = "COVID OVER";
    char buffer[MAXLINE];
    printf("Enter your message: ");
    // Read input from user
    Fgets(buffer, MAXLINE, stdin);
   // int buffer_num[100];
   // printf("How many time you want to repeat: ");
   // Fgets(buffer_num, 100, stdin);
    PrintYellow("SENDING: ");
    printf("%s\n", buffer);
    send_message(buffer, sock_fd);
   // write(sock_fd, buffer, strlen(buffer));
   // write(sock_fd, buffer_num, strlen(buffer_num)); 
 //   char resp[1000];
  //  int len = read(sock_fd, resp, 999);
   // resp[len] = '\0';
    read_response(sock_fd);
   // PrintBlue("FROM SERVER: ");
   // printf("%s\n", resp);
  }
  close(sock_fd); 
    
}
