import java.util.PriorityQueue;
import java.util.Comparator;

// === 1. STANDARD LINEAR QUEUE ===
class StandardQueue<T> {
    private Object[] items;
    private int front, rear, capacity;

    public StandardQueue(int size) {
        this.capacity = size;
        this.items = new Object[capacity];
        this.front = 0;
        this.rear = -1;
    }

    public void enqueue(T item) {
        if (rear == capacity - 1) {
            throw new RuntimeException("Queue Overflow: Antrean penuh (tidak melingkar)");
        }
        items[++rear] = item;
    }

    @SuppressWarnings("unchecked")
    public T dequeue() {
        if (isEmpty()) throw new RuntimeException("Queue Underflow: Antrean kosong");
        T item = (T) items[front];
        front++;
        return item;
    }

    public boolean isEmpty() {
        return front > rear;
    }
}

// === 2. CIRCULAR QUEUE (Berdasarkan kode Anda) ===
class CircularQueue<T> {
    private Object[] items;
    private int front, rear, count, capacity;

    public CircularQueue(int size) {
        this.capacity = size;
        this.items = new Object[capacity];
        this.front = 0; 
        this.rear = -1; 
        this.count = 0;
    }

    public void enqueue(T item) {
        if (isFull()) throw new RuntimeException("Circular Queue Overflow");
        rear = (rear + 1) % capacity;
        items[rear] = item;
        count++;
    }

    @SuppressWarnings("unchecked")
    public T dequeue() {
        if (isEmpty()) throw new RuntimeException("Circular Queue Underflow");
        T item = (T) items[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    @SuppressWarnings("unchecked")
    public T peek() {
        if (isEmpty()) return null;
        return (T) items[front];
    }

    public boolean isEmpty() { return count == 0; }
    public boolean isFull() { return count == capacity; }
    public int size() { return count; }
}

// === 3. PRIORITY QUEUE (Model Pasien) ===
class Patient {
    String name;
    int priority;

    Patient(String name, int priority) {
        this.name = name;
        this.priority = priority;
    }

    @Override
    public String toString() {
        return "[Pasien: " + name + " | Prioritas: " + priority + "]";
    }
}

public class BelajarJava {
    public static void main(String[] args) {
        System.out.println("=== TEST STANDARD QUEUE ===");
        StandardQueue<Integer> sq = new StandardQueue<>(3);
        sq.enqueue(10);
        sq.enqueue(20);
        sq.enqueue(30);
        System.out.println("Dequeue: " + sq.dequeue());
        // sq.enqueue(40); // Jika ini di-uncomment akan ERROR Overflow, walau ada slot kosong di depan.

        
        System.out.println("\n=== TEST CIRCULAR QUEUE ===");
        CircularQueue<String> cq = new CircularQueue<>(3);
        cq.enqueue("A");
        cq.enqueue("B");
        cq.enqueue("C");
        System.out.println("Dequeue: " + cq.dequeue());
        cq.enqueue("D");
        System.out.println("Peek antrean terdepan: " + cq.peek());
        
        
        System.out.println("\n=== TEST PRIORITY QUEUE ===");
        PriorityQueue<Patient> pq = new PriorityQueue<>(
            Comparator.comparingInt(p -> p.priority)
        );
        
        pq.offer(new Patient("Budi (Flu Biasa)", 3));
        pq.offer(new Patient("Siti (Serangan Jantung)", 1));
        pq.offer(new Patient("Andi (Patah Tulang)", 2));

        while (!pq.isEmpty()) {
            System.out.println("Memproses: " + pq.poll());
        }
    }
}