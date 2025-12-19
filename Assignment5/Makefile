PROJECT = a5
CXX = g++
CXXFLAGS = -Wall -Wextra
GTEST_LIBS = -lgtest -lgtest_main -pthread 
SRC = main.cpp Rational.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(PROJECT)