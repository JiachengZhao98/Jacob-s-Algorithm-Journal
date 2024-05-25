#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>
#include <vector>

std::mutex mtx;  // Mutex for synchronization

void printBlock(int n, char c) {
    mtx.lock();  // Lock mutex
    for (int i = 0; i < n; ++i) { std::cout << c; }
    std::cout << '\n';
    mtx.unlock();  // Unlock mutex
}

// A semaphore initialized to allow 3 concurrent accesses
std::counting_semaphore<3> sem(3);

void accessDatabase(int thread_id) {
    // Wait and acquire access
    sem.acquire();
    std::cout << "Thread " << thread_id << " is accessing the shared resource.\n";

    // Simulating work
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Thread " << thread_id << " is leaving the shared resource.\n";
    // Release the semaphore
    sem.release();
}

class buffer {

private:
    std::mutex mtx;
    std::condition_variable cv;
    std::queue<int> q;
    int capacity;

public:
    buffer(int capacity) {
        this->capacity = capacity;
    }

    void writer(int i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{return q.size() < this->capacity;});
        q.push(i);
        std::cout<<"writer writes "<<i<<std::endl;
        cv.notify_all();
    }

    void reader() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{return q.size() > 0;});
        int num = q.front();
        q.pop();
        std::cout<<"reader reads "<<num<<std::endl;
        cv.notify_all();
    }
};

    void write(buffer& Buffer, int num) {
        Buffer.writer(num);
    }

    void read(buffer& Buffer) {
        Buffer.reader();
    }

int main() {
    std::vector<std::thread> threads;

    // Create and start 5 threads
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(accessDatabase, i + 1);
    }

    // Join all threads
    for (auto& th : threads) {
        th.join();
    }

    return 0;
}


// int main() {
//     std::thread t1(printBlock, 500, '*');
//     std::thread t2(printBlock, 500, '#');

//     t1.join();
//     t2.join();

//     return 0;
// }
