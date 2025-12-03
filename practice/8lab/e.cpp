#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> hashes(N);
    for (int i = 0; i < N; i++) {
        cin >> hashes[i];
    }
    
    string result = "";
    
    long long first_char_value = hashes[0];
    result += char(97 + first_char_value);
    
    for (int i = 1; i < N; i++) {
        long long diff = hashes[i] - hashes[i-1];
        long long power = 1LL << i;
        
        long long char_value = diff / power;
        result += char(97 + char_value);
    }
    
    cout << result << endl;
    
    return 0;
}