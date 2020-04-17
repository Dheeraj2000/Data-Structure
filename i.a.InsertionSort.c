//Intersion sort


#include<stdio.h>
void main()
{
int i,j,n,key;
printf("Enter Size of array");
scanf("%d",&n);
int a[n];
printf("Enter %d Array Elements",n);
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
key=a[i];
j=i-1;
while(j>=0&&a[j]>key)
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=key;
}
for(i=0;i<=n-1;i++)
{
printf("%d ",a[i]);
}
}
