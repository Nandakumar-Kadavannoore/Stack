// To convert infix into postfix //

#include<stdio.h>
#include<conio.h>
#include<string.h>

char stack[56];
int top=-1;

int pre(char k)
  { if(k=='^')
      return 4;
    else if(k=='*'||k=='/')
      return 3;
    else if(k=='+'||k=='-')
      return 2;
    else
      return 1; }

void evaluate(char x[])
  {  int i;
     char z;
    for(i=0;x[i]!='\0';i++)
     { z=x[i];
       switch(z)
	{ case '(': top++; stack[top]=z; break;
	  case ')': while(stack[top]!='(')
		     { printf("%c",stack[top]); top--; }
		    top--; break;
	  case '+':
	  case '-':
	  case '*':
	  case '/':
	  case '^':
		    while(pre(stack[top])>=pre(z))
		    { printf("%c",stack[top]); top--; }
		    top++; stack[top]=z; break;
	  default: printf("%c",z); break; } }
	  while(top>=0)
	   { printf("%c",stack[top]); top--; }  }

void main()
  { char x[45]; int i=0,c=0;
    printf("\nEnter : ");
    gets(x);

    while(x[i]!='\0')
    { if(x[i]==')')
       { c++; }
      if(x[i]==')')
       { c--; } i++; }

    if(c==0)
     { evaluate(x); }

    else
     { printf("\nInvailed "); }

    getch(); }
