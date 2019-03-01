LIBS = -lmingw32 -lSDL2main -lSDL2

MISC = -w

INC_PATH = -IC:\mingw_dev_lib\include

LIB_PATH = -LC:\mingw_dev_lib\lib

ALL_FILES = src\Engine-Tester.cpp src\TTTlib\TTTprogram.cpp

all:
	g++  $(ALL_FILES) $(INC_PATH) $(LIB_PATH) $(LIBS) $(MISC) -o debug/ttt.exe
	

