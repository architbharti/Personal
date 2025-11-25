<<<<<<< HEAD
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t rw_mutex;    // Semaphore for reader/writer mutual exclusion
sem_t mutex;       // Semaphore for protecting read_count
int read_count = 0; // Number of readers currently reading
int shared_data = 0; // The shared resource

void* reader(void* arg) {
    int id = *((int*)arg);

    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&rw_mutex);  // First reader locks resource
    sem_post(&mutex);

    // Critical Section (Reading)
    cout << "Reader " << id << " is reading shared_data = " << shared_data << endl;
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
        sem_post(&rw_mutex);  // Last reader releases resource
    sem_post(&mutex);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    int id = *((int*)arg);

    sem_wait(&rw_mutex);

    // Critical Section (Writing)
    shared_data++;
    cout << "Writer " << id << " is writing shared_data = " << shared_data << endl;
    sleep(1);

    sem_post(&rw_mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t r[5], w[5];
    int id[5];

    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &id[i]);
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}
=======
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t rw_mutex;    // Semaphore for reader/writer mutual exclusion
sem_t mutex;       // Semaphore for protecting read_count
int read_count = 0; // Number of readers currently reading
int shared_data = 0; // The shared resource

void* reader(void* arg) {
    int id = *((int*)arg);

    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&rw_mutex);  // First reader locks resource
    sem_post(&mutex);

    // Critical Section (Reading)
    cout << "Reader " << id << " is reading shared_data = " << shared_data << endl;
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
        sem_post(&rw_mutex);  // Last reader releases resource
    sem_post(&mutex);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    int id = *((int*)arg);

    sem_wait(&rw_mutex);

    // Critical Section (Writing)
    shared_data++;
    cout << "Writer " << id << " is writing shared_data = " << shared_data << endl;
    sleep(1);

    sem_post(&rw_mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t r[5], w[5];
    int id[5];

    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &id[i]);
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
