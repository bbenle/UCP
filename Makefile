CC = gcc
CFLAGS = -Wall -Werror -pedantic -ansi -std=c89 -g 
OBJ = fileio.o menu.o game.o linkedlist.o logs.o winchecks.o
EXEC = TicTacToe

ifdef SECRET
CFLAGS += -D SECRET
SECRET : clean $(EXEC)
endif

ifdef EDITOR
CFLAGS += -D EDITOR
SECRET : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

fileio.o : fileio.c fileio.h
	$(CC) $(CFLAGS) -c fileio.c

menu.o : menu.c menu.h fileio.h game.h linkedlist.h
	$(CC) $(CFLAGS) -c menu.c

game.o : game.c game.h fileio.h linkedlist.h
	$(CC) $(CFLAGS) -c game.c

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

logs.o : logs.c logs.h
	$(CC) $(CFLAGS) -c logs.c

winchecks.o : winchecks.c winchecks.h
	$(CC) $(CFLAGS) -c winchecks.c

val : $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC) settings.txt

clean:
	rm -f $(EXEC) $(OBJ)

