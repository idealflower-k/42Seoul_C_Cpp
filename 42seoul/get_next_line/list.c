#include "get_next_line.h"
#include <stdio.h>

void newlst_front(t_list **head)
{
	t_list *node;

	printf("Making new front node\n");
	node = (t_list *)malloc(sizeof(t_list));
	if(!node)
		return ;
	node -> next = *head;
	printf("new node = %p\n", node);
	printf("head = %p, node -> next = %p\n", *head, node -> next);
	*head = node;
	printf("new head = %p\n", *head);
}

int main(void)
{
	t_list *head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (-1);
	printf("head = %p\n", head);
	newlst_front(&head);
	printf("head = %p\n", head);
	free(head);

	return (0);
}