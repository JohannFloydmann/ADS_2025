#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#include <iostream>
#include <climits>
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
    bool empty;

public:
    Queue(int size)
    {
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

    T top(){
        return data[head];
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

    T dequeue()
    {
        full = false;

        T x; // Default-constructed T (avoids INT_MIN for non-int types)

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

    void emptyQueue()
    {
        head = 0;
        tail = 0;
        full = false;
        empty = true;
    }

    void sort()
    {
        if (empty)
        {
            return;
        }

        int count = 0;
        if (head <= tail)
        {
            count = tail - head;
        }
        else
        {
            count = size - head + tail;
        }

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - 1 - i; j++)
            {
                int idx1 = (head + j) % size;
                int idx2 = (head + j + 1) % size;
                if (data[idx1] < data[idx2])
                {
                    T temp = data[idx1];
                    data[idx1] = data[idx2];
                    data[idx2] = temp;
                }
            }
        }
        tail = (head + count) % size;
        empty = (count == 0);
        full = (count == size);
    }


    void print()
    {
        if (empty)
        {
            cout << "Queue is empty" << endl;
            return;
        }

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
        cout << endl;
    }
};

int main(){
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = 0;
    }
    
    Queue<int> q(1000);

    int currModeCount = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] = arr[temp]+1;
        if (arr[temp] == currModeCount)
        {
            q.enqueue(temp);
        }

        if (arr[temp] > currModeCount)
        {
            currModeCount = arr[temp];
            q.emptyQueue();
            q.enqueue(temp);
        }
        
    }
    q.sort();
    q.print();

    return 0;
}