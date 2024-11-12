%{ 
#include<stdio.h>
%}

digit [0-9]
letter [a-zA-Z]
keyword "unknown"

%%


{digit}+                    	{ printf("Integer:%s\n", yytext);}
{digit}+"."{digit}+           	{ printf("Float:%s\n", yytext);}
{keyword}   		    	{ printf("keyword :%s\n",yytext);}
{letter}({letter}|{digit})* 	{ printf("Identifier :%s\n",yytext);}
[ \t\n]+                    	{ /* ignore whitespace */ }
.           		   	{ printf("unknown character:%s\n",yytext);}

%%

int main() {
	yylex();
	return 0;
	}
	
