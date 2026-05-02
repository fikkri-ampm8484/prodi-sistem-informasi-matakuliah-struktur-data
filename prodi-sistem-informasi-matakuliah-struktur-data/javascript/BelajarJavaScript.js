// ==========================================
// 1. REGULAR QUEUE
// ==========================================
class Queue {
    constructor(maxSize = 100) {
        this.items = [];
        this.maxSize = maxSize;
    }

    enqueue(item) {
        if (this.items.length >= this.maxSize) {
            throw new Error("Queue Overflow");
        }
        this.items.push(item);
    }

    dequeue() {
        if (this.isEmpty()) {
            throw new Error("Queue Underflow");
        }
        return this.items.shift();
    }

    peek() { 
        return this.isEmpty() ? null : this.items[0]; 
    }
    
    isEmpty() { 
        return this.items.length === 0; 
    }
    
    size() { 
        return this.items.length; 
    }
}

// ==========================================
// 2. CIRCULAR QUEUE
// ==========================================
class CircularQueue {
    constructor(maxSize) {
        this.maxSize = maxSize;
        this.items = new Array(maxSize).fill(null);
        this.front = -1;
        this.rear = -1;
        this.count = 0;
    }

    enqueue(item) {
        if (this.isFull()) return false;
        if (this.front === -1) this.front = 0;
        this.rear = (this.rear + 1) % this.maxSize;
        this.items[this.rear] = item;
        this.count++;
        return true;
    }

    dequeue() {
        if (this.isEmpty()) return null;
        const item = this.items[this.front];
        this.items[this.front] = null;
        this.count--;
        if (this.count === 0) {
            this.front = -1; 
            this.rear = -1;
        } else {
            this.front = (this.front + 1) % this.maxSize;
        }
        return item;
    }

    isFull() { return this.count === this.maxSize; }
    isEmpty() { return this.count === 0; }
}

// ==========================================
// 3. PRIORITY QUEUE
// ==========================================
class PriorityQueue {
    constructor() { 
        this.items = []; 
    }

    enqueue(item, priority) {
        const element = { item, priority };
        let added = false;
        
        for (let i = 0; i < this.items.length; i++) {
            if (element.priority < this.items[i].priority) {
                this.items.splice(i, 0, element);
                added = true; 
                break;
            }
        }
        if (!added) this.items.push(element);
    }

    dequeue() {
        if (this.isEmpty()) return null;
        return this.items.shift().item;
    }

    isEmpty() { return this.items.length === 0; }
}

// ==========================================
// MAIN PROGRAM
// ==========================================

console.log("--- 1. TEST REGULAR QUEUE ---");
const q = new Queue(5);
q.enqueue("A");
q.enqueue("B");
console.log("Keluar:", q.dequeue());
console.log("");

console.log("--- 2. TEST CIRCULAR QUEUE ---");
const cq = new CircularQueue(3);
cq.enqueue(10);
cq.enqueue(20);
cq.enqueue(30);
console.log("Daftar Array:", cq.items);
console.log("Hapus:", cq.dequeue());
cq.enqueue(40);
console.log("Daftar Array Terbaru:", cq.items);
console.log("");

console.log("--- 3. TEST PRIORITY QUEUE ---");
const pq = new PriorityQueue();
pq.enqueue("Pasien Urgent", 2);
pq.enqueue("Pasien Gawat Darurat", 1);
pq.enqueue("Pasien Biasa", 3);

while (!pq.isEmpty()) {
    console.log("Proses:", pq.dequeue());
}