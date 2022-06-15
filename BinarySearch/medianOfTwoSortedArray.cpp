#include<bits/stdc++.h>
using namespace std;

double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    
    if(b.size() < a.size() )return median(b,a);
    int n = a.size();
    int m = b.size();
    
    
    
    int start = 0;
    int end = n;
    
    double ans;
    while(start <= end)
    {
        int cut1 = start + (end - start)/2;
        int cut2 = (n+m+1)/2 - cut1;
        
        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        
        int r1 = (cut1 == n) ? INT_MAX : a[cut1];
        int r2 = (cut2 == m) ? INT_MAX : b[cut2];
        
        
        if(l1 <= r2 && l2 <= r1)
        {
            if((n+m)%2 == 0)
                return (max(l1, l2) + min(r1, r2))/2.0;
            else
                return max(l1, l2);
        }
        else if(l1 > r2)
        {
            end = cut1 - 1;
        }
        else 
            start = cut1 + 1;
    }
    return 0.0;
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        double ans = median(a, b);

        cout << ans << endl;

    }
}