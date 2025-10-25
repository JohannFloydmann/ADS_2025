#include <iostream>
#include <queue>

using namespace std;
int main(){
    int n;
    cin >> n;
    deque<int> d;
    for (int i = 0; i < n; i++)
    {
        int ping;
        cin >> ping;
        d.emplace_front(ping);
        while (d.front()-d.back() > 3000)
        {
            d.pop_back();
        }
        int count = 0;
        for(deque<int>::iterator it = d.begin(); it != d.end(); ++it){
            count++;
        }
        cout << count << ' ';
    }
    
    return 0;
}