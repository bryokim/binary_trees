#include "binary_trees.h"

/**
 * binary_tree_size - Measure the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The size of the binary tree.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (!tree)
	{
		return (0);
	}
	else
	{
		left_size = binary_tree_size(tree->left);
		right_size = binary_tree_size(tree->right);

		return (left_size + right_size + 1);
	}
}
