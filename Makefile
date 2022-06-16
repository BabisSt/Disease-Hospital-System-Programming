CC = gcc
CFLAGS = -g3 -Wall
LDFLAGS = -lm

ODIR = BUILD
IDIR = HEADERS
SDIR = SRC

EXECUTABLE = diseaseMonitor

_DEPS = list.h patient.h avl.h date.h hash.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o list.o patient.o avl.o date.o hash.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(ODIR)/*.o
	# rm -f $(BDIR)/$(EXECUTABLE)
