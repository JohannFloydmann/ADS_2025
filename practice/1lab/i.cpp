#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char s[200005];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int S[200005], K[200005];
    int headS = 0, tailS = 0;
    int headK = 0, tailK = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'S')
        {
            S[tailS++] = i;
        }
        else
        {
            K[tailK++] = i;
        }
    }

    // пока обе фракции живы
    while (headS < tailS && headK < tailK)
    {
        int i = S[headS++];
        int j = K[headK++];

        if (i < j)
        {
            // S ходит раньше и побеждает
            S[tailS++] = i + n;
        }
        else
        {
            // K ходит раньше и побеждает
            K[tailK++] = j + n;
        }
    }

    if (headS == tailS)
    {
        cout << "KATSURAGI";
    }
    else
    {
        cout << "SAKAYANAGI";
    }

    return 0;
}