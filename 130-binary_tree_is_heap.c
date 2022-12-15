#include "binary_trees.h"

unsigned int count_nodes(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, unsigned int index,
	unsigned int number_nodes);
int is_heap(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);

/**
 * count_nodes - Counts the number of nodes in a tree.
 * @tree: The pointer to the root of the tree.
 * Return: The number of nodes in the tree.
 */
unsigned int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Checks if a tree is complete.
 * @tree: The pointer to the root of the tree.
 * @index: The index of the current node.
 * @number_nodes: The number of nodes in the tree.
 * Return: If the tree is complete (1) or (0).
 */
int is_complete(const binary_tree_t *tree, unsigned int index,
	unsigned int number_nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= number_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
	is_complete(tree->right, 2 * index + 2, number_nodes));
}

/**
 * is_heap - Checks if the nodes are max of it's children.
 * @tree: The pointer to the root of the tree.
 * Return: True (1) or (0).
 */
int is_heap(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->right == NULL)
		return (tree->n >= tree->left->n);
	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return ((is_heap(tree->left)) && (is_heap(tree->right)));
	else
		return (0);
}

/**
 * binary_tree_is_heap - Checks if a tree is a max heap.
 * @tree: The pointer to the root of the tree.
 * Return: If the tree is a max heap (1) or (0).
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (is_complete(tree, 0, count_nodes(tree)) && is_heap(tree))
		return (1);
	return (0);
}
