int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        }
        else if (num == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return candidate;
}

Time: O(N)
Space: O(1)



Dry run

Start:

candidate = ?
count = 0
i	nums[i]	Action	candidate	count
0	2	count was 0 → candidate = 2	2	1
1	2	same → count++	2	2
2	1	different → count--	2	1
3	1	different → count--	2	0
4	1	count = 0 → candidate = 1	1	1
5	2	different → count--	1	0
6	2	count = 0 → candidate = 2	2	1

So final:

candidate = 2
count = 1


count represents the balance after cancelling different elements, not how many times the candidate appears.

Because the problem guarantees that a majority element exists, we can simply return:

return candidate;
