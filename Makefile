# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Include directories (if headers are in 'include/')
INCLUDES = -I.

# Source and object files
SRCS = main.cpp prim.cpp dfs.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Pattern rule for object file compilation
%.o: %.cpp %.h cell.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# For main.o, which just depends on its headers
main.o: main.cpp prim.h cell.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp -o main.o

prim.o: prim.cpp prim.h cell.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c prim.cpp -o prim.o

dfs.o: dfs.cpp dfs.h cell.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c dfs.cpp -o dfs.o

# recursiveBacktracking.o: recursiveBacktracking.cpp recursiveBacktracking.h cell.h
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -c recursiveBacktracking.cpp -o recursiveBacktracking.o

# dfsRecursive.o: dfsRecursive.cpp dfsRecursive.h cell.h
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -c dfsRecursive.cpp -o dfsRecursive.o

clean:
	rm -f $(OBJS) $(TARGET)
