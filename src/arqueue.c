#include "arqueue.h"

static bool double_queue_capacity(arqueue *queue);

bool init_queue(arqueue *queue, size_t initial_capacity) {
    arqueue newqueue = {
        .data = malloc(initial_capacity),
        .head = 0,
        .length = 0,
    };
    newqueue.capacity = newqueue.data == NULL ? 0 : initial_capacity;
    *queue = newqueue;
    return newqueue.data == NULL;
}

bool enqueue(arqueue *queue, int entry) {
    if (queue_full(queue) && double_queue_capacity(queue)) {
        return true;
    }
    queue->data[(queue->head + queue->length) % queue->capacity] = entry;
    queue->length++;
    return false;
}

bool dequeue(arqueue *queue, int *dest) {
    if (queue_empty(queue)) {
        return true;
    }
    *dest = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->length--;
    return false;
}

bool queue_full(const arqueue *queue) {
    return queue->length == queue->capacity;
}

bool queue_empty(const arqueue *queue) {
    return queue->length == 0;
}

static bool double_queue_capacity(arqueue *queue) {
    int *new_data = malloc(queue->capacity * 2 * sizeof *queue);
    if (new_data == NULL) {
        return true;
    }
    for (int i = 0; i < queue->length; i++) {
        new_data[i] = queue->data[(queue->head + i) % queue->capacity];
    }
    free(queue->data);
    queue->data = new_data;
    queue->head = 0;
    queue->capacity *= 2;
    return false;
}

