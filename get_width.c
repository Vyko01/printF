#include "main.h"

/**
 * get_width - calculates the width for printing.
 * @format: formatted string in which to print the arguments
 * @index: list of arguments to be printed
 * @list: list of arguments
 *
 * Return: width
 */

int get_width(const char *format, int *index, va_list list)
{
	int curr_index;
	int width = 0;

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			width *= 10;
			width += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*index = curr_index - 1;

	return (width);
}
