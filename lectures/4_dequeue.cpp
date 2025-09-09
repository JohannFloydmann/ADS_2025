#include <iostream>
using namespace std;

class Dequeue
{
private:
    int *data;
    int size;
    int head;
    int tail;
    bool full;
    bool empty;

public:
    Dequeue(int size)
    {
        data = new int[size];
        this->size = size;

        head = 0;
        tail = 0;

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

    void front_enqueue(int value)
    {
        empty = false;

        if (!full)
        {
            if(head == 0){
                head = size-1;
            }
            else{
                head--;
            }
            data[head] = value;

            if(head == tail){
                full = true;
            }
        }
        else
        {
            cout << "queue is full" << endl;
        }
    }

    int front_dequeue()
    {
        full = false;

        int x = INT_MIN;

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

    int back_dequeue()
    {
        full = false;

        int x = INT_MIN;

        if (!empty)
        {
            if (tail == 0)
            {
                tail = size-1;
            }
            else{
                tail--;
            }
            x = data[tail];

            if(tail == head){
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
    Queue s(10);
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.print();
    return 0;
}