//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#include "Tree.h"

int buildExpressionTree(char* str,Tree* tr){
    if(isValidString(str) == FALSE) return FALSE;
    tr->root = _build_Expression_tree(str,tr->root);
    return TRUE;
}

TreeNode* _build_Expression_tree(char* str,TreeNode* root){
    int leftStrSize;
    char* rightStr = skipToSource(str,&leftStrSize);
    char* leftStr = str+1; //Remove first '(' in order to get down a level

    root = createLeaf(rightStr[0]); //Set new source

    //Set leafs if exist OR set inner sources instead
    if(isNum(leftStr[leftStrSize-1]) && isNum(rightStr[1])){
        root->left = createLeaf(leftStr[leftStrSize-1]);
        root->right = createLeaf(rightStr[1]);
    }
    else if(isNum(rightStr[1])){
        root->right = createLeaf(rightStr[1]);
        root->left = _build_Expression_tree(leftStr,root->left);
    }
    else if (isNum(leftStr[leftStrSize-1])){
        root->left = createLeaf(leftStr[leftStrSize-1]);
        root->right = _build_Expression_tree(rightStr+1,root->right);
    }else{
        root->left = _build_Expression_tree(leftStr,root->left);
        root->right = _build_Expression_tree(rightStr+1,root->right);
    }

    return root;
}

char* skipToSource(char* str, int* leftStrSize){
    int counter = 0,i = 0;
    //The source will always be an operator between only one pair of parenthesis, hence:
    while(!(counter == 1 && isOperator(str[i]))){
            if(str[i] == '(') counter++;
            if(str[i] == ')') counter--;
            i++;
    }
    *leftStrSize = i-1;
    return str+i;
}


BOOL isValidString(char* str){
    int counter = 0;
    for(int i=0 ; str[i] != EOS ; i++){
        if((!isValidChar(str[i])) || ((isNum(str[i])) && (isNum(str[i+1]))))
            return FALSE;
        if(str[i] == '(') counter++;
        if(str[i] == ')') counter--;
    }
    return (counter == 0)? TRUE : FALSE;
}

double calcExpression(Tree tr){
    float result = _calc_expression(tr.root);
    return result;
}

double _calc_expression(TreeNode* root){
    float result;
    switch (root->data){
        case '-':
            result = _calc_expression(root->left) - _calc_expression(root->right);
            break;
        case '+':
            result = _calc_expression(root->left) + _calc_expression(root->right);
            break;
        case '*':
            result = _calc_expression(root->left) * _calc_expression(root->right);
            break;
        case '/':
            result = _calc_expression(root->left) / _calc_expression(root->right);
            break;
        case '%':
            result = (int)(_calc_expression(root->left)) % (int)(_calc_expression(root->right));
            break;
        default:
            result = parseInt(root->data);
    }
    return result;
}


TreeNode* createLeaf(char ch){
    TreeNode* newLeaf = (TreeNode*)malloc(sizeof(TreeNode));
    checkMemoryAllocation(newLeaf);
    newLeaf->data = ch;
    newLeaf->left = NULL;
    newLeaf->right = NULL;
    return newLeaf;
}

void printTreeInorder(Tree tr){
    _print_tree_inorder(tr.root);
}

void _print_tree_inorder(TreeNode* root){
    if(root == NULL) return;
    _print_tree_inorder(root->left);
    printf("%c ",root->data);
    _print_tree_inorder(root->right);
}

void freeTree(Tree tr){
    _free_tree(tr.root);
}

void _free_tree(TreeNode* root){
    if(root == NULL) return;
    _free_tree(root->left);
    _free_tree(root->right);
    free(root);
}