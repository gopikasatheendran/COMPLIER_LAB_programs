#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
FILE *input, *output;
char keyword[30][30]={"int","main","for","while","if", "else"};
void main(){
  int l=1,t=0,j,i;
  int flag;
  char str[20],ch;
  input=fopen("input.txt", "r");
  output=fopen("output.txt", "w");
  fprintf(output,"line no\t token no\t\t token\t\t lexeme\n\n");
  while(!feof(input)){
    flag=0,i=0;
    ch=fgetc(input);
    if(ch=='/' && (ch=fgetc(input)=='/')){
      while (ch=fgetc(input)!='\n'&& ch!=EOF)
        l++;
        }
    if (ch=='+' ||ch=='-' ||ch=='*' ||ch=='/' ||ch=='^' ||ch=='=' ){
      fprintf(output, "%7d\t%7d\t\tOperators\t\t %7c\n", l,t,ch);
      t++;
      }
    else if (ch=='$' ||ch=='&' ||ch=='@' ||ch=='#' ||ch=='(' ||ch==')' ){
      fprintf(output, "%7d\t%7d\t\tSpecial Symbols\t\t %7c\n", l,t,ch);
      t++;
      }
    else if(isdigit(ch)){
      fprintf(output, "%7d\t%7d\t\tDigits\t\t %7c\n", l,t,ch);
      t++;}
    else if(isalpha(ch)){
      str[i]=ch;
      i++;
      ch=fgetc(input);
      while(isalnum(ch)&& ch!=' '){
        str[i]=ch;
        i++;
        ch=fgetc(input);}
        str[i]='\0';
        for(j=0;j<=30;j++){
          if(strcmp(str,keyword[j])==0){
            flag=1;
            break;
            }}
        if (flag==1){
          fprintf(output, "%7d\t\t%7d\t\tKeyword\t %7s\n", l,t,str);
          t++;}   
       else{
        fprintf(output, "%7d\t%7d\t\tVariables\t %7s\n", l,t,str);
        t++;}}
      else if(ch=='\n')
        l++;
      }
    fclose(input);
    fclose(output);
    }
      
        
        
        
  
