#include <iostream>
#include <cmath>
using namespace std;


int rolypoly(string s,int prime,int size){
            int h = (int)s[0];
            int alphabeth_size = 256;
            for (int i = 1; i < size; i++)
            {
                h = ((h * alphabeth_size)%prime + (int)s[i])%prime;
            }
            return h;
}

bool check(string text, string pat, int i){
    for (int j = 0; j < pat.size(); j++)
    {
        if(text[i+j] != pat[j])
            return false;
    }
    return true;
}


int RabinKarp(string text, string pat, int hash_size){
    //variable that stores hash of text
    int t = rolypoly(text,hash_size,pat.size());

    //variable that stores hash of pat
    int p = rolypoly(pat,hash_size,pat.size());


    int pow = 1;
    int alphabeth = 256;

    for (int i = 0; i < pat.size()-1; i++)
    {
        pow = (pow*alphabeth)%hash_size;
    }
    
    cout<<"p:"<<p<<endl;

    for (int i = 0; i < text.size()-pat.size()+1; i++)
    {
        cout<<"t:"<<t<<endl;
        if(t==p){
            if(check(text,pat,i)){
                return i;
            }
        }

        //substract, multiply, add for the next hash

        t = (t - (int)text[i]*pow)%hash_size;//substract
        if(t<0)
            t = (t+hash_size)%hash_size;
        t = (t*alphabeth)%hash_size;//multiply
        t = (t+(int)text[i+pat.size()])%hash_size;//addition
    }

    return -1;
}


int main(){
    string text = "this is a long string";
    string pat = "string";


    cout<<check(text,pat,0)<<" "<<check(text,pat,1)<<endl;
    cout<<RabinKarp(text,pat,101);
}