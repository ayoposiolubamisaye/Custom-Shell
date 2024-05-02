/*
 * File: tokenizer.h
 * Author: ayoposi
 * Description: Header file for tokenizer library.
 * Date: 9/24
 */

char** tokenize(char* input, int* token_count);
void free_token(char ** tokens,int token_count);