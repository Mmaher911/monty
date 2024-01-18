#include "monty.h"
/**
* free_stack - free the linked list doubly
* @header: head of the stack
*/
void free_stack(stack_t *header)
{
	stack_t *aux;

	aux = header;
	while (header)
	{
		aux = header->next;
		free(header);
		header = aux;
	}
}
