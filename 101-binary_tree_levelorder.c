#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void print_current_level(const binary_tree_t *tree,
		void (*func)(int), int level);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

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
 * print_current_level - prints nodes at a current level.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 * @level: the level at which the nodes will be printed.
 */
void print_current_level(const binary_tree_t *tree,
		void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		print_current_level(tree->left, func, level - 1);
		print_current_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 *
 * Description: If tree or func is NULL, does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
		print_current_level(tree, func, i);
}
