CC = gcc
CFLAGS = -g -Wall -Wextra -std=c99
HEADERS = bmp_header.h utils.h
OBJECTS = main.o utils.o 
EXEC = tema3
ARG1 = 1
ARG2 = 2
ARG3 = 3
ARG4 = 4
ARGBONUS = bonus
.PHONY = default build clean

default: build

build: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

run_task1: build
	./$(EXEC) $(ARG1) 

run_task2: build
	./$(EXEC) $(ARG2)

run_task3: build
	./$(EXEC) $(ARG3) 

run_task4: build
	./$(EXEC) $(ARG4)

run_bonus: build
	./$(EXEC) $(ARGBONUS)

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC)
	-rm -f *.bmp