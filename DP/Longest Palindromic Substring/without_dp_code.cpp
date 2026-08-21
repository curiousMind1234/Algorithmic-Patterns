void expand(const string& s, int left, int right, string& best) {

    while (left >= 0 &&
           right < s.size() &&
           s[left] == s[right]) {

        left--;
        right++;
    }

    string current = s.substr(left + 1, right - left - 1);

    if (current.size() > best.size()) {
        best = current;
    }
}


string longestPalindrome(string s) {

    string best = "";

    for (int i = 0; i < s.size(); i++) {

        // Odd-length palindrome
        expand(s, i, i, best);

        // Even-length palindrome
        expand(s, i, i + 1, best);
    }

    return best;
}

Time  = O(n²)
Space = O(n)
