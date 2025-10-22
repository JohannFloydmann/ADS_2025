#include <iostream>
#include <iomanip>
using namespace std;
class GradeMap
{
private:
    GradeMap() = delete;

public:
    static float getGPA(const string &grade)
    {
        if (grade == "A+")
            return 4.00f;
        if (grade == "A")
            return 3.75f;
        if (grade == "B+")
            return 3.50f;
        if (grade == "B")
            return 3.00f;
        if (grade == "C+")
            return 2.50f;
        if (grade == "C")
            return 2.00f;
        if (grade == "D+")
            return 1.50f;
        if (grade == "D")
            return 1.00f;
        if (grade == "F")
            return 0.00f;
        return -1.0f;
    }
};

bool shouldComeFirst(const pair<string, float> &a, const pair<string, float> &b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    return a.first > b.first;
}

void merge(pair<string, float> *arr, int beg, int mid, int end)
{
    int left_len = mid - beg + 1;
    int right_len = end - mid;
    pair<string, float> *left = new pair<string, float>[left_len];
    pair<string, float> *right = new pair<string, float>[right_len];

    for (int i = 0; i < left_len; i++)
    {
        left[i] = arr[beg + i];
    }
    for (int i = 0; i < right_len; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = beg;
    while (k <= end)
    {
        if ((i < left_len) && (j >= right_len ||
                               !shouldComeFirst(left[i], right[j])))
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    delete[] left;
    delete[] right;
}

void merge_sort_rec(pair<string, float> *arr, int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        merge_sort_rec(arr, beg, mid);
        merge_sort_rec(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void merge_sort(pair<string, float> *arr, int len)
{
    merge_sort_rec(arr, 0, len - 1);
}

int main()
{
    int n;
    cin >> n;
    pair<string, float> students[n];
    for (int i = 0; i < n; i++)
    {
        string surname, name;
        cin >> surname >> name;
        string fullName = surname + ' ' + name;

        int subjects;
        cin >> subjects;
        float upper = 0;
        float lower = 0;
        for (int i = 0; i < subjects; i++)
        {
            string a;
            int c;
            cin >> a >> c;
            upper += GradeMap::getGPA(a) * c;
            lower += c;
        }
        students[i] = make_pair(fullName, float(upper / lower));
    }
    merge_sort(students, n);

    for (int i = 0; i < n; i++)
    {
        cout << students[i].first << ' ' << fixed << setprecision(3)<< students[i].second << endl;
    }
    return 0;
}