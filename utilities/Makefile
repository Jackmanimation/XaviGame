#OBJS specifies which files to compile as part of the project
OBJS = ../../game/include/general.cpp ../../game/include/SDLEngine.cpp ../../game/include/gamefunction.cpp utility.cpp
FILE_OBJS = files.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=gnu++0x -I/usr/local/include

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -L/usr/local/lib  -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
FILE_LINKER_FLAG =

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = utility
FILE_OBJ_NAME = files

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

file : $(FILE_OBJS)
	$(CC) $(FILE_OBJS) $(COMPILER_FLAGS) $(FILE_LINKER_FLAGS) -o $(FILE_OBJ_NAME)

