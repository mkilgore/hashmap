
EXE := example

CFLAGS += -g -pg -O2

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

.PHONY: clean
clean:
	rm -f $(EXE)
	rm -f $(OBJS)


