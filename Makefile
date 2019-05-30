# Compiler, Linker Defines
CC      := /usr/bin/gcc
LD      := /usr/bin/gcc
CFLAGS  := -std=c99 -Wall -O2
LIBPATH := -L.
LDFLAGS := -o $(EXE) $(LIBPATH) $(LIBS)
CFDEBUG := -std=c99 -Wall -g -DDEBUG $(LDFLAGS)


# All the subdirs that contain source files to be compiled.
# The obj subdirs will match the src layout.
MODULES := finite_state_machine main misc 
SRC_DIR := $(addprefix src/,$(MODULES))
OBJ_DIR := $(addprefix obj/,$(MODULES))
BIN_DIR := bin

SRC      := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ      := $(patsubst src/%.c,obj/%.o,$(SRC))
INCLUDES := $(addprefix -I,$(SRC_DIR))

vpath %.c $(SRC_DIR)

define make-goal
$1/%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs $(BIN_DIR)/test

$(BIN_DIR)/test: $(OBJ)
	$(LD) $^ -o $@


checkdirs: $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)

$(foreach objdir,$(OBJ_DIR),$(eval $(call make-goal,$(objdir))))
