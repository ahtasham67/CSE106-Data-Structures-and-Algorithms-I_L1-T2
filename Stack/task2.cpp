#include <iostream>
#include <string>
#include <cctype>
#include "header.cpp"
using namespace std;

bool isValidExp(const string &exp);
bool matchPair(char open, char close);
float evaluateExp(const string &exp);
float applyOperator(char Operator, float operand1, float operand2);
int operatorPrecedence(char Operator);
bool isLeftAssociative(char Operator);

// to match the parenthesis to check the validation of the exp
bool matchPair(char open, char close)
{
    if ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'))
    {
        return true;
    }
    else
        return false;
}

// validation checking for parenthesis and consecutive +/-
bool isValidExp(const string &exp)
{
    Stack<char> stack;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') // checking validation for parenthesis
        {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stack.isEmpty() || matchPair(stack.topValue(), ch) == false)
            {
                return false;
            }
            else
                stack.pop();
        }
        else if (ch == '+' || ch == '-') // to check consecutive +/-
        {
            if (i > 0 && (exp[i - 1] == '+' || exp[i - 1] == '-'))
            {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

float applyOperator(char Operator, float operand1, float operand2)
{
    if (Operator == '+')
    {
        return operand1 + operand2;
    }
    else if (Operator == '-')
    {
        return operand1 - operand2;
    }
    else if (Operator == '*')
    {
        return operand1 * operand2;
    }
    else if (Operator == '/')
    {
        return operand1 / operand2;
    }
    return 0.0f;
}

bool isLeftAssociative(char Operator)
{
    if (Operator == '+' || Operator == '-' || Operator == '*' || Operator == '/')
    {
        return true;
    }
    return false;
}

int operatorPrecedence(char Operator)
{
    if (Operator == '*' || Operator == '/')
    {
        return 2;
    }
    else if (Operator == '+' || Operator == '-')
    {
        return 1;
    }
    return 0;
}

// the core code for evaluating the exp if valid
float evaluateExp(const string &exp)
{
    // first need two stacks: for operator and for operand
    Stack<float> operandStack;
    Stack<char> operatorStack;

    for (int i = 0; i < exp.length(); ++i)
    {
        char ch = exp[i];

        if (ch == ' ')
        {
            continue;
        }
        else if (isdigit(ch))
        {
            string operandStr;
            while (i < exp.length() && isdigit(exp[i]))
            {
                operandStr += exp[i];
                i++;
            }
            i--;
            float operand = stof(operandStr);
            operandStack.push(operand);
        }
        else if (ch == '(')
        {
            operatorStack.push(ch);
        }
        else if (ch == ')')
        {
            // open parenthesis na asha porjonto stack er element gula pop korte thkbo
            // and calculate kore abar operandStack e pathabo as operand
            while (!operatorStack.isEmpty() && operatorStack.topValue() != '(')
            {
                char op = operatorStack.topValue();
                operatorStack.pop();

                float operand2 = operandStack.topValue();
                operandStack.pop();
                float operand1 = operandStack.topValue();
                operandStack.pop();

                // operandstack e result ta firaye debo
                float result = applyOperator(op, operand1, operand2);
                operandStack.push(result);
            }
            operatorStack.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (ch == '-' && (i == 0 || exp[i - 1] == '(')) // for unary operations
            {
                // Handle unary minus negative number
                float operand = 0.0f;
                // bool isNegative = true;
                while (i + 1 < exp.length() && isdigit(exp[i + 1]))
                {
                    i++;
                    // operand = operand * 10.0f + (exp[i] - '0') * (isNegative ? -1.0f : 1.0f);
                    operand = operand * 10.0f + (exp[i] - '0') * (-1.0f);

                    // isNegative = false;
                }
                operandStack.push(operand);
            }

            else // except unary minus operation
            {
                while (!operatorStack.isEmpty() && operatorStack.topValue() != '(' && ((isLeftAssociative(ch) && operatorPrecedence(operatorStack.topValue()) >= operatorPrecedence(ch)) || (!isLeftAssociative(ch) && operatorPrecedence(operatorStack.topValue()) > operatorPrecedence(ch))))
                {
                    char op = operatorStack.topValue();
                    operatorStack.pop();

                    float operand2 = operandStack.topValue();
                    operandStack.pop();
                    float operand1 = operandStack.topValue();
                    operandStack.pop();

                    float result = applyOperator(op, operand1, operand2);
                    operandStack.push(result);
                }
                operatorStack.push(ch);
            }
        }
        else
        {
            cout << "Invalid exp: " << exp << endl;
            return 0.0f; // Return 0 to indicate failure
        }
    }

    while (!operatorStack.isEmpty())
    {
        char op = operatorStack.topValue();
        operatorStack.pop();

        float operand2 = operandStack.topValue();
        operandStack.pop();
        float operand1 = operandStack.topValue();
        operandStack.pop();

        float result = applyOperator(op, operand1, operand2);
        operandStack.push(result);
    }

    return operandStack.topValue();
}

int main()
{
    string Infixexpression;
    cout << "Enter the infix exp" << endl;
    getline(cin, Infixexpression);
    if (isValidExp(Infixexpression))
    {
        float result = evaluateExp(Infixexpression);
        cout << "The expression is valid" << endl;
        cout << "The computed value is: " << result << endl;
    }
    else
    {
        cout << "The expression is Invalid" << endl;
    }
    return 0;
}