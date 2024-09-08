#include"student_information.h"



int main() 
{
    int numStudents;
    char showCategoryOption;
    char sortOption;
    string subject;
    string gender;
    string major;
    string temp;
    const int MAX_NUM = 100;
    Student students[MAX_NUM];


    cout << "Please enter the number of students:";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) 
    {
        cout << "Please enter the " << i + 1 << " student information:" << endl;
        inputStudent(students[i]);
        cout << endl;
    }

    cout << "Display all current student information:" << endl;
    for (int i = 0; i < numStudents; ++i) 
    {
        outputStudent(students[i]);
        cout << endl;
    }


    cout << "\n\n*********< View students by category >*********" << endl;
    cout << "\n1.View by gender.\n2.View by major." << endl;
    cout << "Please enter sorting options (1/2):";
    cin >> showCategoryOption;
    switch (showCategoryOption)
    {
        case '1':
            
            cout << "Please enter gender(string: Male/Female):";
            cin >> gender;
            displayStudentsByGender(students, numStudents, gender);

        case '2':
            cout << "Please enter your major (string: IME/BME) :";
            cin >> major;
            displayStudentsByMajor(students, numStudents, major); 
    }
 


    cout << "\n\nEnter any key to calculate the student's total and average scores for each subject:" << endl;
    cin >> temp;
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tstudent's name:" << students[i].name << endl;
        cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tChinese score:" << students[i].chineseScore << endl;
        cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tMath score   :" << students[i].mathScore << endl;
        cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tEnglish score:" << students[i].englishScore << endl;
        cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tTotal score  :" << calculateTotalScore(students[i]) << endl;
        cout << "\t\t\t\t\t\t\t\t\t|\n\t|\taverage score:" << calculateAverageScore(students[i]) << endl<< endl;
        cout << "\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
    }


    cout << "\n\n*********< Sort the students >*********" << endl;
    cout << "\n1.Sorting by single subject score.\n2.Sorting by total score." << endl;
    cout << "Please enter sorting options (1/2):";
    cin >> sortOption;
    switch (sortOption)
    {
        case '1':
            cout << "Please enter the subject (Chinese/Math/English) :";
            cin >> subject;
            bubbleSortBySubject(students, numStudents, subject);

        case '2':
            bubbleSortByTotalScore(students, numStudents);
    }


    cout << "The sorted student information is as follows:" << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        outputStudent(students[i]);
        cout << endl;
    }

    cout << "\n\nEnter any key to finish" << endl;
    cin >> temp;

    return 0;
}

void inputStudent(Student& student) 
{
    cout << "\t------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t|\n\t|\tPlease enter the student name(string):";
    cin >> student.name;
    cout << "\t\t\t\t\t\t\t\t\t\t|\n\t|\tPlease enter the age of the student(int):";
    cin >> student.age;
    cout << "\t\t\t\t\t\t\t\t\t\t|\n\t|\tPlease enter student's gender(string: Male/Female):";
    cin >> student.gender;
    cout << "\t\t\t\t\t\t\t\t\t\t|\n\t|\tPlease enter the student's major£¨string: IME/BME£©:";
    cin >> student.major;
    cout << "\t\t\t\t\t\t\t\t\t\t|\n\t|\tPlease enter the student's Chinese scores(float):";
    cin >> student.chineseScore;
    cout << "\t\t\t\t\t\t\t\t\t\t|\n\t|\tPlease enter the student's Math scores(float):";
    cin >> student.mathScore;
    cout << "\t\t\t\t\t\t\t\t\t\t|\n\t|\tPlease enter the student's English scores(float):";
    cin >> student.englishScore;
    cout << "\t-------------------------------------------------------------------------\n" << endl;
}

void outputStudent(const Student& student)
{
    cout << "\t*****************************************************************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tName         :\t" << student.name << endl;
    cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tAge          :\t" << student.age << endl;
    cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tGender       :\t" << student.gender << endl;
    cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tMajor        :\t" << student.major << endl;
    cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tChinese score:\t" << student.chineseScore << endl;
    cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tMath score   :\t" << student.mathScore << endl;
    cout << "\t\t\t\t\t\t\t\t\t|\n\t|\tEnglish score:\t" << student.englishScore << endl;
    cout << "\t*****************************************************************\n" << endl;
}

float calculateTotalScore(const Student& student) 
{
    return student.chineseScore + student.mathScore + student.englishScore;
}


float calculateAverageScore(const Student& student) 
{
    return calculateTotalScore(student) / 3.0;
}


void bubbleSortBySubject(Student students[], int numStudents, const string& subject)
{
    for (int i = 0; i < numStudents - 1; ++i)
    {
        for (int j = 0; j < numStudents - i - 1; ++j) 
        {
            float score1, score2;
            if (subject == "Chinese")
            {
                score1 = students[j].chineseScore;
                score2 = students[j + 1].chineseScore;
            }
            else if (subject == "Math") 
            {
                score1 = students[j].mathScore;
                score2 = students[j + 1].mathScore;
            }
            else if (subject == "English") 
            {
                score1 = students[j].englishScore;
                score2 = students[j + 1].englishScore;
            }
            else
            {
                cout << "Invalid string£¡" << endl;
                return;
            }

            if (score1 < score2) 
            {
                swap(students[j], students[j + 1]);
            }
        }
    }
}


void bubbleSortByTotalScore(Student students[], int numStudents)
{
    for (int i = 0; i < numStudents - 1; ++i)
    {
        for (int j = 0; j < numStudents - i - 1; ++j) 
        {
            float totalScore1 = calculateTotalScore(students[j]);
            float totalScore2 = calculateTotalScore(students[j + 1]);

            if (totalScore1 < totalScore2) 
            {
                swap(students[j], students[j + 1]);
            }
        }
    }
}


void displayStudentsByGender(const Student students[], int numStudents, const string& gender) 
{
    cout << "Information for students with " << gender << " :" << endl;
    for (int i = 0; i < numStudents; ++i) 
    {
        if (students[i].gender == gender)
        {
            outputStudent(students[i]);
            cout << endl;
        }
    }
}

void displayStudentsByMajor(const Student students[], int numStudents, const string& major) 
{
    cout << "Information of students majoring in " << major << " :" << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].major == major)
        {
            outputStudent(students[i]);
            cout << endl;
        }
    }
}