INC = -I SDL2 -I rebound-engine -I Game

ASSETSDIR = assets
BINDIR = bin/linux

OBJS = rebound-engine/src/Rendering/GameSprite.cpp \
	rebound-engine/src/Rendering/GameWindow.cpp \
	rebound-engine/src/Rendering/RenderManager.cpp \
	Game/src/States/GameOverState.cpp \
	Game/src/States/MainMenuState.cpp \
	Game/src/States/RandomRebound_GameState.cpp \
	rebound-engine/src/Util/Font.cpp \
	rebound-engine/src/Util/Text.cpp \
	rebound-engine/src/Util/Timer.cpp \
	rebound-engine/src/Util/AudioResourceManager.cpp \
	rebound-engine/src/Util/MusicPlayer.cpp \
	rebound-engine/src/Util/SoundPlayer.cpp \
	rebound-engine/src/Util/Camera.cpp \
	rebound-engine/src/Util/Composite.cpp \
	rebound-engine/src/Util/Dimension.cpp \
	rebound-engine/src/Util/ImageResourceManager.cpp \
	rebound-engine/src/Util/Point.cpp \
	rebound-engine/src/Util/Rect.cpp \
	rebound-engine/src/Util/RotatedRectangle.cpp \
	rebound-engine/src/Util/Focusable.cpp \
	rebound-engine/src/Util/Vector2f.cpp \
	Game/src/main.cpp \
	rebound-engine/src/Exception/FileNotFoundException.cpp \
	rebound-engine/src/GameEngine.cpp \
	rebound-engine/src/GameState.cpp \
	rebound-engine/src/Rendering/Drawable.cpp \
	Game/src/States/GameStateFactory.cpp \
	Game/src/GameEntities/Ball.cpp \
	Game/src/GameEntities/Crate.cpp \
	Game/src/GameEntities/Paddle.cpp


CC = g++

COMPILER_FLAGS = -g -w 

LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

OBJ_NAME = bin/linux/rebound
INSTALL_SCRIPT_DIR = build-scripts/linux/install.sh

all: build

clean: 	
	rm -rf bin/linux

before_build: 
	mkdir -p bin
	mkdir -p bin/linux
	mkdir -p bin/linux/assets
	cp -R $(ASSETSDIR) $(BINDIR)


after_build: 

build: before_build OUT after_build

OUT: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(INC) $(LINKER_FLAGS) -o $(OBJ_NAME)
	cp ${INSTALL_SCRIPT_DIR} bin/linux

clean_build: clean build