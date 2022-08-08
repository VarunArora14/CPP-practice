#include<stdio.h>
#include<math.h>
int N;
double length(double x,double y,double x1,double y1)
{
    double c=(x-x1)*(x-x1)+(y-y1)*(y-y1);
    double l=sqrt(c);
    return l;
}
/*void Merge_Sort(int a[],int Start,int End)
{
    int Mid;
    if(Start>=End)
        return;
    Mid=(Start+End)/2;
    Merge_Sort(a,Start,Mid);
    Merge_Sort(a,Mid+1,End);
    Merge(a,Start,Mid,End);
}
void Merge(int a[],int Start,int Mid,int End)
{
    int Firstarr=Start,temp[N],i,Secondarr=Mid+1;
    for(i=Start;i<=End;i++)
    {
        if(Firstarr>Mid)
        {
            temp[i]=a[Secondarr++];
        }
        else if(Secondarr>End)
        {
            temp[i]=a[Firstarr++];
        }
        else if(a[Firstarr]<a[Secondarr])
        {
            temp[i]=a[Firstarr++];
        }
        else
        {
            temp[i]=a[Secondarr++];
        }
    }
    for(i=Start;i<=End;i++)
    {
        a[i]=temp[i];
    }
}*/
int main()
{
    int t,i,j,temp;
    long long int M;
    double ribbon,first,second,last,second_last;
    scanf("%d",&t);
    while(t--)
    {
        ribbon=0;
        scanf("%d%ld",&N,&M);
        if(N==3)
        {
            int a[3];
            scanf("%d%d%d",&a[0],&a[1],&a[2]);
            for(i=0;i<2;i++)
            {
                for(j=i+1;j<3;j++)
                {
                    if(a[i]>a[j])
                    {
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                }
            }
            first=a[0];
            second=a[1];
            last=a[2];
            ribbon+=length(second,first,first,second);
            ribbon+=length(first,second,first,last);
            ribbon+=length(first,last,second,last);
            ribbon+=length(second,last,last,second);
            ribbon+=length(last,second,last,first);
            ribbon+=length(last,first,second,first);
            long long int z=ceil(ribbon);
            printf("%lld\n",z*M);
            continue;
        }
        int a[N];
        scanf("%d%d",&a[0],&a[1]);
        if(a[0]>a[1])
        {
            second=a[0];
            first=a[1];
            last=a[0];
            second_last=a[1];
        }
        else
        {
            first=a[0];
            second=a[1];
            last=a[1];
            second_last=a[0];
        }
        for(i=2;i<N;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<first)
            {
                second=first;
                first=a[i];
            }
            else if(a[i]<second)
            {
                second=a[i];
            }
            if(a[i]>last)
            {
                second_last=last;
                last=a[i];
            }
            else if(a[i]>second_last)
            {
                second_last=a[i];
            }
        }
        ribbon+=length(second,first,first,second);
        ribbon+=length(first,second,first,last);
        ribbon+=length(first,last,second_last,last);
        ribbon+=length(second_last,last,last,second_last);
        ribbon+=length(last,second_last,last,first);
        ribbon+=length(last,first,second,first);
        long long int z=ceil(ribbon);
        printf("%lld\n",z*M);
    }
    return 0;
}
