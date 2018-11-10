CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99 -pedantic -g $(shell sdl2-config --cflags)
LDLIBS += $(shell sdl2-config --libs)

OBJS = src/game.o src/map.o src/animation.o
OBJS = src/main.o

CFLAGS += -Isrc/**

# Adding game sources
CFLAGS += -Isrc/game/
	# Adding manager sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/manager/*.c))
	# Adding animation sources
CFLAGS += -Isrc/animation/
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/animation/*.c))
	# Adding map sources
CFLAGS += -Isrc/map/
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/map/*.c))
	# Adding map sources
CFLAGS += -Isrc/physic/
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/physic/*.c))

# Adding menu sources
CFLAGS += -Isrc/menu/
	# Adding manager sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/menu/manager/*.c))

game : $(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

all : game

run : game
	./game

clean:
	$(RM) $(LIB) $(OBJS) game

.PHONY: all run clean
