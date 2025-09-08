#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findMedian' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int partition(vector<int>& arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    swap(arr[pivotIndex], arr[right]);

    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}


int findMedian(vector<int> arr) {
    srand(time(nullptr));
    int n = arr.size();
    int midIndex = n / 2;
    return quickselect(arr, 0, n - 1, midIndex);
}


int findMedian2(vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    
    return arr[arr.size()/2];
}

int quickselect(vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];

    int pivotIndex = partition(arr, left, right);

    if (pivotIndex == k) {
        return arr[pivotIndex];
    } else if (pivotIndex > k) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}


int findMedian(vector<int> arr) {
    srand(time(nullptr));
    int n = arr.size();
    int midIndex = n / 2;
    return quickselect(arr, 0, n - 1, midIndex);
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

std::vector<string> split(const string &str)
{
    vector<string> tokens;
    string_view str_view(str);
    size_t start = 0;
    size_t end = 0;

    while ((end = str_view.find(' ', start)) != string_view::npos)
    {
        if (end > start)
        {
            tokens.emplace_back(str_view.substr(start, end - start));
        }
        start = end + 1;
    }

    if (start < str_view.size())
    {
        tokens.emplace_back(str_view.substr(start));
    }

    return tokens;
}
