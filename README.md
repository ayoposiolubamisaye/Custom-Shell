# Assignment 1

regrade ... 
  looks like closing NULL is not added to the tokenv array
  if (strcmp(tokens[i], ">") == 0){    --- avoid magic values  ... #define OUTPUT_REDIRECT ">"
    
  see the problem with `int output_redirect = 0;` :) 

much better!  i suspect given the time for polish the redirection , you could sort that as well.


where did the code come from?

please see me
Grade: F

int max_tokens = 10; -- not a fan :)
why "max_tokens *= 2;"




## Instructions

View the following files to learn about this assignment:
1. assignment.md: Basic directions and requirements for the assignment.
2. phases.md: Describes the sub-problems that you should consider solving separately to remember C. Also includes details on the requirements of the different aspects of the assignment described at a high level in assignment.md.
3. rubric.md: The rubric that will be used to grade your solution including the minimum requirements for each letter grade. 

# AyoShell

A simple shell implementation in C.

# How to use

1. Clone the repository.
2. Compile the shell:

Use make to compile, then make clean to clear
Then use ./shell to run

# Features
Shell functions and executing commands.
Input and output redirection using < and >.
Proper error handling.

# Milestones
1. Read user input from stdin
2. tokenized user input with error checking
3. Started parent and child processes
4. freed memory after use
5. 
# Honor Code
I did not violate honor code

# rubric rows accomplished
3-15
18-25
26-31


