#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int top=0, i,j,n,k,row, col;
char ip[20],stack[20],opt[10][10][1], ter[10];
void main(){
  for(i=0;i<10;i++){
    stack[i]=0;
    ip[i]=0;
    for(j=0;j<10;j++){
      opt[i][j][1]=0;
      }}
  printf("enter the number of terminals");
  scanf("%d",&n);
  printf("enter the terminals:");
  scanf("%s", ter);
  printf("enter the precedence values:\n ");
  for (i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%c %c :", ter[i],ter[j]);
      scanf("%s", opt[i][j]);}}
  printf("operator precedence table");
  for(i=0;i<n;i++)
  printf("\t%c" ,ter[i]);
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("\n%c" ,ter[i]);
    for (j=0;j<n;j++){
      printf("\t%c",opt[i][j][0]);}}
  stack[top]='$';
  printf("enter the input string:");
  scanf("%s",ip);
  i=0;
  printf("STACK\t\t INPUT STRING\t\t ACTION\n");
  printf("%s\t\t%s\t\t", stack,ip);
  while(i<=strlen(ip)){
    for(k=0;k<n;k++){
      if(stack[top]==ter[k])
        col=k;
      if(ip[i]==ter[k])
        row=k;
        }
    if(stack[top]=='$' && ip[i]=='$'){
      printf("String is accepted");
      break;
      }
    else if(opt[col][row][0]=='<' || opt[col][row][0]=='='){
      stack[++top]=opt[col][row][0];
      stack[++top]=ip[i];
      printf("SHIFT %c", ip[i]);
      i++;}
    else{
      if (opt[col][row][0]=='>' ){
        while(stack[top]!='<')
          --top;
        top=top-1;
        printf("REDUCE");
        }
    else{
      printf("\n string not accepted");
      }}
    printf("\n");
    for(k=0;k<=top;k++)
    printf("%c",stack[k]);
    printf("\t\t");
    for(k=0;k<=strlen(ip);k++)
    printf("%c",ip[k]);
    printf("\t\t");}}
      
      
