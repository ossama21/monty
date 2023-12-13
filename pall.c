#include "monty.h"

/**
 * pall - prints all the values on the stack, from the top.
 * @stack: stack header
 * @line_number: line number
 * Return: 0
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	UNUSED(line_number);
	head = *stack;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
