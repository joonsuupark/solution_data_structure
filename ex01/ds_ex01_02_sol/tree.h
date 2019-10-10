#pragma once
#include "node.h"

typedef struct cbtree {
	node_t* front; /* same as root */
	node_t* tail;
	size_t length;
}CompleteBinaryTree_t;

CompleteBinaryTree_t* TreePush(CompleteBinaryTree_t* tree, data_t data);
data_t TreePop(CompleteBinaryTree_t* tree);