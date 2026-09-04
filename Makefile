.PHONY: run clean all dirs

CFLAGS=-std=c++17
SFML=SFML
INCLUDE=-I $(SFML)/include
LIB=-L $(SFML)/bin
LFLAGS= -lsfml-graphics-3 -lsfml-window-3 -lsfml-system-3 -mwindows

SOURCES = entry.cpp GameManager.cpp Field.cpp Snake.cpp
TARGETS = $(SOURCES:%.cpp=obj/%.o)

SNAKE=bin/snake.exe

all: dirs $(SNAKE)
	@cp -u textures/* bin/textures
	@cp -u fonts/* bin/fonts

dirs:
	@mkdir -p bin
	@mkdir -p bin/textures
	@mkdir -p bin/fonts
	@mkdir -p obj

$(SNAKE): $(TARGETS)
	g++ $(LIB) $(LFLAGS) $^ -o $@

obj/%.o: %.cpp
	g++ -c $< $(CFLAGS) $(INCLUDE) -o $@

run: all
	./$(SNAKE)

clean:
	rm -rf bin/textures bin/fonts bin/snake.exe obj