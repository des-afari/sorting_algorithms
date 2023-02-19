#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm
 *
 * @list: Address of pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *prev, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;

    while (curr != NULL)
    {
        prev = curr->prev;
        next = curr->next;

        while (prev != NULL && prev->n > curr->n)
        {
            /* Swap curr and prev nodes */
            if (prev->prev != NULL)
                prev->prev->next = curr;
            else
                *list = curr;

            if (curr->next != NULL)
                curr->next->prev = prev;

            prev->next = next;
            curr->prev = prev->prev;
            prev->prev = curr;
            curr->next = prev;

            print_list(*list);

            prev = curr->prev;
        }

        curr = next;
    }
}
