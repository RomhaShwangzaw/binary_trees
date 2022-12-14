#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);
binary_tree_t *lowest_common_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: a pointer to the node to measure the depth.
 * Return: 0 if tree is NULL, or the depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent)
	{
		tree = tree->parent;
		++depth;
	}
	return (depth);
}

/**
 * lowest_common_ancestor - finds lowest common ancestor of two nodes.
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 * Return: a pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if ancestor not found.
 */
binary_tree_t *lowest_common_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	while (second)
	{
		if (second == first)
			return ((binary_tree_t *)second);
		second = second->parent;
	}
	return (NULL);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 * Return: a pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if ancestor not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first, depth_second;
	binary_tree_t *tmp;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_first < depth_second)
	{
		while (first)
		{
			tmp = lowest_common_ancestor(first, second);
			if (tmp)
				return (tmp);
			first = first->parent;
		}
	}
	else
	{
		while (second)
		{
			tmp = lowest_common_ancestor(second, first);
			if (tmp)
				return (tmp);
			second = second->parent;
		}
	}
	return (NULL);
}
