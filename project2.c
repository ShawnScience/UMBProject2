#include <stdio.h>  //for printf()
#include <string.h> //For Strings
#include <stdlib.h> //For exit()
#include <stdbool.h> //for boolean flags

//Function prototypes
void read_lines(FILE *fd_in, FILE *fd_out);

// *******************


int main(int argc, char *argv[])
{
  bool ikeep_go = true; //to escape interactive mode
  // bool fkeep_go = true; // to escape file mode
  //  char *path = "/bin"; //initial shell path
  
  if(argc > 2)
    {
      fprintf(stderr, "Error, too many arguments to wish.\n");
      exit(-3);
    }
  if(argc == 1) //Interactive Mode
    {
      while(ikeep_go)
	{
	  printf("wish> ");
	  read_lines(stdin, stdout);
	  exit(0);
	  
	}
      exit(0); //Called exit function.
    }
  if(argc == 2) //File Mode
    {
      printf("Got 1 arg");
      exit(2);
      /* while(fkeep_go)
	{
	 //close(0&1) then try to open file then pipe and fork
	}
	exit(0); //Called exit function.
       */
    }
}

void read_lines(FILE *fd_in, FILE *fd_out)
{
  char *line = NULL; //The line we read. 
  size_t size = 0; //line size. getline uses ralloc

   getline(&line, &size, fd_in);
   printf("You entered: \n %s", line);
   return;
}

void exec_cmnds(char **cmnds)
{
  
}
