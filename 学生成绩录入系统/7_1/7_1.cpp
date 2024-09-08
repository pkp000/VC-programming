#include"7_1.h"


string Student::getName()
{
    return name;
}

short Student::getAge()
{
    return age;
}

char Student::getSex()
{
    return sex;
}

float Student::getEnglishScore()
{
    return englishScore;
}

float Student::getMathScore()
{
    return mathScore;
}

float Student::getProgramScore()
{
    return programScore;
}

float Student:: getTotalScore()
{
    return totalScore;
}


void Student::inputStudentInformation()
{   cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Enter student's name (enter '@' to finish inputStudentInformation): ";

    // Clear the input buffer to allow 'Space(s)' in the input
    getline(cin >> ws, name);

    if (name == "@")
    {
        return;
    }

    cout << "Enter student's age          : ";
    cin >> age;
    cout << "Enter student's sex (M/F)    : ";
    cin >> sex;
    cout << "Enter student's English score: ";
    cin >> englishScore;
    cout << "Enter student's Math score   : ";
    cin >> mathScore;
    cout << "Enter student's Program score: ";
    cin >> programScore;
    totalScore = englishScore + mathScore + programScore;
}


void Student::outputStudentInformation()
{
    // Originally wanted to use static variables, but it is inconvenient to add students
    // static bool hasHeader;

    if (!hasHeader) 
    {
         cout << "\n\nDisplays information about all current students:" << endl;
         cout << "_________________________________________________________________________________" << endl;
         cout << left << setw(12) << "Name" << setw(12) << "Age" << setw(12) << "Sex" << setw(12) << "English";
         cout << setw(12) << "Math" << setw(12) << "Program" << setw(12) << "Total" << endl;
         cout << "_________________________________________________________________________________" << endl;
    }

    // table header
    hasHeader = true;

    cout << setw(12) << name << setw(12) << age << setw(12) << sex << setw(12) << englishScore << setw(12);
    cout << mathScore << setw(12) << programScore << setw(12) << totalScore << endl;
}


const short Number_of_Students = 1;
short size0 = Number_of_Students;

// Dynamic create
Student* students = new Student[size0];

short count0 = 0;

void startStudentInformationEntryProcess()
{
    while (true)
    {
        if (count0 == size0)
        {
            size0 += 1;

            // Dynamic create intermediate variable
            Student* temp = new Student[size0];

            for (short i = 0; i < count0; ++i)
            {
                temp[i] = students[i];
            }

            delete[] students;
            students = temp;
        }

        students[count0].inputStudentInformation();

        if (students[count0].getName() == "@")
        {
            break;
        }
        count0++;
    }

    for (short i = 0; i < count0; ++i)
    {
        float totalScore = students[i].getEnglishScore() + students[i].getMathScore() + students[i].getProgramScore();
    }

    for (short i = 0; i < count0 - 1; ++i)
    {
        for (short j = 0; j < count0 - i - 1; ++j)
        {
            if (students[j].getTotalScore() < students[j + 1].getTotalScore())
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (short i = 0; i < count0; ++i)
    {
        students[i].outputStudentInformation();
    }

    // Function nested call
    continueAddingStudents();

    // Release the dynamically applied memory space 
    delete[] students;
}


void continueAddingStudents() 
{
    char choice;
    cout << "\n******************************************************************" << endl;
    cout << "Whether to continue adding students (Y/N) ?  ";
    cin >> choice;

    if (choice == 'Y')
    {
        // Note that the table header will also be redisplayed after this addition
        hasHeader = false;

        // Function nested call
        startStudentInformationEntryProcess();
    }

    else
        return;
}

void welcome()
{
    cout << " >*** Welcome to use student information entry ! ****< " << endl;
    cout << "Now you can enter the student information ..." << endl;
}

int main() 
{
    welcome();
    startStudentInformationEntryProcess();
}