#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;


// queueCreate(void)
// Create and allocate memory for a new (FIFO) Queue
// Return newly created Queue, or NULL in the event of error
Queue* queueCreate(void);

// queueDestroy(Queue* queue)
// Destroy (FIFO) queue and free allocated memory
// Return success/error code
int queueDestroy(Queue* queue);

// queueEnqueue(Queue* queue, int val)
// Add val to the back of the (FIFO) queue
// Return success/error code
int queueEnqueue(Queue* queue, int val);

// queueDequeue(Queue* queue)
// Retrieve and remove the value at the front of the (FIFO) queue
// Return the value, or an error code
int queueDequeue(Queue* queue);

// queuePeek(Queue* queue)
// Retrieve the value at the front of the FIFO queue
// Return the value, or an error code
int queuePeek(Queue* queue);

// queueSize(Queue* queue)
// Retrieve the size of the FIFO queue
// Return the value, or an error code
int queueSize(Queue* queue);

#endif