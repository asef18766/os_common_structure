# Critical Section Design
## flag check
sharing a variable to indicate which thread is going to enter critical section
### criteria analysis
* mutual exclusion
* **progress**: any thread will be blocked **until the thread of initial value entered and left C.S.**
* bounded waiting
## flag raising
each thread holding a flag to represent the willing to enter C.S.
### criteria analysis
* mutual exclusion
* **progress**: none of the threads will be entered C.S. if they **set their flag to 1 simultaneously**
* bounded waiting
## peterson
