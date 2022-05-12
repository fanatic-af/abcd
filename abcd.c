#include<stdio.h>
#include<stdlib.h>
void position(int n,int i,int j)
{
    static int count=0,p=0,q=0;

    if(count>=n)
        return;
    if(n%2==0)
    {
        printf("i=%d,j=%d\n",i,j);
        p++;
        count++;
        if(p==n/2)
            {
                p=0;
                q=2;
            }
        position(n,2*p,q);
    }
    else
    {
        printf("i=%d,j=%d\n",i,j);
        p++;
        count++;
        if(p==(n+1)/2)
            {
                p=0;
                q=2;
            }
        position(n,2*p,q);
    }
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    if(n>2)
    position(n,0,0);
    else if(n==2)
    printf("NOT POSSIBLE\n");
        return 0;
}
