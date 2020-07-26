#include "functions.h"

int main() {
    string expression;
    queue<string> expression_RPN;
    int value_of_expression;
    
    getExpression(expression);

    expression_RPN = representsExpression(expression); 
    value_of_expression = calculateExpressionValue(expression_RPN);
    
    cout << "Value of expression is: " << value_of_expression << endl;

    return 0;
}