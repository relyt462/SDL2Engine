#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.

#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Win32SDL2Window.cpp SDL2Renderer.cpp Texture.cpp Sprite.cpp GameObjectManager.cpp GameWindow.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -ID:\GameDevStuff\MinigwDevLib\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LD:\GameDevStuff\Minigwdevlib\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
# -std=c++11 sets the compiler to user the c++ 11 standard
COMPILER_FLAGS = -w -Wl,-subsystem,windows -std=c++11

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = test

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
