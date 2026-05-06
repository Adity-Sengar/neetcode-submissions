#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<int> st;
    stack<int> minSt;

    MinStack() {

    }

    void push(int val) {

        st.push(val);

        // Push minimum so far
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {

        if(st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {

        return st.top();
    }

    int getMin() {

        return minSt.top();
    }
};