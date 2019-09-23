CXXFLAGS = --std=c++17

averages: main.o average.o *.h
	$(CXX) $(CXXFLAGS) main.o average.o -o averages

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

average.o: average.cpp *.h
	$(CXX) $(CXXFLAGS) -c average.cpp -o average.o

clean:
	rm -f *.o *.gch ~* a.out averages
 
