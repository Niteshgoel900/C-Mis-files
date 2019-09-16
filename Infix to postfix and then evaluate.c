/* COP 3502C Midterm Assignment One This program is written by: Nitesh Goel
    IMPORTANT:
    While running on Eustis use: gcc MidtermAssignment1.c -lm
    The reason for this is math.h was used for Pow funtion */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// The array will store the items in the stack, first in
// index 0, then 1, etc. top will represent the index
// to the top element in the stack. If the stack is
// empty top will be -1.

#define SIZE 10
#define EMPTY -1

struct stack {
    
    int items[SIZE];
    int top;
};

void initialize(struct stack* stackPtr);
int full(struct stack* stackPtr);
void push(struct stack* stackPtr, char value);
int empty(struct stack* stackPtr);
char pop(struct stack* stackPtr);
void removespaces(char *infix);
int Precedence(char Operator);
void InfixToPostfix(char *infix, char *postfix, struct stack *Pstack);
void remove_newline_character(char *infix);
char identifying_doubles(char *infix, char *expression);//
int finds_doubles_in_infix(int *e, char *expression);
long int Evaluate(char *postfix, int *e, struct stack *Pstack);
long int check_operator(int a, int b, char c);



int main(void) {
    
    char infix[100], postfix[100];
    char expression[100];
    int e[100];
    int open=0, close=0, i=0;
    long int temp; // This is what stoes the reult
    struct stack Pstack;
    initialize(&Pstack);
    printf("Enter the Infix Expression:");
    fgets(infix, 100, stdin);
    remove_newline_character(infix);
    
    
    // This is used to check if the  brackets are balanced
    for(i=0; i<strlen(infix); i++)
    {
        if(infix[i]=='(')
        {
            open++; // if theres an opening bracket counter is increased by one
        }
        if(infix[i]==')')
        {
            close++; // if theres an closing bracket counter is increased by one
        }
    }
    
    if(open==close) //If tboth counters are equal then only will the program execute
    {
        removespaces(infix); //removes spaces in the infix if any
        InfixToPostfix(infix, postfix, &Pstack);
        identifying_doubles(infix,expression);
        printf("The Postfix Expression is:%s\n", postfix);
        remove_newline_character(expression);
        finds_doubles_in_infix(e,expression);
        temp=Evaluate(postfix, e, &Pstack);
        printf("The result is: %ld\n",temp);
    }
    else
    {
        printf("The Infix Expression entered is invalid due to brackets not balanced\n");
        exit (0);
    }
    return 0;
}




void InfixToPostfix(char *infix, char *postfix, struct stack *Pstack){
    int i=0; //This will be used for infix
    int x=0; //This will be used for postfix
    char temp;
    for(i=0; i<strlen(infix); i++)
    {
       // If there is an opening bracket we want to push it into the stack
        if(infix[i]=='(')
        {
            push(Pstack,infix[i]);
        }
        
        // If closing bracket we have to pop until we see the open and then pop that
        else if(infix[i]==')')
        {
            for( ; (*Pstack).items[(*Pstack).top] !='(' ; )
            {
                postfix[x]=pop(Pstack);
                x++;
            }
            temp = pop(Pstack); // Closing the opening bracket
        }
        
        // If the element in the infix is a digit we directly send to postfix
        else if(infix[i] == '0'|| infix[i] == '1'|| infix[i] == '2'|| infix[i] == '3'|| infix[i] == '4'|| infix[i] == '5'|| infix[i] == '6'|| infix[i] == '7'|| infix[i] == '8'|| infix[i] == '9')
        {
            //send it to postfix
            postfix[x]=infix[i];
            x++;
        }
        
        // If operator check the last operator and see it's precedence, accordingly push and pop
        else if(infix[i] == '^' || infix[i] == '*' || infix[i] == '%' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-')
        {
            //send it to the stack and see if there is any current opperator there and if any does it have high presedence
            for(; Precedence((*Pstack).items[(*Pstack).top]) >= Precedence(infix[i])   ;)
            {
                postfix[x]=pop(Pstack); // If the new operator has a higher precedence
                x++;
            }
            push(Pstack,infix[i]); // Push the New if the last operator has a lower precedence
        }
       
        // If the infix expression has characters other than operators and digits
        else
        {
            printf("The Infix Expression entered is invalid due some foreign symbol\n");
            exit (0);
        }
    }
    
    // This is where we need to print all remaining elements in the stack(operators)
    for(; (*Pstack).top != -1 ;)
    {
        postfix[x]=pop(Pstack);
        x++;
    }
    postfix[x]= '\0';
}



// This is an important function which sets the last chracter in the array to termination character '\0' rather than '\n'
// This is used as we have called fgets in the funtion
// If this was not used it wouldn't be possible to write an exit statment in the infix to postfix funtion
void remove_newline_character(char *infix)
{
    int i=0;
    for(i=0; i<strlen(infix); i++)
    {
        if(infix[i]== '\n')
        {
            infix[i]= '\0';
        }
    }
}


// Checks prescedence
int Precedence(char Operator) {
    switch(Operator)
    {
        case '^':
            return (10);
            break;
        case '/':
            return (5);
            break;
        case '%':
            return (5);
            break;
        case '*':
            return (5);
            break;
        case '+':
            return (0);
            break;
        case '-':
            return (0);
            break;
        default:
            return (-1);
    }
}

// This funtion removes all spaces in the infix allowing us to navigate through the array easily
void removespaces(char *infix) {
    int i;
    int position = 0; // This is the position
    
    for(i = 0 ; i < strlen(infix); i++)
    {
        if(infix[i] != ' ')
        {
            infix[position] = infix[i];
            position++;
        }
    }
    infix[position]= '\0';
}

void initialize(struct stack* stackPtr) {
    stackPtr->top = -1;
}

// If the push occurs, 1 is returned. If the
// stack is full and the push can't be done, 0 is
// returned.
void push(struct stack* stackPtr, char value) {
    
    // Check if the stack is full.
    if (full(stackPtr))
        return;
    
    // Add value to the top of the stack and adjust the value of the top.
    stackPtr->items[stackPtr->top+1] = value;
    (stackPtr->top)++;
}

// Returns true iff the stack pointed to by stackPtr is full.
int full(struct stack* stackPtr) {
    return (stackPtr->top == SIZE - 1);
}

// Returns true iff the stack pointed to by stackPtr is empty.
int empty(struct stack* stackPtr) {
    return (stackPtr->top == -1);
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is popped and returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
char pop(struct stack* stackPtr) {
    
    char retval;
    
    // Check the case that the stack is empty.
    if (empty(stackPtr))
        return EMPTY;
    
    // Retrieve the item from the top of the stack, adjust the top and return
    // the item.
    retval = stackPtr->items[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}


char identifying_doubles(char *infix, char *expression)
{
    int i=0, j=0;
    for(i=0; i<strlen(infix);i++)
    {
        if(infix[i] == '0'|| infix[i] == '1'|| infix[i] == '2'|| infix[i] == '3'|| infix[i] == '4'|| infix[i] == '5'|| infix[i] == '6'|| infix[i] == '7'|| infix[i] == '8'|| infix[i] == '9')
        {
            expression[j] = infix[i];
            
            // If there are two digits next to each other
            if(infix[i+1] == '0'|| infix[i+1] == '1'|| infix[i+1] == '2'|| infix[i+1] == '3'|| infix[i+1] == '4'|| infix[i+1] == '5'|| infix[i+1] == '6'|| infix[i+1] == '7'|| infix[i+1] == '8'|| infix[i+1] == '9')
            {
                expression[j+1]=infix[i+1];
                expression[j+2]=' '; // This is adding spaces after two digits are next to each other like   33  ...
                j++;
                j++;
                j++;
                i++;
                if(infix[i+1] == '0'|| infix[i+1] == '1'|| infix[i+1] == '2'|| infix[i+1] == '3'|| infix[i+1] == '4'|| infix[i+1] == '5'|| infix[i+1] == '6'|| infix[i+1] == '7'|| infix[i+1] == '8'|| infix[i+1] == '9')
                {
                    printf("This program doesn't support evaluation of numbers with three digits or more. Please enter a valid one ot two digit numbers\n");
                    exit (0);
                }
            }
            
            // This is to identify if the first element was a digit and the second is not
            else if(infix[i+1] != '0'|| infix[i+1] != '1'|| infix[i+1] != '2'|| infix[i+1] != '3'|| infix[i+1] != '4'|| infix[i+1] != '5'|| infix[i+1] != '6'|| infix[i+1] != '7'|| infix[i+1] != '8'|| infix[i+1] != '9')
            {
                infix[i+1]=' ';
                expression[j+1]=infix[i+1];
                j++;
            }
        }
        
        // If the element isn't a digit add a space
        else if(infix[i] != '0'|| infix[i] != '1'|| infix[i] != '2'|| infix[i] != '3'|| infix[i] != '4'|| infix[i] != '5'|| infix[i] != '6'|| infix[i] != '7'|| infix[i] != '8'|| infix[i] != '9')
        {
            infix[i]=' ';
            expression[j]=infix[i];
            j++;
        }
    }
    return 0;
}

int finds_doubles_in_infix(int *e, char *expression)
{
    int k=0;
    for(int i=0; i<strlen(expression);i++)
    {
        if(expression[i] == '0'|| expression[i] == '1'|| expression[i] == '2'|| expression[i] == '3'|| expression[i] == '4'|| expression[i] == '5'|| expression[i] == '6'|| expression[i] == '7'|| expression[i] == '8'|| expression[i] == '9')
        {
            if(expression[i+1] == '0'|| expression[i+1] == '1'|| expression[i+1] == '2'|| expression[i+1] == '3'|| expression[i+1] == '4'|| expression[i+1] == '5'|| expression[i+1] == '6'|| expression[i+1] == '7'|| expression[i+1] == '8'|| expression[i+1] == '9')
            {
                e[k]=((expression[i]-'0')*10)+(expression[i+1]-'0');
                k++;
                i++;
            }
            else
            {
                e[k]=(expression[i]-'0');
                k++;
            }
        }
        else if (expression[i]==' ')
        {
            continue;
        }
    }
    return 0;
}

long int Evaluate(char *postfix, int *e, struct stack *Pstack)
{
    int i=0, a=0, b=0, j=0;
    
    for(i=0; i<strlen(postfix); i++)
    {
        // If the element in the postfix is an operator then we will need to apply it to the last two digits in the operant stack
        if(postfix[i] == '^' || postfix[i] == '*' || postfix[i] == '%' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')
       {
           a=pop(Pstack);
           b=pop(Pstack);
           push(Pstack,check_operator(a, b, postfix[i]));
       }
      
        // If the element in the postfix is a digit we just it from e[j] into the stack
        if(postfix[i] == '0'|| postfix[i] == '1'|| postfix[i] == '2'|| postfix[i] == '3'|| postfix[i] == '4'|| postfix[i] == '5'|| postfix[i] == '6'|| postfix[i] == '7'|| postfix[i] == '8'|| postfix[i] == '9')
        {
            push(Pstack, e[j]); // we use e[j] as thats where the int array for the numbers enetered by teh use is
            if(e[j]>=10)
            {
                i++;
            }
            j++;
        }
        if(strlen(postfix)==1) // This is checking if the length of the postfix is one then infix expression isn't valid
        {
            printf("Evaluation will not be possible as there was an invalid infix expression entered\n");
            exit (0);
        }
    }
    return pop(Pstack);
}


// This funtion checks the operator and applies it to a and b which are already popped
long int check_operator(int a, int b, char c)
{
    switch(c)
    {
        case '^':
            return pow(b,a);
            break;
        case '/':
            return b/a;
            break;
        case '%':
            return b%a;
            break;
        case '*':
            return a*b;
            break;
        case '+':
            return a+b;
            break;
        case '-':
            return b-a;
            break;
        default:
            return (0);
    }
}
