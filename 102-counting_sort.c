#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* _calloc - Custom calloc implementation.
* @nmemb: Number of elements.
* @size: Size of each element.
* Return: Pointer to the allocated memory.
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int i;
char *p;

if (nmemb == 0 || size == 0)
return (NULL);

p = malloc(nmemb * size);

if (p == NULL)
return (NULL);

for (i = 0; i < nmemb * size; i++)
p[i] = '\0';

return (p);
}

/**
* counting_sort - Implementation of the Counting sort algorithm.
* @array: Array to be sorted.
* @size: Size of the array.
*/
void counting_sort(int *array, size_t size)
{
int index, maximum = 0, *counter = NULL, *tmp = NULL;
size_t i;

if (array == NULL || size < 2)
return;

/* Find the maximum number in the array */
for (i = 0; i < size; i++)
if (array[i] > maximum)
maximum = array[i];

counter = _calloc(maximum + 1, sizeof(int));
tmp = _calloc(size, sizeof(int));

if (counter == NULL || tmp == NULL)
{
free(counter);
free(tmp);
return;
}

/* Count the occurrences of each element in the array */
for (i = 0; i < size; i++)
counter[array[i]]++;

/* Get the cumulative values in the counter array */
for (index = 1; index <= maximum; index++)
counter[index] += counter[index - 1];

print_array(counter, maximum + 1);

/* Create a new array with sorted elements */
for (i = 0; i < size; ++i)
{
tmp[counter[array[i]] - 1] = array[i];
counter[array[i]]--;
}

/* Copy the sorted elements back to the original array */
for (i = 0; i < size; i++)
array[i] = tmp[i];

free(tmp);
free(counter);
}

