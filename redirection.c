#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    const char* outputFile = "outputFile.txt";

    int output = open(outputFile, O_WRONLY | O_CREAT | O_TRUNC );

    if (outputFile == -1){
        perror("file open failed");
        exit(EXIT_FAILURE);
    }

    dup2(output,1);
    close(output);

    char command[1024];

    while (fgets(command, sizeof(command), stdin) != NULL) {
        printf("%s", command);
    }
    return 0;



}