#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char op[2], arg1[10],arg2[10],result[10];
void main(){
  FILE *fp;
  fp=fopen("in.txt", "r");
  while(fscanf(fp,"%s%s%s%s",op, arg1, arg2, result)!= EOF){
    printf("MOV R0 ,%s\n",arg1);
    switch(op[0]){
      case '+':printf("ADD R0 ,%s\n",arg2);
              break;
      case '-':printf("SUB R0 ,%s\n",arg2);
              break;
      case '*':printf("MUL R0 ,%s\n",arg2);
              break;
      case '/':printf("DIV R0 ,%s\n",arg2);
              break;
          }
    printf("MOV %s,R0\n",result);     
    }
    fclose(fp);
    }
    
