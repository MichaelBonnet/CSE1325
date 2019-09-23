CXXFLAGS = --std=c++17

all: hello hello_getuid hello_whoami

hello: hello.cpp
	$(CXX) $(CXXFLAGS) hello.cpp -o hello

hello_getuid: hello_getuid.cpp
	$(CXX) $(CXXFLAGS) hello_getuid.cpp -o hello_getuid

hello_whoami: hello_whoami.cpp
	$(CXX) $(CXXFLAGS) hello_whoami.cpp -o hello_whoami

clean:
	-rm -f *.o *~ a.out hello hello_getuid hello_whoami
