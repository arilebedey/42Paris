Each philosopher is represented as a separate thread. (`pthread_create`)

The monitor thread is also created to oversee the simulation.

### Creating a thread

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg);
```

- thread: Pointer to the thread identifier.
- attr: Thread attributes (can be NULL for default attributes).
- start_routine: Function executed by the thread.
- arg: Argument passed to the thread function.

### Wait for the main thread

(`pthread_join`) waits for a thread to terminate. Ensures that the main thread waits for all philosopher threads and the monitor thread to finish before exiting.

### Mutex functions

`pthread_mutex_init` initializes a mutex. Mutexes are used to protect shared resources.
`pthread_mutex_destroy`
`pthread_mutex_lock`
`pthread_mutex_unlock`

###
