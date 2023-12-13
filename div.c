#include "monty.h"

/**
 * f_div - divs the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: nothing
 */

void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int len = 0, sum = 0;


	while (head)
	{
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		cleanup_and_exit();
	}

	head = *stack;

	if (head->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		cleanup_and_exit();
	}

	sum = head->next->n / head->n;
	head->next->n = sum;
	*stack = head->next;
	free(head);
}

