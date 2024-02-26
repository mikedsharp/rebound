INC = -I SDL2 -I Engine/include

ASSETSDIR = assets
BINDIR = bin/linux

OBJS = Engine/src/Rendering/GameSprite.cpp \
	Engine/src/Rendering/GameWindow.cpp \
	Engine/src/Rendering/RenderManager.cpp \
	Engine/src/States/GameOverState.cpp \
	Engine/src/States/MainMenuState.cpp \
	Engine/src/States/RandomRebound_GameState.cpp \
	Engine/src/Util/AudioResourceManager.cpp \
	Engine/src/Util/MusicPlayer.cpp \
	Engine/src/Util/SoundPlayer.cpp \
	Engine/src/Util/Camera.cpp \
	Engine/src/Util/Composite.cpp \
	Engine/src/Util/Dimension.cpp \
	Engine/src/Util/ImageResourceManager.cpp \
	Engine/src/Util/Point.cpp \
	Engine/src/Util/Rect.cpp \
	Engine/src/Util/RotatedRectangle.cpp \
	Engine/src/Util/Util/Focusable.cpp \
	Engine/src/Util/Vector2f.cpp \
	Engine/src/main.cpp \
	Engine/src/Exception/FileNotFoundException.cpp \
	Engine/src/GameEngine.cpp \
	Engine/src/GameState.cpp \
	Engine/src/GameStateFactory.cpp \
	Engine/src/Game/Ball.cpp \
	Engine/src/Game/Crate.cpp \
	Engine/src/Game/Paddle.cpp \
	Engine/src/Rendering/Drawable.cpp

CC = g++

COMPILER_FLAGS = -g -w 

LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image

OBJ_NAME = bin/linux/rebound

all: build

clean: 	
	rm -rf bin/linux

before_build: 
	mkdir bin/linux
	mkdir bin/linux/assets
	cp -R $(ASSETSDIR) $(BINDIR)


after_build: 

build: before_build OUT after_build

OUT: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(INC) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean_build: clean build

