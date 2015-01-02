#include <stdio.h>
#include <stdlib.h>

struct linklist {
	int data;
	struct linklist *next;
};

void insert(int n, struct linklist **head) {
	struct linklist *node = malloc (sizeof(struct linklist));
	node->data = n;
	node->next = *head;
	*head = node;
}

void delete (struct linklist **head) {
	if (*head == NULL) {
		printf ("List is empty! \n");
		return;
	}
	struct linklist *temp;
	temp = *head;
	*head = (*head)->next;
	printf("The data being deleted is: %d\n", temp->data);	
	free (temp);
}

void display (struct linklist **head) {
	struct linklist *node = *head;
	
	while (node!=NULL) {
		printf ("%d->", node->data);
		node = node->next;
	}
	printf ("NULL\n");
}


void reverse (struct linklist **head) {
	struct linklist *current = *head, *prev = NULL, *next;
	next = current->next;
	while (current!=NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void displayn (int n, struct linklist **head) {
	int count;
	struct linklist *node = *head;
	struct linklist *temp;
	if (*head==NULL) {
		printf ("List is empty!\n");
		return;
	}
	else
		count = 1;
	while (node) {
		if (count == n-1) 
			break;
		node = node->next;
		count++;
	}
	temp = node->next;
	printf ("%dth element is: %d\n", n, temp->data);
	node->next = node->next->next;
	free(temp);
}

int main() {
	struct linklist *head, *temp, *node;
	char c;
	int n, data;
	printf ("Enter choice (i)nsert, (d)elete, dis(p)lay, display(n), (e)xit: ");
	while (1) {
		printf ("Enter choice: ");
		scanf (" %c", &c);
		switch (c) {
			case 'i':
				printf ("Enter data to insert: ");
				scanf ("%d", &data);
				insert (data, &head);	
				break;
	
			case 'd':
				delete(&head);	
				break;
		
			case 'p':
				display(&head);
				break;
		
			case 'n':
				printf ("Enter n: ");
				scanf (" %d", &n);
				displayn (n,&head);
				break;

			case 'r':
				reverse(&head);
				printf ("Reverseed list is: ");
				display (&head);
				break;			

			case 'e':
				exit(0);
				break;

			default:
				printf("Wrong choice! Enter again\n");
				break;
	
		}
	}
	return 0;
}
