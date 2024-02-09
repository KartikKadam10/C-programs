
#include <stdio.h>
#include<stdlib.h>

int main()
{
    printf("Hello, World!\n");
    char ch;
    int choice;
    printf("\nEnter the character\n");
    scanf("%c", &ch);
    
    printf("Please Select your choice\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("ASCII value for Character is %d \n", ch);
            break;
        case 2:
            if(ch =='a' || ch == 'e' || ch == 'i'  || ch == 'o' || ch=='u')
                printf("Entered character is vowels");
            else
                printf("Entered character is consonants");
            break;
        case 3:
            if(ch>=65 && ch<=91) 
                printf("\nEntred character is UpperCase\n");
            else if(ch>=97 && ch<122)
                printf("\n Entered Character is LowerCase\n");
            else
                printf("\nEntered character is not Alphabet\n");
            break;
        case 4:
            if(ch>=48 && ch <=57)
                printf("\nEntered character is Digit\n");
            else
                printf("\nEntered character is not a Digit\n");
            break;
        case 5:
            if (ch>=32 && ch <=47 || ch>=58 && ch<=64 && ch>=91 && ch<=96 || ch>=123 && ch<=126)   
                printf("\nEntered character is Special Symbol\n");
            else
                printf("\nEntered character is not Special Symbol\n");
            break;
        case 6:
               exit(0);
        default:
            printf("\nYou have enter a wrong choice/charecter\n");
    }

    return 0;
}