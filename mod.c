#include "monty.h"

/**
 * mod - mods the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int len = 0, result = 0;

	head = *stack;
	while (head)
	{
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}

	head = *stack;

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}

	result = head->next->n % head->n;
	head->next->n = result;
	*stack = head->next;
	free(head);
}

