#include <stdio.h>
//#include "insort.h"
#include <stdlib.h>
#include <stdbool.h>

struct intnode {
	int item;
	struct intnode *next;
};
typedef struct intnode IntNode;

IntNode *first = NULL;

IntNode *createNode(int val) {
	IntNode *intnode = (IntNode*)malloc(sizeof(IntNode));
	(*intnode).item = val;
	(*intnode).next = NULL;
	return intnode;
}

void insert(IntNode *header, int val) {
	IntNode *ptrNode = header;
	if (header == NULL) {
		first = createNode(val);
	}

	else if (val < (*ptrNode).item) {
		IntNode *s = createNode(val);
		(*s).next = header;
		first = s;
		return;
	}
	else {
		while (((*ptrNode).next != NULL) && (val > (*(*ptrNode).next).item) 		) {
			ptrNode = (*ptrNode).next;
		}
		IntNode *s = createNode(val);
		(*s).next = (*ptrNode).next;
		(*ptrNode).next = s;
	}
	return;
}	

void printAll(IntNode *header) {
	IntNode *S = header;
	while(S != NULL) {
		printf("%d ", (*S).item);
		S = (*S).next;
	}
	printf("\n");
	return;
}

int main () {
	printf("Enter some numbers, ending with -1: ");
	int ch;
	int n;
	first = NULL;
	scanf("%d", &n);
	while(n != -1) {
		insert(first, n);
		scanf("%d", &n);
	}
	printAll(first);
	return 0;
}

