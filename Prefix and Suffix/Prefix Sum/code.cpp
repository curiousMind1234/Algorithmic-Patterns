vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> answer(n, 1);

    int product = 1;

    // Left → Right
    for (int i = 0; i < n; i++) {
        answer[i] = product;
        product *= nums[i];
    }

    // Right → Left
    product = 1;

    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= product;
        product *= nums[i];
    }

    return answer;
}


The key idea is:

answer[i] = product of elements LEFT of i
            ×
            product of elements RIGHT of i

For [1,2,3,4]:

Left products:   [1, 1, 2, 6]
Right products:  [24, 12, 4, 1]

Answer:          [24, 12, 8, 6]
For your interview revision notes
Problem: Product of Array Except Self
Pattern: Prefix & Suffix Product
Technique: Two passes
1st pass: Left → Right → store prefix product
2nd pass: Right → Left → multiply suffix product
TC: O(N)
SC: O(1) extra
