#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(string text, string pat){
    string s = pat+"#"+text;

    vector<int> pi(s.size());

    pi[0] = 0;
    int k;
    for (int i = 1; i < s.size(); i++)
    {
        k = pi[i-1];

        while(k>0){
            if(s[i]==s[k]){
                k++;
                break;
            }
            k = pi[k-1];
        }
        if(k==0 && s[i]==s[k]){
            k = 1;
        }
        pi[i] = k;
    }
    return pi;
}

void cover(string text, string pattern, bool* covered){
    vector<int> p = prefix(text,pattern);
    
    int index_found;
    for (int i = 0; i < p.size(); i++)
    {
        if(p[i]==pattern.size()){
            index_found = i-2*pattern.size();
            for (int j = 0; j < pattern.size(); j++)
            {
                covered[index_found+j] = true;
            }
            
        }
    }
    
}

bool allTrue(bool* arr, int size){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]!=true)
            return false;
    }
    return true;
}

void check(string s, bool* covered){
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<":"<<covered[i]<<";"<<endl;
    }
}

int main(){

    string text;
    int patNum;
    
    cin>>text;
    cin>>patNum;
    string* patterns = new string[patNum];

    for (int i = 0; i < patNum; i++)
    {
        cin>>patterns[i];
    }
    bool* covered = new bool[text.size()];

    for (int i = 0; i < text.size(); i++)
    {
        covered[i] = false;
    }

    for (int i = 0; i < patNum; i++)
    {
        cover(text,patterns[i],covered);
    }

    if(allTrue(covered,text.size()))
        cout<<"YES";
    else
        cout<<"NO";    
    
    
    delete[] covered;
    delete[] patterns;
    return 0;
}