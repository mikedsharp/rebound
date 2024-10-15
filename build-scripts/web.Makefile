CC = emcc
INC = -Irebound-engine -IGame
EMFLAGS = -lembind \
		  -s WASM=1 \
		  -s USE_SDL=2 \
		  -s USE_SDL_MIXER=2 \
		  -s USE_SDL_IMAGE=2 \
		  -s USE_SDL_TTF=2 \
		  -s SDL2_IMAGE_FORMATS=png \
		  -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=0 \
		  -s EXPORT_ES6 \
		  -O3 \
		  --preload-file assets \
		  --shell-file app-container.html

SOURCES = rebound-engine/src/Rendering/GameSprite.cpp \
	rebound-engine/src/Util/JavascriptCallbackHandler.cpp \
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

all: before_build build

build: before_build OUT

OUT: $(SOURCES)
	 $(CC) $(EMFLAGS) $(INC) $(SOURCES) -o web-game-player/public/index.js

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