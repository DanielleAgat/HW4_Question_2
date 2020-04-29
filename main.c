//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

/* This program
 * TODO: FILL!!!
 */

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

typedef int BOOL;
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

