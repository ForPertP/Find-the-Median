int findMedian(vector<int> arr)
{
    std::sort(arr.begin(), arr.end());
    
    return arr[arr.size()/2];
}
