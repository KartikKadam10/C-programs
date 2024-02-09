#include <stdio.h>
#include<stdlib.h>

int main()
{
 
 FILE *fp=NULL;
 char ch;

 char str[]="Kartik Kadam is learning file handling in C !";
 
 fp=fopen("abc.txt","r");
 if ( fp==NULL)
 {
     printf("\nno file");
     exit(0);
 }
 else 
 
 while ( !feof(fp) )
 {
    ch=fgetc(fp);
    printf("%c",ch);
 }

 fclose(fp);
 return 0;
}