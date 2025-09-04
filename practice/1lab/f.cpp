#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n%i == 0)
            return false;
    }
    return true;
    
}

int main() {
    int n;
    cin >> n;

    int num = 0;

    for (int i = 0; i < n; num++)
    {
        if (isPrime(num))
        {
            i++;
        }
        
    }
    num--;
    cout << num;
    
    return 0;
}