#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    if (n == 0)
        return 0;
    long long maxSum = 0;
    long long currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        maxSum = max(currsum, maxSum);

        if (currsum < 0)
            currsum = 0;
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long ans = maxSubarraySum(arr, n);

    cout << ans << endl;

} 