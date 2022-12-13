#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node.
 * @parent: a pointer to the parent node of the node to create.
 * @value: the value to put in the new node.
 * Return: a pointer to the new node, or NULL on failure.
 * Description: When created, a node does not have any child.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = node->right = NULL;

	if (parent)
	{
		if (parent->left == NULL)
			parent->left = node;
		else if (parent->right == NULL)
			parent->right = node;
		else
			return (NULL);
	}
	return (node);
}
