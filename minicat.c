#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	char buff[1024];
	bool exitLoop = false;

	while(!exitLoop){
		printf("Please enter a line: ");

	if (fgets(buff, sizeof(buff), stdin) == NULL) {
		exitLoop = true; // checks for EOF
	}else{
		printf("You entered: %s", buff);
	}
   }
   return 0;
}
