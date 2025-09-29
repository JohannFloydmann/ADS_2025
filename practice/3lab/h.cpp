#include <iostream>
using namespace std;

int main()
{

    int blocks, m;
    cin >> blocks >> m;
    int lines[blocks];
    int ends[blocks];

    int answers[m];

    for (int i = 0; i < blocks; i++)
    {
        cin >> lines[i];
        i == 0 ? ends[i] = lines[i] : ends[i] = lines[i] + ends[i - 1];
    }

    int mistakes[m];
    for (int i = 0; i < m; i++)
    {
        cin >> mistakes[i];
    }

    for (int i = 0; i < m; i++)
    {
        int left = 0;
        int right = blocks;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (mistakes[i] > ends[mid])
            {
                left = mid+1;
            }
            else if (mistakes[i] <= ends[mid])
            {
                answers[i] = mid;
                right = mid;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << answers[i] +1 << endl;
    }
    

    return 0;
}
