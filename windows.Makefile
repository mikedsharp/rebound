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
RESINC = 
LIBDIR = -L${SDL_LOCATION}\\lib -L${SDL_IMAGE_LOCATION}\\lib -L${SDL_MIXER_LOCATION}\\lib
LIB = ${SDL_LOCATION}\\lib
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image

CFLAGS = -g -w -Wl,-subsystem,windows
RESINC = $(RESINC)
RCFLAGS = $(RCFLAGS)
LIB = 
OBJDIR = obj\\build
DEP = 
OUT = bin\\rebound.exe

OBJ = $(OBJDIR)\\Engine\\src\\Rendering\\GameSprite.o $(OBJDIR)\\Engine\\src\\Rendering\\GameWindow.o $(OBJDIR)\\Engine\\src\\Rendering\\RenderManager.o $(OBJDIR)\\Engine\\src\\States\\GameOverState.o $(OBJDIR)\\Engine\\src\\States\\MainMenuState.o $(OBJDIR)\\Engine\\src\\States\\RandomRebound_GameState.o $(OBJDIR)\\Engine\\src\\Util\\AudioResourceManager.o $(OBJDIR)\\Engine\\src\\Util\\MusicPlayer.o $(OBJDIR)\\Engine\\src\\Util\\SoundPlayer.o $(OBJDIR)\\Engine\\src\\Util\\Camera.o $(OBJDIR)\\Engine\\src\\Util\\Composite.o $(OBJDIR)\\Engine\\src\\Util\\Dimension.o $(OBJDIR)\\Engine\\src\\Util\\ImageResourceManager.o $(OBJDIR)\\Engine\\src\\Util\\Point.o $(OBJDIR)\\Engine\\src\\Util\\Rect.o $(OBJDIR)\\Engine\\src\\Util\\RotatedRectangle.o $(OBJDIR)\\Engine\\src\\Util\\Util\\Focusable.o $(OBJDIR)\\Engine\\src\\Util\\Vector2f.o $(OBJDIR)\\Engine\\src\\main.o $(OBJDIR)\\Engine\\src\\Exception\\FileNotFoundException.o $(OBJDIR)\\Engine\\src\\GameEngine.o $(OBJDIR)\\Engine\\src\\GameState.o $(OBJDIR)\\Engine\\src\\GameStateFactory.o $(OBJDIR)\\Engine\\src\\Game\\Ball.o $(OBJDIR)\\Engine\\src\\Game\\Crate.o $(OBJDIR)\\Engine\\src\\Game\\Paddle.o $(OBJDIR)\\Engine\\src\\Rendering\\Drawable.o

all: build

clean: clean_build

before_build: 
	cmd /c if not exist bin md bin
	cmd /c if not exist $(OBJDIR)\\Engine\\src\\Rendering md $(OBJDIR)\\Engine\\src\\Rendering
	cmd /c if not exist $(OBJDIR)\\Engine\\src\\States md $(OBJDIR)\\Engine\\src\\States
	cmd /c if not exist $(OBJDIR)\\Engine\\src\\Util md $(OBJDIR)\\Engine\\src\\Util
	cmd /c if not exist $(OBJDIR)\\Engine\\src\\Util\\Util md $(OBJDIR)\\Engine\\src\\Util\\Util
	cmd /c if not exist $(OBJDIR)\\Engine\\src md $(OBJDIR)\\Engine\\src
	cmd /c if not exist $(OBJDIR)\\Engine\\src\\Exception md $(OBJDIR)\\Engine\\src\\Exception
	cmd /c if not exist $(OBJDIR)\\Engine\\src\\Game md $(OBJDIR)\\Engine\\src\\Game

after_build: 

build: before_build OUT after_build

OUT: before_build $(OBJ) $(DEP)
	$(LD) $(LIBDIR) -o $(OUT) $(OBJ)  $(LDFLAGS) $(LIB)

$(OBJDIR)\\Engine\\src\\Rendering\\GameSprite.o: Engine\\src\\Rendering\\GameSprite.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Rendering\\GameSprite.cpp -o $(OBJDIR)\\Engine\\src\\Rendering\\GameSprite.o

$(OBJDIR)\\Engine\\src\\Rendering\\GameWindow.o: Engine\\src\\Rendering\\GameWindow.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Rendering\\GameWindow.cpp -o $(OBJDIR)\\Engine\\src\\Rendering\\GameWindow.o

$(OBJDIR)\\Engine\\src\\Rendering\\RenderManager.o: Engine\\src\\Rendering\\RenderManager.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Rendering\\RenderManager.cpp -o $(OBJDIR)\\Engine\\src\\Rendering\\RenderManager.o

$(OBJDIR)\\Engine\\src\\States\\GameOverState.o: Engine\\src\\States\\GameOverState.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\States\\GameOverState.cpp -o $(OBJDIR)\\Engine\\src\\States\\GameOverState.o

$(OBJDIR)\\Engine\\src\\States\\MainMenuState.o: Engine\\src\\States\\MainMenuState.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\States\\MainMenuState.cpp -o $(OBJDIR)\\Engine\\src\\States\\MainMenuState.o

$(OBJDIR)\\Engine\\src\\States\\RandomRebound_GameState.o: Engine\\src\\States\\RandomRebound_GameState.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\States\\RandomRebound_GameState.cpp -o $(OBJDIR)\\Engine\\src\\States\\RandomRebound_GameState.o

$(OBJDIR)\\Engine\\src\\Util\\AudioResourceManager.o: Engine\\src\\Util\\AudioResourceManager.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\AudioResourceManager.cpp -o $(OBJDIR)\\Engine\\src\\Util\\AudioResourceManager.o

$(OBJDIR)\\Engine\\src\\Util\\MusicPlayer.o: Engine\\src\\Util\\MusicPlayer.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\MusicPlayer.cpp -o $(OBJDIR)\\Engine\\src\\Util\\MusicPlayer.o

$(OBJDIR)\\Engine\\src\\Util\\SoundPlayer.o: Engine\\src\\Util\\SoundPlayer.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\SoundPlayer.cpp -o $(OBJDIR)\\Engine\\src\\Util\\SoundPlayer.o

$(OBJDIR)\\Engine\\src\\Util\\Camera.o: Engine\\src\\Util\\Camera.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\Camera.cpp -o $(OBJDIR)\\Engine\\src\\Util\\Camera.o

$(OBJDIR)\\Engine\\src\\Util\\Composite.o: Engine\\src\\Util\\Composite.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\Composite.cpp -o $(OBJDIR)\\Engine\\src\\Util\\Composite.o

$(OBJDIR)\\Engine\\src\\Util\\Dimension.o: Engine\\src\\Util\\Dimension.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\Dimension.cpp -o $(OBJDIR)\\Engine\\src\\Util\\Dimension.o

$(OBJDIR)\\Engine\\src\\Util\\ImageResourceManager.o: Engine\\src\\Util\\ImageResourceManager.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\ImageResourceManager.cpp -o $(OBJDIR)\\Engine\\src\\Util\\ImageResourceManager.o

$(OBJDIR)\\Engine\\src\\Util\\Point.o: Engine\\src\\Util\\Point.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\Point.cpp -o $(OBJDIR)\\Engine\\src\\Util\\Point.o

$(OBJDIR)\\Engine\\src\\Util\\Rect.o: Engine\\src\\Util\\Rect.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\Rect.cpp -o $(OBJDIR)\\Engine\\src\\Util\\Rect.o

$(OBJDIR)\\Engine\\src\\Util\\RotatedRectangle.o: Engine\\src\\Util\\RotatedRectangle.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\RotatedRectangle.cpp -o $(OBJDIR)\\Engine\\src\\Util\\RotatedRectangle.o

$(OBJDIR)\\Engine\\src\\Util\\Util\\Focusable.o: Engine\\src\\Util\\Util\\Focusable.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\Util\\Focusable.cpp -o $(OBJDIR)\\Engine\\src\\Util\\Util\\Focusable.o

$(OBJDIR)\\Engine\\src\\Util\\Vector2f.o: Engine\\src\\Util\\Vector2f.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Util\\Vector2f.cpp -o $(OBJDIR)\\Engine\\src\\Util\\Vector2f.o

$(OBJDIR)\\Engine\\src\\main.o: Engine\\src\\main.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\main.cpp -o $(OBJDIR)\\Engine\\src\\main.o

$(OBJDIR)\\Engine\\src\\Exception\\FileNotFoundException.o: Engine\\src\\Exception\\FileNotFoundException.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Exception\\FileNotFoundException.cpp -o $(OBJDIR)\\Engine\\src\\Exception\\FileNotFoundException.o

$(OBJDIR)\\Engine\\src\\GameEngine.o: Engine\\src\\GameEngine.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\GameEngine.cpp -o $(OBJDIR)\\Engine\\src\\GameEngine.o

$(OBJDIR)\\Engine\\src\\GameState.o: Engine\\src\\GameState.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\GameState.cpp -o $(OBJDIR)\\Engine\\src\\GameState.o

$(OBJDIR)\\Engine\\src\\GameStateFactory.o: Engine\\src\\GameStateFactory.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\GameStateFactory.cpp -o $(OBJDIR)\\Engine\\src\\GameStateFactory.o

$(OBJDIR)\\Engine\\src\\Game\\Ball.o: Engine\\src\\Game\\Ball.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Game\\Ball.cpp -o $(OBJDIR)\\Engine\\src\\Game\\Ball.o

$(OBJDIR)\\Engine\\src\\Game\\Crate.o: Engine\\src\\Game\\Crate.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Game\\Crate.cpp -o $(OBJDIR)\\Engine\\src\\Game\\Crate.o

$(OBJDIR)\\Engine\\src\\Game\\Paddle.o: Engine\\src\\Game\\Paddle.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Game\\Paddle.cpp -o $(OBJDIR)\\Engine\\src\\Game\\Paddle.o

$(OBJDIR)\\Engine\\src\\Rendering\\Drawable.o: Engine\\src\\Rendering\\Drawable.cpp
	$(CXX) $(CFLAGS) $(INC) -c Engine\\src\\Rendering\\Drawable.cpp -o $(OBJDIR)\\Engine\\src\\Rendering\\Drawable.o

clean_build: 
	cmd /c del /f $(OBJ) $(OUT)
	cmd /c rd bin
	cmd /c rd $(OBJDIR)\\Engine\\src\\Rendering
	cmd /c rd $(OBJDIR)\\Engine\\src\\States
	cmd /c rd $(OBJDIR)\\Engine\\src\\Util
	cmd /c rd $(OBJDIR)\\Engine\\src\\Util\\Util
	cmd /c rd $(OBJDIR)\\Engine\\src
	cmd /c rd $(OBJDIR)\\Engine\\src\\Exception
	cmd /c rd $(OBJDIR)\\Engine\\src\\Game
