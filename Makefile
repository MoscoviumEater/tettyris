CC ?= gcc
SRCS = main.c glob.c log.c pcs.c ren.c
LDFLAGS = -lncurses -ltinfo -lm 
CFLAGS ?= -O1 -march=native
PREFIX ?= /usr
DIR ?= $(PREFIX)/bin


tettyris: $(SRCS)
	$(CC) $(SRCS) -o tettyris $(LDFLAGS) $(CFLAGS)

clean:
	rm -f tettyris
install:
	mkdir -p $(DESTDIR)$(DIR)
	cp tettyris $(DESTDIR)$(DIR)/tettyris
uninstall:
	rm -f $(DIR)/tettyris
