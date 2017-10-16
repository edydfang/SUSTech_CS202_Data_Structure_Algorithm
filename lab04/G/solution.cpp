#include <iostream>
#include <cstring>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#define MAXSIZE 100
using namespace std;

// get weight of operators as per precedence
// higher weight given to operators with higher precedence
// for non operators, return 0
int getWeight(char ch)
{
      switch (ch)
      {
      case '^':
            return 3;
      case '/':
      case '*':
            return 2;
      case '+':
      case '-':
            return 1;
      default:
            return 0;
      }
}

// convert infix expression to postfix using a stack
void infix2postfix(char infix[], char postfix[], int size)
{
      stack<char> s;
      int weight;
      int i = 0;
      int k = 0;
      int has_num = 0;
      char ch;
      // iterate over the infix expression
      while (i < size)
      {
            ch = infix[i];
            if(!isdigit(ch)){
                  if(has_num){
                        postfix[k++] = '|';
                  }
                  has_num = 0;
            }
            if (ch == '(')
            {
                  // simply push the opening parenthesis
                  s.push(ch);
                  i++;
                  continue;
            }
            if (ch == ')')
            {
                  // if we see a closing parenthesis,
                  // pop of all the elements and append it to
                  // the postfix expression till we encounter
                  // a opening parenthesis
                  while (!s.empty() && s.top() != '(')
                  {
                        postfix[k++] = s.top();
                        s.pop();
                  }
                  // pop off the opening parenthesis also
                  if (!s.empty())
                  {
                        s.pop();
                  }
                  i++;
                  continue;
            }
            weight = getWeight(ch);
            if (weight == 0)
            {
                  // we saw an operand
                  // simply append it to postfix expression
                  if(!has_num){
                        has_num = 1;
                        postfix[k++] = '|';
                  }
                  postfix[k++] = ch;
                  
            }
            else
            {
                  // we saw an operator
                  if (s.empty())
                  {
                        // simply push the operator onto stack if
                        // stack is empty
                        s.push(ch);
                  }
                  else
                  {
                        // pop of all the operators from the stack and
                        // append it to the postfix expression till we
                        // see an operator with a lower precedence that
                        // the current operator
                        while (!s.empty() && s.top() != '(' &&
                               weight <= getWeight(s.top()))
                        {
                              postfix[k++] = s.top();
                              s.pop();
                        }
                        // push the current operator onto stack
                        s.push(ch);
                  }
            }
            i++;
      }
      if(isdigit(postfix[k-1])){
            postfix[k++] = '|';
      }
      // pop of the remaining operators present in the stack
      // and append it to postfix expression
      while (!s.empty())
      {
            postfix[k++] = s.top();
            s.pop();
      }
      postfix[k] = 0; // null terminate the postfix expression
}

int calculate(char postfix[],int size)
{
      int i, tmp_num = 0, has_num = 0, a, b;
      stack<int> num_stack;
      for (i = 0; i < size; i++)
      {
            if(postfix[i] == '|'){
                  has_num = !has_num;
                  if(!has_num){
                        num_stack.push(tmp_num);
                        //cout << tmp_num << endl;
                        tmp_num = 0;
                  }
            }else if (isdigit(postfix[i]))
            {
                  if (has_num)
                  {
                        tmp_num = tmp_num * 10 + postfix[i]- '0';
                  }
            }
            else
            {
                  a = num_stack.top();
                  num_stack.pop();
                  b = num_stack.top();
                  num_stack.pop();
                  //cout << a << "-" << b << endl;
                  switch (postfix[i])
                  {
                  case '*':
                        num_stack.push(a * b);
                        break;
                  case '+':
                        num_stack.push(a + b);
                        break;
                  case '-':
                        num_stack.push(b - a);
                        break;
                  case '/':
                        num_stack.push(b / a);
                        break;
                  case '^':
                        num_stack.push((int)pow((double)b,(double)a));
                        break;
                  }
                  //cout <<"size"<< num_stack.size() << endl;
            }
      }
      return num_stack.top();
}

// main
int main()
{
      int T,i,size,result;
      char expression_infix[100], expression_postfix[100];
      cin >> T;
      for(i=0;i<T;i++){
            scanf("%s",expression_infix);
            size = strlen(expression_infix);
            infix2postfix(expression_infix, expression_postfix, size);
            //cout << expression_postfix << endl;
            size = strlen(expression_postfix);
            result = calculate(expression_postfix, size);
            printf("%d\n",result);
      }
      /* for testing
      char infix[] = "4^5/(1*(2+3))";
      int size = strlen(infix);
      char postfix[MAXSIZE];
      infix2postfix(infix, postfix, size);
      size = strlen(postfix);
      cout << "\nInfix Expression :: " << infix;
      cout << "\nPostfix Expression :: " << postfix << endl;
      cout << calculate(postfix, size) << endl;
      */
      return 0;
}