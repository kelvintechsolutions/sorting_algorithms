#include "sort.h"
/**
 * swap_list - function to help sort doubly-linked list.
 *@head: head of the list.
 *@node1:it is the first node to be swapped/sorted.
 *@node2:it is the second node to be swapped/sorted.
 * Return:it is returns void.
 */
void swap_list(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list -it sorts a double linked list with insertion method.
 *@list:it is the list to be sorted.
 * Return:t is  void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *temp;

	if (list == NULL || *list == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_list(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
