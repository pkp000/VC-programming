#include"9_1.h"


// Defined after the header file declaration "Person"
string Person::getName0()
{
    return name;
}

string Person::getGender0()
{
    return sex;
}

int Person::getAge0()
{
    return age;
}

Person::Person(string name, string sex, int age) : name(name), sex(sex), age(age) {}

void Person::display()
{
    // Set header, similarly hereinafter
    static bool hasHeader0 = false;

    if(!hasHeader0)
    {
        cout << "\n\nDisplays information about person:" << endl;
        cout << "_________________________________________________________________________________" << endl;
        cout << left << setw(12) << "Name" << setw(12) << "Age" << setw(12) << "Sex" << setw(12) << endl;
        cout << "_________________________________________________________________________________" << endl;
        hasHeader0 = true;
    }

    cout << setw(12) << name << setw(12) << age << setw(12) << sex << endl;
}



// Defined after the header file declaration "Registrant"
Registrant::Registrant(int num) : registeredNumber(num) {}

int Registrant::getRegisteredNumber()
{
    return registeredNumber;
}



// Defined after the header file declaration "Teacher"

string Teacher::getName()
{
    return getName0();
}

string Teacher::getGender()
{
    return getGender0();
}

int Teacher::getAge()
{
    return getAge0();
}

Teacher::Teacher(string n, string g, int a, int num, string dept, string t): 
    Person(n, g, a), Registrant(num), department(dept), title(t) {}

void Teacher::display()
{
    static bool hasHeader1 = false;

    if (!hasHeader1)
    {
        cout << "\n\nDisplays information about teathers:" << endl;
        cout << "___________________________________________________________________________________" << endl;
        cout << left << setw(12) << "Name" << setw(12) << "Sex" << setw(12) << "Age" << setw(12);
        cout << "ID" << setw(16) << "Department" << setw(16) << "Title" << setw(12) << endl;
        cout << "___________________________________________________________________________________" << endl;
        hasHeader1 = true;
    }

    cout << setw(12) << getName() << setw(12) << getGender() << setw(12) << getAge();
    cout << setw(12) << getRegisteredNumber() << setw(16) << department << setw(16) << title << endl;

}



// Defined after the header file declaration "Student"
string Student::getName()
{
    return getName0();
}

string Student::getGender()
{
    return getGender0();
}

int Student::getAge()
{
    return getAge0();
}

Student::Student(string name, string sex, int age, int id, string classname, int score): 
    Person(name, sex, age), Registrant(id), className(classname), score(score) {}

void Student::display()
{
    static bool hasHeader2 = false;
    if (!hasHeader2)
    {
        cout << "\n\nDisplays information about students:" << endl;
        cout << "_____________________________________________________________________" << endl;
        cout << left << setw(12) << "Name" << setw(12) << "Sex" << setw(12) << "Age" << setw(12);
        cout << "ID" << setw(12) << "Class" << setw(12) << "Score" << setw(12) << endl;
        cout << "_____________________________________________________________________" << endl;
        hasHeader2 = true;
    }

    cout << setw(12) << getName() << setw(12) << getGender() << setw(12) << getAge();
    cout << setw(12) << getRegisteredNumber() << setw(12) << className << setw(12) << score << endl;

}



void  informationDisplay()
{
    Teacher* teachers[4];
    teachers[0] = new Teacher("Sissi", "F", 70, 1003, "Transnatural", "Academician");
    teachers[1] = new Teacher("Jeremiah", "M", 55, 1021, "Math", "Professor");
    teachers[2] = new Teacher("Charles", "M", 49, 1032, "Politics", "Associate professor");
    teachers[3] = new Teacher("Marianne", "F", 44, 1050, "English", "Lecturer");
 

    Student* students[5];
    students[0] = new Student("Milly", "F", 21, 21001, "A", 91);
    students[1] = new Student("Suzaku", "M", 20, 21002, "A", 65);
    students[2] = new Student("Lelouch", "M", 20, 22001, "B", 98);
    students[3] = new Student("Shirley", "F", 19, 22002, "B", 87);
    students[4] = new Student("Nunnally", "F", 18, 23001, "C", 75);

    // Display teacher information by category
    for (int i = 0; i < 4; ++i) 
    {
        teachers[i]->display();
    }

    // Display student information by category
    for (int i = 0; i < 5; ++i)
    {
        students[i]->display();
    }

    // Release memory
    for (int i = 0; i < 4; ++i)
    {
        delete teachers[i];
        delete students[i];
    }
}

void welcome()
{
    cout << "\t\tWelcome!" << endl;
    cout << "The following is a school personnel information display system." << endl;
}

void goodbye()
{

    cout << "\n\nEnter any key to exit..." << endl;
    cin.ignore();
    cin.get();
}


int main()
{   
    welcome();
    informationDisplay();
    goodbye();
}