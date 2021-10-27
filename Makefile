all: compile execute

compile:
	g++ -Isrc -Iinclude -g src/*.cpp -Llib -lsfml-graphics -lsfml-window -lsfml-system -o bin/Laser.exe

execute:
	bin/Laser.exe