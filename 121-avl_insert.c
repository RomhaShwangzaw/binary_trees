#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree.
 * @tree: a double pointer to the root node of the AVL tree to insert the value
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
 * Description: The resulting tree after insertion, must be a balanced AVL Tree
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *curr, *new;
	int bfactor;

	if (tree != NULL)
	{
		curr = *tree;
		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < curr->n) /* insert in left subtree */
		{
			if (curr->left != NULL)
				return (avl_insert(&curr->left, value));
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			bfactor = binary_tree_balance(curr);
			if (bfactor > 1)
				binary_tree_rotate_right(curr);
			return (curr->left = new);
		}
		if (value > curr->n) /* insert in right subtree */
		{
			if (curr->right != NULL)
				return (avl_insert(&curr->right, value));
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			bfactor = binary_tree_balance(curr);
			if (bfactor < -1)
				binary_tree_rotate_left(curr);
			return (curr->right = new);
		}
	}
	return (NULL);
}
