#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef struct ListNode{
	int data;
	struct ListNode *next;
}ListNode;


struct list_stack
{
	ListNode *node[MAXSIZE];
	int top;
	
};

void print_list_reverse(ListNode *pHead)
{
	if (pHead == NULL)
	{
		return;
	}

	if (pHead->next == NULL)
	{
		printf("%d\n",pHead->data);
		return;
	}
	int i;
	struct list_stack lStack;

	for (i = 0; i < MAXSIZE; ++i)
	{
		lStack.node[i] = NULL;
	}
	/*insert list node to the stack*/
	lStack.top = -1;
	ListNode *node = pHead;
	while(node != NULL)
	{
		if(lStack.top == MAXSIZE -1)
		{
			return;
		}
		lStack.top++;
		lStack.node[lStack.top] = node;
		node = node->next;
	}
	/*pop node from the stack*/	
	while(lStack.top != -1)
	{

		printf("%d\t", lStack.node[lStack.top]->data);
		lStack.node[lStack.top] = NULL;
		lStack.top--;
	}
	printf("\n");
}


void print_list_reverse_recursively(ListNode *pHead)
{
	if(pHead == NULL)
	{
		return;
	}
	print_list_reverse_recursively(pHead->next);
	printf("%d\t", pHead->data);
}

ListNode * new_node()
{
	return (ListNode*)malloc(sizeof(ListNode));
}

/*insert a node to tail*/
void add_to_tail(ListNode **pHead, int value)
{
	ListNode * pNew = new_node();
	pNew->data = value;
	pNew->next = NULL;

	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;
		while(pNode->next != NULL)
		{
			pNode = pNode->next;
		}

		pNode->next = pNew;
	}
}


/*find a node has the value and remove the node*/
void remove_node(ListNode **pHead, int value)
{
	if(pHead == NULL || *pHead == NULL)
		return;

	ListNode * delete_node = NULL;
	if((*pHead)->data == value)
	{
		delete_node = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode *node = *pHead;
		//traverse all node to find the value
		while(node->next != NULL && node->next->data != value)
			node = node->next;
		//if find the node 
		if(node->next != NULL && node->next->data == value)
		{
			delete_node = node->next;
			node->next = node->next->next;
		}
	}

	if(delete_node != NULL)
	{
		free(delete_node);
		delete_node = NULL;
	}
}


void print_list(ListNode *pHead)
{
	if(pHead == NULL)
	{
		return;
	}

	ListNode *node = pHead;
	while(node!= NULL)
	{
		printf("%d\t", node->data);
		node = node->next;

	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	ListNode *pListHead = NULL;
	add_to_tail(&pListHead,2);
	add_to_tail(&pListHead,3);
	add_to_tail(&pListHead,9);
	print_list(pListHead);
	// remove_node(&pListHead,2);
	// print_list_reverse(pListHead);
	print_list_reverse_recursively(pListHead);

	return 0;
}