source: source.o window.o rectangle.o player.o
	g++ bin/source.o bin/window.o bin/rectangle.o bin/player.o -o bin/source -LC:\mingw_dev_lib\lib -lmingw32 -lSDL2main -lSDL2

source.o: src/source.cpp
	g++ -c src/source.cpp -o bin/source.o -IC:\mingw_dev_lib\include\SDL2 -w

window.o: src/window.cpp
	g++ -c src/window.cpp -o bin/window.o -IC:\mingw_dev_lib\include\SDL2 -w

rectangle.o: src/rectangle.cpp
	g++ -c src/rectangle.cpp -o bin/rectangle.o -IC:\mingw_dev_lib\include\SDL2 -w

player.o: src/player.cpp
	g++ -c src/player.cpp -o bin/player.o -IC:\mingw_dev_lib\include\SDL2 -w

clean:
	rm -f bin/*.o
run:
	bin/source.exe