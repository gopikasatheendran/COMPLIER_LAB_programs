%{ 
	#include<stdio.h>
	int flag=0;
%}
%token NUMBER
%left'+''-'
%left '*''%''/'
%left '('')'

%%

ArithmeticExpression:E{
	printf("result:%d\n",$$);
	return 0;
	}
	E:E'+'E {$$=$1+$3;}
	|E'-'E {$$=$1-$3;}
	|E'*'E {$$=$1*$3;}
	|E'%'E {$$=$1%$3;}
	|E'/'E {$$=$1/$3;}
	|'('E')' {$$=$2;}
	|NUMBER {$$=$1;}
	;
%%

int yyerror()
{
	flag=1;
	printf("invalid expression");
	}
void main()
{
	printf("enter the expression:");
	yyparse();
	if(flag==0)
	printf("\n\n");
	}

