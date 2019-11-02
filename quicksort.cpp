#include <iostream>
using namespace std;


int partition(int a[],int l,int r)
{
    int x=a[r];int j=l-1;
    for(int i=l;i<=r;i++)
    {
        if(a[i]<=x)
        {
            j++;
            int t=a[i];a[i]=a[j];a[j]=t;
            
            
        }
        
        
    }
    return j;
    
    
}


void quicksort(int a[] , int l,int r)
{
    if(l<r)
    {
        int i=partition(a,l,r);
        quicksort(a,l,i-1);
        quicksort(a,i+1,r);
    }
}




int main()
{
    int a[]={6,321,9,1000,8,3,5};
    quicksort(a,0,6);
    //  cout<<partition(a,0,6);
    //  cout<<partition(a,5,6);
    
    
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
