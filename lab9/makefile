
all: lab9_class lab9_y

%.o: %.cpp
	$(CXX) -c $< -o $@
lab9_y: lab9_y.o
	$(CXX) $^ -o $@
lab9_class: lab9_class.o LivingSpace.o
	$(CXX) $^ -o $@