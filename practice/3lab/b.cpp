#include <iostream>
using namespace std;

long long maxEl(long long* a, int size){
    long long curMax = a[0];
    for (int i = 1; i < size; i++)
    {
        curMax = max(curMax, a[i]);
    }
    return curMax;
}

long long sum(long long* a, int size){
    long long ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}

long long count_blocks(long long* a, int size, long long min_sum){
    long long currSum = 0;
    int blocks = 0;
    for (int i = 0; i < size; i++)
    {
        if (currSum + a[i] > min_sum)
        {
            currSum = 0;
            blocks++;
        }
        currSum += a[i];
    }
    return blocks+1;
}

int main(){
    int houses, k;
    cin >> houses >> k;
    long long a[houses];

    for (int i = 0; i < houses; i++)
    {
        cin >> a[i];
    }
    
    long long left = maxEl(a, houses);
    long long right = sum(a, houses);
    long long answer = right;
    while (left < right)
    {
        long long mid = (left+right)/2;
        if (count_blocks(a, houses, mid) <= k)
        {
            answer = mid;
            right = mid;
        }
        else if (count_blocks(a, houses, mid) > k)
        {
            left = mid+1;
        }
    }
    cout << answer;


    
    return 0;
}