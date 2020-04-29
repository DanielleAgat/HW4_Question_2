//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#include "Tree.h"

int buildExpressionTree(char* str,Tree tr){
    int counter = 0;
    tr.root = _build__Expression_tree(str,tr.root,&counter);

    if(counter != 0) return FALSE;
}

TreeNode* _build__Expression_tree(char* str,TreeNode* root,int* c){
    int counter = *c;
    if(str[0] == '(') counter++;
    if(str[0] == ')') counter--;

    if(isNum(str[0]) == TRUE && root->left == NULL){ // Numbers are always leafs
        root->left = createLeaf(str[0]);
        root = _build__Expression_tree(str++,root,&counter);
        return root;
    }else if(isNum(str[0]) == TRUE && root->right == NULL){
        root->right = createLeaf(str[0]);
        return root;
    }
    if(str[0] == '*' || str[0] == '/' || str[0] == '-' || str[0] == '+' ){
        if(counter == 1){
            //This is the root source
        }
    }
    //Insert an operator and add leafs

//    root = createLeaf(arr[midIndex]);
//    root->left = _build_tree_from_array(arr,midIndex,root->left);
//    root->right = _build_tree_from_array(arr + midIndex +1 ,size - midIndex - 1,root->right);
    *c = counter;
    return root;
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