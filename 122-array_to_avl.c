#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in array.
 *
 * Return: Pointer to the root of the new AVL.
*/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (array)
	{
		for (i = 0; i < size; i++)
			avl_insert(&root, *(array + i));
	}

	return (root);
}
