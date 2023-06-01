#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

bst_t *search(bst_t *root, int value);
bst_t *get_swap_node(const bst_t *node, int val);
void swap_values_if_not_parent(bst_t *swap_node, bst_t *node_to_remove);
void swap_values_if_parent(bst_t *swap_node, bst_t *node_to_remove);

/**
 * bst_remove - Removes a node from the BST.
 *
 * Description: If the node to be deleted has two children, it is replaced
 *	with its first in-order successor (not predecessor)
 * @root: Pointer to the root node of the BST.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the root node of the resulting tree.
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_to_remove, *swap_node;

	node_to_remove = search(root, value);
	if (!node_to_remove)
		return (root);

	swap_node = (node_to_remove->right && node_to_remove->left) ?
		get_swap_node(node_to_remove->right, node_to_remove->n) :
		get_swap_node(node_to_remove, node_to_remove->n);

	if (swap_node != node_to_remove)
	{
		if (swap_node->parent != node_to_remove)
			swap_values_if_not_parent(swap_node, node_to_remove);
		else
			swap_values_if_parent(swap_node, node_to_remove);

		if (node_to_remove->parent)
		{
			if (node_to_remove == node_to_remove->parent->left)
				node_to_remove->parent->left = swap_node;
			else
				node_to_remove->parent->right = swap_node;
		}
		swap_node->parent = node_to_remove->parent;
	}
	else
	{
		if (swap_node == swap_node->parent->left)
			swap_node->parent->left = NULL;
		else
			swap_node->parent->right = NULL;
	}
	free(node_to_remove);
	if (swap_node && !swap_node->parent)
		return (swap_node);
	else
		return (root);
}

/**
 * search - Finds the node to remove.
 *
 * @root: Pointer to the root of the BST.
 * @value: value of the node to find.
 *
 * Return: Pointer to the node with the given value.
*/
bst_t *search(bst_t *root, int value)
{
	if (!root)
	{
		return (NULL);
	}
	else
	{
		if (root->n == value)
			return (root);
		else if (root->n > value)
			return (search(root->left, value));
		else
			return (search(root->right, value));
	}
}

/**
 * get_swap_node - Get the node to take place of the one being deleted.
 *
 * @node: Pointer to the node to remove if it has one child. Should be
 *	given as pointer to the right child of the node to remove if it
 *	has both children.
 * @val: Value of the node to remove.
 *
 * Return: Pointer to the node to swap with the one to remove.
*/
bst_t *get_swap_node(const bst_t *node, int val)
{
	if (!node->right && !node->left)
		return ((bst_t *)node);

	if (node->right && node->left && node->right->left &&
	(node->left->n - val) > (node->right->left->n - val))
		return (get_swap_node(node->right->left, val));
	else if (node->left)
		return (get_swap_node(node->left, val));
	else if (node->right)
		return (node->right);

	return ((bst_t *)node);
}

/**
 * swap_values_if_not_parent - Gives the swap node its new pointer values if
 *	node to be deleted is not parent of the swap node.
 *
 * @swap_node: Pointer to occupy place of the deleted node.
 * @node_to_remove: Pointer to the node to be deleted.
*/
void swap_values_if_not_parent(bst_t *swap_node, bst_t *node_to_remove)
{
	if (swap_node->parent->left == swap_node)
		swap_node->parent->left = NULL;
	else
		swap_node->parent->right = NULL;

	swap_node->left = node_to_remove->left;
	swap_node->right = node_to_remove->right;

	if (node_to_remove->left)
		node_to_remove->left->parent = swap_node;
	if (node_to_remove->right)
		node_to_remove->right->parent = swap_node;
}

/**
 * swap_values_if_parent - Gives the swap node its new pointer values if node
 *	to be deleted is the parent of the swap node.
 *
 * @swap_node: Pointer to occupy place of the deleted node.
 * @node_to_remove: Pointer to the node to be deleted.
*/
void swap_values_if_parent(bst_t *swap_node, bst_t *node_to_remove)
{
	if (swap_node == node_to_remove->left)
	{
		swap_node->right = node_to_remove->right;
		if (node_to_remove->right)
			node_to_remove->right->parent = swap_node;
	}
	else
	{
		swap_node->left = node_to_remove->left;
		if (node_to_remove->left)
			node_to_remove->left->parent = swap_node;
	}
}
