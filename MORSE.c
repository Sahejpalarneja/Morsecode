#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"MORSE.h"

//FUnctio to make the nodes for the data
Tree *NODE()
{
    Tree *pReturn=(Tree*)malloc(sizeof(Tree));
    if(pReturn==NULL)
    {
        printf("Memory allocation problem\n");
    }
    pReturn->data='*';
    pReturn->dot=NULL;
    pReturn->dash=NULL;
    return pReturn;
}
//function return the whole tree
void preorder(Tree *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%c\t",root->data);
    preorder(root->dot);
    preorder(root->dash);


}
//function to add value into the Tree
void assignDATA(Tree *root,char morse[],char data)
{
    Tree *pReturn;
    pReturn=root;
    if(pReturn!=NULL)
    {
        pReturn->data='*';
    }
    int len=0,i=0;
    len=strlen(morse);
    for(i=0;i<=len;i++)
    {
        if(morse[i]=='.')
        {
            if(pReturn->dot==NULL)
            {
                pReturn->dot=NODE();
            }
            pReturn=pReturn->dot;
        }
        else
        {
            if(pReturn->dash==NULL)
            {
                pReturn->dash=NODE();
            }
            pReturn=pReturn->dash;
        }
    }
    pReturn->data=data;
}
//Function to decode the morse code
char decode(Tree *root,char morse[]) {

    Tree *pReturn = (Tree *) malloc(sizeof(Tree));
    pReturn = root;
    int len = 0, i = 0;
    len = strlen(morse);
    if (pReturn == NULL) {
        printf("error\n");
    }
    for (i = 0; i <= len; i++) {
        if (morse[i] == '.') {
            if (pReturn->dot == NULL) {
                printf("wrong symbol\n");
                return 1;

            }
            pReturn = pReturn->dot;
        } else {
            if (pReturn->dash == NULL) {
                printf("Wrong symbol\n");
                return 1;
            }
            pReturn = pReturn->dash;
        }
    }
    return pReturn->data;
}
//Dictionary for getting morse value of the Alphabets
void dictionary(char c)
{
    switch(c)
    {
        case 'A':
            printf(".- ");
            break;
        case 'B':
            printf("-... ");
            break;
        case 'C':
            printf("-.-. ");
            break;
        case 'D':
            printf("-.. ");
            break;
        case 'E':
            printf(". ");
            break;
        case 'F':
            printf("..-. ");
            break;
        case 'G':
            printf("--. ");
            break;
        case 'H':
            printf(".... ");
            break;
        case 'I':
            printf(".- ");
            break;
        case 'J':
            printf(".--- ");
            break;
        case 'K':
            printf("-.- ");
            break;
        case 'L':
            printf(".-.. ");
            break;
        case 'M':
            printf("-- ");
            break;
        case 'N':
            printf("-. ");
            break;
        case 'O':
            printf("--- ");
            break;
        case 'P':
            printf(".--. ");
            break;
        case 'Q':
            printf("--.- ");
            break;
        case 'R':
            printf(".-. ");
            break;
        case 'S':
            printf("... ");
            break;
        case 'T':
            printf("- ");
            break;
        case 'U':
            printf("..- ");
            break;
        case 'V':
            printf("...- ");
            break;
        case 'W':
            printf(".-- ");
            break;
        case 'X':
            printf("-..- ");
            break;
        case 'Y':
            printf("-.-- ");
            break;
        case 'Z':
            printf("--.. ");
            break;
        default: {
            if (c != NULL && c!=' ') {
                printf("Wrong Entry\n");
            }

        }
    }

}
//functoin to encode the alphabets to morse code
void encode(char word[])
{
    int len=0,i=0;
    len=strlen(word);
    for(i=0;i<=len;i++) {
        dictionary(word[i]);
    }
}

