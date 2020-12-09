ifeq ($(OS),Windows_NT)
    CXX := g++
	CXX_FLAGS := -Wall -lws2_32 -g
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
    	CXX := clang++
		CXX_FLAGS := -Wall -Wextra -std=c++17 -g
	else
		CXX := g++
		CXX_FLAGS := -Wall -Wextra
	endif
endif

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib
SRCS 	:= $(wildcard *.cpp)

LIBRARIES	:=
EXECUTABLE	:= main
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
ALL_SRC_FILES=$(call rwildcard,src,*.cpp !**/esp32/**)
DEV_SRC_FILES = $(filter-out src/esp32/%,$(ALL_SRC_FILES))

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(DEV_SRC_FILES)
	$(CXX) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) -Ddev $(CXX_FLAGS)

clean:
	-rm $(BIN)/*