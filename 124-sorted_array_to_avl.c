#include "binary_trees.h"

avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);
avl_t *sorted_array_to_avl(int *array, size_t size);

/**
 * aux_sort - create the tree using the half element of the array.
 * @parent: parent of the node to create.
 * @array: sorted array.
 * @begin: position where the array starts.
 * @last: position where the array ends.
 * Return: tree created.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		root = binary_tree_node(parent, array[mid]);
		if (root == NULL)
			return (NULL);

		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - builds an AVL Tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of element in the array.
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 *
 * Description: We can assume there will be no duplicate value in the array.
 * We are not allowed to rotate.
 * We can only have 2 functions in our file.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, size - 1));
}
