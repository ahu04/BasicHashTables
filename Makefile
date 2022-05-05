#############################################################################
#
#    Makefile
#
#############################################################################


CXX      = g++
CXXFLAGS = -std=c++11 -g -O2 -Wall -Wextra

tester: tester.cpp hashing_OA.o hashing_chaining.o hashing_total.o hashing_max.o LinkedList.o
	$(CXX) $(CXXFLAGS) -o hash hashing_OA.o hashing_chaining.o hashing_total.o hashing_max.o tester.cpp LinkedList.o

testerchaining: testerchaining.cpp hashing_OA.o hashing_chaining.o hashing_total.o hashing_max.o LinkedList.o
	$(CXX) $(CXXFLAGS) -o hashtwo hashing_OA.o hashing_chaining.o hashing_total.o hashing_max.o testerchaining.cpp LinkedList.o

hashing_chaining.o: hashing_chaining.cpp hashing_chaining.h LinkedList.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -c hashing_chaining.cpp LinkedList.cpp

hashing_OA.o: hashing_OA.cpp hashing_OA.h
	$(CXX) $(CXXFLAGS) -c hashing_OA.cpp

hashing_total.o: hashing_total.cpp hashing_total.h
	$(CXX) $(CXXFLAGS) -c hashing_total.cpp

hashing_max.o: hashing_max.cpp hashing_max.h
	$(CXX) $(CXXFLAGS) -c hashing_max.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp


clean:
	rm -f chaining hash openaddressing max total snapshot_end.txt snapshot_start.txt *.o *~