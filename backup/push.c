#include "monty.h"

/**
 * push - adds node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/

void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (bus.arg != NULL)
	{
		if (bus.arg[0] == '-')
			j++;
	for (; bus.arg[j] != '\0'; j++)
	{
		if (bus.arg[j] > 57 || bus.arg[j] < 48)
			flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(*stack);
			cleanup_and_exit();
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		cleanup_and_exit();
	}
	n = atoi(bus.arg);
	if (bus.is_stack == 0)
		add_node(stack, n);
	else
		add_node_end(stack, n);
}

