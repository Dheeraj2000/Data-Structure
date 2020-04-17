//Program for Selection Sorting
#include<stdio.h>
void main()
{
    int i,j,n,temp,min;
    printf("enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
	    { 
             min=j;
	    }
	}
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
    }
    printf("the sorted array is:\n");
   for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
