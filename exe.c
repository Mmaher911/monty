#include "monty.h"
/**
 * execute_opcode - Executes the specified opcode.
 * @content: Pointer to the head of the linked list (stack).
 * @stack: Line number being processed in the Monty file.
 * @counter: Pointer to the Monty file being parsed.
 * @file: Content of the current line in the Monty file.
 *
 * Description: This function executes the specified opcode
 *
 * Return: No explicit return value.
 */
int execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_node}, {"pall", print_stack}, {"pint", print_top_element},
				{"pop", pop_top_element},
				{"swap", swap_top_elements},
				{"add", add_top_two_elements},
				{"nop", do_nothing},
				{"sub", subtract_top_elements},
				{"div", divide_top_two_elements},
				{"mul", multiply_top_two_elements},
				{"mod", f_mod},
				{"pchar", print_char_at_top},
				{"pstr", print_string_from_top},
				{"rotl", rotate_stack_left},
				{"rotr", rotate_stack_right},
				{"queue", queue_top},
				{"stack", print_stack_top},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
