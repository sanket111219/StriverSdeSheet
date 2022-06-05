#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int breakPoint, greaterThanbreakPoint;
    for(breakPoint = n - 2; breakPoint >= 0; breakPoint--)
        if(permutation[breakPoint] < permutation[breakPoint+1])
            break;
    
    if(breakPoint < 0)
        reverse(permutation.begin(), permutation.end());
    
    else
    {
        for(greaterThanbreakPoint = n-1; greaterThanbreakPoint > breakPoint; greaterThanbreakPoint--)
            if(permutation[greaterThanbreakPoint] > permutation[breakPoint])
                break;
        
        swap(permutation[greaterThanbreakPoint], permutation[breakPoint]);
        reverse(permutation.begin()+breakPoint+1, permutation.end());
    }
    return permutation;
}

int main()
{
    int n;
    cin >> n;

    vector<int> permutation;

    for(int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        permutation.push_back(number);
    }

    vector<int> ans = nextPermutation(permutation, n);

    for(int i = 0; i < n; i++)
        cout << ans[i] <<" ";
}