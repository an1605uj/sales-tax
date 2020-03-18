CFLAGS = 
CC = g++

build: main.o item.o tax.o
		$(CC) $(CFLAGS) -o app main.o tax.o item.o 
tax.o: sources/tax.cpp 
		$(CC) $(CFLAGS) -c sources/tax.cpp 
item.o: sources/item.cpp
		$(CC) $(CFLAGS) -c sources/item.cpp
main.o: main.cpp
		$(CC) $(CFLAGS) -c main.cpp
run: build 
	 ./app
clean: 
		rm -f *.o app
