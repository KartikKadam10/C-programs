// checking the difference between char name[20] and char * str

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char name[20];
    char *str;

    printf("\nEnter the string: ");
    fgets(name,sizeof(name),stdin);

    str=(char*)malloc((30)*sizeof(char));
    printf("\nEnter the second string: ");
    scanf("%[^\n]",str);
    
    name[0]='w';
    str='h';
    printf("\n\t%s",name);
    
    printf("\n\t%s",str);
   
    free(str);
    return 0;
}