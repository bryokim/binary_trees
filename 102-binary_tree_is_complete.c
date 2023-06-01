#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int check_is_complete(const binary_tree_t *tree, int level,
	CHILD_NODES prev_node);
int check_child_nodes(const binary_tree_t *tree, CHILD_NODES prev_node);
CHILD_NODES present_nodes(binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if is complete, 0 otherwise.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	int balance, level;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	balance = left_height - right_height;

	if (balance > 1 || balance < -1)
		return (0);

	level = (left_height > right_height) ? left_height - 1 : right_height - 1;

	if (!check_is_complete(tree, level, DEFAULT))
		return (0);

	return (1);
}

/**
 * check_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root of the binary tree.
 * @level: Last level of the full tree from root.
 * @prev_node: Indicates the number of children in the last node checked.
 *
 * Return: 1 if is complete, or 0 if otherwise.
*/
int check_is_complete(const binary_tree_t *tree, int level,
	CHILD_NODES prev_node)
{
	int right_leaves, left_leaves;

	if (!tree || (!tree->left && tree->right) ||
		(tree->left && !tree->right))
	{
		return (0);
	}
	else if ((level <= 1) && tree->left && tree->right)
	{
		if (level == 1)
			return (check_child_nodes(tree, prev_node));
		else
			return (1);
	}
	else
	{
		left_leaves = check_is_complete(tree->left, level - 1, prev_node);
		if (!left_leaves && tree->left)
			return (0);

		right_leaves = check_is_complete(tree->right, level - 1, left_leaves);
		if (!right_leaves && tree->right)
			return (0);

		return (right_leaves);
	}
}

/**
 * check_child_nodes - Check whether the given node has the correct child nodes
 *	for a complete tree.
 *
 * @tree: Pointer to the node to check for the correct child nodes.
 * @prev_node: Child nodes in the previous node checked.
 *
 * Return: If the child nodes are valid, then the children in the right
 *	node are returned. 0 if the child nodes are invalid.
*/
int check_child_nodes(const binary_tree_t *tree, CHILD_NODES prev_node)
{
	CHILD_NODES left_node, right_node;

	left_node = present_nodes(tree->left);
	right_node = present_nodes(tree->right);

	if (prev_node == LEFT && left_node == LEFT)
		return (0);
	else if (prev_node == NONE && left_node != NONE)
		return (0);

	if (left_node == RIGHT || right_node == RIGHT)
		return (0);
	else if (left_node == LEFT && right_node == LEFT)
		return (0);
	else if (left_node == NONE && right_node != NONE)
		return (0);

	return (right_node);
}

/**
 * present_nodes - Checks for the child nodes present in the given node.
 *
 * @tree: Pointer to the node to check for the children.
 *
 * Return:
 *	1 if no children were present (NONE)
 *	2 if only the left child is present (LEFT)
 *	3 if only the right child is present (RIGHT)
 *	4 if both children are present (BOTH)
*/
CHILD_NODES present_nodes(binary_tree_t *tree)
{
	if (tree->left && tree->right)
		return (BOTH);
	else if (tree->left && !tree->right)
		return (LEFT);
	else if (!tree->left && tree->right)
		return (RIGHT);
	else
		return (NONE);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree. If tree is NULL 0 is returned.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height;
	size_t left_height;

	if (!tree)
	{
		return (0);
	}
	else
	{
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);

		if (left_height > right_height)
			return (left_height + 1);
		else
			return (right_height + 1);
	}
}
