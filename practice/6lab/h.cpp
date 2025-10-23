#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    char letters[n];

    for (int i = 0; i < n; i++)
    {
        cin >> letters[i];
    }
    char letter;
    cin >> letter;

    for (int i = 0; i < n; i++)
    {
        if(letters[i] > letter){
            cout << letters[i];
            return 0;
        }
    }
    cout << letters[0];

    return 0;
}