#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int check_bst_nodes(binary_tree_t *tree, size_t level, int val,
	int (*func)(binary_tree_t *, int));
int check_right(binary_tree_t *tree, int val);
int check_left(binary_tree_t *tree, int val);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if is valid BST, or 0 if otherwise.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	size_t i, height;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);

	for (i = 0; i < height; i++)
	{
		if (!(check_bst_nodes(tree->left, i, tree->n, &check_left) &&
		check_bst_nodes(tree->right, i, tree->n, &check_right)))
			return (0);
	}
	return (1);
}

/**
 * check_bst_nodes - Check nodes on a given level are valid BST nodes.
 *
 * @tree: Pointer to the root of the binary tree.
 * @level: Level of the binary tree to get.
 * @val: Value of the root node.
 * @func: Pointer to the function to apply on every node.
 *
 * Return: 1 if tree is a valid bst, 0 if otherwise.
*/
int check_bst_nodes(binary_tree_t *tree, size_t level, int val,
	int (*func)(binary_tree_t *tree, int val))
{
	int left, right;

	if (!tree)
	{
		return (1);
	}
	else if (level == 0)
	{
		return (func(tree, val));
	}
	else
	{
		left = check_bst_nodes(tree->left, level - 1, val, func);
		if (!left)
			return (0);

		right = check_bst_nodes(tree->right, level - 1, val, func);

		return (left && right);
	}
}

/**
 * check_left - Checks that the left child of a node is valid BST node.
 *
 * @tree: Pointer to the node to check.
 * @val: Value of the root node of the binary tree.
 *
 * Return: 1 if tree is valid left child in a BST, or 0 if otherwise.
*/
int check_left(binary_tree_t *tree, int val)
{
	return ((tree == tree->parent->left) ?
		(tree->n < tree->parent->n) :
		(tree->n > tree->parent->n && tree->n < val));
}

/**
 * check_right - Checks that the right child of a node is valid BST node.
 *
 * @tree: Pointer to the node to check.
 * @val: Value of the root node of the binary tree.
 *
 * Return: 1 if tree is valid right child in a BST, or 0 if otherwise.
*/
int check_right(binary_tree_t *tree, int val)
{
	return ((tree == tree->parent->left) ?
		(tree->n < tree->parent->n && tree->n > val) :
		(tree->n > tree->parent->n));
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

	if (!tree || (!tree->right && !tree->left))
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
