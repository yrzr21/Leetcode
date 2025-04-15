#include "../tools.h"

class MinStack {
   private:
    stack<int> s;
    stack<int> min_s;

   public:
    MinStack() = default;

    void push(int val) {
        if (s.empty() || min_s.top() > val) {
            min_s.push(val);
        } else {
            min_s.push(min_s.top());
        }
        s.push(val);
    }

    void pop() {
        s.pop();
        min_s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return min_s.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(int argc, char const* argv[]) {
    return 0;
}
