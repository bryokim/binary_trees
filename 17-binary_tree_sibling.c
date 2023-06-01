#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 *
 * @node: Pointer to the node to find the sibling.
 *
 * Return: Pointer to the sibling node. If node is NULL or the parent is NULL
 *      returns NULL.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	else if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
