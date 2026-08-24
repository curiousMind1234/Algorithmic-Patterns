class MinStack {
    stack<pair<int, int>> st;

public:
    void push(int val) {
        int currentMin = st.empty()
            ? val
            : min(val, st.top().second);

        st.push({val, currentMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

Complexity
Operation	Time
push()	O(1)
pop()	O(1)
top()	O(1)
getMin()	O(1)

