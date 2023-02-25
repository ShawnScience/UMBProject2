#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc > 1)
    {
      fprintf(stderr, "Error, too many arguments to wish.\n");
      exit(-3);
    }
  if(argc == 0)
    {
      printf("We got 0 args");
      exit(-1);
    }
  if(argc == 1)
    {
      printf("Got 1 arg");
      exit(2);
    }
}
