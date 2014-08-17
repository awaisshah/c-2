#include <stdio.h>
#include <stdlib.h>

struct bst {
	int data;
	struct bst *right;
	struct bst *left;
};

struct bst* insert(struct bst *root, int data);
int search (struct bst *root, int data);
void delete(int data);
void view();

int main() {
	struct bst *root, *node, *temp;
	int flag = 0, data;
	char c;
	root = NULL;
	node = NULL;
	temp = NULL;
	printf ("\na. Insert\nb. Delete\nc. Search\nd. View\ne. Exit\n");
	while (1) {
		printf ("\nEnter a choice : ");
		scanf (" %c", &c);
		if (c == 'a') {
			printf ("Enter data to be added to BST : ");
			scanf (" %d", &data);
			if (root == NULL) {
				root = insert (root, data);
				printf ("Data : %d\n", root->data);
			}
			else {
				temp = root;
				node = insert (temp, data);
				printf ("Temp Data : %d\n", temp->data);
				printf ("Data : %d\n", node->data);
			}	
		}
		else if (c == 'e')
			break;
	}
	temp = root;
	flag = search (temp, 20);
	printf ("\n\nFlag = %d\n\n", flag);
	return 0;
}

struct bst* insert (struct bst *temp, int data) {
	if (temp == NULL) {
		temp = malloc (sizeof (struct bst));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
	}
	else if (data <= temp->data) {
		insert (temp->left, data);
	}
	else if (data > temp->data) {
		insert (temp->right, data);
	}
	return temp;
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
}

void delete (int data) {
}

void view () {
}
