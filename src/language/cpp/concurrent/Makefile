.PHONY: clean

build: async

async: async.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $^ -pthread -std=c++20

run: async
	./async.out

clean:
	rm -fr *.out *.o *.dSYM