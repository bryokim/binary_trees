#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root.
 *
 * @node: Pointer to the node to be checked.
 *
 * Return: 1 if node is a root, 0 otherwise or if node is NULL.
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);

	return (1);
}
