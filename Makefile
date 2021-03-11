CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb
SFML := -lsfml-graphics -lsfml-window -lsfml-system
BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main.app


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ $(SFML) -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
