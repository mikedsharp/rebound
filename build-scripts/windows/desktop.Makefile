WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

# BE SURE TO UPDATE THIS TO A PATH WHERE YOU HAVE SDL INSTALLED
SDL_LOCATION = lib\\SDL2
SDL_MIXER_LOCATION = lib\\SDL2
SDL_IMAGE_LOCATION = lib\\SDL2
SDL_TTF_LOCATION = lib\\SDL2
MINGW_LIB_LOCATION = lib\\MinGW

INC = -I ${SDL_LOCATION}\\include\\SDL2 -I rebound-engine -I Game
ASSETSDIR=assets
RESINC = 
LIBDIR = -L ${SDL_LOCATION}\\lib -L ${SDL_IMAGE_LOCATION}\\lib -L ${SDL_MIXER_LOCATION}\\lib -L ${SDL_TTF_LOCATION}\\lib
LIB = ${SDL_LOCATION}\\lib
LDFLAGS = -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

CFLAGS = -static-libgcc -static-libstdc++ -g -w -Wl,-subsystem,windows
RESINC = $(RESINC)
RCFLAGS = $(RCFLAGS)
BINDIR = bin\\windows
LIB = 
OBJDIR = obj\\build
DEP = 
OUT = $(BINDIR)\\rebound.exe

OBJ = $(OBJDIR)\\rebound-engine\\src\\Rendering\\GameSprite.o \
      $(OBJDIR)\\rebound-engine\\src\\Rendering\\GameWindow.o \
	  $(OBJDIR)\\rebound-engine\\src\\Rendering\\RenderManager.o \
	  $(OBJDIR)\\Game\\src\\States\\GameOverState.o \
	  $(OBJDIR)\\Game\\src\\States\\MainMenuState.o \
	  $(OBJDIR)\\Game\\src\\States\\RandomRebound_GameState.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Font.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Text.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Timer.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\AudioResourceManager.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\MusicPlayer.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\SoundPlayer.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Camera.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Composite.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Dimension.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\ImageResourceManager.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Point.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Rect.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\RotatedRectangle.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Util\\Focusable.o \
	  $(OBJDIR)\\rebound-engine\\src\\Util\\Vector2f.o \
	  $(OBJDIR)\\rebound-engine\\src\\main.o \
	  $(OBJDIR)\\rebound-engine\\src\\Exception\\FileNotFoundException.o \
	  $(OBJDIR)\\rebound-engine\\src\\GameEngine.o \
	  $(OBJDIR)\\rebound-engine\\src\\GameState.o \
	  $(OBJDIR)\\Game\\src\\States\\GameStateFactory.o \
	  $(OBJDIR)\\Game\\src\\Game\\Ball.o \
	  $(OBJDIR)\\Game\\src\\Game\\Crate.o \
	  $(OBJDIR)\\Game\\src\\Game\\Paddle.o \
	  $(OBJDIR)\\rebound-engine\\src\\Rendering\\Drawable.o

all: build

clean: 	
	cmd /c if exist obj rd /s /q obj
	cmd /c if exist $(OUT) del /q $(OUT)

before_build: 
	cmd /c if not exist bin\\windows md bin\\windows
	cmd /c if not exist $(BINDIR)\\assets md $(BINDIR)\\assets
	cmd /c xcopy /s /e /h /y $(ASSETSDIR) $(BINDIR)\\assets
	cmd /c if not exist $(OBJDIR)\\rebound-engine\\src\\Rendering md $(OBJDIR)\\rebound-engine\\src\\Rendering
	cmd /c if not exist $(OBJDIR)\\rebound-engine\\src\\States md $(OBJDIR)\\rebound-engine\\src\\States
	cmd /c if not exist $(OBJDIR)\\rebound-engine\\src\\Util md $(OBJDIR)\\rebound-engine\\src\\Util
	cmd /c if not exist $(OBJDIR)\\rebound-engine\\src\\Util\\Util md $(OBJDIR)\\rebound-engine\\src\\Util\\Util
	cmd /c if not exist $(OBJDIR)\\rebound-engine\\src md $(OBJDIR)\\rebound-engine\\src
	cmd /c if not exist $(OBJDIR)\\rebound-engine\\src\\Exception md $(OBJDIR)\\rebound-engine\\src\\Exception
	cmd /c if not exist $(OBJDIR)\\Game md $(OBJDIR)\\Game
	cmd /c if not exist $(OBJDIR)\\Game\\src md $(OBJDIR)\\Game\\src
	cmd /c if not exist $(OBJDIR)\\Game\\src\\States md $(OBJDIR)\\Game\\src\\States
	cmd /c if not exist $(OBJDIR)\\Game\\src\\GameEntities md $(OBJDIR)\\Game\\src\\GameEntities

after_build: 
	cmd /c copy /y $(SDL_LOCATION)\\bin\\SDL2.dll $(BINDIR)\\SDL2.dll
	cmd /c copy /y $(SDL_IMAGE_LOCATION)\\bin\\SDL2_image.dll $(BINDIR)\\SDL2_image.dll
	cmd /c copy /y $(SDL_MIXER_LOCATION)\\bin\\SDL2_mixer.dll $(BINDIR)\\SDL2_mixer.dll
	cmd /c copy /y $(SDL_TTF_LOCATION)\\bin\\SDL2_ttf.dll $(BINDIR)\\SDL2_ttf.dll
	cmd /c copy /y $(MINGW_LIB_LOCATION)\\bin\\libwinpthread-1.dll $(BINDIR)\\libwinpthread-1.dll


build: before_build OUT after_build

OUT: before_build $(OBJ) $(DEP)
	$(LD) $(CFLAGS) $(LIBDIR) -o $(OUT) $(OBJ)  $(LDFLAGS) $(LIB)

$(OBJDIR)\\rebound-engine\\src\\Rendering\\GameSprite.o: rebound-engine\\src\\Rendering\\GameSprite.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Rendering\\GameSprite.cpp -o $(OBJDIR)\\rebound-engine\\src\\Rendering\\GameSprite.o

$(OBJDIR)\\rebound-engine\\src\\Rendering\\GameWindow.o: rebound-engine\\src\\Rendering\\GameWindow.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Rendering\\GameWindow.cpp -o $(OBJDIR)\\rebound-engine\\src\\Rendering\\GameWindow.o

$(OBJDIR)\\rebound-engine\\src\\Rendering\\RenderManager.o: rebound-engine\\src\\Rendering\\RenderManager.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Rendering\\RenderManager.cpp -o $(OBJDIR)\\rebound-engine\\src\\Rendering\\RenderManager.o

$(OBJDIR)\\Game\\src\\States\\GameOverState.o: Game\\src\\States\\GameOverState.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\States\\GameOverState.cpp -o $(OBJDIR)\\Game\\src\\States\\GameOverState.o

$(OBJDIR)\\Game\\src\\States\\MainMenuState.o: Game\\src\\States\\MainMenuState.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\States\\MainMenuState.cpp -o $(OBJDIR)\\Game\\src\\States\\MainMenuState.o

$(OBJDIR)\\Game\\src\\States\\RandomRebound_GameState.o: Game\\src\\States\\RandomRebound_GameState.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\States\\RandomRebound_GameState.cpp -o $(OBJDIR)\\Game\\src\\States\\RandomRebound_GameState.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Font.o: rebound-engine\\src\\Util\\Font.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Font.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Font.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Text.o: rebound-engine\\src\\Util\\Text.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Text.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Text.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Timer.o: rebound-engine\\src\\Util\\Timer.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Timer.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Timer.o

$(OBJDIR)\\rebound-engine\\src\\Util\\AudioResourceManager.o: rebound-engine\\src\\Util\\AudioResourceManager.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\AudioResourceManager.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\AudioResourceManager.o

$(OBJDIR)\\rebound-engine\\src\\Util\\MusicPlayer.o: rebound-engine\\src\\Util\\MusicPlayer.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\MusicPlayer.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\MusicPlayer.o

$(OBJDIR)\\rebound-engine\\src\\Util\\SoundPlayer.o: rebound-engine\\src\\Util\\SoundPlayer.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\SoundPlayer.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\SoundPlayer.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Camera.o: rebound-engine\\src\\Util\\Camera.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Camera.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Camera.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Composite.o: rebound-engine\\src\\Util\\Composite.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Composite.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Composite.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Dimension.o: rebound-engine\\src\\Util\\Dimension.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Dimension.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Dimension.o

$(OBJDIR)\\rebound-engine\\src\\Util\\ImageResourceManager.o: rebound-engine\\src\\Util\\ImageResourceManager.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\ImageResourceManager.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\ImageResourceManager.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Point.o: rebound-engine\\src\\Util\\Point.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Point.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Point.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Rect.o: rebound-engine\\src\\Util\\Rect.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Rect.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Rect.o

$(OBJDIR)\\rebound-engine\\src\\Util\\RotatedRectangle.o: rebound-engine\\src\\Util\\RotatedRectangle.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\RotatedRectangle.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\RotatedRectangle.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Util\\Focusable.o: rebound-engine\\src\\Util\\Util\\Focusable.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Util\\Focusable.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Util\\Focusable.o

$(OBJDIR)\\rebound-engine\\src\\Util\\Vector2f.o: rebound-engine\\src\\Util\\Vector2f.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Util\\Vector2f.cpp -o $(OBJDIR)\\rebound-engine\\src\\Util\\Vector2f.o

$(OBJDIR)\\Game\\src\\main.o: Game\\src\\main.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\main.cpp -o $(OBJDIR)\\Game\\src\\main.o

$(OBJDIR)\\rebound-engine\\src\\Exception\\FileNotFoundException.o: rebound-engine\\src\\Exception\\FileNotFoundException.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Exception\\FileNotFoundException.cpp -o $(OBJDIR)\\rebound-engine\\src\\Exception\\FileNotFoundException.o

$(OBJDIR)\\rebound-engine\\src\\GameEngine.o: rebound-engine\\src\\GameEngine.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\GameEngine.cpp -o $(OBJDIR)\\rebound-engine\\src\\GameEngine.o

$(OBJDIR)\\rebound-engine\\src\\GameState.o: rebound-engine\\src\\GameState.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\GameState.cpp -o $(OBJDIR)\\rebound-engine\\src\\GameState.o

$(OBJDIR)\\Game\\src\\States\\GameStateFactory.o: Game\\src\\States\\GameStateFactory.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\States\\GameStateFactory.cpp -o $(OBJDIR)\\Game\\src\\States\\GameStateFactory.o

$(OBJDIR)\\Game\\src\\Game\\Ball.o: Game\\src\\Game\\Ball.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\Game\\Ball.cpp -o $(OBJDIR)\\Game\\src\\Game\\Ball.o

$(OBJDIR)\\Game\\src\\Game\\Crate.o: Game\\src\\Game\\Crate.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\Game\\Crate.cpp -o $(OBJDIR)\\Game\\src\\Game\\Crate.o

$(OBJDIR)\\Game\\src\\Game\\Paddle.o: Game\\src\\Game\\Paddle.cpp
	$(CXX) $(CFLAGS) $(INC) -c Game\\src\\Game\\Paddle.cpp -o $(OBJDIR)\\Game\\src\\Game\\Paddle.o

$(OBJDIR)\\rebound-engine\\src\\Rendering\\Drawable.o: rebound-engine\\src\\Rendering\\Drawable.cpp
	$(CXX) $(CFLAGS) $(INC) -c rebound-engine\\src\\Rendering\\Drawable.cpp -o $(OBJDIR)\\rebound-engine\\src\\Rendering\\Drawable.o

clean_build: clean build

