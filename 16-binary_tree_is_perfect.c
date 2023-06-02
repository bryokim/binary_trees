#include "binary_trees.h"

size_t max_depth(const binary_tree_t *tree);
int check_is_full(const binary_tree_t *tree);
int check_depth(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if is perfect, 0 if otherwise.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else
	{
		return (check_is_full(tree) &&
			check_depth(tree));
	}
}

/**
 * check_depth - Checks the depth of all the subtrees.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if all depths are equal, 0 if otherwise.
 */
int check_depth(const binary_tree_t *tree)
{
	int depth;

	if (!tree || (!tree->left && !tree->right))
	{
		return (1);
	}
	else if ((tree->left && !tree->right) || (!tree->left && tree->right))
	{
		return (0);
	}
	else
	{
		depth = (max_depth(tree->left) == max_depth(tree->right));
		if (!depth)
			return (0);
		if (!check_depth(tree->left))
			return (0);
		if (!check_depth(tree->right))
			return (0);
		return (1);
	}
}
/**
 * max_depth - Find the max depth of a binary tree.
 *
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: Max depth of the binary tree.
*/
size_t max_depth(const binary_tree_t *tree)
{
	size_t right_depth, left_depth;

	if (!tree)
	{
		return (0);
	}
	else
	{
		left_depth = max_depth(tree->left);
		right_depth = max_depth(tree->right);

		if (left_depth > right_depth)
			return (left_depth + 1);
		else
			return (right_depth + 1);
	}
}

/**
 * check_is_full - Checks if a binary tree is full.
 *
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if is full, or 0 if otherwise.
*/
int check_is_full(const binary_tree_t *tree)
{
	int right_leaves, left_leaves;

	if (!tree || (!tree->left && tree->right) ||
		(tree->left && !tree->right))
	{
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		left_leaves = check_is_full(tree->left);
		if (!left_leaves && tree->left)
			return (0);

		right_leaves = check_is_full(tree->right);

		return ((left_leaves + right_leaves + 1) % 2);
	}
}
