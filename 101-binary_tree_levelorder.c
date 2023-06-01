#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void get_current_level_nodes(const binary_tree_t *tree,
	void (*func)(int), size_t level);

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * traversal.
 *
 * @tree: Pointer to the root node of the binary tree.
 * @func: Pointer to a function to call on each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i;
	size_t height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
		get_current_level_nodes(tree, func, i);
}

/**
 * get_current_level_nodes - Get nodes on given level.
 *
 * @tree: Pointer to the root of the binary tree.
 * @func: Pointer to a function to call for each node.
 * @level: Level of the binary tree to get.
*/
void get_current_level_nodes(const binary_tree_t *tree,
	void (*func)(int), size_t level)
{
	if (!tree)
	{
		return;
	}
	else if (level == 0)
	{
		func(tree->n);
	}
	else
	{
		get_current_level_nodes(tree->left, func, level - 1);
		get_current_level_nodes(tree->right, func, level - 1);
	}
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
