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
    int islands;
    long long flights;  // f can be large
    cin >> islands >> flights;

    int child[islands];
    for (int i = 0; i < islands; i++)
    {
        cin >> child[i];
    }

    int min = 1;
    int max = maxEl(child, islands);
    int answer = max;

    while (min <= max){
        int middle = (min + max) / 2;
        long long total = 0;

        for (int i = 0; i < islands; i++)
        {
            total += (child[i] + (long long)middle - 1) / middle;
    
            if (total > flights) 
                break;
        }

        if (total <= flights)
        {
            answer = middle;
            max = middle - 1;
        }
        else
        {
            min = middle + 1;
        }
    }
    
    cout << answer;
    return 0;
}