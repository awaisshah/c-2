/* Least Common Ancestor */

#include <stdio.h>
#include <stdlib.h>

struct bst {
	int data;
	struct bst *left, *right;
};

struct bst *insert (struct bst *root, int data);
struct bst *newNode (int data);
struct bst *lca (struct bst *root, int d1, int d2);

int main() {
	struct bst *root = NULL;
	struct bst *node;
	root = insert (root, 6);
	insert (root, 4);
	insert (root, 8);
	insert (root, 3);
	insert (root, 5);
	node = lca (root,3,5);
	printf ("LCA of 3 and 5 is: %d\n", node->data);
	return 0;
}

struct bst *insert (struct bst *root, int data) {
	if (root == NULL)
		return newNode(data);

	if (data < root->data)
		root->left = insert (root->left,data);
	else
		root->right = insert (root->right,data);

	return root;
}	

struct bst *lca (struct bst *root, int d1, int d2) {
	if (root == NULL)
		return NULL;
	
	if (root->data > d1 && root->data > d2) 
		return lca (root->left, d1, d2);
	else if (root->data < d1 && root->data < d2)
		return lca (root->right, d1, d2);
	
	return root;
}

struct bst *newNode (int data) {
	struct bst *node = malloc (sizeof(struct bst));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
