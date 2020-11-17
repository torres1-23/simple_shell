#include "header.h"

/**
 * add_node_end - adds a new node at the end of a list.
 * @head: pointer to last head.
 * @str: string to add.
 *
 * Return:  the address of the new element, or NULL if it failed.
 */

listdir *add_node_end(listdir **head, const char *str)
{
	listdir *new, *tmp;
	unsigned int len = 0;

	if (!head)
		return (NULL);
	while (str[len])
		len++;
	new = malloc(sizeof(listdir));
	if (!new)
		return (NULL);
	tmp = *head;
	new->directory = strdup(str);
	new->next = NULL;
	if (!tmp)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}
