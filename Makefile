

shell: shell.c 
	gcc -o shell shell.c tokenizer.c ioredirect.c

clean:
	/bin/rm shell
