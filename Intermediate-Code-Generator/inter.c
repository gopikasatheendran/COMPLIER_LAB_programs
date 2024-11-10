#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0,j=0,l,tmpch=90,p,q;
char st[20],left[20],right[20];
void sortoperator();
void explore();
void findopr();
void fleft(int);
void fright(int);
struct exp{
  int pos;
  char op;
} k[15],temp;
void main(){
  printf("enter the expression");
  scanf("%s",st);
  printf("expression\t\t intermediate code\n");
  findopr();
  sortoperator();
   explore();
   }
void findopr(){
for (int i=0;st[i]!='\0';i++){
  if(st[i]=='+'){
    k[j].pos=i;
    k[j++].op='+';
    }
  else if(st[i]=='*'){
    k[j].pos=i;
    k[j++].op='*';
    }
  else if(st[i]=='-'){
    k[j].pos=i;
    
    k[j++].op='-';
    }}}
void sortoperator(){
  for(p=0;p<j-1;p++){
    for(q=0;q<j-p-1;q++){
      int pre1=(k[q].op=='+'||  k[q].op=='-')?1 :2;
      int pre2 =(k[q+1].op=='+'|| k[q+1].op=='-')?1 :2;
      if (pre1<pre2){
        temp=k[q];
        k[q]=k[q+1];
        k[q+1]=temp;
        }}}}
void explore(){
  i=0;
  while(i<j){
    fleft(k[i].pos);
    fright(k[i].pos);
    st[k[i].pos]=tmpch--;
    printf("\t%c:=%s%c%s\t\t",st[k[i].pos],left , k[i].op,right);
    for(int l=0;st[l]!='\0';l++){
        if (st[l]!='$')
          printf("%c",st[l]);
  }
  printf("\n");
  i++;
  }
  printf("\t%c:=%c\n",st[0],st[k[--i].pos]);
  }
void fleft(int x){
  int w=0, flag=0;
  x--;
  while(x!=-1&& st[x]!='+'&& st[x]!='*'){
    if (st[x]!='$'&& flag==0){
      left[w++]=st[x];
      left[w]='\0';
      st[x]='$';
      flag=1;
      }
      x--;}}
void fright(int x){
  int w=0, flag=0;
  x++;
  while(st[x]!='\0'&& st[x]!='+'&& st[x]!='*'){
    if (st[x]!='$'&& flag==0){
      right[w++]=st[x];
      right[w]='\0';
      st[x]='$';
      flag=1;
      }
      x++;}}
