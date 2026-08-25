int lengthOfLongestSubstring(string s) {
    int left = 0, maxLength = 0;
    unordered_map<char, int> mp;
    for(int i=0;i<s.length();i++){
        if(mp.find(s[i]) != mp.end() && mp[s[i]] >= left){
            left = mp[s[i]] + 1;
        }
        mp[s[i]] = i;
        maxLength = max(maxLength, i-left + 1);        
    }
    return maxLength;
}

O(N)
O(1)
