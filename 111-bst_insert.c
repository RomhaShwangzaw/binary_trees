#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp, *current, *parent;

	tmp = malloc(sizeof(bst_t));
	if (tmp == NULL)
		return (NULL);

	tmp->n = value;
	tmp->parent = tmp->left = tmp->right = NULL;

	if (*tree == NULL)
		*tree = tmp;
	else
	{
		current = *tree;
		parent = NULL;

		while (1)
		{
			parent = current;
			if (value < parent->n)
			{
				current = current->left;
				if (current == NULL)
				{
					parent->left = tmp;
					break;
				}
			}
			else
			{
				current = current->right;
				if (current == NULL)
				{
					parent->right = tmp;
					break;
				}
			}
		}
	}
	return (tmp);
}
