#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		for (swap = curr->prev; swap != NULL; swap = swap->prev)
		{
			if (swap->n > curr->n)
			{
				if (swap->prev != NULL)
					swap->prev->next = curr;
				else
					*list = curr;
				curr->prev = swap->prev;
				swap->prev = curr;
				swap->next = curr->next;
				if (curr->next != NULL)
					curr->next->prev = swap;
				curr->next = swap;
				print_list(*list);
			}
			else
			{
				break;
			}
		}
	}
}
