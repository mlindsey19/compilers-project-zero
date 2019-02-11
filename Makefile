#Mitch (david) Lindsey
#cs4280
#02-10-2019

CC = gcc
CFLAGS = -g -Wall
OBJ = main.o traversals.o buildTree.o tree.o checkArgs.o
.SUFFIXES: .c .o

P0: $(OBJ)
	$(CC)  $(CFLAGS) -o P0 $(OBJ)
%.o: %.c *.h
	$(CC) -c $(CFLAGS) $*.c -o $*.o

clean:
	rm P0 *.o *.preorder *.postorder *.inorder
