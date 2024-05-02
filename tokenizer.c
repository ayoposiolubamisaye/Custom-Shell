/*
 * File: tokenizer.c
 * Author: ayoposi
 * Description: A library for tokenizing input strings.
 * Date: 9/24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
    /* main loop */
    /* get a line of input (from Mini Cat) */ 
   // tokenv = tokenize(input, &tokenc);
    /* now tokenc, tokenv are just like argc, argv */ 
    /* process an argument list (from Mini Echo) */

 //return an array of tokens   
char** tokenize(char* input, int* token_count) {
    
    //set token count to 0
    *token_count = 0;

    //set pointer for array and set value of maximum tokens to 10
    char** tokens = NULL;
    int max_tokens = 10;
   
    //dynamically allocate memory for the array
    tokens = (char**)malloc(max_tokens * sizeof(char*));

    //error checking
    if (tokens == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    //splits user input into tokens (accounting for whitespace)
    char* token = strtok(input, " \t\n");

    while (token != NULL) {
        (*token_count)++;
        //error checking if need for increasing of memory to reallocate
        if (*token_count >= max_tokens) {
            max_tokens *= 2; 
            char** new_tokens = (char**)realloc(tokens, max_tokens * sizeof(char*));
            //error check if it worked
            if (new_tokens == NULL) {
                perror("Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
            // new token value matching memory
            tokens = new_tokens;
        }
        //saves value to array and prompts user for next input
        tokens[(*token_count) - 1] = strdup(token);
        token = strtok(NULL, " \t\n");
    }

    return tokens;
}

// function to free token to prevent memory leak
//referred to prior 366 example
void free_token(char ** tokens,int token_count){
   for(int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);

}
