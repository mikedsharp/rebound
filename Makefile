WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

# BE SURE TO UPDATE THIS TO A PATH WHERE YOU HAVE SDL INSTALLED
SDL_LOCATION = C:\\SDL2
SDL_MIXER_LOCATION = C:\\SDL2
SDL_IMAGE_LOCATION = C:\\SDL2

INC = -I${SDL_LOCATION}\\include\\SDL2 -IEngine\\include
CFLAGS = 
RESINC = 
LIBDIR = -L${SDL_LOCATION}\\lib -L${SDL_IMAGE_LOCATION}\\lib -L${SDL_MIXER_LOCATION}\\lib
LIB = ${SDL_LOCATION}\\lib
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g -w -Wl,-subsystem,windows
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = 
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG = 
OUT_DEBUG = bin\\Debug\\rebound.exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = 
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE = 
OUT_RELEASE = bin\\Release\\rebound.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\GameSprite.o $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\GameWindow.o $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\RenderManager.o $(OBJDIR_DEBUG)\\Engine\\src\\States\\GameOverState.o $(OBJDIR_DEBUG)\\Engine\\src\\States\\MainMenuState.o $(OBJDIR_DEBUG)\\Engine\\src\\States\\RandomRebound_GameState.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\AudioResourceManager.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\MusicPlayer.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\SoundPlayer.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Camera.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Composite.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Dimension.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\ImageResourceManager.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Point.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Rect.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\RotatedRectangle.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Util\\Focusable.o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Vector2f.o $(OBJDIR_DEBUG)\\Engine\\src\\main.o $(OBJDIR_DEBUG)\\Engine\\src\\Exception\\FileNotFoundException.o $(OBJDIR_DEBUG)\\Engine\\src\\GameEngine.o $(OBJDIR_DEBUG)\\Engine\\src\\GameState.o $(OBJDIR_DEBUG)\\Engine\\src\\GameStateFactory.o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Ball.o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Crate.o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Paddle.o $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\Drawable.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\GameSprite.o $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\GameWindow.o $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\RenderManager.o $(OBJDIR_RELEASE)\\Engine\\src\\States\\GameOverState.o $(OBJDIR_RELEASE)\\Engine\\src\\States\\MainMenuState.o $(OBJDIR_RELEASE)\\Engine\\src\\States\\RandomRebound_GameState.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\AudioResourceManager.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\MusicPlayer.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\SoundPlayer.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Camera.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Composite.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Dimension.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\ImageResourceManager.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Point.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Rect.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\RotatedRectangle.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Util\\Focusable.o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Vector2f.o $(OBJDIR_RELEASE)\\Engine\\src\\main.o $(OBJDIR_RELEASE)\\Engine\\src\\Exception\\FileNotFoundException.o $(OBJDIR_RELEASE)\\Engine\\src\\GameEngine.o $(OBJDIR_RELEASE)\\Engine\\src\\GameState.o $(OBJDIR_RELEASE)\\Engine\\src\\GameStateFactory.o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Ball.o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Crate.o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Paddle.o $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\Drawable.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG)\\Engine\\src\\Rendering md $(OBJDIR_DEBUG)\\Engine\\src\\Rendering
	cmd /c if not exist $(OBJDIR_DEBUG)\\Engine\\src\\States md $(OBJDIR_DEBUG)\\Engine\\src\\States
	cmd /c if not exist $(OBJDIR_DEBUG)\\Engine\\src\\Util md $(OBJDIR_DEBUG)\\Engine\\src\\Util
	cmd /c if not exist $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Util md $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Util
	cmd /c if not exist $(OBJDIR_DEBUG)\\Engine\\src md $(OBJDIR_DEBUG)\\Engine\\src
	cmd /c if not exist $(OBJDIR_DEBUG)\\Engine\\src\\Exception md $(OBJDIR_DEBUG)\\Engine\\src\\Exception
	cmd /c if not exist $(OBJDIR_DEBUG)\\Engine\\src\\Game md $(OBJDIR_DEBUG)\\Engine\\src\\Game

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\GameSprite.o: Engine\\src\\Rendering\\GameSprite.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Rendering\\GameSprite.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\GameSprite.o

$(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\GameWindow.o: Engine\\src\\Rendering\\GameWindow.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Rendering\\GameWindow.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\GameWindow.o

$(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\RenderManager.o: Engine\\src\\Rendering\\RenderManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Rendering\\RenderManager.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\RenderManager.o

$(OBJDIR_DEBUG)\\Engine\\src\\States\\GameOverState.o: Engine\\src\\States\\GameOverState.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\States\\GameOverState.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\States\\GameOverState.o

$(OBJDIR_DEBUG)\\Engine\\src\\States\\MainMenuState.o: Engine\\src\\States\\MainMenuState.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\States\\MainMenuState.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\States\\MainMenuState.o

$(OBJDIR_DEBUG)\\Engine\\src\\States\\RandomRebound_GameState.o: Engine\\src\\States\\RandomRebound_GameState.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\States\\RandomRebound_GameState.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\States\\RandomRebound_GameState.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\AudioResourceManager.o: Engine\\src\\Util\\AudioResourceManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\AudioResourceManager.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\AudioResourceManager.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\MusicPlayer.o: Engine\\src\\Util\\MusicPlayer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\MusicPlayer.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\MusicPlayer.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\SoundPlayer.o: Engine\\src\\Util\\SoundPlayer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\SoundPlayer.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\SoundPlayer.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\Camera.o: Engine\\src\\Util\\Camera.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\Camera.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Camera.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\Composite.o: Engine\\src\\Util\\Composite.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\Composite.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Composite.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\Dimension.o: Engine\\src\\Util\\Dimension.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\Dimension.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Dimension.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\ImageResourceManager.o: Engine\\src\\Util\\ImageResourceManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\ImageResourceManager.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\ImageResourceManager.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\Point.o: Engine\\src\\Util\\Point.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\Point.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Point.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\Rect.o: Engine\\src\\Util\\Rect.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\Rect.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Rect.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\RotatedRectangle.o: Engine\\src\\Util\\RotatedRectangle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\RotatedRectangle.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\RotatedRectangle.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\Util\\Focusable.o: Engine\\src\\Util\\Util\\Focusable.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\Util\\Focusable.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Util\\Focusable.o

$(OBJDIR_DEBUG)\\Engine\\src\\Util\\Vector2f.o: Engine\\src\\Util\\Vector2f.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Util\\Vector2f.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Vector2f.o

$(OBJDIR_DEBUG)\\Engine\\src\\main.o: Engine\\src\\main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\main.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\main.o

$(OBJDIR_DEBUG)\\Engine\\src\\Exception\\FileNotFoundException.o: Engine\\src\\Exception\\FileNotFoundException.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Exception\\FileNotFoundException.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Exception\\FileNotFoundException.o

$(OBJDIR_DEBUG)\\Engine\\src\\GameEngine.o: Engine\\src\\GameEngine.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\GameEngine.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\GameEngine.o

$(OBJDIR_DEBUG)\\Engine\\src\\GameState.o: Engine\\src\\GameState.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\GameState.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\GameState.o

$(OBJDIR_DEBUG)\\Engine\\src\\GameStateFactory.o: Engine\\src\\GameStateFactory.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\GameStateFactory.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\GameStateFactory.o

$(OBJDIR_DEBUG)\\Engine\\src\\Game\\Ball.o: Engine\\src\\Game\\Ball.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Game\\Ball.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Ball.o

$(OBJDIR_DEBUG)\\Engine\\src\\Game\\Crate.o: Engine\\src\\Game\\Crate.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Game\\Crate.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Crate.o

$(OBJDIR_DEBUG)\\Engine\\src\\Game\\Paddle.o: Engine\\src\\Game\\Paddle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Game\\Paddle.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Paddle.o

# $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Tile.o: Engine\\src\\Game\\Tile.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Game\\Tile.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\Tile.o

# $(OBJDIR_DEBUG)\\Engine\\src\\Game\\TileLayer.o: Engine\\src\\Game\\TileLayer.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Game\\TileLayer.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\TileLayer.o

# $(OBJDIR_DEBUG)\\Engine\\src\\Game\\TileMap.o: Engine\\src\\Game\\TileMap.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Game\\TileMap.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Game\\TileMap.o

$(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\Drawable.o: Engine\\src\\Rendering\\Drawable.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Engine\\src\\Rendering\\Drawable.cpp -o $(OBJDIR_DEBUG)\\Engine\\src\\Rendering\\Drawable.o

clean_debug: 
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)\\Engine\\src\\Rendering
	cmd /c rd $(OBJDIR_DEBUG)\\Engine\\src\\States
	cmd /c rd $(OBJDIR_DEBUG)\\Engine\\src\\Util
	cmd /c rd $(OBJDIR_DEBUG)\\Engine\\src\\Util\\Util
	cmd /c rd $(OBJDIR_DEBUG)\\Engine\\src
	cmd /c rd $(OBJDIR_DEBUG)\\Engine\\src\\Exception
	cmd /c rd $(OBJDIR_DEBUG)\\Engine\\src\\Game

before_release: 
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE)\\Engine\\src\\Rendering md $(OBJDIR_RELEASE)\\Engine\\src\\Rendering
	cmd /c if not exist $(OBJDIR_RELEASE)\\Engine\\src\\States md $(OBJDIR_RELEASE)\\Engine\\src\\States
	cmd /c if not exist $(OBJDIR_RELEASE)\\Engine\\src\\Util md $(OBJDIR_RELEASE)\\Engine\\src\\Util
	cmd /c if not exist $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Util md $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Util
	cmd /c if not exist $(OBJDIR_RELEASE)\\Engine\\src md $(OBJDIR_RELEASE)\\Engine\\src
	cmd /c if not exist $(OBJDIR_RELEASE)\\Engine\\src\\Exception md $(OBJDIR_RELEASE)\\Engine\\src\\Exception
	cmd /c if not exist $(OBJDIR_RELEASE)\\Engine\\src\\Game md $(OBJDIR_RELEASE)\\Engine\\src\\Game

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\GameSprite.o: Engine\\src\\Rendering\\GameSprite.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Rendering\\GameSprite.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\GameSprite.o

$(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\GameWindow.o: Engine\\src\\Rendering\\GameWindow.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Rendering\\GameWindow.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\GameWindow.o

$(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\RenderManager.o: Engine\\src\\Rendering\\RenderManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Rendering\\RenderManager.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\RenderManager.o

$(OBJDIR_RELEASE)\\Engine\\src\\States\\GameOverState.o: Engine\\src\\States\\GameOverState.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\States\\GameOverState.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\States\\GameOverState.o

$(OBJDIR_RELEASE)\\Engine\\src\\States\\MainMenuState.o: Engine\\src\\States\\MainMenuState.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\States\\MainMenuState.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\States\\MainMenuState.o

$(OBJDIR_RELEASE)\\Engine\\src\\States\\RandomRebound_GameState.o: Engine\\src\\States\\RandomRebound_GameState.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\States\\RandomRebound_GameState.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\States\\RandomRebound_GameState.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\AudioResourceManager.o: Engine\\src\\Util\\AudioResourceManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\AudioResourceManager.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\AudioResourceManager.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\MusicPlayer.o: Engine\\src\\Util\\MusicPlayer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\MusicPlayer.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\MusicPlayer.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\SoundPlayer.o: Engine\\src\\Util\\SoundPlayer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\SoundPlayer.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\SoundPlayer.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\Camera.o: Engine\\src\\Util\\Camera.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\Camera.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Camera.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\Composite.o: Engine\\src\\Util\\Composite.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\Composite.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Composite.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\Dimension.o: Engine\\src\\Util\\Dimension.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\Dimension.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Dimension.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\ImageResourceManager.o: Engine\\src\\Util\\ImageResourceManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\ImageResourceManager.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\ImageResourceManager.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\Point.o: Engine\\src\\Util\\Point.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\Point.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Point.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\Rect.o: Engine\\src\\Util\\Rect.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\Rect.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Rect.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\RotatedRectangle.o: Engine\\src\\Util\\RotatedRectangle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\RotatedRectangle.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\RotatedRectangle.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\Util\\Focusable.o: Engine\\src\\Util\\Util\\Focusable.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\Util\\Focusable.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Util\\Focusable.o

$(OBJDIR_RELEASE)\\Engine\\src\\Util\\Vector2f.o: Engine\\src\\Util\\Vector2f.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Util\\Vector2f.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Vector2f.o

$(OBJDIR_RELEASE)\\Engine\\src\\main.o: Engine\\src\\main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\main.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\main.o

$(OBJDIR_RELEASE)\\Engine\\src\\Exception\\FileNotFoundException.o: Engine\\src\\Exception\\FileNotFoundException.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Exception\\FileNotFoundException.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Exception\\FileNotFoundException.o

$(OBJDIR_RELEASE)\\Engine\\src\\GameEngine.o: Engine\\src\\GameEngine.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\GameEngine.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\GameEngine.o

$(OBJDIR_RELEASE)\\Engine\\src\\GameState.o: Engine\\src\\GameState.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\GameState.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\GameState.o

$(OBJDIR_RELEASE)\\Engine\\src\\GameStateFactory.o: Engine\\src\\GameStateFactory.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\GameStateFactory.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\GameStateFactory.o

$(OBJDIR_RELEASE)\\Engine\\src\\Game\\Ball.o: Engine\\src\\Game\\Ball.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Game\\Ball.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Ball.o

$(OBJDIR_RELEASE)\\Engine\\src\\Game\\Crate.o: Engine\\src\\Game\\Crate.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Game\\Crate.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Crate.o

$(OBJDIR_RELEASE)\\Engine\\src\\Game\\Paddle.o: Engine\\src\\Game\\Paddle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Game\\Paddle.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Paddle.o

# $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Tile.o: Engine\\src\\Game\\Tile.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Game\\Tile.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\Tile.o

# $(OBJDIR_RELEASE)\\Engine\\src\\Game\\TileLayer.o: Engine\\src\\Game\\TileLayer.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Game\\TileLayer.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\TileLayer.o

# $(OBJDIR_RELEASE)\\Engine\\src\\Game\\TileMap.o: Engine\\src\\Game\\TileMap.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Game\\TileMap.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Game\\TileMap.o

$(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\Drawable.o: Engine\\src\\Rendering\\Drawable.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Engine\\src\\Rendering\\Drawable.cpp -o $(OBJDIR_RELEASE)\\Engine\\src\\Rendering\\Drawable.o

clean_release: 
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)\\Engine\\src\\Rendering
	cmd /c rd $(OBJDIR_RELEASE)\\Engine\\src\\States
	cmd /c rd $(OBJDIR_RELEASE)\\Engine\\src\\Util
	cmd /c rd $(OBJDIR_RELEASE)\\Engine\\src\\Util\\Util
	cmd /c rd $(OBJDIR_RELEASE)\\Engine\\src
	cmd /c rd $(OBJDIR_RELEASE)\\Engine\\src\\Exception
	cmd /c rd $(OBJDIR_RELEASE)\\Engine\\src\\Game

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

