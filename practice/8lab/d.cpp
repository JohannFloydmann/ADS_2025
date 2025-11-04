#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Queue
{
private:
    T *data;
    int size;
    int head;
    int tail;
    bool full;

public:
    bool empty;
    Queue(int GivenSize)
    {
        size = GivenSize * 2;
        data = new T[size];
        this->size = size;

        head = 0;
        tail = 0;

        full = false;
        empty = true;
    }

    ~Queue()
    {
        delete[] data;
    }
    void clear()
    {
        head = 0;
        tail = 0;

        full = false;
        empty = true;
    }
    void enqueue(T value)
    {
        empty = false;

        if (!full)
        {
            data[tail] = value;
            if (tail == size - 1)
            {
                tail = 0;
            }
            else
            {
                tail++;
            }
            if (tail == head)
            {
                full = true;
            }
        }
        else
        {
            cout << "queue is full" << endl;
        }
    }

    int getTop()
    {
        return data[head];
    }

    int dequeue()
    {
        full = false;

        int x = -2147483647;

        if (!empty)
        {
            x = data[head];
            if (head == size - 1)
            {
                head = 0;
            }
            else
            {
                head++;
            }
            if (tail == head)
            {
                empty = true;
            }
        }
        else
        {
            cout << "the queue is empty" << endl;
        }
        return x;
    }

    void print()
    {
        int i = head;
        while (i != tail)
        {
            cout << data[i] << endl;

            if (i == size - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }
    }
};

int rolypoly(const string &s, int prime, int size)
{
    int h = 0;
    const int alphabeth_size = 256;
    for (int i = 0; i < size; i++)
    {
        h = (h * alphabeth_size + (unsigned char)s[i]) % prime;
    }
    return h;
}

int RabinKarp(const string &text1, const string &pat, int hash_size)
{
    int count = 0;

    int t1 = rolypoly(text1, hash_size, pat.size());
    int p = rolypoly(pat, hash_size, pat.size());

    int pow = 1;
    const int alphabeth = 256;

    for (int i = 0; i < pat.size() - 1; i++)
    {
        pow = (pow * alphabeth) % hash_size;
    }

    for (int i = 0; i <= text1.size() - pat.size(); i++)
    {
        if (t1 == p)
            count++;

        // Update hash only if there is another window
        if (i < text1.size() - pat.size())
        {
            // Update hash for first text
            t1 = (t1 - (unsigned char)text1[i] * pow) % hash_size;
            if (t1 < 0)
                t1 += hash_size;
            t1 = (t1 * alphabeth + (unsigned char)text1[i + pat.size()]) % hash_size;
        }
    }

    return count;
}

int main()
{

    while (true)
    {
        int n;
        cin >> n;
        if(n==0) break;

        string pats[n];
        for (int i = 0; i < n; i++)
        {
            cin >> pats[i];
        }
        string text;
        cin >> text;

        Queue<string> q(n);
        int curMax = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = RabinKarp(text, pats[i], 10001);
            if (cur == curMax)
            {
                q.enqueue(pats[i]);
            }
            else if (cur > curMax)
            {
                curMax = cur;
                q.clear();
                q.enqueue(pats[i]);
            }
        }
        cout << curMax << endl;
        q.print();
    }
}
