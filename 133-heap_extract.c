#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

heap_t *sift_up(heap_t *node);
void sift_down(heap_t *node, heap_t *root);
void sift_all_left(heap_t *root);
void sift_all_right(heap_t *root);

int heap_extract(heap_t **root)
{
        heap_t *node;
        int temp;

        if ((*root)->left->n > (*root)->right->n)
                node = sift_up((*root)->left);
        else
                node = sift_up((*root)->right);


        sift_down(node, *root);

        temp = (*root)->n;
        free(*root);
        *root = node;

        sift_all_left((*root)->left);
        sift_all_right((*root)->right);
        
        return (temp);
}

void sift_all_left(heap_t *root)
{
        if (!root || (!root->right && !root->left))
        {
                return;
        }
        else
        {
                sift_up(root);
                sift_all_left(root->left);
        }
}

void sift_all_right(heap_t *root)
{
        if (!root || (!root->right && !root->left))
        {
                return;
        }
        else
        {
                sift_all_right(root->right);
                sift_all_right(root->left);
                sift_up(root);
        }
}

heap_t *sift_up(heap_t *node)
{
        heap_t *temp, *left, *right;

        if (node->left && node->left->n > node->n)
        {
                if (node->right && node->right->n > node->left->n)
                        return (sift_up(node->right));
                else
                        return (sift_up(node->left));
        }
        else if (node->right && node->right->n > node->n)
        {
                return (sift_up(node->right));
        }

        if (node->parent && node->parent->parent)
        {
                temp = node->parent;
                left = temp->left;
                right = temp->right;

                if (node->left)
                        node->left->parent = temp;
                if (node->right)
                        node->right->parent = temp;

                if (temp->parent->left == temp)
                        temp->parent->left = node;
                else
                        temp->parent->right = node;

                node->parent = temp->parent;
                temp->parent = node;
                temp->left = node->left;
                temp->right = node->right;

                if (node == left)
                {
                        if (right)
                                right->parent = node;
                        node->left = temp;
                        node->right = right;
                }
                else
                {
                        if (left)
                                left->parent = node;
                        node->right = temp;
                        node->left = left;
                }
        }
        return (node);
}

void sift_down(heap_t *node, heap_t *root)
{
        heap_t *temp, *right, *left;

        if (!root)
                return;

        node->parent = root->parent;

        if (node == root->left)
        {
                if (root->right)
                        root->right->parent = node;
                right = node->right;
                node->right = root->right;

                while (right && node->left)
                {
                        temp = right;
                        right = node->left->right;
                        node->left->right = temp;
                        temp->parent = node->left;
                        node = node->left;
                }
                if (right && !node->left)
                        node->left = right;
        }
        else
        {
                if (root->left)
                        root->left->parent = node;
                left = node->left;
                node->left = root->left;

                while (left && node->right)
                {
                        temp = left;
                        left = node->right->left;
                        node->right->left = temp;
                        temp->parent = node->right;
                        node = node->right;
                }
                if (left && !node->right)
                        node->right = left;
        }
}
