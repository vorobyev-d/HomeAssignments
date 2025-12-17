PROJECT = a3
CXX = g++
CXXFLAGS = -Wall -Wextra
GTEST_LIBS = -lgtest -lgtest_main -pthread 
SRC = main.cpp Transformer.cpp TankTransformer.cpp Operator.cpp Engine.cpp CarTransformer.cpp AircraftTransformer.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(PROJECT)
