#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

void init_queue(queue_t* q)
{
	q->front = q->rear = 0;
}

bool is_empty(queue_t* q)
{
	return (q->front == q->rear);
}

bool is_full(queue_t* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(queue_t* q, node_t* item)
{
	if (is_full(q))
		error("full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

node_t* dequeue(queue_t* q)
{
	if (is_empty(q))
		error("empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

