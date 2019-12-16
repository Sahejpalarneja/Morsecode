#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "FILE.h"

//function to read the file and deisplay the frequency for each alphabet used
void FILEREAD()
{
    char tmp[1024];
    int i=0,x,count[26]={0};
    FILE *fp;
    fp=fopen("sample.txt","r");
    if(fp==NULL)
    {
        printf("Error\n");
    }
    while ((fgets(tmp,1024,fp)) >0)
    {

        char *new=(char*)malloc(sizeof(char));
        strcpy(new,tmp);
        while (new[i] != '\0')
        {
            if (new[i] >= 'A' && new[i] <= 'Z')
            {
                x = new[i] - 'A';
                count[x]++;
            }
            i++;
        }
    }
    fclose(fp);
    for (i = 0; i < 26; i++)
    {
        printf("%c occurs %d times \n", i+ 'A', count[i]);
    }

}
//this writes into the file
void ENTER(int flag,char word[])
{

    FILE *fp;
    if(flag==0)
    {
        fp=fopen("sample.txt","w");
    }
    else
    {
        fp=fopen("sample.txt","a");
    }
    if(fp==NULL)
    {
        return;
    }
    fprintf(fp,"%s ",word);
    fclose(fp);


}
