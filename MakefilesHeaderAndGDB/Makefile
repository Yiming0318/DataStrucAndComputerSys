#all: clean run

#compile, greetings: goodbye.c greeting.c start.c
#	@echo -e  "\033[1;93mRunning compile...\033[0m"
#	gcc -g goodbye.c greeting.c start.c -o greetings

#run: greetings
#	@echo -e "\033[1;93mRunning program....\033[0m"
#	./greetings

#.PHONY: compile clean

#clean: 
#	@echo -e  "\033[1;93mCleaning...\033[0m"
#	rm -rf greetings

all:	lab04
lab04:	greeting.c goodbye.c start.c
	gcc greeting.c goodbye.c start.c -o greetings

run: lab04
	./greetings

clean: 
	rm greetings
