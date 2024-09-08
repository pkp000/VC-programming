#pragma once
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


class Person
{
    string name;
    string sex;
    int age;

public:
    Person(string, string, int);
    void display();
    string getName0();
    string getGender0();
    int getAge0();
};


class Registrant
{
    int registeredNumber;

public:
    Registrant(int num);
    int getRegisteredNumber();
};


// Multiple inheritance is used
class Teacher : public Person, public Registrant
{
    string department;
    string title;

public:
    Teacher(string, string, int, int, string, string);
    void display();
    string getName();
    string getGender();
    int getAge();
};


// Multiple inheritance is used
class Student : public Person, public Registrant
{
    string className;
    int score;

public:
    Student(string, string, int, int, string, int);
    void display();
    string getName();
    string getGender();
    int getAge();
};


void  informationDisplay();
void welcome();
void goodbye();