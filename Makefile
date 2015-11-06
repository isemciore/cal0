CC = g++
rCC = clang++

SRC = calendarAndDate/
FLAGS = -std=c++11 -g -Wall -I $(SRC)
CXXL = -I cxxtest/
testOUT = datetest
arrayNa = Vector

main.out: datetest.cpp Julian.o Gregorian.o kattistime.o cal_cxxTest.cpp
	./cxxtest/cxxtestgen.pl --error-printer -o tests.cpp cal_cxxTest.cpp
	$(CC) $(FLAGS) -o main.out $(CXXL) tests.cpp Julian.o Gregorian.o Date.o kattistime.o

Julian.o: $(SRC)julian.cpp Date.o
	$(CC) $(FLAGS) Date.o -c $(SRC)julian.cpp -o Julian.o

Gregorian.o: $(SRC)gregorian.cpp Date.o
	$(CC) $(FLAGS) -c $(SRC)gregorian.cpp Date.o -o Gregorian.o


Date.o : $(SRC)date.cpp
	$(CC) $(FLAGS) -c $(SRC)date.cpp -o Date.o

kattistime.o : $(SRC)kattistime.cpp
	$(CC) $(FLAGS) -c $(SRC)kattistime.cpp -o kattistime.o

clean:
	rm -f *.o *.out && clear 

