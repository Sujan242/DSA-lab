#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
     
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
     
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        
        heapify(arr, n, largest); 
    } 
} 
  

void buildHeap(int arr[], int n) 
{ 
    
    int startIdx = (n / 2) - 1; 
  
    
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 

class Heap
{
    public :int h[10000];
    public :int n;
    public:
    Heap()
    {
        n=0;
    }
    
    void insert(int a)
    {
        h[n]=a;
        n=n+1;
        
    }
    
    int maximum()
    {
        buildHeap(h,n);
        return h[0];
    }
    void extractmax()
    {
        buildHeap(h,n);
        for(int i=0;i<n-1;i++)
        {
            h[i]=h[i+1];
        }
        
    }
    void printfun()
    {
        
        for(int i=0;i<n;i++)
        {
            cout<<h[i]<<" ";
        }
    }
};




int main()
{
    int suj=0;
    while(suj--<10)
    {
        cout<<"1.Insert 2.maximum 3.extractmax 4. buildHeap 5.print"<<endl;
        int ar[10000];int no;int c;
        cin>>c;Heap Myheap=Heap();
        switch(c)
        {
            case 1:
            {
                cout<<"Number of values to insert?";int k;
                cin>>k;
                for(int i=0;i<k;i++){cin>>ar[i];}
                no=k;buildHeap(ar,no);
            }break;
            case 2:
            {
                cout<<ar[0]<<endl;
                
            }break;
            case 3:
            {
                for(int i=0;i<no-1;i++){ar[i]=ar[i+1];}no--;
                buildHeap(ar,no);
            }break;
            case 4:
            {
                buildHeap(ar,no);
            }break;
            case 5:
            {
               for(int i=0;i<no;i++){cout<<ar[i]<<" ";}
            }
        }
    }
    
    
    return 0;
}