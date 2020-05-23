CXX = g++
CXXFLAGS = -Wall -g
HDIR = ./headers
SRC = ./src

OBJECTS = $(SRC)/Main.o $(SRC)/AlarmClock.o $(SRC)/Song.o $(SRC)/MusicPlayer.o

clock : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o clock

Main.o : $(HDIR)/AlarmClock.h $(HDIR)/MusicPlayer.h
MusicPlayer.o : $(HDIR)/MusicPlayer.h
AlarmClock.o : $(HDIR)/AlarmClock.h
Song.o : $(HDIR)/Song.h

.PHONY : clean
clean :
	rm clock $(OBJECTS)