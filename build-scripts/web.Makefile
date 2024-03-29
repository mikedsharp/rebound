CC = emcc
INC = -IEngine/include
EMFLAGS = -s WASM=1 \
		  -s USE_SDL=2 \
		  -s USE_SDL_MIXER=2 \
		  -s USE_SDL_IMAGE=2 \
		  -s SDL2_IMAGE_FORMATS=png \
		  -O3 \
		  --preload-file assets \
		  --shell-file app-container.html

SOURCES = Engine/src/Rendering/GameSprite.cpp \
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

all: before_build build

build: before_build OUT

OUT: $(SOURCES)
	 $(CC) $(EMFLAGS) $(INC) $(SOURCES) -o web/index.html

clean_build: clean build

clean: 
ifeq ($(suffix $(SHELL)),.exe)
	cmd /c if exist web rd /s /q web
else
	rm -rf web
endif
before_build: 
ifeq ($(suffix $(SHELL)),.exe)
	cmd /c if not exist web md web
else
	mkdir web
endif