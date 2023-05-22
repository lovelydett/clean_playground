.PHONY: clean

build: implement1 implement2

implement1: implement1.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^ -pthread -std=c++17

implement2: implement2.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^ -pthread -std=c++20

run: implement2
	./implement2.out 10 3

clean:
	rm -fr *.out *.o *.dSYM