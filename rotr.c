#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: stack header
 * @line_number: line number
 * Return: 0
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	UNUSED(line_number);
	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}

