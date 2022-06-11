#include <bits/stdc++.h> 
using namespace std;


void sort012(int *arr, int n)
{
   //   Write your code here
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
            mid++;
        
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    
}