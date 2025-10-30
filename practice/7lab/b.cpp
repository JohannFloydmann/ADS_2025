#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    int ar[a];
    for (int i = 0; i < a; i++)
    {
        cin >> ar[i];
    }

    int b;
    cin >> b;
    int br[b];
    for (int i = 0; i < b; i++)
    {
        cin >> br[i];
    }
    
    int ans[a+b];
    int i, j, k;
    i = j = k = 0;
    while(k < a+b){
        if(i < a && (j >= b || ar[i] < br[j])){
            ans[k] = ar[i];
            i++;
            k++;
        }
        else{
            ans[k] = br[j];
            j++;
            k++;
        }
    }
    
    for (int i = 0; i < a+b; i++)
    {
        cout << ans[i] << ' ';
    }
    
    return 0;
}