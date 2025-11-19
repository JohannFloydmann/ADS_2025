#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long prime = 1e+7;
const int alph = 256;


int rolypoly(string s, int size){
    int h = s[0];
    for (int i = 1; i < size; i++)
    {
        h = ((h*alph)% prime + s[i])%prime;
    }
    return h;
}

vector<int> RabinKarp(string text, string pat){
    vector<int> res;

    int n = text.length();
    int m = pat.length();

    int t = rolypoly(text, m);
    int p = rolypoly(pat, m);

    int pow = 1;
    for (int i = 0; i < m-1; i++)
    {
        pow = (pow*alph)%prime;
    }
    
    for (int i = 0; i < n - m + 1; i++)
    {
        if (t == p)
        {
            res.push_back(i);
        }
        
        if (i < n - m)
        {
            t = ((t - text[i]*pow)%prime + prime)%prime;
            t = (t*alph)%prime;
            t = (t + text[i + m])%prime;
        }
        
    }
    return res;
}

int main(){
    string text, pat;
    cin >> text >> pat;
    vector<int> a = RabinKarp(text, pat);
    for(auto i : a){
        cout << i << ' ';
    }
}