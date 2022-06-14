#include<bits/stdc++.h>
using namespace std;

int findPivot(int *arr, int n)
{
    int start = 0;
    int end = n-1;
    
    int ans;
    while(start < end)
    {
        int mid = start + (end - start)/2;
        
        if(arr[mid] >= arr[start])
        {
            start = mid + 1;
        }
        else
        {
//             ans = mid;
            end = mid;
        }
    }
    return end;
    
}

int binarySearch(int* arr, int n, int start, int end, int key)
{
    int s = start;
    int e = end;
    
    while(s <= e)
    {
        int mid = s + (e - s)/2;
        if(arr[mid] == key)
            return mid;
        
        else if(arr[mid] > key)
            e = mid - 1;
        else 
            s = mid + 1;
    }
    return -1;
}


int search(int* arr, int n, int key) {
    // Write your code here.
    int pivot = findPivot(arr, n);
    
    int ans;
    if(arr[pivot] <= key && arr[n-1] >= key)
       ans = binarySearch(arr, n, pivot, n - 1, key);
    
    else 
       ans = binarySearch(arr, n, 0, pivot - 1, key);
    
    return ans;
}