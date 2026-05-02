import heapq
from collections import deque

# === 1. REGULAR QUEUE (FIFO) ===
class Queue:
    def __init__(self, max_size=100):
        self.items = deque()
        self.max_size = max_size

    def enqueue(self, item):
        if len(self.items) >= self.max_size:
            raise Exception("Queue Overflow")
        self.items.append(item)

    def dequeue(self):
        if self.is_empty():
            raise Exception("Queue Underflow")
        return self.items.popleft()

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

# === 2. CIRCULAR QUEUE ===
class CircularQueue:
    def __init__(self, max_size):
        self.max_size = max_size
        self.items = [None] * max_size
        self.front = -1
        self.rear = -1
        self.count = 0

    def enqueue(self, item):
        if self.is_full():
            print("Circular Queue Full!")
            return False
        if self.front == -1:
            self.front = 0
        self.rear = (self.rear + 1) % self.max_size
        self.items[self.rear] = item
        self.count += 1
        return True

    def dequeue(self):
        if self.is_empty():
            return None
        item = self.items[self.front]
        self.items[self.front] = None
        self.count -= 1
        if self.count == 0:
            self.front = -1
            self.rear = -1
        else:
            self.front = (self.front + 1) % self.max_size
        return item

    def is_full(self):
        return self.count == self.max_size

    def is_empty(self):
        return self.count == 0

# === 3. PRIORITY QUEUE ===
class PriorityQueue:
    def __init__(self):
        self.items = []
        self.counter = 0

    def enqueue(self, item, priority):
        heapq.heappush(self.items, (priority, self.counter, item))
        self.counter += 1

    def dequeue(self):
        if self.is_empty():
            return None
        return heapq.heappop(self.items)[2]

    def is_empty(self):
        return len(self.items) == 0

# === MAIN PROGRAM (Fungsi Pengetesan) ===
def main():
    print("=== TEST REGULAR QUEUE ===")
    q = Queue(max_size=3)
    q.enqueue("10")
    q.enqueue("20")
    print(f"Dequeue: {q.dequeue()}")
    print("-" * 30)

    print("=== TEST CIRCULAR QUEUE ===")
    cq = CircularQueue(3)
    cq.enqueue(10)
    cq.enqueue(20)
    cq.enqueue(30)
    print(f"Dequeue: {cq.dequeue()}")
    cq.enqueue(40)  # Bisa masuk karena slot pertama sudah kosong (circular)
    print(f"Status Array: {cq.items}")
    print("-" * 30)

    print("=== TEST PRIORITY QUEUE ===")
    pq = PriorityQueue()
    pq.enqueue("Pasien Biasa", 3)
    pq.enqueue("Pasien Gawat Darurat", 1)
    pq.enqueue("Pasien Urgent", 2)
    
    while not pq.is_empty():
        print(f"Melayani: {pq.dequeue()}")

if __name__ == "__main__":
    main()