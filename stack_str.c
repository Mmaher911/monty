#include "monty.h"

/**
 * printchar - Print Ascii value.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */
void printchar(stack_t **stack, unsigned int linenumber)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_error(11, lin_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_error(10, linenumber);
	printf("%c\n", ascii);
}

/**
 * printstr - Print the string.
 * @stack: pointing to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void printstr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotleft - Rotates first node to the bottom.
 * @stack: pointing to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void rotleft(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotright - Rotate last node of the stack to the top.
 * @stack: pointing to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void rotright(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
