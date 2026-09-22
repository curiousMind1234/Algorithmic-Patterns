Find the first non-repeating character

Given:

string s = "swiss";

Return:

w

Because:

s → appears 3 times
w → appears once
i → appears once
first unique character is w
------------------------------------------------------
char firstNonRepeating(const string& s)
{
    unordered_map<char, int> mp;

    for (char c : s) {
        mp[c]++;
    }

    for (char c : s) {
        if (mp[c] == 1) {
            return c;
        }
    }

    return '\0';
}

TC: O(N)
SC: O(N)
