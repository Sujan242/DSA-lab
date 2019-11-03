#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int d;
    int height;
    struct Node* left;
    struct Node* right;
};
int height(struct Node* root)
{
    if(root==NULL){return 0;}
    return root->height;
    
}
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}

struct Node* rightrotate(struct Node* y)
{
    
    struct Node* x=y->left;
    struct Node* t2=x->right;
    y->left=t2;
    x->right=y;
    y->height=1+max(height(y->right),height(y->left));
    x->height=1+max(height(x->right),height(x->left));
    return x;
}
struct Node* leftrotate(struct Node* y)
{
    struct Node* x=y->right;
    struct Node* t2=x->left;
    y->right=t2;
    x->left=y;
    y->height=1+max(height(y->right),height(y->left));
    x->height=1+max(height(x->right),height(x->left));
    return x;
    
}

struct Node* insert(struct Node* root, int d)
{
    if(root==NULL)
    {
        struct Node* n=new Node();
        n->d=d;
        root=n;
        root->height=1;
        
    }
    else if(d<root->d)
    {
        root->left=insert(root->left,d);
    }
    else
    {
        root->right=insert(root->right,d);
    }
    
    root->height=1+max(height(root->right),height(root->left));
    int b=height(root->left)-height(root->right);
    if(b>1)
    {
        if(d<root->left->d){root=rightrotate(root);}
        else
        {
            root->left=leftrotate(root->left);
            root=rightrotate(root);
            
        }
    }
    else if(b<-1)
    {
        if(d>root->left->d){root=leftrotate(root);}
        else
        {
            root->right=rightrotate(root->right);
            root=leftrotate(root);
            
        }
    }
    return root;
}

struct Node* del(struct Node* root,int d)
{
    if(root==NULL)
    {return root;}
    if(d<root->d)
    {
        root->left=del(root->left,d);
    }
    else if(d>root->d)
    {
        root->right=del(root->right,d);
    }
    else
    {
        if(root->right==NULL && root->left==NULL){root=NULL;}
        else if(root->right==NULL)
        {
            struct Node* temp=root->left;
            root=NULL;
            root=temp;
        }
        else if(root->left==NULL)
        {
            struct Node* temp=root->right;
            root=NULL;
            root=temp;
        }
        else
        {
            struct Node* temp=root->right;
            while(temp->left!=NULL){temp=temp->left;}
            root->d=temp->d;
            root->right=del(root->right,root->d);
        }
    }
    if(root==NULL){return NULL;}
     root->height=1+max(height(root->right),height(root->left));
    int b=height(root->left)-height(root->right);
    if(b>1)
    {
        int b1=height(root->left->left)-height(root->left->right);
        if(b1>=0)
        {
            root=rightrotate(root);
        }
        else
        {
            root->left=leftrotate(root->left);
            root=rightrotate(root);
        }
    }
    else if(b<-1)
    {
        int b1=height(root->right->right)-height(root->right->left);
        if(b1>0)
        {
            root=leftrotate(root);
        }
        else
        {
             root->right=rightrotate(root->right);
            root=leftrotate(root);
        }
        
        
    }
    return root;
    
}
void printing(struct Node* root)
{
    if(root!=NULL)
    {
        cout<<root->d<<" ";
        printing(root->left);
        printing(root->right);
    }
}
void levelorder(struct Node* root)
{
    queue <struct Node*> q;
    q.push(root);
    while(!q.empty())
    {
        cout<<q.front()->d<<" ";
        if(q.front()->left!=NULL){q.push(q.front()->left);}
        if(q.front()->right!=NULL){q.push(q.front()->right);}
        q.pop();
        
        
    }
    cout<<endl;
}

int main()
{
    struct Node* root;
    root = insert(root, 9);  
    root = insert(root, 5);  
    root = insert(root, 10);  
    root = insert(root, 0);  
      
    printing(root);cout<<endl;
    root=del(root,10);
    printing(root);
}
