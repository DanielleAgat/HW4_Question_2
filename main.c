//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

/* This program gets a mathematical expression and creates an expression tree.
 * If the expression was valid then it calculates and prints its value.
 */

#include <stdio.h>
#include "Tree.h"


#define SIZE 100

void main(){
    char str[SIZE];
    Tree tr;
    double res;
    BOOL expressionOK;
    printf("Please enter the expression: ");
    gets(str);
    expressionOK = buildExpressionTree(str, &tr);

    if(expressionOK == TRUE){
        res = calcExpression(tr);
        printf("%s = %.2f", str, res);
    } else
        printf("The input expression is not valid\n");
    freeTree(tr);
}

