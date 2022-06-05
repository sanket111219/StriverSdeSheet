#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    
    // approach - 1
    int n = matrix.size();
    int m = matrix[0].size();
    
//     int* rowDummy = new int[n];
//     int* colDummy = new int[m];
//     for(int i = 0; i < n; i++)
//         rowDummy[i] = -1;
    
//     for(int i = 0; i < m; i++)
//         colDummy[i] = -1;
    
//     for(int row = 0; row < n; row++)
//         for(int col = 0; col < m; col++)
//             if(matrix[row][col] == 0)
//                 rowDummy[row] = colDummy[col] = 0;
    
//     for(int row = 0; row < n; row++)
//         for(int col = 0; col < m; col++)
//             if(rowDummy[row] == 0 || colDummy[col] == 0)
//                 matrix[row][col] = 0;
    
    // approach 2
    
    bool col0 = 1;
    
    for(int row = 0; row < n; row++)
    {
        if(matrix[row][0] == 0)
            col0 = 0;
        for(int col = 1; col < m; col++)
            if(matrix[row][col] == 0)
                matrix[row][0] = matrix[0][col] = 0;
    }
    for(int row = n - 1; row >= 0; row--)
    {
        for(int col = m - 1; col >= 1; col--)
            if(matrix[row][0] == 0 || matrix[0][col] == 0)
                matrix[row][col] = 0;
        if(col0 == 0)
            matrix[row][0] = 0;
    }

}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int number;
            cin >> number;
            temp.push_back(number);
        }
        matrix.push_back(temp);
    }

    setZeros(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}