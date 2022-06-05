#include <iostream>
using namespace std;

struct LinkedList
{
	int var;
	LinkedList* next;
};

void appendNode(LinkedList** list, int var)
{
	LinkedList* node = new(LinkedList);
	node->var = var;
	node->next = NULL;
	
	LinkedList** temp = list;
	while(*temp != NULL)
		temp = &((*temp)->next);
	*temp = node;
}

void deleteNode(LinkedList** list, int var)
{
	LinkedList** temp = list;
	while(*temp != NULL && (*temp)->var != var)
		temp = &((*temp)->next);
	*temp = (*temp)->next;
}

void printAllNode(LinkedList** list)
{
	while(*list != NULL)
	{
		cout << (*list)->var << ",";
		*list = (*list)->next;
	}
}

int main() 
{
	LinkedList* list = NULL;
	
	appendNode(&list, 100);
	appendNode(&list, 5);
	appendNode(&list, 20);
	deleteNode(&list, 5);
	printAllNode(&list);

	return 0;
}
