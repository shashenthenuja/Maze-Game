CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o map.o terminal.o world.o control.o
EXEC = maze

ifdef DARK
CFLAGS += -D DARK
DARK : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c main.h map.h terminal.h world.h control.h
	$(CC) $(CFLAGS) main.c -c

map.c : map.c map.h
	$(CC) $(CFLAGS) map.c -c

terminal.c : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

world.c : world.c world.h
	$(CC) $(CFLAGS) world.c -c

control.c : control.c control.h
	$(CC) $(CFLAGS) control.c -c

clean :
	rm -f $(EXEC) $(OBJ)