CXX = g++
CXXFLAGS = -Wall -g
HDIR = ./headers

OBJECTS = Main.o AlarmClock.o Song.o MusicPlayer.o

clock : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o clock

Main.o : $(HDIR)/AlarmClock.h $(HDIR)/MusicPlayer.h
MusicPlayer.o : $(HDIR)/Song.h

.PHONY : clean
clean :
	rm clock $(objects)