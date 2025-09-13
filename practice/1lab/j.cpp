#include <iostream>
using namespace std;

class Dequeue
{
private:
    int *data;
    int head;
    int tail;
    bool full;
    int size;

public:
    int count;
    bool empty;
    Dequeue(int size)
    {
        data = new int[size];
        this->size = size;

        head = 0;
        tail = 0;
        count = 0;

        full = false;
        empty = true;
    }

    ~Dequeue()
    {
        delete[] data;
    }

    void back_enqueue(int value)
    {
        empty = false;

        if (!full)
        {
            data[tail] = value;
            count++;
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
    }

    void front_enqueue(int value)
    {
        empty = false;
        if (!full)
        {
            if (head == 0)
            {
                head = size - 1;
            }
            else
            {
                head--;
            }
            data[head] = value;
            count++;
            if (head == tail)
            {
                full = true;
            }
        }
    }

    int front_dequeue()
    {
        full = false;

        int x = -2147483647;

        if (!empty)
        {
            x = data[head];
            count--;
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
            return 0;
        }
        return x;
    }

    int back_dequeue()
    {
        full = false;

        int x = -2147483647;

        if (!empty)
        {
            count--;
            if (tail == 0)
            {
                tail = size - 1;
            }
            else
            {
                tail--;
            }
            x = data[tail];

            if (tail == head)
            {
                empty = true;
            }
        }
        else
        {
            return 0;
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
    Dequeue deq(100000);

    char sym;
    int num;
    while (cin >> sym)
    {
        if (sym == '!')
        {
            break;
        }

        else if (sym == '+')
        {
            cin >> num;
            deq.back_enqueue(num);
        }
        else if (sym == '-')
        {
            cin >> num;
            deq.front_enqueue(num);
        }
        else if (sym == '*')
        {
            if (deq.count <= 1)
                if(deq.empty){
                    cout << "error" << endl;
                }
                else{
                    cout << deq.back_dequeue() * 2 << endl;
                }
            else
            {
                cout << deq.back_dequeue() + deq.front_dequeue() << endl;
            }
        }
    }

    return 0;
}