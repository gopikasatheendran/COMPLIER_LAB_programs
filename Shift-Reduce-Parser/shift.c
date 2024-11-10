#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[18],ac[18],stk[30];
int i=0,j=0,z=0,c=0,k=0;
void check();
void main(){
  printf("GRAMMAR:\n E->E+E\n E->E-E\n E->E*E\n E->(E)\n E->ID\n");
  printf("enter the expression:");
  scanf("%s",a);
  strcpy(ac,"SHIFT");
  c=strlen(a);
  printf("STACK\tINPUT\tACTION\n");
  for(i=0;j<c;j++,i++){
    if (a[j]=='i'&& a[j+1]=='d'){
      strcpy(ac,"SHIFT");
      stk[i]=a[j];
      stk[i+1]=a[j+1];
      stk[i+2]='\0';
      a[j]=' ';
      a[j+1]=' ';
      printf("$%s\t%s$\t%s\n",stk,a,ac);
      check();
      }
    else{
      strcpy(ac,"SHIFT");
      stk[i]=a[j];
      stk[i+1]='\0';
      a[j]=' ';
      printf("$%s\t%s$\t%s\n",stk,a,ac);
      check();
      }}
      for(k=0;stk[k]!='\0';k++)
      check();
      if (stk[0]=='E' && stk[1]=='\0')
      printf("Accept");
      else
      printf("reject");
      }

void check(){
  strcpy(ac,"Reduce");
  for(z=0;z<c;z++){
    if (stk[z]=='i'&& stk[z+1]=='d'){
      stk[z]='E';
      stk[z+1]='\0';
      printf("$%s\t%s$\t%s\n",stk,a,ac);
      j++;
      }}
  for(z=0;z<c;z++){
    if (stk[z]=='E'&& stk[z+1]=='+'&&stk[z+2]=='E'){
      stk[z]='E';
      stk[z+1]='\0';
      stk[z+2]='\0';
      printf("$%s\t%s$\t%s\n",stk,a,ac);
      i=i-2;
      }}
  for(z=0;z<c;z++){
    if (stk[z]=='E'&& stk[z+1]=='*'&&stk[z+2]=='E'){
      stk[z]='E';
      stk[z+1]='\0';
      stk[z+2]='\0';
      printf("$%s\t%s$\t%s\n",stk,a,ac);
      i=i-2;
      }}
    for(z=0;z<c;z++){
    if (stk[z]=='('&& stk[z+1]=='E'&&stk[z+2]==')'){
      stk[z]='E';
      stk[z+1]='\0';
      stk[z+2]='\0';
      printf("$%s\t%s$\t%s\n",stk,a,ac);
      i=i-2;
      }}}
  
