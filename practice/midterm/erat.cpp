#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    bool erat[n + 1];
    for (int i = 0; i <= n; i++) {
        erat[i] = true;
    }
    
    erat[0] = erat[1] = false;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            for (int j = i; i * j <= n; j++) {
                erat[i * j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0 && erat[i] == true)
        {
            count++;
        }
        
    }
    
    cout << count;
    return 0;
}