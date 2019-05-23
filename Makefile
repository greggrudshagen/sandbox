# Source, Executable, Includes, Library Defines
FSM_SRC = fsm_main.c fsm_init.c fsm_north.c fsm_east.c fsm_south.c fsm_west.c
LL_SRC  = linklist.c
INCL    = 
SRC     = main.c arrarys.c bits.c random.c utility.c $(FSM_SRC) $(LL_SRC)
OBJ     = $(SRC:.c=.o)
LIBS    =
EXE     = gdr

# Compiler, Linker Defines
CC      = /usr/bin/gcc
CFLAGS = -std=c99 -Wall -O2 -I.
LIBPATH = -L.
LDFLAGS = -o $(EXE) $(LIBPATH) $(LIBS)
CFDEBUG = -std=c99 -Wall -g -DDEBUG $(LDFLAGS)
RM      = /bin/rm -f

# Compile and Assemble C Source Files into Object Files
%.o: %.c
	$(CC) -c $(CFLAGS) $*.c

# Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

# Objects depend on these Libraries
$(OBJ): $(INCL)

# Create a gdb/dbx Capable Executable with DEBUG flags turned on
debug:
	$(CC) $(CFDEBUG) $(SRC)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	$(RM) $(OBJ) $(EXE) core a.out
