#include "functions.h"

bool checkExpression(const string &expression) {
    int count_operand(0), count_operator(0), count_open_bracket(0), count_close_bracket(0), len;
    string operand;
    
    len = expression.length();
    
    for (int i = 0; i < len; i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (isDigit(expression[i]) == true) {
            operand = getOperandInExpression(expression, i);
            
            if (isOperand(operand))
                count_operand++;

        } else if (isOperator(expression[i])) {
            count_operator++;
            
            if (expression[i] == '-' && expression[i + 1] == '0') 
                return false;

        } else if (isBracket(expression[i]) == 1) {
            count_open_bracket++;
            
            if (expression[i + 1] == ')')
                return false;
        
        } else if (isBracket(expression[i]) == 2) {
            count_close_bracket++;
        } else {
            return false;
        } 
    }

    if ((count_operand != count_operator + 1) || (count_open_bracket != count_close_bracket))
        return false;
    return true;
}

void getExpression(string &expression) {
    cout << "- Operand is positive integer." << endl;
    cout << "- Operator: +, -, *, /" << endl;
    
    while (true) {
        cout << "Enter an expression: ";
        getline(cin, expression);

        if (checkExpression(expression) == false) {
            cout << "==> Invalid Expression." << endl;
            expression = "";
        } else {
            cout << "==> Valid Expression." << endl;
            return;
        }   
    }
}

string getOperandInExpression(const string &str, int &index) {
    string result = "";
    int len = str.length();
    bool flag = false;

    for (index; index < len; index++) {
        if (!isDigit(str[index]))
            break;
        
        result += str[index];
        flag = true;
    }

    if (flag) 
        index--;

    return result;
}

bool isDigit(const char &ch) {
    if ('0' <= ch && ch <= '9')
        return true;
    return false;
}

bool isOperand(const string &str) {
    for (const char &ch : str)
        if (!isDigit(ch))
            return false;

    return true;
}

int isOperator(const char &ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int isBracket(const char &ch) {
    if (ch == '(')
        return 1;
    else if (ch == ')')
        return 2;
    return 0;
}

int calculate(const int &a, const int &b, const char &__operator) {
    if (__operator == '+')
        return a + b;
    else if (__operator == '-')
        return a - b;
    else if (__operator == '*')
        return a * b;
    else if (__operator == '/')
        return a / b;
    return INT_MIN;
}

queue<string> representsExpression(const string &expression) {
    queue<string> result;
    stack<string> st;
    string temp, top_element;
    int len = expression.length();
    bool flag = true;

    for (int i = 0; i < len; i++) {
        temp = getOperandInExpression(expression, i);
        if (temp == "")
            temp += expression[i];
    
        if (temp == " ") {
            continue;
        
        } else if (isOperand(temp)) {
            result.push(temp);
        
        } else if (isOperator(temp[0])) {
            if (st.empty() == false) {
                top_element = st.top();
                
                while (isOperator(top_element[0]) > 0 && flag == true) {
                    if (isOperator(top_element[0]) >= isOperator(temp[0])) {
                        result.push(top_element);
                        st.pop();
                    } else {
                        break;
                    }

                    if (st.empty() == true)
                        break;
                    
                    top_element = st.top();
                }
            }

            flag = true;
            st.push(temp);
        
        } else if (isBracket(temp[0]) == 1) {
            st.push(temp);
        
        } else if (isBracket(temp[0]) == 2) {
            top_element = st.top();
            while (isBracket(top_element[0]) != 1) {
                result.push(top_element);
                st.pop();
                top_element = st.top();
            }

            st.pop();
        }
    }

    while (st.empty() == false) {
        result.push(st.top());
        st.pop();
    }

    return result;
}

int calculateExpressionValue(queue<string> &expression) {
    stack<string> result;
    string temp;
    int operand_1, operand_2;

    while (expression.empty() == false) {
        temp = expression.front();
        expression.pop();

        if (isOperand(temp)) {
            result.push(temp);
        } else if (isOperator(temp[0])) {
            if (result.size() < 2) {
                return INT_MIN;
            }

            operand_1 = stoi(result.top());
            result.pop();

            operand_2 = stoi(result.top());
            result.pop();

            result.push(to_string(calculate(operand_2, operand_1, temp[0])));
        }
    }

    if (result.size() == 1)
        return stoi(result.top());
    return INT_MIN;
}