#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isCommonSubstring(const vector<string>& strings, const string& substr) {
    for (int i = 0; i < strings.size(); i++) {
        if (strings[i].find(substr) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    int K;
    cin >> K;
    
    vector<string> strings(K);
    string shortest;
    int minLength = 5001;
    
    for (int i = 0; i < K; i++) {
        cin >> strings[i];
        if (strings[i].length() < minLength) {
            minLength = strings[i].length();
            shortest = strings[i];
        }
    }
    
    string result = "";
    
    for (int len = minLength; len > 0; len--) {
        bool found = false;
        
        for (int start = 0; start <= shortest.length() - len; start++) {
            string candidate = shortest.substr(start, len);
            if (isCommonSubstring(strings, candidate)) {
                result = candidate;
                found = true;
                break;
            }
        }
        
        if (found) {
            break;
        }
    }
    
    cout << result << endl;
    
    return 0;
}