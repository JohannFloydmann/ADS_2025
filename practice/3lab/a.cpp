#include <iostream>
using namespace std;

int binary_search(int* arr, int beg, int end, int key){
    int mid = (beg+end)/2;

    if(key == arr[mid]){
        return mid;
    }


    if (beg < end){
        if(key < arr[mid]){
            return binary_search(arr, mid+1, end, key);
        }
        else{
            return binary_search(arr, beg, mid-1, key);
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int find[n];
    for (int i = 0; i < n; i++)
    {
        cin >> find[i];
    }

    int rows, columns;
    cin >> rows >> columns;
    int snake[rows * columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i%2==0)
            {
                cin >> snake[columns * i + j];
            }
            else{
                cin >> snake[columns * i + columns - j - 1];
            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        int p = binary_search(snake, 0, rows*columns-1, find[i]);
        int row = p/columns;
        int column = row%2==0 ? p%columns : columns - 1 - (p%columns);

        if (column == -1)
        {
            cout << -1 << endl;
            continue;
        }
        

        cout << row << ' ' << column << endl;
    }
    
    
    

    return 0;
}
