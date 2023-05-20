.PHONY: clean

build: implement1

implement1: implement1.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^ -pthread -std=c++17

run: implement1
	./implement1.out 10 3

clean:
	rm -fr *.out *.o *.dSYM