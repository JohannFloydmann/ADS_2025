#include <iostream>
using namespace std;

int main()
{

    int len, q;
    cin >> len >> q;

    int c[len];
    int query[q][4];
    int answers[q] = {0};

    for (int i = 0; i < len; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> query[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {

        for (int j = 0; j < len; j++)
        {
            if ((c[j] >= query[i][0] && c[j] <= query[i][1]) || (c[j] >= query[i][2] && c[j] <= query[i][3]))
            {
                answers[i]++;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << answers[i] << endl;
    }

    return 0;
}