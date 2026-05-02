// Step 1 - 3: Definisi Queue Utama
class Queue {
    constructor(maxSize = 10) {
        this.items = [];
        this.maxSize = maxSize;
        this.counter = 0;
    }
    get size() { return this.items.length; }
    get isEmpty() { return this.items.length === 0; }
    get isFull() { return this.items.length >= this.maxSize; }

    enqueue(customer) {
        if (this.isFull) {
            return { success: false, msg: "Antrean penuh!" };
        }
        const ticket = {
            id: ++this.counter,
            name: customer,
            time: new Date().toLocaleTimeString(),
            serviceTime: Math.floor(Math.random() * 5) + 1 // 1-5 detik untuk simulasi
        };
        this.items.push(ticket);
        return { success: true, ticket };
    }

    dequeue() {
        if (this.isEmpty) {
            return { success: false, msg: "Antrean kosong!" };
        }
        const customer = this.items.shift();
        return { success: true, customer };
    }

    peek() {
        if (this.isEmpty) return null;
        return this.items[0];
    }
}

// Step 4: Sistem Loket dengan sistem Callback
class ServiceCounter {
    constructor(id) {
        this.id = id;
        this.currentCustomer = null;
        this.busy = false;
    }
    
    serve(customer, onComplete) {
        this.currentCustomer = customer;
        this.busy = true;
        
        setTimeout(() => {
            this.busy = false;
            this.currentCustomer = null;
            if(onComplete) onComplete(this.id);
        }, customer.serviceTime * 1000); 
    }
}

// --- IMPLEMENTASI SISTEM SIMULASI ---
class CustomerServiceSystem {
    constructor() {
        this.queue = new Queue(15);
        this.counters = [
            new ServiceCounter(1),
            new ServiceCounter(2),
            new ServiceCounter(3)
        ];
    }

    // Aksi: Ambil Tiket
    ambilTiket(namaPelanggan) {
        const result = this.queue.enqueue(namaPelanggan);
        if (result.success) {
            console.log(`[TIKET] ${namaPelanggan} masuk antrean. (Tiket #${result.ticket.id}, Estimasi layanan: ${result.ticket.serviceTime} detik)`);
            this.autoServe(); // Langsung coba layani jika ada loket kosong
        } else {
            console.log(`[GAGAL] ${result.msg}`);
        }
        this.cetakStatus();
    }

    // Aksi: Auto-Serve (Mengecek antrean dan loket kosong)
    autoServe() {
        if (this.queue.isEmpty) return;

        for (let i = 0; i < this.counters.length; i++) {
            const loket = this.counters[i];
            
            if (!loket.busy && !this.queue.isEmpty) {
                const popResult = this.queue.dequeue();
                
                if (popResult.success) {
                    const customer = popResult.customer;
                    console.log(`\n[PANGGILAN] Tiket #${customer.id} (${customer.name}) silakan menuju Loket ${loket.id}`);
                    
                    loket.serve(customer, (idLoket) => {
                        console.log(`\n[SELESAI] Loket ${idLoket} telah selesai melayani Tiket #${customer.id}.`);
                        this.autoServe();
                        this.cetakStatus();
                    });
                }
            }
        }
    }

    // Tampilan Status Live
    cetakStatus() {
        console.log("-----------------------------------------");
        console.log(`Antrean Menunggu: ${this.queue.size} orang`);
        this.counters.forEach(loket => {
            const status = loket.busy ? `Melayani Tiket #${loket.currentCustomer.id}` : "Kosong";
            console.log(`Loket ${loket.id} : ${status}`);
        });
        console.log("-----------------------------------------\n");
    }
}

const csSystem = new CustomerServiceSystem();

console.log("=== SISTEM CUSTOMER SERVICE READY ===");

// Simulasi pelanggan datang secara berurutan
csSystem.ambilTiket("Andi");
csSystem.ambilTiket("Budi");
csSystem.ambilTiket("Citra");

// Pelanggan ke-4 dan ke-5 datang beberapa detik kemudian
setTimeout(() => {
    csSystem.ambilTiket("Dewi");
    csSystem.ambilTiket("Eka");
}, 2000);