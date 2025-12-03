#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using ull = unsigned long long;
constexpr ull MOD = 1e9 + 7;
vector<ull> POW11;

void prepare_power(size_t max_len) {
    POW11.resize(max_len + 1);
    POW11[0] = 1;
    for (size_t i = 1; i <= max_len; ++i) {
        POW11[i] = (POW11[i - 1] * 11) % MOD;
    }
}

ull to_hash(const string &str) {
    ull result = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        ull term = ((str[i] - 47) * POW11[i]) % MOD;
        result = (result + term) % MOD;
    }
    return result % MOD;
}

bool is_digit(const string &s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull N;
    cin >> N;

    vector<string> items(2 * N);
    size_t max_len = 0;
    for (string &s : items) {
        cin >> s;
        max_len = max(max_len, s.size());
    }

    prepare_power(max_len);

    unordered_map<string, int> freq;
    for (const string &s : items) {
        ++freq[s];
    }

    int count = 0;
    for (const string &s : items) {
        if (count == N) break;
        if (!is_digit(s)) continue;

        ull h = to_hash(s);
        string h_s = to_string(h);

        if (freq[h_s] > 0) {
            cout << "Hash of string \"" << s << "\" is " << h << '\n';
            ++count;
        }
    }

    return 0;
}