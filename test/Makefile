#                                                                                                                
#,--.   ,--.        ,--.           ,---.,--.,--.            ,---.                    ,--.                 ,--.   
#|   `.'   | ,--,--.|  |,-. ,---. /  .-'`--'|  | ,---.     /  .-' ,---. ,--.--.    ,-'  '-. ,---.  ,---.,-'  '-. 
#|  |'.'|  |' ,-.  ||     /| .-. :|  `-,,--.|  || .-. :    |  `-,| .-. ||  .--'    '-.  .-'| .-. :(  .-''-.  .-' 
#|  |   |  |\ '-'  ||  \  \\   --.|  .-'|  ||  |\   --.    |  .-'' '-' '|  |         |  |  \   --..-'  `) |  |   
#`--'   `--' `--`--'`--'`--'`----'`--'  `--'`--' `----'    `--'   `---' `--'         `--'   `----'`----'  `--'   
#

# test the entire project
SystemTest: SystemTest.cpp Windows.o Oop.o Subject.o Iofile.o Question.o Ise.o Lfs.o
	g++ -std=c++11 SystemTest.cpp Windows.o Oop.o Subject.o Iofile.o Question.o Ise.o Lfs.o -lncurses 

# the first time I make a prototype of my project
MainTest:	MainTest.cpp functionTest.cpp Iofile.o Oop.o Subject.o Question.o Windows.o
	g++ -std=c++11 MainTest.cpp functionTest.cpp Iofile.o Oop.o Subject.o Question.o Windows.o -lncurses

# test the Iofile class
IofileTest: IofileTest.cpp Iofile.o
	g++ -std=c++11 IofileTest.cpp Iofile.o
	./a.out

# test the Question class
QuestionTest: QuestionTest.cpp Question.o
	g++ -std=c++11 QuestionTest.cpp Question.o
	./a.out

# test the Question and the Iofile class
ReadQAfromfileTest: ReadQAfromfileTest.cpp Iofile.o Question.o
	g++ -std=c++11 ReadQAfromfileTest.cpp Iofile.o Question.o
	./a.out > ReadQAfromfileTestOutput1.txt
	diff ReadQAfromfileTestInput1.txt ReadQAfromfileTestOutput1.txt

# test the single function(add_question()) in Subject class
add_questionTest: add_questionTest.cpp Oop.o Subject.o Windows.o Iofile.o Question.o
	g++ -std=c++11 add_questionTest.cpp Oop.o Subject.o Windows.o Iofile.o Question.o -lncurses

# test the single function(rm_question()) in Subject class
rm_questionTest: rm_questionTest.cpp Oop.o Subject.o Windows.o Iofile.o Question.o
	g++ -std=c++11 rm_questionTest.cpp Oop.o Subject.o Windows.o Iofile.o Question.o -lncurses

# test the sub-class(Oop) of the subject class
OopTest: Subject.o Oop.o Question.o OopTest.cpp Iofile.o Windows.o
	g++ -std=c++11 Subject.o Oop.o Question.o Iofile.o Windows.o OopTest.cpp -lncurses

# test the sub-class(ISE) of the subject class
IseTest: IseTest.cpp Subject.o Ise.o Question.o Iofile.o Windows.o
	g++ -std=c++11 IseTest.cpp Subject.o Ise.o Question.o Iofile.o Windows.o -lncurses

# test the sub-class(LFS) of the subject class
LfsTest: LfsTest.cpp Subject.o Lfs.o Question.o Iofile.o Windows.o
	g++ -std=c++11 LfsTest.cpp Subject.o Lfs.o Question.o Iofile.o Windows.o -lncurses

# link windows.h and windows.cpp
Windows.o:	../src/Windows.cpp ../src/Windows.h
	g++ -c -std=c++11 ../src/Windows.cpp

# link Oop.h and Oop.cpp
Oop.o:	../src/Oop.h ../src/Oop.cpp
	g++ -c -std=c++11 ../src/Oop.cpp

# link Iofile.h and Iofile.cpp
Iofile.o:	../src/Iofile.cpp ../src/Iofile.h
	g++ -c -std=c++11 ../src/Iofile.cpp

# link Subject.h and Subject.cpp
Subject.o: ../src/Subject.h ../src/Subject.cpp
	g++ -c -std=c++11 ../src/Subject.cpp

# link Question.h and Question.cpp
Question.o: ../src/Question.h ../src/Question.cpp
	g++ -c -std=c++11 ../src/Question.cpp

# link Ise.h and Ise.cpp
Ise.o: ../src/Ise.h ../src/Ise.cpp
	g++ -c -std=c++11 ../src/Ise.cpp

# link Lfs.h and Lfs.cpp
Lfs.o:	../src/Lfs.h ../src/Lfs.cpp
	g++ -c -std=c++11 ../src/Lfs.cpp

# delete object file and the excutable file
clean:
	rm *.o *.out