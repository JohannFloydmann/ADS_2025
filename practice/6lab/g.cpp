#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, string> names;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string oldName, newName;
        cin >> oldName >> newName;
        bool found = false;
        for (map<string, string>::iterator it = names.begin(); it != names.end(); it++)
        {
            if (it->second == oldName)
            {
                it->second = newName;
                found = true;
            }
        }

        if(!found)
        {
            names.emplace(oldName, newName);
            count++;
        }
    }
    cout << count << endl;
    for (map<string, string>::const_iterator it = names.begin(); it != names.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}