#include <iostream>
#include <vector>
using namespace std;

vector<int> makeLps(string pattern){
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0;
    for (int i = 1; i < n; i++)
    {
        if(pattern[len] == pattern[i]){
            len++;
            lps[i]++;
        }
        else if(len == 0){
            lps[i] = 0;
        }
        else{
            len = lps[len-1];
        }
    }
    return lps;
}

vector<int> search(string pat, string text){
    vector<int> lps = makeLps(pat);
    vector<int> res;
    int n = text.length();
    int m = pat.length();
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
            if (j == m)
            {
                
                res.push_back(i-j);
                j = lps[j-1];
            }
            
        }
        else{
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
    }
    
    return res;
}

int main(){
    for(auto i : search("ba", "baobab")){
        cout << i << ' ';
    }
    return 0;
}