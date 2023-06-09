#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node.
 *
 * Description: If parent has a left child, the new node takes its place and
 * the old left child is set as the left child of the new node.
 *
 * @parent: Pointer to the node to insert the left-child in.
 * @value: Value to store in new node.
 *
 * Return: Pointer to the new node, or NULL on failure or if parent is NULL.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_child;

	if (!parent)
		return (NULL);

	new_left_child = binary_tree_node(parent, value);
	if (!new_left_child)
		return (NULL);

	if (parent->left)
	{
		new_left_child->left = parent->left;
		parent->left->parent = new_left_child;
	}
	parent->left = new_left_child;

	return (new_left_child);
}
