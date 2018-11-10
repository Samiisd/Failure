CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99 -pedantic -g $(shell sdl2-config --cflags)
LDLIBS += $(shell sdl2-config --libs)

OBJS = src/main.o

# Adding game sources
CFLAGS += -Isrc/game/
	# Adding person sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/person/*.c))
	# Adding manager sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/manager/*.c))
	# Adding animation sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/animation/*.c))
	# Adding map sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/map/*.c))
	# Adding physics sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/game/physic/*.c))

# Adding menu sources
CFLAGS += -Isrc/menu/
	# Adding manager sources
OBJS += $(patsubst %.c,%.o,$(wildcard src/menu/manager/*.c))

# Adding list sources
CFLAGS += -Isrc/list
OBJS += $(patsubst %.c,%.o,$(wildcard src/list/*.c))

best_game_ever : $(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

all : best_game_ever

run : best_game_ever
	./best_game_ever

clean:
	$(RM) $(LIB) $(OBJS) best_game_ever

.PHONY: all run clean
