#pragma once
#include <iostream>
#include <string>
using namespace std;


struct Student
{
    string name;
    int age;
    string gender;
    string major;
    float chineseScore;
    float mathScore;
    float englishScore;
};


float calculateTotalScore(const Student& student);
float calculateAverageScore(const Student& student);
void inputStudent(Student& student);
void outputStudent(const Student& student);
void displayStudentsByGender(const Student students[], int numStudents, const string& gender);
void displayStudentsByMajor(const Student students[], int numStudents, const string& major);
void bubbleSortBySubject(Student students[], int numStudents, const string& subject);
void bubbleSortByTotalScore(Student students[], int numStudents);