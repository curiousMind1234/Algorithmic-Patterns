void rotateArray(vector<int>& arr, int k)
{
    int n = arr.size();

    if (n == 0)
        return;

    k = k % n;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

For:

arr = [1,2,3,4,5]
k = 2

Output:

[4,5,1,2,3]

Time: O(n)
Space: O(1)
