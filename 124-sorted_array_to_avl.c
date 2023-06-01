#include "binary_trees.h"

avl_t *insert_nodes(size_t lo, size_t hi, int *array, avl_t *tree);

/**
 * sorted_array_to_avl - Builds an AVL tree from an array.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL
 *      on failure.
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL, *new_node;
	size_t midpoint = size / 2;

	root = binary_tree_node(NULL, array[midpoint]);
	if (!root)
		return (NULL);

	new_node = insert_nodes(0, midpoint, array, root);
	if (!new_node)
		return (NULL);

	new_node = insert_nodes(midpoint + 1, size, array, root);
	if (!new_node)
		return (NULL);

	return (root);
}

/**
 * insert_nodes - Inserts nodes from a sorted array into an AVL.
 *
 * @lo: Lowest index in the array.
 * @hi: Highest index in the array
 * @array: Pointer to the array with elements to insert.
 * @tree: Pointer to the parent of the new node.
 *
 * Return: Pointer to the last created node, or NULL on failure.
*/
avl_t *insert_nodes(size_t lo, size_t hi, int *array, avl_t *tree)
{
	size_t midpoint;
	avl_t *new_node, *is_null;

	if (lo >= hi)
	{
		return (tree);
	}
	else
	{
		midpoint = ((hi + lo) / 2);
		new_node = binary_tree_node(tree, array[midpoint]);

		if (!new_node)
			return (NULL);

		if (new_node->n < tree->n)
			tree->left = new_node;
		else
			tree->right = new_node;

		is_null = insert_nodes(lo, midpoint, array, new_node);
		if (!is_null)
			return (NULL);

		is_null = insert_nodes(midpoint + 1, hi, array, new_node);
		if (!is_null)
			return (NULL);

		return (is_null);
	}

}
