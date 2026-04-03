CC = gcc
SRCS = main.c glob.c log.c pcs.c ren.c
FLAGS = -lncurses -ltinfo -lm -O1 -march=native

tettyris: $(SRCS)
	$(CC) $(SRCS) -o tettyris $(FLAGS)

clean:
	rm -f tettyris
