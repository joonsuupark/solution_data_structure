#pragma once

typedef unsigned int size_t;
typedef int data_t;

typedef struct node {
	data_t data;
	struct node* next;
	struct node* prev;
	struct node* left;
	struct node* right;
}node_t;

node_t* NewNode(data_t* data, node_t* next, node_t* prev, node_t* left, node_t* right);
