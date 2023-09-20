#include "main.h"
/**
 * get_flags - calculate active flags
 * @format: formatted strings in which to print the argument
 * by allucius and Ruot
 * @i: take a [arameter
 * Return: flags
 */

int get_flags(const char *format, int*index)
{
	/* - + 0 # ' ' */
	/* 1 2 3 8 16 */
	int j, curr_index;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_index = *index + 1; format[curr_index] != '\0'; j++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; curr_index++)
			if (format[curr_index] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}

	*index = curr_index -1;

	return (flags);
}
