#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int left = 0;
    int right = n;
    string ans = "No";
    while (left < right)
    {
        int mid = (left + right)/2;
        if (arr[mid] < x)
        {
            left = mid+1;
        }
        else if(arr[mid] > x){
            right = mid;
        }
        else{
            ans = "Yes";
            break;
        }
    }
    cout << ans;
    

    return 0;
}