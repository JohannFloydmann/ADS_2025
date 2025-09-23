#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "\n";
        return;
    }

    int deck[1005]; // массив для колоды
    int size = 0;   // текущий размер колоды

    // идём от последней карты к первой
    for (int i = n; i >= 1; i--)
    {
        // вставляем карту i в начало
        for (int j = size; j > 0; j--)
            deck[j] = deck[j - 1];
        deck[0] = i;
        size++;

        // циклический сдвиг i карт с конца в начало
        for (int j = 0; j < i; j++)
        {
            if (size > 1)
            {
                int last = deck[size - 1];
                for (int k = size - 1; k > 0; k--)
                    deck[k] = deck[k - 1];
                deck[0] = last;
            }
        }
    }

    // вывод колоды
    for (int i = 0; i < size; i++)
    {
        cout << deck[i] << (i == size - 1 ? "\n" : " ");
    }
}

int main()
{
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}