#include <iostream>
using namespace std;

void merge(string &a, int beg, int mid, int end){
    int left_len = mid - beg + 1;
    int right_len = end - mid;
    string left = a.substr(beg, left_len);
    string right = a.substr(mid+1, right_len);

    int i = 0;
    int j = 0;
    int k = beg;
    while (k <= end)
    {
        if ((i < left_len) && (j >= right_len ||
            int(left[i]) < int(right[j])))
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else{
            a[k] = right[j];
            j++;
            k++;
        }
    }
}

void mergeSort_rec(string &a, int beg, int end){
    if (beg < end)
    {
        int mid = (beg + end)/2;
        mergeSort_rec(a, beg, mid);
        mergeSort_rec(a, mid+1, end);
        merge(a, beg, mid, end);
    }
}

void mergeSort(string &a){
    mergeSort_rec(a, 0, a.length()-1);
}


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
    
    mergeSort(vowels);
    mergeSort(cons);

    cout << vowels << cons;

    
    return 0;
}