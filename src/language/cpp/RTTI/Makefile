.PHONY: clean

build: typeid

typeid: typeid.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^ -std=c++17

run: typeid
	./typeid.out

clean:
	rm -rf *.out *.o *.dSYM