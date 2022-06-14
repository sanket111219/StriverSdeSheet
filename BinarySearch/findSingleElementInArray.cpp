#include<bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int start = 0;
    int end = n-2;
    
    int ans;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        
//         if(mid % 2 == 0)
//         {
//             if(arr[mid] != arr[mid+1])
//             {

//                 end = mid - 1;
//             }
//             else
//             {
//                 start = mid +1;
//             }
            
//         }
//         else
//         {
//             if(arr[mid] == arr[mid + 1])
//             {
//                 end = mid - 1;
//             }
//             else
//             {
//                 start = mid + 1;
//             }
            
//         }
        
        if(arr[mid] == arr[mid ^ 1])
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return arr[start];
}
