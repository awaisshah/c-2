#include <stdio.h>
#include <stdlib.h>

struct adjListNode {
	int v;
	struct adjListNode *next;
};

struct adjList {
	struct adjListNode *head;
};

struct graph {
	int v;
	struct adjList *list;
};

struct graph *create_graph (int v);
struct adjListNode* addNode (int v);
void addEdge(struct graph *g, int v, int w);
void printGraph (struct graph *g);

int main(int argc, char *argv[]) {
	
	if (argc < 2) {
		printf ("Input of the form: ./[exe] [no. of vertices]\n");
		exit(1);
	}

	struct graph *g = create_graph(atoi(argv[1]));
	
	addEdge (g,0,1);
	addEdge (g,2,3);
	addEdge (g,1,3);
	
	printGraph (g);

	return 0;
}

struct graph *create_graph (int v) {
	int i;
	struct graph *g = malloc (sizeof(struct graph));
	g->v = v;
	
	g->list = malloc (v*sizeof(struct adjList));
	for (i=0; i<v; i++) {
		g->list[i].head = NULL;
	}
	return g;
}

struct adjListNode* addNode (int v) {
	struct adjListNode *node = malloc (sizeof(struct adjListNode));
	node->v = v;
	node->next = NULL;
	return node;
}

void addEdge(struct graph *g, int v, int w) {
	struct adjListNode *node = addNode(w);
	node->next = g->list[v].head;
	g->list[v].head = node;

	node = addNode(v);
	node->next = g->list[w].head;
	g->list[w].head = node;
}

void printGraph (struct graph *g) {
	int i;
	struct adjListNode *node;
	for (i=0; i<g->v; i++) {
		node = g->list[i].head;
		printf ("Adjacency List of Vertex %d: \n%d", i, i);
		while (node) {
			printf ("->%d", node->v);
			node = node->next;
		}
		printf ("\n");
	}

}


