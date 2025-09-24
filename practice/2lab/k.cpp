#include <iostream>
using namespace std;

#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class Queue
{
private:
    int *data;
    int size;
    int head;
    int tail;
    bool full;

public:
    bool empty;
    Queue(int GivenSize)
    {
        size = GivenSize *2;
        data = new int[size];
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

    void enqueue(int value)
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

    int getTop(){
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
            cout << data[i] << ' ';

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

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int num;
        cin >> num;
        int freq[1000] = {0};
        Queue<char> q(num);
        for (int i = 0; i < num; i++)
        {
            char ch;
            cin >> ch;
            freq[int(ch)] = freq[int(ch)] + 1;
            q.enqueue(ch);

            while(!q.empty && freq[q.getTop()] > 1){
                q.dequeue();
            }

            if (q.empty)
            {
                cout << -1 << " ";
            }
            else{
                cout << char(q.getTop()) << ' ';
            }
        }
        cout << endl;
    }
    
    return 0;
}