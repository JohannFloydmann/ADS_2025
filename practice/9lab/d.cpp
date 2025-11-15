#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string lowerc(const string &s) {
    string t = s;
    for (char &ch : t) ch = tolower(ch);
    return t;
}

int main() {
    string prev;
    cin >> prev;

    int n;
    cin >> n;

    vector<string> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    string prev_l = lowerc(prev);
    vector<string> c_l(n);
    for (int i = 0; i < n; i++)
        c_l[i] = lowerc(c[i]);

    int best = 0;
    vector<int> match(n, 0);

    for (int i = 0; i < n; i++) {
        int plen = prev_l.size();
        int clen = c_l[i].size();
        int maxLen = min(plen, clen);

        for (int len = 1; len <= maxLen; len++) {
            if (prev_l.compare(plen - len, len, c_l[i], 0, len) == 0) {
                match[i] = len;
            }
        }
        best = max(best, match[i]);
    }

    vector<string> ans;
    for (int i = 0; i < n; i++)
        if (match[i] == best && best > 0)
            ans.push_back(c[i]);

    cout << ans.size() << "\n";
    for (auto &s : ans)
        cout << s << "\n";

    return 0;
}
