CC=g++
CFLAGS=-g -pedantic -std=gnu17 -Wall -Werror -Wextra

.PHONY: all
all: ATM

ATM: ATM.cpp bankAccount.cpp transaction.cpp cases.cpp global.h bankAccount.h transaction.h cases.h
	g++ -o atm ATM.cpp bankAccount.cpp transaction.cpp cases.cpp

.PHONY: clean
clean:
	rm -f *.o ATM