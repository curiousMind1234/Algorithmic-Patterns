vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    vector<int> res;

    // Count frequency
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    // Store {frequency, number}
    for (auto i : mp) {
        pq.push({i.second, i.first});
    }

    // Get top k
    for (int i = 0; i < k; i++) {
        int elem = pq.top().second;
        pq.pop();
        res.push_back(elem);
    }

    return res;
}

Complexity

Let N = number of elements and U = number of unique elements.

Frequency counting → O(N)
Inserting U elements into heap → O(U log U)
Popping K elements → O(K log U)

Overall:
Time: O(N + U log U + K log U)
Since U ≤ N, commonly simplified to:
O(N log N)
Space: O(U)

"I use an unordered_map to count frequencies. Then I insert {frequency, number} pairs into a max heap. Since the priority queue compares the first element of the pair first, the highest-frequency number stays at the top. I pop K elements to get the answer."

