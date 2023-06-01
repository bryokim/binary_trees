#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Number of nodes with at least 1 child. 0 if tree is NULL.
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (!tree || (!tree->left && !tree->right))
	{
		return (0);
	}
	else
	{
		left_nodes = binary_tree_nodes(tree->left);
		right_nodes = binary_tree_nodes(tree->right);

		return (left_nodes + right_nodes + 1);
	}
}
