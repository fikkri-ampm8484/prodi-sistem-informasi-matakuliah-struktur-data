public class StackArray {
    private int[] data;
    private int top;
    private int capacity;

    public StackArray(int capacity) {
        this.capacity = capacity;
        this.data = new int[capacity];
        this.top = -1;
    }

    public void push(int value) {
        if (top == capacity - 1) {
            throw new RuntimeException("Stack Overflow!");
        }
        data[++top] = value;
    }

    public int pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack Underflow!");
        }
        return data[top--];
    }

    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Stack kosong!");
        }
        return data[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public int size() {
        return top + 1;
    }

    public static void main(String[] args) {
        StackArray stack = new StackArray(6);
        stack.push(33);
        stack.push(36);
        stack.push(39);
        System.out.println("Peek: " + stack.peek());
        System.out.println("Size: " + stack.size());
        System.out.println("Pop: " + stack.pop());
        System.out.println("Peek: " + stack.peek());
        System.out.println("IsEmpty: " + stack.isEmpty());
    }
}