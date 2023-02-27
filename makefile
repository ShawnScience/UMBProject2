#Getting Fancier with automatic variables
.PHONY : all #Not really a file so its a phony, allows file name all, clean etc
all : project2
GCC := gcc -o
args := -Wall -Werror

project2: project2.c
	$(GCC) $@ $? $(args)
# $@ is the calling name ie project2, $? is the preregs ie project2.c

.PHONY : clean
clean :
	rm -f *.o project2

