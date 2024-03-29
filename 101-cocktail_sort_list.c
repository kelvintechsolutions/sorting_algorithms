#include "sort.h"

/**
 * swap_tail -it functions to swap list.
 *@list:it is the list to be swapped.
 *@head:it is the head of list.
 *@tail:it is the tail of list.
 *
 * Return -it returns void
 */
void swap_tail(listint_t **list, listint_t **head, listint_t **tail)
{
	listint_t *temp = (*tail)->next;

	if ((*tail)->prev != NULL)
	{
		(*tail)->prev->next = temp;
	}
	else
		*list = temp;
	temp->prev = (*tail)->prev;
	(*tail)->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = *tail;
	}
	else
		*head = *tail;
	(*tail)->prev = temp;
	temp->next = *tail;
	*tail = temp;
}

/**
 * swap_head -it functions to swap head of linked list.
 *@list:it is the doubly linked list to be sorted.
 *@tail:it is the tail of double linked list.
 *@head:it is the head of double linked list.
 * Return -it returns void.
 */
void swap_head(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *temp = (*head)->prev;

	if ((*head)->prev != NULL)
		(*head)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*head)->next;
	(*head)->prev = temp->prev;
	if (temp->prev != NULL)
	{
		temp->prev->next = *head;
	}
	else
		*list = *head;
	(*head)->next = temp;
	temp->prev = *head;
	*head = temp;
}

/**
 * cocktail_sort_list - function to sort doubly linked list w/ cocktail sort
 *@list:it is the list to be sorted.
 * Return -t returns void.
 */
void cocktail_sort_list(listint_t **list)
{
	bool booln = false;
	listint_t *head;
	listint_t *tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next != NULL;)
	{
		tail = tail->next;
	}
	while (booln == false)
	{
		booln = true;
		for (head = *list; head != tail; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap_tail(list, &tail, &head);
				print_list((const listint_t *) *list);
				booln = false;
			}
		}
		for (head = head->prev; head != *list; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_head(list, &tail, &head);
				print_list((const listint_t *) *list);
				booln = false;
			}
		}
	}
}
