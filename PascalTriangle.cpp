#include <bits/stdc++.h>
using namespace std; 


vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> ans;
    for(int i = 1; i <= n; i++)
    {
        vector<long long int> temp;
        temp.push_back(1);
        if(i == 2)
            temp.push_back(1);
        
        else if(i > 2)
        {
            for(int j = 1; j < i-1; j++)
            {
                temp.push_back(ans[i-2][j-1] + ans[i-2][j]);
            }
            temp.push_back(1);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<long long int>> ans = printPascal(n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
