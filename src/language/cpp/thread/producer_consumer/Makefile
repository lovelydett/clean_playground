.PHONY: clean

build: implement1

implement1: implement1.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^ -pthread

run: implement1
	./implement1.out

clean:
	rm -fr *.out *.o *.dSYM