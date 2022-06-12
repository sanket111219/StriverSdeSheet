#include<bits/stdc++.h>
bool isPossible(int n, long long m,  double mid)
{
    double ans = 1.0;
    for(int i = 1; i <= n; i++)
    {
        ans = ans * mid;
    }
    return ans < m;
}

// void getPrecision(int n, long long m, double &ans)
// {
//     double digit = 1;
//     for(int i = 1; i <= 1e7; i++)
//     {
//         digit /= 10;
//         double counter = digit;
//         while(pow((ans + counter), n) < m)
//         {
//             ans += counter;
//             counter += digit;
//         }
//     }
    
// }

double findNthRootOfM(int n, long long m) {
	// Write your code here


//  ******** binary search**************



//     double start = 1;
//     double end = m;
//     double eps = 1e-7;
    
//     double ans;
//     while((end - start) > eps)
//     {
//          double mid = (start + end)/2.0;
        
//         if(isPossible(n, m, mid))
//         {
// //             ans = mid;
//             start = mid;
//         }
//         else
//         {
//             end = mid;
//         }
//     }
    
    
//     return start;



//************* Newton Rahpson Law.***************
    double eps = 1e-7;
    double xPre = 1.0;
    double difference = INT_MAX;
    double xK;
    while(difference > eps)
    {
        xK = ((n - 1)*xPre + (double)m/pow(xPre, n-1))/(double)n;
        difference = abs(xK - xPre);
        xPre = xK;
    }
    return xK;
    
}
