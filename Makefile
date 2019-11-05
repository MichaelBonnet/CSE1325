CXXFLAGS += --std=c++17 -g
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

shelter:  main.o mainwin.o shelter.o animal.o dog.o *.h
	$(CXX) $(CXXFLAGS)  main.o mainwin.o shelter.o animal.o dog.o $(GTKFLAGS) -o shelter

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

shelter.o: shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c shelter.cpp -o shelter.o

animal.o: animal.cpp *.h
	$(CXX) $(CXXFLAGS) -c animal.cpp -o animal.o

dog.o: dog.cpp  *.h
	$(CXX) $(CXXFLAGS) -c dog.cpp -o dog.o

clean:
	rm -f *.o *.gch a.out shelter

# remake:
# 	clean make
# how the hell do I make a remake rule again, jfc

