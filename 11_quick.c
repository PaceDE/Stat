#include <stdio.h>
#define MAX 100
void quick_sort(int[],int,int);
int partition(int[],int,int);
int main() {
  int a[MAX],n,i,j,temp;
    printf("Enter the number of Data item: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    printf("\nData after sorting: ");
    for(i=0;i<n;++i)
        printf("%d ",a[i]);
     printf("\n______________________________________________________\n");
        printf("Smaran Rawal\n");
        printf("______________________________________________________\n");
    return 0;
}
void quick_sort(int a[ ],int l,int r)
{
int j;
if(l<r)
{ j=partition(a,l,r);
quick_sort(a,l,j-1);
quick_sort(a,j+1,r);
}
 }
int partition(int a[],int l,int r)
{
int pivot,i,j,temp;
pivot=a[l];
i=l;
for(j=i+1;j<=r;j++)
{
    if(a[j]<=pivot)
    {
        i++;
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
    }
}
        temp=a[l];
        a[l]=a[i];
        a[i]=temp;

       return i;

}
