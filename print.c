#include "monty.h"
/**
 * print_top_element - Prints the value at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: prints the value at the top of stack to standard output.
 *
 * Return: No explicit return value.
 */
void print_top_element(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
