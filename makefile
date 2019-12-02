CFLAGS = -std=c++11 -Wall

library:	library.o book.o main.o
	g++ library.o book.o main.o -o library $(CFLAGS)

main.o:	main.cpp library.h book.h
	g++ -c main.cpp $(CFLAGS)

test:	library.o book.o test.o
	g++ library.o book.o test.o -o test $(CFLAGS)

test.o:	test.cpp library.h book.h
	g++ -c test.cpp $(CFLAGS)


library.o:	library.cpp library.h book.h
	g++ -c library.cpp $(CFLAGS)

book.o:	book.cpp book.h
	g++ -c book.cpp $(CFLAGS)


clean:
	rm *.o library test
