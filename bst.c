#include <stdio.h>
#include <stdlib.h>

struct bst {
	int data;
	struct bst *right;
	struct bst *left;
} *root, *node, *temp;

struct bst* newNode (int data);
struct bst* insert(struct bst *root, int data);
int search (struct bst *root, int data);
void delete(int data);
void view();

int main() {

	int flag = 0, data;
	char c;
	root = NULL;
	node = NULL;
	temp = NULL;
	printf ("\na. Insert\nb. Search\nc. Exit\n");
	while (1) {
		printf ("\nEnter a choice : ");
		scanf (" %c", &c);
		if (c == 'a') {
			printf ("Enter data to be added to BST : ");
			scanf (" %d", &data);
			root = insert (root, data);
		}
		else if (c == 'b') {
			printf ("Enter the element to be searched for : ");
			scanf (" %d", &data);
			flag = search (root, data);
			if (flag == 1) 
				printf ("Element found\n");
			else
				printf ("Element not found\n");
			flag = 0;
		}
		else if (c == 'c')
			break;
	}
	return 0;
}

struct bst* newNode (int data) {
	struct bst* node = malloc (sizeof (struct bst));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct bst* insert (struct bst* root, int data) {
	if (root == NULL) {
		root = newNode (data);
        return root;
	}
    
    else if (data <= root->data) {
        root->left = insert (root->left, data);
    }
    
    else {
        root->right = insert (root->right, data);
    }
    return root;
}

int search (struct bst *root, int data) {
	if (root == NULL)
		return 0;
	else if (root->data == data)
		return 1;
	else if (data <= root->data)
		return search (root->left, data);
	else if (data > root->data)
		return search (root->right, data);
	return 0;
}

