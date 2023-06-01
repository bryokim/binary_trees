#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full, 0 if not full or tree is NULL.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int right_leaves, left_leaves;

	if (!tree || (!tree->left && tree->right) ||
		(tree->left && !tree->right))
	{
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		left_leaves = binary_tree_is_full(tree->left);
		if (!left_leaves && tree->left)
			return (0);
		printf("Brian\n");

		right_leaves = binary_tree_is_full(tree->right);

		return ((left_leaves + right_leaves + 1) % 2);
	}
}
