all: compile execute

compile:
	g++ -Wno-deprecated -Isrc -Iinclude -g src/*.cpp src/Game/*.cpp src/Game/State/*.cpp src/Game/GameObject/*.cpp src/Game/GameObject/Pattern/*.cpp src/Game/GameObject/Laser/*.cpp -Llib -lsfml-graphics -lsfml-window -lsfml-system -o bin/Laser.exe

execute:
	cd ./bin
	bin/Laser.exe