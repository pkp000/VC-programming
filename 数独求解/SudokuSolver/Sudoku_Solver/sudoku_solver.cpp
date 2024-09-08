#include <iostream>
#include <limits>
using namespace std;


// Excluding rotation, reflection, or rearrangement, the maximum number of results is 5,472,730,538
int number_of_results = 0;
const int N = 9;
int results[1500][N][N]; 


bool is_feasible(int sudoku[N][N], int row, int column, int figure)
{
    //  Check: current row has the same number as figure
    for (int i = 0; i < N; i++)
    {
        if (sudoku[row][i] == figure)
        {
            return false;
        }
    }

    // Check: current column has the same number as figure
    for (int i = 0; i < N; i++)
    {
        if (sudoku[i][column] == figure)
        {
            return false;
        }
    }

    // This treatment is similar to image processing filtering
    int startRow = row - row % 3;
    int startColumn = column - column % 3;

    //  Check: current the subsquare of 3x3 has the same number as figure
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[startRow + i][startColumn + j] == figure)
            {
                return false;
            }
        }
    }

    return true;
}

void put_element(int sudoku[N][N]) 
{
    // Define local variables first
    bool isZero = true;
    int row = -1;
    int column = -1;
    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Find a spare seat
            if (sudoku[i][j] == 0)
            {
                row = i;
                column = j;
                isZero = false;
                break;
            }
        }
        if (!isZero) 
        {
            break;
        }
    }

    if (isZero)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) 
            {
                // Store the end result
                results[number_of_results][i][j] = sudoku[i][j];
            }
        }
        number_of_results++;
        return;
    }

    for (int figure = 1; figure <= N; figure++) 
    {
        if (is_feasible(sudoku, row, column, figure)) 
        {
            sudoku[row][column] = figure;

            // recursive call,"figure" keeps growing in order to ensure that all the results are available
            put_element(sudoku);

            // sudoku: just store the results of the intermediate process
           
        }
    }
}

void output_result(int sudoku[N][N])
{
    // Top horizontal line
    cout << "  -----------------------------------" << endl;

    for (int i = 0; i < N; i++) 
    {
        
        for (int j = 0; j < N; j++) 
        {
            // Output the element at every other position and then add a vertical line
            cout << " | " << sudoku[i][j];
        }

        // Add a final vertical line
        cout << " | " << endl;

        // Draw a horizontal line after each output row
        cout << "  -----------------------------------" << endl;
    }
}

int main() 
{
    int sudoku[N][N] =
    {
        {5, 0, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {0, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "\tOriginal State:\n" << endl;
    output_result(sudoku);
    cout << "\n\n\n" << endl;

    put_element(sudoku);

    if (number_of_results == 0)
    {
        cout << "This sudoku has no solution!\n" << endl;
    }
    else 
    {
        cout << "The Sudoku has "<< number_of_results <<" solutions." << endl;
        cout << "All the solutions found in this sudoku£º\n" << endl;

        for (int i = 0; i < number_of_results; i++)
        {
            output_result(results[i]);
            cout << "\n\n**************************************\n\n" << endl;
        }
    }
    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
