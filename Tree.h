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

//This Macro returns TRUE if a given char represents a digit; FALSE otherwise.
#define isNum(num) ((((num) >= '0') && ((num) <= '9')) ? TRUE : FALSE )
//This Macro returns True if a given char represents a valid operator ('+','-','*','/','%') ; False otherwise.
#define isOperator(char) ((char == '*') || (char == '/') || (char == '-') || (char == '+') || (char == '%'))
//This Macro returns True if a given char is a valid char(num/operator/parenthesis) ; False otherwise.
#define isValidChar(char) ((isOperator(char)) || (isNum(char)) || (char == '(') || (char == ')'))
//This Macro returns the given char digit as an integer.
#define parseInt(char) ((char) - '0')




typedef struct treeNode {
    unsigned char data;
    struct treeNode *left;
    struct treeNode *right;
}TreeNode;

typedef struct tree {
    TreeNode *root;
}Tree;

// This function gets a string of a mathematical expression and creates an expression tree if valid.
// Returns TRUE if the expression was valid; FALSE otherwise.
int buildExpressionTree(char* str,Tree* tr);

//This is an inner function. It creates an expression tree if valid.
TreeNode* _build_Expression_tree(char* str,TreeNode* root);

//This method gets a string and returns the string starts from the first operator between only one pair of parenthesis
char* skipToSource(char* str,int* leftStrSize);

//This method gets a string and returns TRUE if valid; FALSE otherwise.
BOOL isValidString(char* str);

//This method gets an expression tree and returns its mathematical value.
double calcExpression(Tree tr);

//This is an inner function. It gets an expression tree and returns its mathematical value.
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