# Common make definitions, customized for each platform

# Definitions required in all program directories to compile and link
# C programs using gcc.

CC=gcc
COMPILE.c=$(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK.c=$(CC) $(CFLAGS) $(CPPFLAGS) $(LDDIR) $(LDLIBS) 
LDDIR=-Llib
LDLIBS=lib/error.a
CFLAGS=-std=c11 -Iinc -Wall -DMACOS

# Common temp files to delete from each directory.
TEMPFILES=core core.* *.o temp.* *.out typescript*

BIN = bin
PROGS = $(BIN)/fig1.1 $(BIN)/fig1.2 $(BIN)/fig1.3 $(BIN)/fig1.4 $(BIN)/fig1.5 \
		$(BIN)/fig1.6 $(BIN)/fig1.7 $(BIN)/fig1.8 $(BIN)/fig2.2 $(BIN)/fig3.1 \
		$(BIN)/fig3.2 $(BIN)/fig3.3 $(BIN)/fig3.4 $(BIN)/excise3.2 $(BIN)/fig4.1 \
		$(BIN)/fig4.2 $(BIN)/fig4.3

all:	$(PROGS)

$(PROGS):bin/%:src/%.c
	$(LINK.c) $< -o $@

clean:
	rm -f ${PROGS} ${TEMPFILES} file.hole
