ROOT_DIR := $(shell git rev-parse --show-toplevel)
TARGET = enumUtilsTest
BIN = ./bin

CXX = g++
AR = ar
CXXFLAGS = -g -Wall -Werror -Wextra
ARFLAGS = -rcs

INC_DIR =
INC_DIR += -I ../if

all: create_bin $(BIN)/$(TARGET)

create_bin:
	@mkdir -p $(BIN)

$(BIN)/${TARGET}: $(BIN)/enumUtilsTest.o
	$(CXX) $^ $(CXXFLAGS) -o $@

$(BIN)/enumUtilsTest.o: enumUtilsTest.cc
	$(CXX) -c $(CXXFLAGS) -o $@ $(INC_DIR) $<

run:
	$(BIN)/$(TARGET)

clean:
	rm -rf $(BIN)