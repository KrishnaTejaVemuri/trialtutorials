#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char infix[50],postfix[50],stack[40],ch,x;
int top=-1,i=0,j=0;

void push(char ch)
{
    stack[++top]=ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    switch(ch)
    {
   /* case '^':
    case '$':
        return 10;*/
    case '*':
    case '/':
        return 8;

    case '+':
    case '-':
        return 6;
    }
    return 0;
}

void check(char ch)
{
    while(priority(ch)<=priority(stack[top]))
    {
        postfix[j++]=pop();
    }
}

void main()
{
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    push('#');
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(isalnum(ch))
            postfix[j++]=ch;
        if(ch=='(')
            push(ch);
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/' /*||ch=='$'||ch=='^'*/)
        {
            check(ch);
            push(ch);
        }
        if(ch==')')
        {

            do
            {

                x=pop();
                postfix[j++]=x;
            }while(x!='(');
            j--;
        }
        i++;
    }
    while(stack[top]!='#')
    {

        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("The given infix expression is :: %s\n",infix);
    printf("The converted postfix expression is :: %s\n",postfix);
}
