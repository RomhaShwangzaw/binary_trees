#include "binary_trees.h"

/**
 * min_value_node - finds the node with minimum key value found in that tree.
 * @tree: a pointer to the root node of the tree where we will search for
 * the minimum key.
 *
 * Return: the node with minimum key value found in that tree.
 */
bst_t *min_value_node(bst_t *tree)
{
	while (tree && tree->left)
		tree = tree->left;
	return (tree);
}

/**
 * bst_remove - removes a node from a Binary Search Tree.
 * @root: a pointer to the root node of the tree where you will remove a node.
 * @value: the value to remove in the tree.
 * Return: a pointer to the new root node of the tree after removing the
 * desired value.
 *
 * Description: Once located, the node containing a value equals to value
 * must be removed and freed.
 * If the node to be deleted has two children, it must be replaced with
 * its first in-order successor (not predecessor).
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* node with only one child or no child */
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		/*
		 * node with two children. Get the inorder successor
		 * (smallest in the right subtree)
		 */
		tmp = min_value_node(root->right);

		/* Copy the inorder successor's content to this node */
		root->n = tmp->n;

		/* Delete the inorder successor */
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
