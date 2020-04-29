//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "ErrorsHandlings.h"

#define FALSE 0
#define TRUE 1
#define isNum(num) ((((num) >= '0') && ((num) <= '9')) ? TRUE : FALSE )

typedef struct treeNode {
    unsigned char data;
    struct treeNode *left;
    struct treeNode *right;
}TreeNode;

typedef struct tree {
    TreeNode *root;
}Tree;

//This function gets an array and creates a tree from it's values.TODO: Change description
int buildExpressionTree(char* str,Tree tr);

//This is an inner function. It create a tree from a given array. TODO: Change description
TreeNode* _build__Expression_tree(char* str,TreeNode* root,int* c);

//This function gets a value and creates a new leaf.
TreeNode* createLeaf(char ch);

//This function prints a given root's values in LDR order
void printTreeInorder(Tree tr);

//This is an inner function. It gets a root and print its tree's values in LDR form.
void _print_tree_inorder(TreeNode* root);

//This function frees a given tree's memory
void freeTree(Tree tr);

//This is an inner function. It gets a root and frees its tree's memory.
void _free_tree(TreeNode* root);


#endif