#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
# define SUCCESS 1
# define FAILURE 0
const char* cursor;
int E(), EDASH(), T(), TDASH(), F();
void print_action(const char* current ,const char* action); 
char string[128];
void print_action(const char* current ,const char* action){
  printf("%-16s %s\n", current, action);
  }
int parse(const char *input){
  cursor=input;
  puts("");
  puts("input     action");
  puts("-------------------------");
  if(E() && *cursor=='\0'){
    puts("-------------------------");
    puts("successfully parsed");
    }
  else
    puts ("error in parsing ");
  }
int E(){
  print_action(cursor, " E->TE'");
  if (T() && EDASH())
    return SUCCESS;
  else
    return FAILURE ;}
int T(){
  print_action(cursor, " T->FT'");
  if (F() && TDASH())
    return SUCCESS;
  else
    return FAILURE ;}
 int EDASH(){
  if (*cursor=='+'){
    print_action(cursor, "E'->+TE'");
    cursor++;
     if (T() && EDASH())
        return SUCCESS;
      else
        return FAILURE ;}
  else{
    print_action(cursor,"E'->$");
    return SUCCESS;
    }}
    
int TDASH(){
  if (*cursor=='*'){
    print_action(cursor, "T'->+FT'");
    cursor++;
     if (F() && TDASH())
        return SUCCESS;
      else
        return FAILURE ;}
  else{
    print_action(cursor,"T'->$");
    return SUCCESS;
    }}
int F(){
  if (*cursor=='('){
    print_action(cursor, "F->(E)'");
    cursor++;
    if (E() && *cursor==')'){ 
      cursor++;
      return SUCCESS;}
    else
      return FAILURE;
      }
  else if(isalpha(*cursor)&& islower(*cursor)){
    while(isalpha(*cursor)&& islower(*cursor))
    cursor++;
    print_action(cursor, "F->identifier'");
    return SUCCESS;}
  else
      return FAILURE;
      }
void main(){
  puts("enter the string");
  if(fgets(string,sizeof(string),stdin)==NULL)
  puts("error in reading the input");
  size_t len=strlen(string);
  if(len>0 && string[len-1]=='\n')
  string[len-1]='\0';
  parse(string);
  }
    
    
  

