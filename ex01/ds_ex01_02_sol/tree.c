#pragma once
#include "tree.h"
#include <stdlib.h>
#include <limits.h>
#define GET_PARENT_IDX(IDX) (((int)((IDX)/2)) - 1)
#define DECREASE(X) ((X) = ((X) - 1 > 0? (X)-1: 0))
#define INCREASE(X) ((X) = (X) + 1)
#define ERROR_VALUE INT_MIN

CompleteBinaryTree_t* NewTree(node_t* node)
{
	CompleteBinaryTree_t* tree = NULL;
	if ((tree = (CompleteBinaryTree_t*)malloc(sizeof(CompleteBinaryTree_t))) == NULL) return NULL;
	tree->front = node;
	tree->tail = node;
	tree->length = 0;
	return tree;
}

node_t* GetParentNode(CompleteBinaryTree_t* tree, int child_idx)
{
	node_t* node = tree->front;
	int parent_idx = GET_PARENT_IDX(child_idx);
	while (parent_idx-- > 0)node = node->next;
	return node;
}

CompleteBinaryTree_t* TreePush(CompleteBinaryTree_t* tree, data_t data)
{
	node_t* node = NULL;
	node_t* parent = NULL;
	if (tree && tree->length > 0) {
		if ((node = NewNode(data, NULL, tree->tail, NULL, NULL)) == NULL) return NULL;
		tree->tail->next = node;
		tree->tail = node;
		parent = GetParentNode(tree, tree->length + 1);
		if (tree->length % 2) parent->left = node;
		else parent->right = node;
	}
	else {
		if (tree) free(tree);
		if ((node = NewNode(data, NULL, NULL, NULL, NULL)) == NULL) return NULL;
		if ((tree = NewTree(node)) == NULL) return NULL;
	}
	INCREASE(tree->length);
	return tree;
}

data_t TreePop(CompleteBinaryTree_t* tree)
{
	data_t data = ERROR_VALUE;
	node_t* parent = NULL, * current = NULL;
	if (!(tree && tree->length > 0)) return data;
	current = tree->tail;
	data = current->data;
	if (tree->length == 1) tree->front = tree->tail = NULL;
	else {
		parent = GetParentNode(tree, tree->length);
		tree->tail = tree->tail->prev;
		tree->tail->next = NULL;
		if (tree->length % 2) parent->right = NULL;
		else parent->left = NULL;
	}
	free(current);
	current = NULL;
	DECREASE(tree->length);
	return data;
}