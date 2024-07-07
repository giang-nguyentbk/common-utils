ROOT_DIR := $(shell git rev-parse --show-toplevel)
TARGET = stringUtilsTest
BIN = ./bin

CXX = g++
AR = ar
CXXFLAGS = -g -Wall -Werror -Wextra
ARFLAGS = -rcs

INC_DIR =
INC_DIR += -I ./
INC_DIR += -I ../if
INC_DIR += -I ../../traceIf/if

all: create_bin $(BIN)/$(TARGET)

create_bin:
	@mkdir -p $(BIN)

$(BIN)/${TARGET}: $(BIN)/stringUtilsTest.o $(BIN)/traceIf.o
	$(CXX) $^ $(CXXFLAGS) -o $@

$(BIN)/traceIf.o: $(ROOT_DIR)/sw/traceIf/src/traceIf.c
	$(CC) -c $(CCFLAGS) -o $@ $(INC_DIR) $<

$(BIN)/stringUtilsTest.o: stringUtilsTest.cc
	$(CXX) -c $(CXXFLAGS) -o $@ $(INC_DIR) $<

run:
	$(BIN)/$(TARGET)

clean:
	rm -rf $(BIN)