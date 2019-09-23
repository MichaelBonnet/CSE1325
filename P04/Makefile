CXXFLAGS = --std=c++17

trains: main.o train.o stock.o coach.o locomotive.o *.h
	$(CXX) $(CXXFLAGS) main.o train.o stock.o coach.o locomotive.o -o trains

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

train.o: train.cpp train.h
	$(CXX) $(CXXFLAGS) -c train.cpp -o train.o

stock.o: stock.cpp stock.h
	$(CXX) $(CXXFLAGS) -c stock.cpp -o stock.o

coach.o: coach.cpp coach.h stock.h
	$(CXX) $(CXXFLAGS) -c coach.cpp -o coach.o

locomotive.o: locomotive.cpp locomotive.h stock.h
	$(CXX) $(CXXFLAGS) -c locomotive.cpp -o locomotive.o

clean:
	rm -f *.o *.gch ~* a.out trains