CC ?= gcc
SRCS = main.c glob.c log.c pcs.c ren.c
LDFLAGS = -lncurses -ltinfo -lm 
CFLAGS ?= -O1 -march=native
PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
DESTDIR ?=
OBJS = $(SRCS:.c=.o)


tettyris: $(OBJS)
	$(CC) $(OBJS) -o tettyris $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJS): decl.h

clean:
	rm -f $(OBJS) tettyris
install:
	install -d $(DESTDIR)$(BINDIR)
	install -m755 tettyris $(DESTDIR)$(BINDIR)/tettyris
uninstall:
	rm -f $(DESTDIR)$(BINDIR)/tettyris
