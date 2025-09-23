#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    const int MAX = 1250;
    int primes[MAX], primeCount = 0;
    int num = 2;

    while(primeCount < MAX) {
        if(isPrime(num)) {
            primes[primeCount++] = num;
        }
        num++;
    }
    int superprimeCount = 0;
    for(int i = 0; i < primeCount; ++i) {
        if(isPrime(i+1)) {
            superprimeCount++;
            if(superprimeCount == n) {
                cout << primes[i] << endl;
                break;
            }
        }
    }
    return 0;
}