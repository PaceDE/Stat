//linearsearch

#include<stdio.h>
#define MAX 100
int binarySearch(int a[],int l,int r,int key)
{
   int m;
   if(l<=r)
   {
       m=(l+r)/2;
       if(a[m]==key)
       {
        return m;
       }
       else if(key<a[m])
        return binarySearch(a,l,m-1,key);
       else
        return binarySearch(a,m+1,r,key);
   }
   return -1;

}
int main()
{
    int i,n,key,location,a[MAX];
    printf("Enter then size of list: ");
    scanf("%d",&n);
    printf("\nEnter the content of list : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the element to find in array: ");
    scanf("%d",&key);
    location=binarySearch(a,0,n-1,key);

    if(location==-1)
    {
        printf("\n%d is not in the list",key);
    }
    else
    {
        printf("%d is in the index %d of the array",key,location);
    }

     printf("\n______________________________________________________\n");
        printf("Smaran Rawal\n");
        printf("______________________________________________________\n");

    return 0;
}
