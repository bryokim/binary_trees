#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using inorder traversal.
 *
 * @tree: pointer to the binary tree to traverse.
 * @func: Pointer to the function to call for each node.
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
