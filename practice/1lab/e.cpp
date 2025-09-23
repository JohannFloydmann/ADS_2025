#include <iostream>
using namespace std;


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

void Won(Queue &q, int b, int n, string name){
    q.enqueue(b);
    q.enqueue(n);
}

int main() {
    Queue boris(5);
    Queue nurik(5);
    unsigned int count = 0;

    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        boris.enqueue(temp);
    }

    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        nurik.enqueue(temp);
    }
    
    while (!boris.empty && !nurik.empty)
    {
        count++;
        if(count >= 1000000){
            cout << "blin nichya";
            return 0;
        }
        int b = boris.dequeue();
        int n = nurik.dequeue();
        
        if (b == 0 && n == 9)
        {
            Won(boris, b, n, "Boris");
        }
        else if (b == 9 && n == 0){
            Won(nurik, b, n, "Nurik");
        }
        else if (b>n)
        {
            Won(boris, b, n, "Boris");
        }
        else{
            Won(nurik, b, n, "Nurik");
        }
        
        
        
    }
    
    if(nurik.empty){
        cout << "Boris" << ' ' << count;
    }
    else if(boris.empty){
        cout << "Nursik" << ' ' << count;
    }


    return 0;
}