#include <stdio.h>
#define MAX 100
void mergeSort(int a[], int l, int h) {
 int m;
 if(l<h)
 {
     m=(l+h)/2;
     mergeSort(a,l,m);
     mergeSort(a,m+1,h);
     merge(a,l,m+1,h);
 }
}
void merge(int a[],int l,int m,int h)
{
    int i,j,k,temp[MAX];
    i=l;
    j=m;
    k=l;
    while(i<m && j<=h)
    {
        if(a[i] < a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<m)
        temp[k++]=a[i++];
    while(j<=h)
        temp[k++]=a[j++];
    for(i=l;i<=h;i++)
        a[i]=temp[i];
}

int main() {
  int a[MAX],n,i,j,temp;
    printf("Enter the number of Data item: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    printf("\nData after sorting: ");
    for(i=0;i<n;++i)
        printf("%d ",a[i]);
     printf("\n______________________________________________________\n");
        printf("Smaran Rawal\n");
        printf("______________________________________________________\n");
    return 0;
}
