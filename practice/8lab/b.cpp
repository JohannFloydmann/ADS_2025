#include <iostream>
#include <cmath>
using namespace std;

int rolypoly(const string &s, int prime, int size) {
    int h = 0;
    const int alphabeth_size = 256;
    for (int i = 0; i < size; i++) {
        h = (h * alphabeth_size + (unsigned char)s[i]) % prime;
    }
    return h;
}

bool check(const string &text1, const string &text2, const string &pat, int i) {
    for (int j = 0; j < pat.size(); j++) {
        if (text1[i + j] != pat[j] || text2[i + j] != pat[j])
            return false;
    }
    return true;
}

int RabinKarp(const string &text1, const string &text2, const string &pat, int hash_size) {
    int count = 0;

    int t1 = rolypoly(text1, hash_size, pat.size());
    int t2 = rolypoly(text2, hash_size, pat.size());
    int p = rolypoly(pat, hash_size, pat.size());

    int pow = 1;
    const int alphabeth = 256;

    for (int i = 0; i < pat.size() - 1; i++) {
        pow = (pow * alphabeth) % hash_size;
    }

    for (int i = 0; i <= text1.size() - pat.size(); i++) {
        if (t1 == p && t2 == p) count++;

        // Update hash only if there is another window
        if (i < text1.size() - pat.size()) {
            // Update hash for first text
            t1 = (t1 - (unsigned char)text1[i] * pow) % hash_size;
            if (t1 < 0) t1 += hash_size;
            t1 = (t1 * alphabeth + (unsigned char)text1[i + pat.size()]) % hash_size;

            // Update hash for second text
            t2 = (t2 - (unsigned char)text2[i] * pow) % hash_size;
            if (t2 < 0) t2 += hash_size;
            t2 = (t2 * alphabeth + (unsigned char)text2[i + pat.size()]) % hash_size;
        }
    }

    return count;
}

int main() {
    string first, second, pat;
    cin >> first >> second >> pat;

    int f = RabinKarp(first, second, pat, 101);
    cout << f;
}
