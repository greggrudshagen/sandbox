# Compiler, Linker Defines
CC      := /usr/bin/gcc
LD      := /usr/bin/gcc
CFLAGS  := -std=c99 -Wall -O2
LIBPATH := -L.
LDFLAGS := -o $(EXE) $(LIBPATH) $(LIBS)
CFDEBUG := -std=c99 -Wall -g -DDEBUG $(LDFLAGS)


# All the subdirs that contain source files to be compiled
MODULES   := finite_state_machine main misc 
SRC_DIR   := $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix build/,$(MODULES))


SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ       := $(patsubst src/%.c,build/%.o,$(SRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))

vpath %.c $(SRC_DIR)

define make-goal
$1/%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs build/test

build/test: $(OBJ)
	$(LD) $^ -o $@


checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))
