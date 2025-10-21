#include <iostream>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
    string str;
};
bool isSmaller(Date first, Date second){
    if (first.year != second.year) return first.year < second.year;
    if (first.month != second.month) return first.month < second.month;
    return first.day < second.day;
}

void merge(Date *arr, int beg, int mid, int end){
    int left_len = mid - beg + 1;
    int right_len = end - mid;
    Date* left = new Date[left_len];
    Date* right = new Date[right_len];
    
    for (int i = 0; i < left_len; i++)
    {
        left[i] = arr[beg + i];
    }
    for (int i = 0; i < right_len; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int k = beg;
    while(k <= end){
        if ((i < left_len) && (j >= right_len || 
            isSmaller(left[i], right[j])))
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    delete[] left;
    delete[] right;
}

void merge_sort_rec(Date *arr, int beg, int end){
    if (beg < end)
    {
        int mid = (beg + end)/2;
        merge_sort_rec(arr, beg, mid);
        merge_sort_rec(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}

void merge_sort(Date *arr, int len){
    merge_sort_rec(arr, 0, len-1);
}


int main(){

    int n;
    cin >> n;
    Date dates[n];
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        dates[i].str = str;
        dates[i].year = stoi(str.substr(6, 4));
        dates[i].month = stoi(str.substr(3, 2));
        dates[i].day = stoi(str.substr(0, 2));
    }
    merge_sort(dates, n);
    for (int i = 0; i < n; i++)
    {
        cout << dates[i].str << endl;
    }
    
    return 0;
}