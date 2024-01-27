build:
	gcc -Wall -lSDL2 -std=c99 ./src/*.c -o app

run:
	./app

clean:
	rm app