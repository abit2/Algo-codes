# include <stdio.h>
# include "myl.h"
int main(){
  printf("Enter a string : \n");
  char str[20];
  char ch;
  int i = 0;
  while((ch=getchar())!='\n'){
    str[i++] = ch;
  }
  str[i] = '\0';
  printf("String entered by user : \n");
  int no_of_chars = prints(str);
  printf("\nThe no. of characters in given string is : %d\n",no_of_chars);
  printf("\nEnter a number : \n");
  int n;
  int t;
  n = readi(&t);
  if(t)
     printf("Invalid Input\n");
  else{
      printf("The number entered by user : \n");
      no_of_chars = printi(n);
      printf("\nThe number of characters in given number is : %d\n",no_of_chars);
  }
  printf("\nEnter a floating point number\n");
  float num;
  t = readf(&num);
  if(t)
     printf("Invalid Input\n");
  else{
      printf("The number entered by user  : \n");
      no_of_chars = printd(num);
      printf("\nThe number of characters in given number is : \n");
      printf("%d\n",no_of_chars);	
  }
  return 0;
}
