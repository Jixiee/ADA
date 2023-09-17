// Write a program to implement binary search in C using iterative method
#include <stdio.h>
int binarysearch(int a[],int low,int high,int key)
{
int mid;
while(low<=high)
{
mid=(low+high)/2;
if(a[mid]==key)
{
return mid;
}
else if(key>a[mid])
{
low=mid+1;
}
else if(key<a[mid])
high=mid-1;
}
return -1;
}
int main()
{
printf("========================================");
int a[20],i,n,key,pos;
printf("\nEnter the number of Elements= ");
scanf("%d",&n);
printf("Enter %d elements= ",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\n========================================");
printf("\nEnter the element to be searched= ");
scanf("%d",&key);
pos=binarysearch(a,0,n-1,key);
if(pos>=0)
{
printf("Element is found at %d",pos+1);
}
else
{
printf("\nElement is not found");
}
printf("\n========================================");
}
