#include "node.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void level_order(node_t* ptr) {
	queue_t q;
	init_queue(&q);
	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}

int sum_of(node_t* ptr) {
	/* begin: solution */
	int sum = 0;
	queue_t q;
	init_queue(&q);
	if (ptr == NULL) return -1;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		sum += ptr->data;
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
	return sum;
}

int main(void) {
	node_t n1 = { 1, NULL, NULL };
	node_t n2 = { 4, &n1, NULL };
	node_t n3 = { 16, NULL, NULL };
	node_t n4 = { 25, NULL, NULL };
	node_t n5 = { 20, &n3, &n4 };
	node_t n6 = { 15, &n2, &n5 };
	node_t* root = &n6;
	printf("%d", sum_of(root));
	return EXIT_FAILURE;

}