/*
 * File: ioredirect.c
 * Author: ayoposi
 * Description: A library for handling input/output redirection in a shell.
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


void ioRedirection(char** tokens, int token_count) {
     // intial checkers for IO redirect
    int output_redirect = 0;
     for (int i = 0; i < token_count; i++){
            if (strcmp(tokens[i], ">") == 0){
                if (i + 1 < token_count){
                    // open file to modify
                    output_redirect = open(tokens[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    // error checking
                if (output_redirect == -1) {
                    perror("Failed to open file");
                    exit(EXIT_FAILURE);
                }
                // moves stdout to fd
                dup2(output_redirect, 0);
                // close file
                close(output_redirect);

                tokens[i] = NULL; 
            
                break;

            } else {
                exit(EXIT_FAILURE);
            }
        }
    }
}