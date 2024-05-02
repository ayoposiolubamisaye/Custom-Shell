/*
 * File: shell.c
 * Author: ayoposi
 * Description: A simple shell program that handles basic input/output redirection.
 * Date: 9/24
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>

#include "tokenizer.h"
#include "ioredirect.h"

int main(){
    char buff[1024];
	bool exitLoop = false;

	while(!exitLoop){
        // shell name
		printf("ayoshell$ ");
        // Reads user input
	if (fgets(buff, sizeof(buff), stdin) == NULL) {
		exitLoop = true; 
		// checks for EOF
	}else{
		
	}
    
    int token_count = 0;
    char** tokens = NULL;

    // TOkenize input from user
    tokens = tokenize(buff, &token_count);

    // handle io redirection
    ioRedirection(tokens, token_count);
        
    // initializes child process
    pid_t child_pid = fork();

    if (child_pid == -1){ //child process error
        perror("fork");
    } else if (child_pid == 0){ // child process successful
        execvp(tokens[0], tokens); // in the form of args but using token to execute
        perror("error executing");
        exit(EXIT_FAILURE);
    }else if (child_pid > 0) { //parent process
        wait(NULL); // wait for child process to end
    }


     // free used tokens
    free_token(tokens, token_count);

    }
    
}

