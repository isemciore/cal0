CC = g++
rCC = clang++

SRC = calendarAndDate/
FLAGS = -std=c++11 -g -Wall -I $(SRC)
CXXL = -I cxxtest/
testOUT = datetest
arrayNa = Vector

main.out: datetest.cpp cal_cxxTest.cpp kattistime.o
	./cxxtest/cxxtestgen.pl --error-printer -o tests.cpp cal_cxxTest.cpp
	$(CC) $(FLAGS) -o main.out $(CXXL) tests.cpp $(SRC)date.hpp $(SRC)julian.hpp $(SRC)gregorian.hpp kattistime.o


kattistime.o : $(SRC)kattistime.cpp
	$(CC) $(FLAGS) -c $(SRC)kattistime.cpp -o kattistime.o


clean:
	rm -f *.o *.out && clear 

