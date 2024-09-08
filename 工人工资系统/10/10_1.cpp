#include"10_1.h"


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

Person::Person(string n, string s, int a)
{
    name = n;
    sex = s;
    age = a;
}



// Defined after the header file declaration "Staff"
string Staff::getName()
{
    return getName0();
}

string Staff::getGender()
{
    return getGender0();
}

int Staff::getAge()
{
    return getAge0();
}

int Staff::getID()
{
    return id;
}

double Staff::getFixedSalary()
{
    return fixedSalary;
}

Staff::Staff(string n, string g, int a, int i, double f) :Person(n, g, a)
{
    id = i;
    fixedSalary = f;
}


// Notice! Pure virtual functions define concrete content (0)
double Staff::salary()
{
    return fixedSalary;
}




// Static binding (Function overloading)
Director:: Director(string n, int a, string g, int i, double f = 8000.0, string j = "director") :Staff(n, g, a, i, f)
{
    job = j;
}

void Director::displayD()
{
    cout << left << setw(12) << getName() << setw(12) << getGender() << setw(12) << getAge() << setw(12);
    cout << getID() << setw(12) << salary() << setw(12) << job << setw(12) << endl;
}


// Notice! Pure virtual functions define concrete content (1)
double Director::salary()
{
    return getFixedSalary();
}




// Static binding (Function overloading)
Worker::Worker(string n, int a, string g, int i, int o, double f = 3000.0 , string j = "worker") :Staff(n, g, a, i, f)
{
    job = j;
    overtime = o;
}


// Notice! Pure virtual functions define concrete content (1)
double Worker::salary()
{
    return getFixedSalary() + overtime * 100;
}

void Worker::displayW()
{
    cout << left << setw(12) << getName() << setw(12) << getGender() << setw(12) << getAge() << setw(12)<< getID();
    cout  << setw(12) << salary() << setw(12) << job  <<"   " << overtime << setw(12) << endl;
}




void makeHeader()
{
    static bool hasHeader1 = false;
    if (!hasHeader1)
    {
        cout << "\n\nDisplays information about staff:" << endl;
        cout << "_____________________________________________________________________________________" << endl;
        cout << left << setw(12) << "Name" << setw(12) << "Sex" << setw(12) << "Age" << setw(12)<< "ID" << setw(12);
        cout << "Salary(￥)" << setw(12) << "  Job" << setw(12) << "Overtime(h)" << setw(12) << endl;
        cout << "_____________________________________________________________________________________" << endl;
        hasHeader1 = true;
    }

}

void welcome()
{
    cout << "\t\tWelcome!" << endl;
    cout << "The following is a table about monthly salary of the staff ." << endl;
}

void goodbye()
{
    cout << "...\n...\n...\n...\n" << endl;
    cout << "\nBye~\nThank you all the time!\n\nEnter any key to exit..." << endl;
    cin.ignore();
    cin.get();
}

void calculateDisplay()
{
    Person* p;
    Director leader("Sissi", 50, "F", 1003);
    p = &leader;
    cout<<p -> salary(); // 虚函数的使用

    Worker* workers[3];
    workers[0] = new Worker("Marianne", 40, "F", 21003, 12 );
    workers[1] = new Worker("Jeremiah", 35,"M", 22021, 18);
    workers[2] = new Worker("Charles", 29, "M", 23032, 24);
    
    makeHeader();
    
    leader.displayD();


    for (int i = 0; i < 3; ++i)
    {
        workers[i]->displayW();
    }

    // Release memory
    for (int i = 0; i < 3; ++i)
    {
        delete workers[i];
    }
}


int main() 
{
    welcome();
    calculateDisplay();
    goodbye();
    return 0;
}