<<<<<<< HEAD
#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <semaphore.h>
#include <chrono>

using namespace std;

queue<int> buffer;
const int BUFFER_SIZE      = 5;
const int NUM_PRODUCERS    = 2;
const int NUM_CONSUMERS    = 3;
const int ITEMS_PER_PROD   = 7;   // each producer produces 7 items

sem_t sem_empty;   // counts empty slots
sem_t sem_full;    // counts filled slots
sem_t sem_mutex;   // binary semaphore (mutex for buffer)

void producer(int id) {
    for (int i = 1; i <= ITEMS_PER_PROD; ++i) {
        int item = id * 100 + i;

        sem_wait(&sem_empty);   // wait for empty slot
        sem_wait(&sem_mutex);   // lock buffer

        buffer.push(item);
        cout << "Producer " << id << " produced: " << item
             << " | Buffer size: " << buffer.size() << endl;

        sem_post(&sem_mutex);   // unlock buffer
        sem_post(&sem_full);    // signal that one item is available

        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

void consumer(int id) {
    while (true) {
        sem_wait(&sem_full);    // wait for available item
        sem_wait(&sem_mutex);   // lock buffer

        int item = buffer.front();
        buffer.pop();

        sem_post(&sem_mutex);   // unlock buffer
        sem_post(&sem_empty);   // one more empty slot

        // -1 is our termination signal
        if (item == -1) {
            cout << "Consumer " << id << " exiting.\n";
            break;
        }

        cout << "Consumer " << id << " consumed: " << item
             << " | Buffer size: " << buffer.size() << endl;

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    // initialize semaphores
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full,  0, 0);
    sem_init(&sem_mutex, 0, 1);

    vector<thread> producers;
    vector<thread> consumers;

    // start producer threads
    for (int i = 1; i <= NUM_PRODUCERS; ++i)
        producers.emplace_back(producer, i);

    // start consumer threads
    for (int i = 1; i <= NUM_CONSUMERS; ++i)
        consumers.emplace_back(consumer, i);

    // wait for all producers to finish
    for (int i = 0; i < NUM_PRODUCERS; ++i)
        producers[i].join();

    // send termination signals (one for each consumer)
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        sem_wait(&sem_empty);
        sem_wait(&sem_mutex);

        buffer.push(-1);   // sentinel value

        sem_post(&sem_mutex);
        sem_post(&sem_full);
    }

    // wait for all consumers to finish
    for (int i = 0; i < NUM_CONSUMERS; ++i)
        consumers[i].join();

    cout << "\nAll producers finished,\nall items consumed, buffer is empty.\n";

    // destroy semaphores
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    sem_destroy(&sem_mutex);

    return 0;
}
=======
#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <semaphore.h>
#include <chrono>

using namespace std;

queue<int> buffer;
const int BUFFER_SIZE      = 5;
const int NUM_PRODUCERS    = 2;
const int NUM_CONSUMERS    = 3;
const int ITEMS_PER_PROD   = 7;   // each producer produces 7 items

sem_t sem_empty;   // counts empty slots
sem_t sem_full;    // counts filled slots
sem_t sem_mutex;   // binary semaphore (mutex for buffer)

void producer(int id) {
    for (int i = 1; i <= ITEMS_PER_PROD; ++i) {
        int item = id * 100 + i;

        sem_wait(&sem_empty);   // wait for empty slot
        sem_wait(&sem_mutex);   // lock buffer

        buffer.push(item);
        cout << "Producer " << id << " produced: " << item
             << " | Buffer size: " << buffer.size() << endl;

        sem_post(&sem_mutex);   // unlock buffer
        sem_post(&sem_full);    // signal that one item is available

        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

void consumer(int id) {
    while (true) {
        sem_wait(&sem_full);    // wait for available item
        sem_wait(&sem_mutex);   // lock buffer

        int item = buffer.front();
        buffer.pop();

        sem_post(&sem_mutex);   // unlock buffer
        sem_post(&sem_empty);   // one more empty slot

        // -1 is our termination signal
        if (item == -1) {
            cout << "Consumer " << id << " exiting.\n";
            break;
        }

        cout << "Consumer " << id << " consumed: " << item
             << " | Buffer size: " << buffer.size() << endl;

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    // initialize semaphores
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full,  0, 0);
    sem_init(&sem_mutex, 0, 1);

    vector<thread> producers;
    vector<thread> consumers;

    // start producer threads
    for (int i = 1; i <= NUM_PRODUCERS; ++i)
        producers.emplace_back(producer, i);

    // start consumer threads
    for (int i = 1; i <= NUM_CONSUMERS; ++i)
        consumers.emplace_back(consumer, i);

    // wait for all producers to finish
    for (int i = 0; i < NUM_PRODUCERS; ++i)
        producers[i].join();

    // send termination signals (one for each consumer)
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        sem_wait(&sem_empty);
        sem_wait(&sem_mutex);

        buffer.push(-1);   // sentinel value

        sem_post(&sem_mutex);
        sem_post(&sem_full);
    }

    // wait for all consumers to finish
    for (int i = 0; i < NUM_CONSUMERS; ++i)
        consumers[i].join();

    cout << "\nAll producers finished,\nall items consumed, buffer is empty.\n";

    // destroy semaphores
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    sem_destroy(&sem_mutex);

    return 0;
}
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
