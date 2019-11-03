#include <iostream>
using namespace std;

void heapify(int a[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int lar=i;
    if(l<n && a[l]<a[lar]){lar=l;}
    if(r<n && a[r]<a[lar]){lar=r;}
    if(lar!=i)
    {
        int t=a[i];a[i]=a[lar];a[lar]=t;
        
        heapify(a,n,lar);
    }
}
void buildheap(int a[],int n)
{
    int i=n/2;
    while(i>=0)
    {
        heapify(a,n,i);i--;
    }
}

void heapsort(int a[],int n)
{
   for(int i=n-1;i>=0;i--)
   { int l=a[0];
     a[0]=a[i];
     heapify(a,i,0);
     a[i]=l;
   }
}




int main()
{
    int  a[] = {1, 5, 9, 10, 15, 20};
    int  a2[] = {2,3,8,13};
    buildheap(a2,4);// n2 log(n2)
    
    for(int i=0;i<6;i++)    // n1 log(n2)
    {
        if(a[i]>a2[0])
        {
            int t=a[i];a[i]=a2[0];a2[0]=t;
            heapify(a2,4,0);
        }
    }
    
    
    heapsort(a2,4); // n2log(n)
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    for(int i=3;i>=0;i--)
    {
        cout<<a2[i]<<" ";
    }
    
    
    
    return 0;
}
