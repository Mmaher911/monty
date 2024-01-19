#include "monty.h"

/**
 * openfile - opens file
 * @filename: the file name
 * Return: void
 */

void openfile(char *filename)
{
	FILE *fd = fopen(filename, "r");

	if (filename == NULL || fd == NULL)
		error(2, filename);

	readfile(fd);
	fclose(fd);
}


/**
 * readfile - reads file
 * @fdd: pointer to file
 * Return: void
 */

void readfile(FILE *fdd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fdd) != -1; line_number++)
	{
		format = parseline(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parseline - Separates each line into tokens
 *
 * @buffer: the line from the file
 * @linenumber: theline number
 * @format:  storage format. If 0 Nodes
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseline(char *buffer, int linenumber, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findfunc(opcode, value, linenumber, format);
	return (format);
}

/**
 * findfunc - find the appropriate function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findfunc(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_st},
		{"pall", printstack},
		{"pint", printtop},
		{"pop", poptop},
		{"nop", nope},
		{"swap", swapnodes},
		{"add", addnodes},
		{"sub", subnodes},
		{"div", divnodes},
		{"mul", mulnodes},
		{"mod", modnodes},
		{"pchar", printchar},
		{"pstr", printstr},
		{"rotl", rotleft},
		{"rotr", rotright},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callfun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, ln, opcode);
}


/**
 * callfun - Calls the function.
 * @func: Pointer to the function
 * @op: string representing opcode.
 * @val: string representing the numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */

void callfun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, ln);
		}
		node = createnode(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_que(&node, ln);
	}
	else
		func(&head, ln);
}
