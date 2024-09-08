#pragma once
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Student
{
    string name;
    short age;
    char sex;
    float englishScore;
    float mathScore;
    float programScore;
    float totalScore;

public:    
    string getName();
    short getAge();
    char getSex();
    float getEnglishScore();
    float getMathScore();
    float getProgramScore();
    float getTotalScore();


    void inputStudentInformation();
    void outputStudentInformation();
};


// Easy to display and make a header
bool hasHeader;


void startStudentInformationEntryProcess();
void continueAddingStudents();
void welcome();


/*
Sample input:

Milly
18
F
98.9
99.5
96.7
Suzaku
17
M
55.6
80.1
39.8
Shirley
17
F
78.9
95.2
89.3
Kallen
17
F
91.2
76.2
85.5
Lelouch
17
M
100
100
100
Nina
17
F
90.2
100
88.6
Rivalz
17
M
95.5
70.5
86.3
@


*/