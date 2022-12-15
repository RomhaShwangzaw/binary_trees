#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap Tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of element in the array.
 * Return: a pointer to the root node of the created Binary Heap,
 * or NULL on failure.
 *
 * Description: If a value of the array is already present in the tree,
 * this value must be ignored.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (heap_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
