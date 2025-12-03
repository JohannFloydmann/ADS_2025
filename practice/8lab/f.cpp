#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct SuffixAutomaton {
    struct State {
        int len, link;
        int next[26];
        State() : len(0), link(-1) {
            for (int i = 0; i < 26; i++) next[i] = -1;
        }
    };
    
    vector<State> st;
    int last;
    
    SuffixAutomaton(int maxSize) {
        st.reserve(maxSize * 2);
        st.push_back(State());
        last = 0;
    }
    
    void extend(char c) {
        int curr = st.size();
        st.push_back(State());
        st[curr].len = st[last].len + 1;
        
        int p = last;
        while (p != -1 && st[p].next[c - 'a'] == -1) {
            st[p].next[c - 'a'] = curr;
            p = st[p].link;
        }
        
        if (p == -1) {
            st[curr].link = 0;
        } else {
            int q = st[p].next[c - 'a'];
            if (st[p].len + 1 == st[q].len) {
                st[curr].link = q;
            } else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                
                while (p != -1 && st[p].next[c - 'a'] == q) {
                    st[p].next[c - 'a'] = clone;
                    p = st[p].link;
                }
                st[q].link = st[curr].link = clone;
            }
        }
        last = curr;
    }
    
    long long countDistinctSubstrings() {
        long long result = 0;
        for (int i = 1; i < st.size(); i++) {
            result += st[i].len - st[st[i].link].len;
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    SuffixAutomaton sa(s.length());
    for (char c : s) {
        sa.extend(c);
    }
    
    cout << sa.countDistinctSubstrings() << endl;
    return 0;
}