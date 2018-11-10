CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99 -pedantic -g $(shell sdl2-config --cflags)
LDLIBS += $(shell sdl2-config --libs)

OBJS = src/game.o src/map.o src/animation.o

game : $(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

all : game

run : game
	./game

clean:
	$(RM) $(LIB) $(OBJS) game

.PHONY: all run clean
