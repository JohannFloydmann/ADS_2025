#include <iostream>
using namespace std;

int main(){

    int compNum;
    cin >> compNum;
    int comps[compNum];
    for (int i = 0; i < compNum; i++)
    {
        cin >> comps[i];
    }
    
    int rounds;
    cin >> rounds;
    int powers[rounds];
    for (int i = 0; i < rounds; i++)
    {
        cin >> powers[i];
    }
    
    int wins[rounds] = {0};
    int powerSums[rounds] = {0};
    for (int round = 0; round < rounds; round++)
    {
        for (int comp = 0; comp < compNum; comp++)
        {
            if (comps[comp] <= powers[round])
            {
                wins[round]++;
                powerSums[round] += comps[comp];
            }
            
        }
        cout << wins[round] << ' ' << powerSums[round] << endl;
    }
    

    return 0;
}