#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    size_t head;
    size_t length;
    size_t capacity;
} arqueue;

bool init_queue(arqueue *queue, size_t initial_capacity);

bool enqueue(arqueue *queue, int entry);

bool dequeue(arqueue *queue, int *dest);

bool queue_full(const arqueue *queue);

bool queue_empty(const arqueue *queue);

#define ARQUEUE(type, name)\
typedef struct { type *data; size_t head; size_t length; size_t capacity; } name;\
