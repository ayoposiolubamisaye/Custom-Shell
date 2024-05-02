#include <stdio.h>

int main(int argc, char *argv[]){
//argc (total number of command line arguments including program name)
//argv is array of strings(character pointers)` that hold individual command line arguments
	for(int i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}
	return 0;
}
