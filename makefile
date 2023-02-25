#Getting Fancier with automatic variables
.PHONY : all
all : project2
GCC := gcc -o
args := -Wall -Werror

project2: project2.c
	$(GCC) $@ $? $(args)

.PHONY : clean
clean :
	rm -f *.o project2

