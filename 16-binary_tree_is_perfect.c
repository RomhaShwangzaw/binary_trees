#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: the height of the binary tree.
 * Description: If tree is NULL, the function returns 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * binary_tree_leaves - measures the number of leaves in a binary tree.
 * @tree: a pointer to the root node of the tree to find the number of leaves.
 * Return: the number of leaves in the binary tree.
 * Description: If tree is NULL, the function returns 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t leaves = 0;

		if (tree->left == NULL && tree->right == NULL)
			++leaves;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
		return (leaves);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 if perfect, 0 if not or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, leaves, perfect_leaves = 1;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	leaves = binary_tree_leaves(tree);

	while (height)
	{
		perfect_leaves *= 2;
		--height;
	}
	if (leaves == perfect_leaves)
		return (1);
	else
		return (0);
}
