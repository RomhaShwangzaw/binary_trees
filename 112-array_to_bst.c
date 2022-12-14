#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of element in the array.
 * Return: a pointer to the root node of the created BST, or NULL on failure.
 *
 * Description: If a value of the array is already present in the tree,
 * this value must be ignored.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root, *new;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	root = binary_tree_node(NULL, array[0]);
	if (root == NULL)
		return (NULL);

	for (i = 1; i < size; i++)
	{
		new = bst_insert(&root, array[i]);
		if (new == NULL)
			return (NULL);
	}
	return (root);
}
