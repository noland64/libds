#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;


// Create and allocate memory for a new (FIFO) Queue
// Return newly created Queue, or NULL in the event of error
Queue* queueCreate(size_t bytesPerElement);

// Destroy (FIFO) queue and free allocated memory
// Return success/error code
int queueDestroy(Queue* queue);

// Add val to the back of the (FIFO) queue
// Return success/error code
int queueEnqueue(Queue* queue, void* value);

// Retrieve and remove the value at the front of the (FIFO) queue
// Return the value, or an error code
int queueDequeue(Queue* queue, void* output);

// Retrieve the value at the front of the FIFO queue
// Return the value, or an error code
int queuePeek(Queue* queue, void* output);

// Retrieve the size of the FIFO queue
// Return the value, or an error code
size_t queueSize(Queue* queue);

#endif