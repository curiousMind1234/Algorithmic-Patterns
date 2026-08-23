bool validParentheses(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            s.push(str[i]);
        }

        if (str[i] == '}' || str[i] == ']' || str[i] == ')') {

            if (s.empty())
                return false;

            if ((str[i] == '}' && s.top() == '{') ||
                (str[i] == ']' && s.top() == '[') ||
                (str[i] == ')' && s.top() == '(')) {

                s.pop();
            }
            else {
                return false;
            }
        }
    }

    return s.empty();
}

TC = O(N)
SC = O(N)
