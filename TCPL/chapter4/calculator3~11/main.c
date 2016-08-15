#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <math.h>
#include "head.h"
/* Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.

Exercise 4-4. Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.

Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.

Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?

Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.
   answer: only use a variable instead of a array for buf. 

Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.
   Warnngin: getchar were always return EOF if it had got a EOF before

Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.
    answer: getline is not a std method. use a buf to cacha a line and i-- to ungetch.

Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
    answer: use a static array B to buf push back item;need to check if B is empty befor getch.
    

*/

#define MAXOP 100  /* max size of operand or operator */


/* reverse Polish calculator */
int main() {
    int type;
    double op1, op2, v=0;
    char s[MAXOP];
    double vars[26];
    int has_vars[26];
    for (int i = 0; i <= 25; i++) {
        vars[i] = 0.0;
        has_vars[i] = 0;
    }
    
    while ((type = getop(s))) {
         
        switch (type) {
        case NUMBER:
            // printf("what is atof s %f \n", atof(s));
            push(atof(s));
            break;
        case ALPHA:
            // printf("this s[0] - 'a' is %d \n", s[0] - 'a');
            if (has_vars[s[0] - 'a']) 
                push(vars[s[0] - 'a']);
            else
                push(s[0] - 'a');
            op2 = pop();
            // printf("what is pop var %f \n", op2);
            push(op2);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero division\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero division\n");
            break;
        case '=':
            op2 = pop();
            op1 = pop();
            // printf("the op2 is %f \n", op2);
            // printf("the op1 is %f \n", op1);
            push(vars[(int)op1] = op2);
            // printf("the s is %f \n", vars[(int)(op1)]);
            has_vars[(int)op1] = 1;
            break;
        // print the top element
        case 'P':
            v = echo();
            break;
        // duplicate the top element
        case 'Y':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        // clear the stack
        case 'C':
            clear();
            printf("Clear the stack \n");
            break;
        case 'S':
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case 'V':
            push(v);
            break;
        // math function
        case 1000 + 's':
            push(sin(pop()));
            break;
        case 1000 + 'e':
            push(exp(pop()));
            break;
        case 1000 + 'p':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 1000:
            printf("error: unkown math method \n");
            break;
        // print the top element
        case EOF:
        case '\n':
            v = echo();
            clear();
            break;
        default:
            printf("error: unkown command %s\n", s);
            break;
        }

        if(type == EOF)
            break;
    }
    return 0;
}

