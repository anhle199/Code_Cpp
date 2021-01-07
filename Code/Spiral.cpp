#include <vector>

using namespace std;

vector< vector<int> > spiral_1(int m, int n)
{
    vector< vector<int> > matrix(m, vector<int> (n));
    int row_current(0), col_current(0), value_current(1), count(0);

    while (value_current != (n * m + 1))
    {
        // left to right
        if (value_current == (n * m + 1))
            break;

        while (col_current < n - count)
        {
            matrix[row_current][col_current] = value_current++;
            col_current++;
        }

        col_current--;
        row_current++;

        if (value_current == (n * m + 1))
            break;

        // up to down        
        while (row_current < m - count)
        {
            matrix[row_current][col_current] = value_current++;
            row_current++;
        }

        row_current--;
        col_current--;
        
        if (value_current == (n * m + 1))
            break;

        // right to left
        while (col_current > count - 1)
        {
            matrix[row_current][col_current] = value_current++;
            col_current--;
        }

        col_current++;
        row_current--;
        count++;

        if (value_current == (n * m + 1))
            break;

        // bottom to top
        while (row_current > count - 1)
        {
            matrix[row_current][col_current] = value_current++;
            row_current--;
        }
        
        row_current++;
        col_current++;
    }

    return matrix;
}

vector< vector<int> > spiral_1_square_matrix(int n)
{
	vector< vector<int> > matrix(n, vector<int> (n));
    int row_current(0), col_current(0), value_current(1), count(0);

    while (count != n)
    {
        // left to right
        while (col_current < n - count)
        {
            matrix[row_current][col_current] = value_current++;
            col_current++;
        }

        col_current--;
        row_current++;

        // up to down        
        while (row_current < n - count)
        {
            matrix[row_current][col_current] = value_current++;
            row_current++;
        }

        row_current--;
        col_current--;
        
        // right to left
        while (col_current > count - 1)
        {
            matrix[row_current][col_current] = value_current++;
            col_current--;
        }

        col_current++;
        row_current--;
        count++;

        // bottom to top
        while (row_current > count - 1)
        {
            matrix[row_current][col_current] = value_current++;
            row_current--;
        }
        
        row_current++;
        col_current++;
    }

    return matrix;
}

vector< vector<int> > spiral_2(int n)
{
    vector< vector<int> > matrix(n, vector<int> (n));
	int left(0), right(n), spiralNumber;
    
	spiralNumber = (n / 2) + 1;
	
	do
	{
		for (int i = left; i < right; i++)
		{
			if (i == left || i == right - 1)
				for (int j = left; j < right; j++)
					matrix[i][j] = spiralNumber;
			else
			{
				matrix[i][left] = spiralNumber;
				matrix[i][right - 1] = spiralNumber;
			}
		}
		
		left++;
		right--;
		spiralNumber--;
	} while(right >= 1);

    return matrix;
}