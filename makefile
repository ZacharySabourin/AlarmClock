CXX = g++
CXXFLAGS = -Wall -g
HDIR = ./headers/

objects = Main.o AlarmClock.o Song.o MusicPlayer.o

main : $(objects)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o main

main.o : $(HDIR)AlarmClock.hpp $(HDIR)MusicPlayer.hpp
MusicPlayer.o : $(HDIR)Song.hpp

.PHONY : clean
clean :
	rm main $(objects)