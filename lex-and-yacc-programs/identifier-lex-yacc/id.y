%{
	#include<stdio.h>
	int valid=1;
%}
%token digit letter

%%

start :	letter s
s :	letter s
	| digit s
	|
	;
	
%%
int yyerror()
{
	valid=0;
	printf("not an identifier");
	return 0;
}
int main()
{
	printf("enter the name to be tested for identifier:");
	yyparse();
	if(valid)
	printf("its an identifier!");
}
