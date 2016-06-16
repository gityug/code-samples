// https://leetcode.com/problems/min-stack/
//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
//

class MinStack {
    vector<int> s;
    vector<int> s1;
    
public:
    void push(int x) {
        s.push_back(x);
        if (s1.empty()) s1.push_back(x);
        else {
            if (x < s1.back()) s1.push_back(x);
            else s1.push_back(s1.back());
        }
    }

    void pop() {
        if (!s1.empty()) {
            s.pop_back();
            s1.pop_back();
        }
    }

    int top() {
        return s.back();
    }

    int getMin() {
        return s1.back();
    }
};
