#include<stdio.h>
#include<string.h>
void take_inp()
{
    FILE *fp = fopen("list.txt","a");
    char wor[10];
    int n;
    printf("enter the num of words");
    scanf("%d",&n);
    int i;
    printf("%d",n);
    for(i=0;i<n;i++)
    {
        //printf("emrer");
        scanf("%s",wor);
        fprintf(fp,("%s",wor));
        fprintf(fp,("\n"));

    }
    fclose(fp);
    printf("%d",n);
}
int mak_list()
{
    char c;
    int l;
    FILE *fp = fopen("list.txt","r");
    while(c=getc(fp))
    {
        if(c=='\n')
            l++;
     printf("%c",c);
     //printf("%d",l);
     if(feof(fp))
        break;
    }
    printf("%d",l);
    fclose(fp);
    return l;
}
void  perm(int le)
{
    FILE *fp = fopen("list.txt","r");
    char ch[le][10];
    ch[0][0]='0';
    for(int i=1;i<le+1;i++)
        {
            fscanf(fp,"%s",ch[i]);
            printf("%s \n",ch[i]);

        }
    fclose(fp);
    fp = fopen("W-list.txt","w");
    for(int i=100;i<9999;i++)
    {   //int k = i/100;
        
        if(((i%10)==(i/1000))||((i/10)==((i/100)%10))||((i/10)==((i%100)/10))||((i/1000)==((i/100)%10))||((i/1000)==((i%100)/10))||(((i/100)%10)==((i%100)/10)))
        {   
            fprintf(fp,"\n Entered \n");
            fprintf(fp," \t\t %d \t %d \t %d \t %d ",(i%10),i/1000,(i/100)%10,(i%100)/10);
            continue;//remover where the same string is repeated
        //printf("\n %d",(strlen(ch[i%10])));   
        }
        if((strlen(ch[i%10])+strlen(ch[i/1000])+strlen(ch[(i/100)%10])+strlen(ch[(i%100)/10]))<8)
            continue;
        fprintf(fp,"%s%s%s%s",ch[(i/1000)],ch[((i/100)%10)],ch[((i%100)/10)],ch[(i%10)]);
       fprintf(fp," \t\t %d \t %d \t %d \t %d ",(i/1000),((i/100)%10),((i%100)/10),(i%10));
         fprintf(fp,"\n");
    }    
    fclose(fp);
}

void main()
{
printf("Do you wanna add to the existing words \n Y/N?");
char ans;
scanf("%c",&ans);
printf("%c",ans);
//toupper(ans);
if(ans=='Y')
 take_inp();

perm(mak_list());
}