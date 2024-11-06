CC = g++
FLAGS = -Wall -Werror -pedantic -std=c++17 -g
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

DEPS = FibLFSR.hpp
OBJS = FibLFSR.o

PROGRAM = test PhotoMagic

all: test PhotoMagic PhotoMagic.a

PhotoMagic: main.o PhotoMagic.a
	$(CC) $(FLAGS) -o $@ $^ $(LIBS)

test: test.o PhotoMagic.a
	$(CC) $(FLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(FLAGS) -c $<

PhotoMagic.a: FibLFSR.o PhotoMagic.o
	ar rcs PhotoMagic.a FibLFSR.o PhotoMagic.o

clean:
	rm *.o *.a $(PROGRAM)

lint:
	cpplint *.cpp *.hpp
