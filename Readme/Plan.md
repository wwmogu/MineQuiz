# The structure of this plan file is copu from the design file (but this one is more detiled)
## File distribution plan
- practical-09-11
    - Readme (the design, plan and test log file)
        - mkdown_picture (the picture for all of the md file)
    - src (final version of project will store into it)
    - test (the Test file and each increment will do in this oen)
    - txt (the Ascii text, Question.txt file will store in this one)
----
## Testing Plan
Since the user input is uncertain, my testing will be perform manually.
### Component test
for each Function in an class I will keep track of them then collect functions into its Class.
1. for using create a windows class, I create a functionTest.cpp and ncursesTest.cpp just try how the ncurses windows works.
2. LetterTest.cpp also not for any class, just for the title or some letters I want to use ncurse show on screen.
3. MainTest.cpp is my prototype for whole project, the first it will not include any class or function, only include the logic of my project.
4. re_questionTest.cpp this one is based on Iofile class, only test in ncurses form.
5. add_questionTest.cpp will test the add question function in subject class using iostream then chang it to ncurses form and test it again.

### Unit test
for each Class I will write a sigle Testfile corrdinate to each of them.
1. IofileTest.cpp: test the Iofile class
2. OopTest.cpp: Test Oop class
3. QuestionTest.cpp: Test Question Class
4. ReadQAfromfileTest.cpp: Test both Iofile class and the Question class, implement io questions to or from a file.
### System test
once a Unit test finish, I will collect them into final System test file and test whether it will works.
1. SystemTest.cpp is the real main test file for my whole prject.

## Schedule Plan
add code into my Makefile when the new Test file created.
> there are two Makefile, one in src directory for the final version, another one in test directory for all test version.
### Week 8
draw a bluepoint for the whole project, and delect some of features that is difficut to implement.
### Break Week 1
Create a project prototype to achieve the final look of the project.
### Break Week 2
implement the Iofile, Windows and Question class.
### Week 9
Finish one of the Subject which is Oop, and make the whole program excutable.
### Week 10
Finish LFS and ISE Subject, add all tested code into Main file also make it excutable.
### Week 11
Since the time is limted, in this week, I only double check if my main program works fine and if time is enough i will add some user prompt and color in my final version.