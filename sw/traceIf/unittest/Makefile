ROOT_DIR := $(shell git rev-parse --show-toplevel)
TARGET = traceIfTest
LIBMATHIF_AR := libmathifa.a
BIN = ./bin
LIBDIR = $(BIN)/lib

CC = gcc
AR = ar
CCFLAGS = -g -Wall -Werror -Wextra
ARFLAGS = -rcs

INC_DIR =
INC_DIR += -I ./
INC_DIR += -I ../if/

all: create_bin $(BIN)/mathif.o $(LIBDIR)/$(LIBMATHIF_AR) $(BIN)/$(TARGET)

create_bin:
	@mkdir -p $(BIN)
	@mkdir -p $(LIBDIR)

$(BIN)/${TARGET}: $(BIN)/traceIf.o $(BIN)/traceIfTest.o 
	$(CC) $^ $(CCFLAGS) -lpthread -L$(LIBDIR) -lmathifa -o $@
# This command below cause undefined reference to add, sub, mul, div???
#	$(CC) $(CCFLAGS) -lpthread -L$(LIBDIR) -lmathifa -o $@ $^

$(BIN)/traceIf.o: $(ROOT_DIR)/sw/traceIf/src/traceIf.c
	$(CC) -c $(CCFLAGS) -o $@ $(INC_DIR) $<

$(BIN)/mathif.o: mathif.c
	$(CC) -c $(CCFLAGS) -o $@ $(INC_DIR) $<

$(BIN)/traceIfTest.o: traceIfTest.c
	$(CC) -c $(CCFLAGS) -o $@ $(INC_DIR) $<

$(LIBDIR)/$(LIBMATHIF_AR): $(BIN)/traceIf.o $(BIN)/mathif.o
	$(AR) $(ARFLAGS) $@ $^


run:
	$(BIN)/$(TARGET)

clean:
	rm -rf $(BIN)