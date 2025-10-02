#include <iostream>
using namespace std;

int maxEl(int a[], int size){
    int curMax = a[0];
    for (int i = 1; i < size; i++)
    {
        curMax = max(curMax, a[i]);
    }
    return curMax;
}


int main(){
    int bagsNum, hours;
    cin >> bagsNum >> hours;
    int bags[bagsNum];
    for (int i = 0; i < bagsNum; i++)
    {
        cin >> bags[i];
    }
    
    int left = 1;
    int right = maxEl(bags, bagsNum);
    int ans = right;
    while (left <= right)
    {
        int mid = (left + right)/2;
        int total = 0;
        for (int i = 0; i < bagsNum; i++)
        {
            total += (bags[i] + mid - 1)/mid;

            if (total > hours)
            {
                break;
            }
            
        }

        if (total > hours)
        {
            left = mid+1;
        }
        else{
            ans = mid;
            right = mid-1;
        }
    }
    
    cout << ans;

    return 0;
}