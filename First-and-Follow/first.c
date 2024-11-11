 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<ctype.h>
 void first(char c);
 void follow(char c);
 int n,m=0,i=0,j=0 ,z,k;
 char a[10][10],f[10];
 char ch, c;
 void main(){
 printf("enter no of productions:");
 scanf("%d",&n);
 printf("enter the productions:");
 for(i=0;i<n;i++)
 scanf("%s%c",a[i],&ch);
 do{
  m=0;
  printf("enter the character:");
  scanf("%c",&c);
  first(c);
  printf("first(%c):{",c);
  for(i=0;i<m;i++){
    for(j=i+1;j<m;j++){
      if(f[i]==f[j]){
        f[j]='\0';
        m--;
        }}}
  for(i=0;i<m;i++)
  printf("%c",f[i]);
  printf("}\n");
  strcpy(f,"");
  m=0;
  follow(c);
  printf("follow(%c):{",c);
  for(i=0;i<m;i++){
    for(j=i+1;j<m;j++){
      if(f[i]==f[j]){
        f[j]='\0';
        m--;
        }}}
  for(i=0;i<m;i++)
  printf("%c",f[i]);
  printf("}\n");
  printf("do you want to continue?0/1");
  scanf("%d%c",&z,&ch);
  }while(z==1);
  }
void first(char c){
  int k;
  if(!isupper(c))
  f[m++]=c;
  for(k=0;k<n;k++){
    if(a[k][0]==c){
      if(a[k][2]=='$')
        follow(a[k][0]);
      else if(islower(a[k][2]))
        f[m++]=a[k][2];
      else
        first(a[k][2]);}}}
void follow(char c){
  if(a[0][0]==c)
  f[m++]='$';
  for(i=0;i<n;i++){
    for(j=2;j<strlen(a[i]);j++){
    if(a[i][j]==c)
    {
      if(a[i][j+1]!='\0')
        first(a[i][j+1]);
      if (a[i][j+1]== '\0'&& c!=a[i][0])
        follow(a[i][0]);
        }}}}
 
  
  
 
