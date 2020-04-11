#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct n
{
    bool isEOW;
    struct n *next[ALPHABET_SIZE];

}node;

node *root;

node *createNode()
{
    int i;

    node *n1=malloc(sizeof(node));

    for(i=0;i<ALPHABET_SIZE;i++)
        n1->next[i]=NULL;
    n1->isEOW=false;
    return n1;
}

void insertWord(char wr[])
{   node *temp=root;
    int i;
    for(i=0;wr[i]!='\0';i++)
    {
        int idx=wr[i]-'a';

        if(temp->next[idx]==NULL)
            temp->next[idx]=createNode();
        temp=temp->next[idx];
    }
   temp->isEOW=true;
}


bool hasWord(char a[])
{
    node *temp=root;
    int i;

    for(i=0;a[i]!='\0';i++)
    {
        int id=a[i]-'a';

        if(temp->next[id]==NULL)
            return false;
        temp=temp->next[id];
    }
    return true;

}



void insert(char w[])
{
char *c;
int count=0,count1=0;
int i;
int len=strlen(w);

c=malloc(len+2);
sprintf(c,"%c%s",'~',w);
printf("\nINSERT:\n");


for(i=0;i<=len;i++)
{   char ch;
    for(ch='a';ch<='z';ch++)
    {
        c[i]=ch;
        count1++;

     if(hasWord(c)==true)
     {
         count++;
         printf("\t%s",c);
     }

    }
    c[i]=c[i+1];
}
printf("\nfrom insert:%d\t%d\n",count,count1);
}




void replace(char w[]){
    int len=strlen(w);
    int i;
int count1=0;
int count=0;
printf("\nREPLACE:\n");

  for(i=0;i<len;i++)
  {
      char c=w[i];
      char ch;
    for(ch='a';ch<='z';ch++)
    {   if(ch!=c)
        {
         w[i]=ch;

         if(hasWord(w)==true){count++;
            printf("\t%s",w);}
         count1++;
        }
    }
  w[i]=c;
  }
printf("\nfrom replace:%d\t%d\n",count,count1);
}

/*
 There are many additional operations you can perform, swappping is one among them. 
*/

int main()
{
    int k;
    char cf[50];

    root=createNode();

    FILE *fp;
    fp=fopen("dictionary.txt", "r");

    for(k=0;k<100000;k++)
		{
		    fscanf(fp,"%s",cf);
            insertWord(cf);
        }
		fclose(fp);


    char g[50];
    printf("Enter (mis-spelled)word:\n");
    scanf("%s",g);

     bool i=hasWord(g);
        if(i==true)
            printf("FOUND");
        else
            printf("NOT FOUND");

  replace(g);
  insert(g);

return 0;
}
