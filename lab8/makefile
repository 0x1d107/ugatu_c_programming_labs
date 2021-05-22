CPP=$(wildcard *.cpp)
OBJ=$(CPP:.cpp=.o)
all:lab8_io

lab8_io: $(OBJ)
	$(CXX) -g -fsanitize=address,undefined $^ -o $@
%.o:%.cpp
	$(CXX) -g -c -Wall -fsanitize=address,undefined $< -o $@
