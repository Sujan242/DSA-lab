#include <iostream>
using namespace std;

void heapify(int h[],int i,int n)
{
    
    int lar=h[i];int lari=i;
    if(2*i+1<n && h[2*i+1]>h[i] ){lar=h[2*i+1];lari=2*i+1;}
    
    if(2*i+2<n && h[2*i+2]>lar){lar=h[2*i+2];lari=2*i+2;}
    
    if(lar!=h[i])
    {
        int t=h[lari];h[lari]=h[i];h[i]=t;
        heapify(h,lari,n);
    }
    
    
}
void buildheap(int a[],int n)
{
    int k=n/2;
    while(k-->0)
    {
        heapify(a,k,n);
        
    }
    
}


void printing(int a[],int n)
{
    for(int j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }cout<<endl;
}
void heapsort(int a[],int n)
{
    buildheap(a,n);
    
    for(int i=n-1;i>=0;i--)
    {
        int t=a[i];
        a[i]=a[0];
        a[0]=t;
        heapify(a,0,i);
      
        
    }
    
}


int main()
{
    int a[]={2,6,1456,9,4,1903,3};
    heapsort(a,7);
    printing(a,7);
    
}
