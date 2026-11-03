package LeetCodeProblems.MinStack;

import java.util.ArrayList;
import java.util.List;

public class MinStack {

    private List<Integer> stack;
    private List<Integer> min;

    public MinStack() {
        stack = new ArrayList<>();
        min = new ArrayList<>();
    }

    public void push(int value) {
        if (stack.isEmpty() || value <= min.getLast()) {
            min.add(value);
        }
        stack.add(value);
    }

    public void pop() {
        if (stack.getLast().equals(min.getLast())) {
            min.remove(min.size() - 1);
        }
        stack.remove(stack.size() - 1);
    }

    public int top() {
        return stack.getLast();
    }

    public int getMin() {
        return min.getLast();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
