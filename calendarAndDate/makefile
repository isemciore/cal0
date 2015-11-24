CC    = g++
rCC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 

FLAGS = -std=c++11 -Wall -pedantic -O2

yourprogram.out: calendar15test.cpp kattistime.cpp calendar.hpp julian.hpp gregorian.hpp date.hpp
	$(CC) $(FLAGS) calendar15test.cpp kattistime.cpp -o yourprogram.out 

#yourprogram.out: calendar15test.cpp kattistime.o calendar.o julian.o gregorian.o date.o
#	 $(CC) $(FLAGS) calendar15test.cpp kattistime.o calendar.o julian.o gregorian.o date.o -o yourprogram.out 
#
#kattistime.o: kattistime.cpp
#	$(CC) $(FLAGS) -c kattistime.cpp -o kattistime.o
#	
	
#calendar.o: calendar.hpp
#	$(CC) $(FLAGS) -c calendar.hpp -o calendar.o
	
	
#julian.o: julian.hpp
#	$(CC) $(FLAGS) -c julian.hpp -o julian.o
	
	
#gregorian.o: gregorian.hpp
#	$(CC) $(FLAGS) -c gregorian.hpp -o gregorian.o
	
	
#date.o: date.hpp
#	$(CC) $(FLAGS) -c date.hpp -o date.o
	
	
	



youroutputs:
	cat calendar15.01.in | ./yourprogram.out > calendar15.01.out
	cat calendar15.02.in | ./yourprogram.out > calendar15.02.out
	cat calendar15.03.in | ./yourprogram.out > calendar15.03.out
	cat calendar15.04.in | ./yourprogram.out > calendar15.04.out
	cat calendar15.05.in | ./yourprogram.out > calendar15.05.out
	cat calendar15.06.in | ./yourprogram.out > calendar15.06.out
	cat calendar15.07.in | ./yourprogram.out > calendar15.07.out
	cat calendar15.08.in | ./yourprogram.out > calendar15.08.out
	cat calendar15.09.in | ./yourprogram.out > calendar15.09.out

comparewithans:
	diff calendar15.01.out calendar15.01.ans | tee difference15.01
	diff calendar15.02.out calendar15.02.ans | tee difference15.02
	diff calendar15.03.out calendar15.03.ans | tee difference15.03
	diff calendar15.04.out calendar15.04.ans | tee difference15.04
	diff calendar15.05.out calendar15.05.ans | tee difference15.05
	diff calendar15.06.out calendar15.06.ans | tee difference15.06
	diff calendar15.07.out calendar15.07.ans | tee difference15.07
	diff calendar15.08.out calendar15.08.ans | tee difference15.08
	diff calendar15.09.out calendar15.09.ans | tee difference15.09

answers_thiswilloverwritetheanswerssodontusethisone:
	cat calendar15.01.in | ./calendar15test.out > calendar15.01.ans
	cat calendar15.02.in | ./calendar15test.out > calendar15.02.ans
	cat calendar15.03.in | ./calendar15test.out > calendar15.03.ans
	cat calendar15.04.in | ./calendar15test.out > calendar15.04.ans
	cat calendar15.05.in | ./calendar15test.out > calendar15.05.ans
	cat calendar15.06.in | ./calendar15test.out > calendar15.06.ans
	cat calendar15.07.in | ./calendar15test.out > calendar15.07.ans
	cat calendar15.08.in | ./calendar15test.out > calendar15.08.ans
	cat calendar15.09.in | ./calendar15test.out > calendar15.09.ans

