#include <iostream>
using namespace std;

int distance(int first, int second){
    return (first-second < 0 ? second - first : first - second);
}

int main(){
    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    
    int num;
    cin >> num;

    int offset = 3;
    int dist = 2147483647;

    for (int i = 0; i < size; i++)
    {
        if (distance(arr[i], num) < dist)
        {
            dist = distance(arr[i], num);
            offset = i;
        }
    }
    cout << offset;

    return 0;
}