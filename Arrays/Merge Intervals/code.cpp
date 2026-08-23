vector<vector<int>> merge(vector<vector<int>>& intervals) {

    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    // Add the first interval
    result.push_back(intervals[0]);

    // Process remaining intervals
    for (int i = 1; i < intervals.size(); i++) {

        // If current interval overlaps with the last merged interval
        if (result.back()[1] >= intervals[i][0]) {

            // Extend the end of the merged interval
            result.back()[1] =
                max(result.back()[1], intervals[i][1]);
        }
        else {

            // No overlap, add as a new interval
            result.push_back(intervals[i]);
        }
    }

    return result;
}


Time Complexity: O(N log N)

Sorting: O(N log N)
Traversing intervals: O(N)
Overall: O(N log N)

Space Complexity: O(N)

result can contain up to N intervals.
Sorting itself may use additional implementation-dependent stack/buffer space.


First, I sort the intervals by their starting points. Then I keep the last interval in the result as the current merged interval. If its end is greater than or equal to the next interval's start, they overlap, so I extend the current end using max(). Otherwise, I add the next interval separately.



/*
  What is vector<vector<int>>?

Think of it as a vector containing multiple integer vectors.

For:

vector<vector<int>> intervals = {
    {1, 3},
    {2, 6},
    {8, 10},
    {15, 18}
};

Internally, visualize it like a table:

intervals
   ↓
┌─────────────┐
│ {1, 3}      │ ← intervals[0]
│ {2, 6}      │ ← intervals[1]
│ {8, 10}     │ ← intervals[2]
│ {15, 18}    │ ← intervals[3]
└─────────────┘

Each intervals[i] is itself a vector<int>.

So:

intervals[0]

gives:

{1, 3}

And then:

intervals[0][0] → 1
intervals[0][1] → 3

Therefore:

intervals[i][0] → start
intervals[i][1] → end
2. What is result?

We create:

vector<vector<int>> result;

Initially:

result = []

Then:

result.push_back(intervals[0]);

So:

result = {{1,3}}

Visualize:

result
   ↓
┌──────────┐
│ {1, 3}   │
└──────────┘
    ↑
 result[0]
3. What does result.back() mean?

back() means:

Give me the last element of the vector.

So:

result.back()

means:

the last interval currently stored in result

Initially:

result = {{1,3}}

Therefore:

result.back()

is:

{1,3}

And:

result.back()[0]

is:

1

while:

result.back()[1]

is:

3

So:

result.back()[1]
        ↓
      {1,3}
         ↓
         3

That's why:

result.back()[1] >= intervals[i][0]

means:

current interval's END >= next interval's START
4. What is intervals[i][1]?

Suppose:

i = 1;

Then:

intervals[i]

means:

intervals[1]

which is:

{2,6}

Therefore:

intervals[i][0] → 2
intervals[i][1] → 6

So:

intervals[i][1]

means:

End of the current interval we're processing.*/
