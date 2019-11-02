#include <iostream>
using namespace std;


void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int a1[n1];int a2[n2];
    
    for(int i=l;i<n1+l;i++)
    {
        a1[i-l]=a[i];
    }
    for(int i=n1+l;i<n2+n1+l;i++)
    {
        a2[i-n1-l]=a[i];
    }
    
    int i1=0,i2=0;int i=l;
    while(i1< n1 && i2<n2)
    {
        if(a1[i1]<a2[i2])
        {
            a[i]=a1[i1];
            i1++;i++;
        }
        else
        {
            a[i]=a2[i2];
            i2++;i++;
        }
    }
    for(int j=i1;j<n1;j++)
    {
        a[i]=a1[j];i++;
    }
    for(int j=i2;j<n2;j++)
    {
        a[i]=a2[j];i++;
    }
    
    
}



void mergesort(int a[],int l,int r)
{
    int m=(l+r)/2;
    if(l<r)
    {
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}


int main()
{
    int a[]={6,3,9000,1,8000,3,5};
    mergesort(a,0,6);
    
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
