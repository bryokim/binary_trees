#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node as the right child of another node.
 *
 * Description: If parent already has a right child the new node takes its
 * place and the old right child isset as the right child of the new node.
 *
 * @parent: Pointer to the node to insert the right child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node, or Null on failure or if parent is NULL.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right_child;

	if (!parent)
		return (NULL);

	new_right_child = binary_tree_node(parent, value);
	if (!new_right_child)
		return (NULL);

	if (parent->right)
	{
		new_right_child->right = parent->right;
		parent->right->parent = new_right_child;
	}
	parent->right = new_right_child;

	return (new_right_child);
}
