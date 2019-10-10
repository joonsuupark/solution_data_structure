#pragma once
#include "node.h"
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100

typedef struct queue {
	data_t data[MAX_QUEUE_SIZE];
	index_t front, rear;
}queue_t;

void error(char* message);
void init_queue(queue_t* q);
bool is_empty(queue_t* q);
bool is_full(queue_t* q);
void enqueue(queue_t* q, node_t* item);
node_t* dequeue(queue_t* q);