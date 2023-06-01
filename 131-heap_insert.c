#include "binary_trees.h"

int is_perfect(const binary_tree_t *tree);
heap_t *get_parent(heap_t *root, int value);
size_t max_depth(const binary_tree_t *tree);
int check_is_full(const binary_tree_t *tree);
void balance_heap(heap_t *root, heap_t *new_node);

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the heap to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *new_node;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	node = get_parent(*root, value);
	new_node = binary_tree_node(node, value);
	if (!new_node)
		return (NULL);

	if (node->n > value)
	{
		if (node->left)
			node->right = new_node;
		else
			node->left = new_node;
	}
	if (node->n < value)
	{
		balance_heap(node, new_node);
	}

	if (!new_node->parent)
		*root = new_node;

	return (new_node);
}

/**
 * balance_heap - Balances the heap maintaining the correct ordering
 *      if value is to be inserted before the parent that has been gotten.
 *
 * @root: Node to insert the new node before.
 * @new_node: Node to insert before the root.
*/
void balance_heap(heap_t *root, heap_t *new_node)
{
	heap_t *node;

	new_node->parent = root->parent;
	if (root->parent)
	{
		if (root->parent->left == root)
			root->parent->left = new_node;
		else
			root->parent->right = new_node;
	}

	new_node->left = root->left;
	new_node->right = root->right;
	if (root->left)
		root->left->parent = new_node;
	if (root->right)
		root->right->parent = new_node;

	node = get_parent(root, root->n);

	if (root == node)
	{
		if (!new_node->right && !new_node->left)
			new_node->left = node;
		else if (new_node->left)
			new_node->right = node;
		else
			new_node->left = node;

		node->parent = new_node;
		node->left = NULL;
		node->right = NULL;

		return;
	}

	balance_heap(node, root);

}

/**
 * get_parent - Gets the parent from which to insert the new node.
 *
 * Description: The parent gotten might not be the actual parent of
 *      the new node to insert if the value to insert is greater than the
 *      parent's value. In that case the balancing function is usd to place
 *      each node in its correct position.
 *
 * @root: Pointer to the root of the tree.
 * @value: Value of the node to be inserted.
 *
 * Return: Pointer to the parent where to insert the new node.
*/
heap_t *get_parent(heap_t *root, int value)
{
	if (root->n < value || !root->right || !root->left)
		return (root);

	if (!is_perfect(root->left))
	{
		return (get_parent(root->left, value));
	}
	else if (!is_perfect(root->right))
	{
		return (get_parent(root->right, value));
	}
	else
	{
		if (max_depth(root->right) < max_depth(root->left))
			return (get_parent(root->right, value));
		else
			return (get_parent(root->left, value));
	}
	return (root);
}


/**
 * is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if is perfect, 0 if otherwise.
*/
int is_perfect(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else
	{
		return (check_is_full(tree) &&
			(max_depth(tree->left) == max_depth(tree->right)));
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
