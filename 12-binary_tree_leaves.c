#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: pointer to the root node of the tree.
 *
 * Return: Number of leaves. 0 if tree is NULL.
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves, right_leaves;

	if (!tree)
	{
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		left_leaves = binary_tree_leaves(tree->left);
		right_leaves = binary_tree_leaves(tree->right);

		return (left_leaves + right_leaves);
	}
}
