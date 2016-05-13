#include<cstdio>
#include<algorithm>
#define MAX_N 1024
using namespace std;
int n,a[MAX_N];
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<n&&arr[left]>arr[largest])
        largest=left;
    if(right<n&&arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void read()
{
    scanf("%d", &n);
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
}
void print()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    read();
    heapsort(a,n);
    print();
    return 0;
}
