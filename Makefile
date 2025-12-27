# simple makefile for task manager

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lncurses

TARGET = task_manager
SRCS = main.c process_list.c ui.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

# run with sudo if you want to kill other users' processes
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
