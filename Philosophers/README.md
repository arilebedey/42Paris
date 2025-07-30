### Threads

Memory is shared across all threads.

Using threads can lead to race conditions because sometime each thread read from its own CPU register (not to be confused with CPU memory) and a value that was changed by another thread, not have been updated in the CPU register of the other thread.

Each thread can have its own set of CPU registers, which act as temporary storage for data being processed.

This is related to cache coherence and memory visibility issues in multithreaded programming. Without proper synchronization mechanisms (e.g., locks, atomic operations, or memory barriers), threads may not see the most up-to-date values of shared variables.

#### Creating a thread

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg);
```

- thread: Pointer to the thread identifier.
- attr: Thread attributes (can be NULL for default attributes).
- start_routine: Function executed by the thread.
- arg: Argument passed to the thread function.

#### Wait for the main thread

(`pthread_join`) waits for a thread to terminate.

### Approaching the problem

Each philosopher is represented as a separate thread. (`pthread_create`)

The monitor thread is also created to oversee the simulation.

Ensure that the main thread waits for all philosopher threads and the monitor thread to finish before exiting.

### Mutex functions

`pthread_mutex_init` initializes a mutex. Mutexes are used to protect shared resources.
`pthread_mutex_destroy`
`pthread_mutex_lock` will either lock a mutex or wait for the mutex to be unlocked before locking it.
`pthread_mutex_unlock`

###
