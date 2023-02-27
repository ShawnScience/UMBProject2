#include <stdio.h>  //for printf()
#include <string.h> //For Strings and string operations like strsep()
#include <stdlib.h> //For exit()
#include <stdbool.h> //for boolean flags
#include <ctype.h> //for isspace()
#include <unistd.h> //for chdir()

//Function prototypes... Forgot I needed these in c
void read_lines(FILE *fd_in, FILE *fd_out);
char *remove_space(char *in);

// *******************

//Global Variables

char *leave = "exit";
// ******************


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
   const char *delim1 = "&";
   const char *delim2 = ">";
   const char *delim3 = " \t";
   char *token;
   char *token2;
   char *token3;
   bool cdir = false;
   
   while( (token = strsep(&line, delim1) ) != NULL )
     {
       printf("Commands: %s\n", token);
       
       while( (token2 = strsep(&token, delim2) ) != NULL)
	 {	  
	     printf("streams: %s\n", token2);
	   while( (token3 = strsep(&token2, delim3) ) != NULL)
	     {
	       token3 = remove_space(token3);
	       if(token3 != NULL)
		 {
		   printf("Each arg: [%s] \n", token3);
		   printf("char : %d \n", token3[0]);
		   //char *ran = strdup(token3);
		   if(!strcmp(token3, leave) ) //returns 0 if strings are matched
		     exit(0);
		   if( cdir )
		     {
		       if( chdir(token3) < 0)
			 fprintf(stderr, "Failed to change directory to %s", token3);
		       cdir = false; //flip switch off for chdir
		       char wd[100];
		       getcwd(wd, 100);
		       printf("changed directory to %s\n", wd);
		     }
		   if( !strcmp(token3, "cd" ) )
		     {
		       printf("changing directory. \n");
		       cdir = true;
		     }		   
		   
		 }
	     }
	 }
     }
   return;
}

char *remove_space(char *in)
{
  char *out = in;
  int i = 0;
  int j = 0;
  for(; i < strlen(in); )
    {
      if( !isspace(in[i]) && (in[i] != '\0') ) //returns 0 if not a white space
	{
	  out[j] = in[i];
	  i++;
	  j++;
	}
      else
	{
	  i++;
	}
    }
  if(j <= 0) //maybe it was just a space or something idk 
    return NULL;
  if( j < strlen(in) )
    out[j] = '\0'; // null terminator to end
  return out; //Most perfectest spaceless as I can get, string.
}

void exec_cmnds(char *cmnds)
{
  
}
