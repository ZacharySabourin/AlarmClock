CXX = g++
CXXFLAGS = -Wall -g

main : Main.o AlarmClock.o Song.o MusicPlayer.o
	$(CXX) $(CXXFLAGS) -o Main.o AlarmClock.o Song.o MusicPlayer.o

main.o : Main.cpp 

edit : $(objects)
	g++ -c -o edit $(objects)

Main.o : /headers/AlarmClock.h /headers/MusicPlayer.h
MusicPlayer.o : /headers/Song.h

.PHONY : clean
clean :
	rm edit $(objects)