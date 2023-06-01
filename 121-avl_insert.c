#include "binary_trees.h"

avl_t *insert_value(avl_t *tree, int value);
avl_t *balance_left(avl_t **node);
avl_t *balance_right(avl_t **node);

/**
 * avl_insert - Inserts a value in a AVL.
 *
 * @tree: Double pointer to the root node of the AVL to insert the value.
 * @value: Value to store in the inserted node.
 *
 * Return: Pointer to the newly created node, or NULL if value already
 *	exists or if failure occurs.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *root, *temp;
	int balance_factor;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new_node = insert_value(*tree, value);
	if (!new_node)
		return (NULL);

	temp = new_node->parent;
	while (temp)
	{
		root = NULL;
		balance_factor = binary_tree_balance(temp);

		if (balance_factor > 1)
			root = balance_left(&temp);
		else if (balance_factor < -1)
			root = balance_right(&temp);

		temp = temp->parent;

		if (!temp && root)
			*tree = root;
	}

	return (new_node);
}

/**
 * balance_left - Balances AVL if the left tree is greater than the right.
 *
 * @node: Double pointer to the root of the tree to balance.
 *
 * Return: Pointer to the root of the tree after balancing.
*/
avl_t *balance_left(avl_t **node)
{
	int balance_factor;
	avl_t *root;

	binary_tree_rotate_left((*node)->left);

	balance_factor = binary_tree_balance((*node)->left);
	if (balance_factor > 1)
	{
		binary_tree_rotate_right((*node)->left->left);
		binary_tree_rotate_left((*node)->left);
	}

	root = binary_tree_rotate_right(*node);
	*node = (*node)->parent;

	return (root);
}

/**
 * balance_right - Balances AVL if the right tree is greater than the left.
 *
 * @node: Double pointer to the root of the tree to balance.
 *
 * Return: Pointer to the root of the tree after balancing.
*/
avl_t *balance_right(avl_t **node)
{
	int balance_factor;
	avl_t *root;

	binary_tree_rotate_right((*node)->right);

	balance_factor = binary_tree_balance((*node)->right);
	if (balance_factor < -1)
	{
		binary_tree_rotate_left((*node)->right->right);
		binary_tree_rotate_right((*node)->right);
	}

	root = binary_tree_rotate_left(*node);
	*node = (*node)->parent;

	return (root);
}

/**
 * insert_value - Insert a value in a AVL.
 *
 * @tree: Pointer to the root of the tree.
 * @value: Value of the new node to insert.
 *
 * Return: Pointer to the new node, or NULL if value is already in BST
 *      or if an error occurs.
*/
avl_t *insert_value(avl_t *tree, int value)
{
	avl_t *new_node;

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
