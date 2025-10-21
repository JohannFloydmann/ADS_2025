#include <iostream>
using namespace std;

char vowels[] = {'a', 'e', 'i', 'o', 'u'};
bool inVowels(char a){
    int left = 0;
    int right = 4;
    while (left <= right)
    {
        int middle = (left+right)/2;
        if (vowels[middle] == a)
        {
            return true;
        }
        
        if (a > vowels[middle])
        {
            left = ++middle;
        }
        if (a < vowels[middle])
        {
            right = middle-1;
        }
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    string vowels;
    string cons;
    for (int i = 0; i < n; i++)
    {
        if(inVowels(str[i])) vowels.push_back(str[i]);
        else cons.push_back(str[i]);
    }
    
    
    return 0;
}