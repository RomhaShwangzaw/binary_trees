#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 * Return: 0 if tree is NULL, or the balance factor of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		int l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
		return (l - r);
	}
	return (0);
}
