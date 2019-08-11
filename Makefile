#
# Filename: Makefile
# Contains: Makefile for Word Frequency Database
#

CC = clang++
CFLAGS = -Wall -Wextra -c -O2
DEPS = hash.h
 
 %.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

wordDB: hash.o main.o 
	$(CC) -o wordDB hash.o main.o 
  
clean:
	rm -f *.o core* *~ wordDB