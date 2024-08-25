#include<stdio.h>
#define MAX 100


void bubbleSort(int a[],int n)
{
    int temp;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(n-i-1);++j)
        {
            if(a[j]>a[j+1])
            {
                temp= a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

}

int main()
{
    int a[MAX],n,i;
    printf("Enter the number of Data item: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    bubbleSort(a,n);
    printf("\nData after sorting: ");
    for(i=0;i<n;++i)
        printf("%d ",a[i]);

         printf("\n______________________________________________________\n");
        printf("Smaran Rawal\n");
        printf("______________________________________________________\n");

    return 0;
}
