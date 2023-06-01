#include "binary_trees.h"

bst_t *insert_value(bst_t *tree, int value);

/**
 * bst_insert - Inserts a value in a BST.
 *
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the inserted node.
 *
 * Return: Pointer to the newly created node, or NULL if value already
 *	exists or if failure occurs.
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (insert_value(*tree, value));
}

/**
 * insert_value - Insert a value in a BST.
 *
 * @tree: Pointer to the root of the tree.
 * @value: Value of the new node to insert.
 *
 * Return: Pointer to the new node, or NULL if value is already in BST
 *      or if an error occurs.
*/
bst_t *insert_value(bst_t *tree, int value)
{
	bst_t *new_node;

	if ((!tree->left && value < tree->n) ||
	(!tree->right && value > tree->n))
	{

		new_node = binary_tree_node(tree, value);
		if (!new_node)
			return (NULL);

		if (value < tree->n)
			tree->left = new_node;
		else
			tree->right = new_node;

		return (new_node);
	}
	else
	{
		if (value == tree->n)
			return (NULL);
		else if (value < tree->n)
			return (insert_value(tree->left, value));
		else
			return (insert_value(tree->right, value));
	}
}
