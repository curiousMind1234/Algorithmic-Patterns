int longestConsecutive(vector<int>& nums) {

    unordered_set<int> st(nums.begin(), nums.end());

    int maxLength = 0;

    for (int num : nums) {

        if (st.find(num - 1) == st.end()) {

            int current = num;
            int length = 1;

            while (st.find(current + 1) != st.end()) {
                current++;
                length++;
            }

            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}
Time  = O(N) average
Space = O(N)

