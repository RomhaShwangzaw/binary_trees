#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 * Return: a pointer to the new root node of the tree once rotated,
 * or NULL on failure.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	tree->parent = tree->right;
	tree->right = tree->right->left;
	tree->right->left = tree;
	return (tree->right);
}
