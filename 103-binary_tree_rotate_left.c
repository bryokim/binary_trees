#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the rotated tree.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_tree = tree;

	if (tree && tree->right)
	{
		tree = tree->right;  /* Swap root with root->right */
		old_tree->right = tree->left;
		if (tree->left)
			tree->left->parent = old_tree;
		tree->left = old_tree;
		tree->parent = old_tree->parent;
		if (old_tree->parent)
		{
			if (old_tree->parent->left == old_tree)
				old_tree->parent->left = tree;
			else
				old_tree->parent->right = tree;
		}
		old_tree->parent = tree;
	}

	return (tree);
}
