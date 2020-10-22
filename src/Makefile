#                                                                                                                
#,--.   ,--.        ,--.           ,---.,--.,--.            ,---.                    ,--.                 ,--.   
#|   `.'   | ,--,--.|  |,-. ,---. /  .-'`--'|  | ,---.     /  .-' ,---. ,--.--.    ,-'  '-. ,---.  ,---.,-'  '-. 
#|  |'.'|  |' ,-.  ||     /| .-. :|  `-,,--.|  || .-. :    |  `-,| .-. ||  .--'    '-.  .-'| .-. :(  .-''-.  .-' 
#|  |   |  |\ '-'  ||  \  \\   --.|  .-'|  ||  |\   --.    |  .-'' '-' '|  |         |  |  \   --..-'  `) |  |   
#`--'   `--' `--`--'`--'`--'`----'`--'  `--'`--' `----'    `--'   `---' `--'         `--'   `----'`----'  `--'   
#

all: MineQuizMain.cpp editSubject.cpp Windows.o Oop.o Subject.o Iofile.o Question.o Ise.o Lfs.o
	g++ -o Main -std=c++11 MineQuizMain.cpp editSubject.cpp Windows.o Oop.o Subject.o Iofile.o Question.o Ise.o Lfs.o -lncurses 

# move the excutable file to root
run: all
	./Main

# link windows.h and windows.cpp
Windows.o:	Windows.cpp Windows.h
	g++ -c -std=c++11 Windows.cpp

# link Oop.h and Oop.cpp
Oop.o:	Oop.h Oop.cpp
	g++ -c -std=c++11 Oop.cpp

# link Iofile.h and Iofile.cpp
Iofile.o:	Iofile.cpp Iofile.h
	g++ -c -std=c++11 Iofile.cpp

# link Subject.h and Subject.cpp
Subject.o: Subject.h Subject.cpp
	g++ -c -std=c++11 Subject.cpp

# link Question.h and Question.cpp
Question.o: Question.h Question.cpp
	g++ -c -std=c++11 Question.cpp

# link Ise.h and Ise.cpp
Ise.o:	Ise.h Ise.cpp
	g++ -c -std=c++11 Ise.cpp

# link Lfs.h and Lfs.cpp
Lfs.o:	Lfs.h Lfs.cpp
	g++ -c -std=c++11 Lfs.cpp

# delete object file and the excutable file
clean: all
	rm *.o Main