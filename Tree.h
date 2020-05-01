//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "ErrorsHandlings.h"

typedef int BOOL;
#define FALSE 0
#define TRUE 1
#define EOS '\0'

//TODO: Add description
#define isNum(num) ((((num) >= '0') && ((num) <= '9')) ? TRUE : FALSE )
//TODO: Add description
#define isOperator(char) ((char == '*') || (char == '/') || (char == '-') || (char == '+') || (char == '%'))
//TODO: Add description
#define isValidChar(char) ((isOperator(char)) || (isNum(char)) || (char == '(') || (char == ')'))
//TODO: Add description
#define parseInt(char) ((char) - '0')




typedef struct treeNode {
    unsigned char data;
    struct treeNode *left;
    struct treeNode *right;
}TreeNode;

typedef struct tree {
    TreeNode *root;
}Tree;

//This function gets an array and creates a tree from it's values.TODO: Change description
int buildExpressionTree(char* str,Tree* tr);

//This is an inner function. It create a tree from a given array. TODO: Change description
TreeNode* _build_Expression_tree(char* str,TreeNode* root);

//This method gets a string and returns the string starts from the first operator between only one pair of parenthesis
char* skipToSource(char* str,int* leftStrSize);

//This method gets a string and returns TRUE if valid; FALSE otherwise.
BOOL isValidString(char* str);

//TODO: Add description!!!
double calcExpression(Tree tr);

//TODO: Add description
double _calc_expression(TreeNode* root);

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