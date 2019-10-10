#include "node.h"
#include <stdlib.h>

node_t* NewNode(data_t* data, node_t* left, node_t* right)
{
	node_t* node = NULL;
	if ((node = (node_t*)malloc(sizeof(node_t))) == NULL)return NULL;
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}
