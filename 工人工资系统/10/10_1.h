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
    string getName0();
    string getGender0();
    int getAge0();

    // Notice! This is a pure virtual function
    virtual double salary() = 0;
};


class Staff : public Person
{
    int id;
    double fixedSalary;

public:
    string getName();
    string getGender();
    int getAge();
    int getID();
    double getFixedSalary();
    Staff(string, string, int, int, double);

    // Pure virtual function
    double salary();
};


class Director : public Staff
{
    string job;
public:
    Director(string, int, string, int, double, string);
    void displayD();
    
    // Pure virtual function
    double salary();
};


class Worker : public Staff
{
    string job;
    int overtime;

public:
    Worker(string, int, string, int, int, double, string);
    void displayW();

    // Pure virtual function
    double salary();
};



void makeHeader();
void calculateDisplay();
void welcome();
void goodbye();
