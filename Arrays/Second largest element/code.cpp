int secondLargest(vector<int>& arr) {
    int largest = INT_MIN;
    int second = INT_MIN;

    for (int x : arr) {
        if (x > largest) {
            second = largest;
            largest = x;
        }
        else if (x > second && x != largest) {
            second = x;
        }
    }

    return second;
}

TC: O(N)
SC: O(1)
