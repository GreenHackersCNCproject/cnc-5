BIN = parser
SRCS= src/parser.c src/math/converter.c
OBJS= $(SRCS:.c=.o)

CC= gcc
CCFLAGS= -g -Wall -Iinclude -O0 -pipe
LD= gcc
LDFLAGS= -g $(LIBS) -lm

all: $(BIN)

.c.o:
	$(CC) $(CCFLAGS) $(LIBS) -o $@ -c $<

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

clean:
	-rm -f *.o */*.o */*/*.o $(BIN)

.PHONY: all clean
