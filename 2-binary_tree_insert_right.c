#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * of another node.
 * @parent: a pointer to the node to insert the right child in.
 * @value: the value to put in the new node.
 * Return: a pointer to the new node, or NULL on failure or if parent is NULL.
 * Description: If parent already has a right-child, the new node must take its
 * place, and the old right-child must be set as the right-child
 * of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = node->right = NULL;

	if (parent->right != NULL)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}
	parent->right = node;

	return (node);
}
