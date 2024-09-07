#include<iostream>
#include<windows.h>
#pragma comment(lib, "winmm.lib")
#include <graphics.h>
#include <mmsystem.h>
#include <filesystem>
using namespace std;

void human_move()
{
	char static_unit[4][6] =
	{
		"  @ ",
		"-<#>-",
		" / \\",
	};
	char mobile_unit[4][6] =
	{
		"  @ ",
		"-<#>-",
		" / >",
	};

	// Clean the screen
	system("cls");  

	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 4; j++)
			cout << static_unit[i][j];
		cout << endl;
	}
	int n;
	cout << "Please enter the number of steps the hunman moves:";
	cin >> n;

	// Clean the screen
	system("cls");  

	Sleep(1000);
	for (int i = 0; i <= 3; i++)
	{
		for (int k = 0; k <= n; k++)
		{
			cout << " ";
		}
		for (int j = 0; j <= 4; j++)
		{
			cout << mobile_unit[i][j];
		}
		cout << endl;
	}
}

void special_shape()
{
	cout << "\n\n            **************" << endl;
	cout << "         *                   *" << endl;
	cout << "      *    ¶«            ´ó    *" << endl;
	cout << "    *         ********          *" << endl;
	cout << "   *        *           *        *" << endl;
	cout << "  *   É½  *              *   Ñ§   *" << endl;
	cout << " *       *                *        *" << endl;
	cout << " *      *       /\\         *       *" << endl;
	cout << " *      *   /\\ /  \\ /\\     *       *" << endl;
	cout << " *       * /  \\    /  \\   *        *" << endl;
	cout << "  *       * ------------ *        *" << endl;
	cout << "   *       *    1901   *         *" << endl;
	cout << "    *         ********          *" << endl;
	cout << "      *                        *" << endl;
	cout << "         *                   *" << endl;
	cout << "            **************\n\n" << endl;
}

void heart_shaped() {
	for (float y = 1.5f; y > -1.5f; y -= 0.1f) {
		for (float x = -1.5f; x < 1.5f; x += 0.05f) {
			float a = x * x + y * y - 1;
			if (a * a * a - x * x * y * y * y <= 0.0f)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}


int main()
{
    int choice;

	// Note that this use applies if the compiler supports C++17 or later.
	if (filesystem::exists("./ÖóÃ×£¨Æ¬¶Î£©.mp3")) 
	{
		// Open music file
		mciSendString(_T("open ÖóÃ×£¨Æ¬¶Î£©.mp3 alias music"), NULL, 0, NULL);
		/* String - related functions sometimes have character set problems,
       and the solution here is to wrap the string using parameterized macros.*/
	}
	else if (filesystem::exists("./x64/Debug/ÖóÃ×£¨Æ¬¶Î£©.mp3"))
	{
		mciSendString(_T("open ./x64/Debug/ÖóÃ×£¨Æ¬¶Î£©.mp3 alias music"), NULL, 0, NULL);
	}
	else if (filesystem::exists("../x64/Debug/ÖóÃ×£¨Æ¬¶Î£©.mp3"))
	{
		mciSendString(_T("open ../x64/Debug/ÖóÃ×£¨Æ¬¶Î£©.mp3 alias music"), NULL, 0, NULL);
	}
    
       // play music(Loop Playback)
    mciSendString(_T("play music repeat"), NULL, 0, NULL);

	// cycle operation
    do
    {
        cout << "Please select an option(1-3) £º";
        cout << "\n1.human move\n2.heart shape\n3.special shape" << endl;
        cout << "(Enter 4 to exit)" << endl;
        cin >> choice;

		// Design function branch
        switch (choice)
        {
        case 1:
            cout << "You chose: 1.human move" << endl;
            Sleep(500);
            human_move();
            break;

        case 2:
            cout << "You chose: 2.heart shape" << endl;
            Sleep(500);
            heart_shaped();
            break;

        case 3:
            cout << "You chose: 3.special shape" << endl;
            Sleep(500);
            special_shape();
            break;

        default:
            // Code that handles invalid options
            cout << "Invalid option---Program quit" << endl;
            break;
        }
		if (choice == 4)
			break;
    } while (1);

    // Turn off the music
    mciSendString(_T("close music"), NULL, 0, NULL);
    return 0;
}
