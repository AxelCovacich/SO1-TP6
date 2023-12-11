cflags = -Wall -Werror -pedantic -g

Mapper: Mapper.o
	gcc $(CFLAGS) -o Mapper Mapper.o

Mapper.o: Mapper.c
	gcc $(cflags) -c Mapper.c

clean:
	rm *.o Mapper