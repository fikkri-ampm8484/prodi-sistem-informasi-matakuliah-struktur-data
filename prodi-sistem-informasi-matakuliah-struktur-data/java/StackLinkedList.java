public class StackLinkedList<T> {

    private class Node {
        T data;
        Node next;
        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node top;
    private int size;

    public StackLinkedList() {
        top = null;
        size = 0;
    }

    public void push(T value) {
        Node newNode = new Node(value);
        newNode.next = top;
        top = newNode;
        size++;
    }

    public T pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack Underflow!");
        }
        T value = top.data;
        top = top.next;
        size--;
        return value;
    }

    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("Stack kosong!");
        }
        return top.data;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public static void main(String[] args) {
        StackLinkedList<String> stack = new StackLinkedList<>();
        stack.push("Buku 1");
        stack.push("Buku 2");
        stack.push("Buku 3");

        System.out.println("Peek: " + stack.peek());
        System.out.println("Pop: " + stack.pop());
        System.out.println("Peek setelah Pop: " + stack.peek());
    }
}