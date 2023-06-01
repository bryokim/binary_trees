#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a BST.
 *
 * @tree: Pointer to the root of the BST to search.
 * @value: value to search in the tree.
 *
 * Return: Pointer to the node containing a value equals to value, or
 *      NULL if tree is NULL, or if nothing is found.
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
	{
		return (NULL);
	}
	else
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		else if (tree->n > value)
			return (bst_search(tree->left, value));
		else
			return (bst_search(tree->right, value));
	}
}
