#include <iostream>
using namespace std;

int n, k;

bool hasSum(int els, int *pref)
{
    int sum = 0;
    for (int i = 0; i <= n - els; i++)
    {
        if (i == 0)
            sum = pref[els - 1];
        else
            sum = pref[i + els - 1] - pref[i - 1];

        if (sum >= k)
            return true;
    }
    return false;
}

int main()
{

    cin >> n >> k;
    int nums[n], pref[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i == 0)
            pref[i] = nums[i];
        else
            pref[i] = pref[i - 1] + nums[i];
    }

    int left = 1;
    int right = n;
    int ans = right;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (hasSum(mid, pref))
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1; 
    }

    cout << ans;

    return 0;
}