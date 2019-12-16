#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"MORSE.h"

//lowercase to upper case
void CAPS(char word[])
{
    int c = 0;
    while (word[c] != '\0') {
        if (word[c] >= 'a' && word[c] <= 'z') {
            word[c] = word[c] - 32;
        }
        c++;
    }
}

//main
int main()
{
    //variable declaration
    char input[1024];
    char word[1024];
    int choice=0,flag=0;
    Tree *root=(Tree*)malloc(sizeof(Tree));

    if(root==NULL)
    {
        printf("ERROR\n");
    }
    if(root!=NULL)
    {
        root->dot=NULL;
        root->dash=NULL;
    }
    //assigning the alphabets to the tree
    //-----------------------------------------------------
    assignDATA(root,".-",'A');
    assignDATA(root,"-...",'B');
    assignDATA(root,"-.-.",'C');
    assignDATA(root,"-..",'D');
    assignDATA(root,".",'E');
    assignDATA(root,"..-.",'F');
    assignDATA(root,"--.",'G');
    assignDATA(root,"....",'H');
    assignDATA(root,"..",'I');
    assignDATA(root,".---",'J');
    assignDATA(root,"-.-",'K');
    assignDATA(root,".-..",'L');
    assignDATA(root,"--",'M');
    assignDATA(root,"-.",'N');
    assignDATA(root,"---",'O');
    assignDATA(root,".--.",'P');
    assignDATA(root,"--.-",'Q');
    assignDATA(root,".-.",'R');
    assignDATA(root,"...",'S');
    assignDATA(root,"-",'T');
    assignDATA(root,"..-",'U');
    assignDATA(root,"...-",'V');
    assignDATA(root,".--",'W');
    assignDATA(root,"-..-",'X');
    assignDATA(root,"-.--",'Y');
    assignDATA(root,"--..",'Z');
    //---------------------------------------------------

    //-----------------------------------------
    while(1)
    {
        printf("\n\nMENU\n");
        printf("1.Decode Morse Code\n");
        printf("2.Encode into Morse Code\n");
        printf("3.Get the Frequency of the Alphabets Used\n");
        printf("4.Exit\n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1: {
                printf("\nEnter morse code\n");
                printf("(Please Use standard Morse Values i.e dots(.) and dashes(-))\n");
                printf("After adding your Input Press ENTER,Then add '.' to continue\n");
                scanf("%[^\n]%*s",input);
                char delim[]=" ";
                char *ptr=strtok(input,delim);//tokenizer with 'space as the delimiter
                while(ptr!=NULL)
                {
                    putchar(decode(root,ptr));
                    ptr=strtok(NULL,delim);
                }
                break;
            }
            case 2:
            {
                printf("\nEnter a word\n");
                 printf("After adding your Input Press ENTER,Then add '.' to continue\n");
                scanf("%[^\n]%*s",word);
                CAPS(word);
                ENTER(flag,word);
                flag=1;
                encode(word);
                break;
            }
            case 3:
            {
                FILEREAD();
                break;
            }

            case 4: {
                exit(0);
            }
            default: {
                printf("wrong choice\n");
                break;
            }
        }
    }
}
