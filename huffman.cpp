#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    int freq;
    node *left;
    node *right;
};
typedef struct node *nodeptr;
nodeptr getNode(){
    nodeptr p= (nodeptr)malloc(sizeof(struct node));
    p->data='\0';
    p->left=NULL;
    p->right=NULL;
    return p;
}
void inOrder(nodeptr p){
    if(p==NULL){
        return;
    }
    inOrder(p->left);
    if(p->data!='\0')
    cout<<p->data<<" ";
    inOrder(p->right);
}
nodeptr huffman(string st,int freq[]){
    int n=st.length();
    nodeptr ptr[n];
    for(int i=0;i<n;i++){
        ptr[i]=getNode();
        ptr[i]->data=st[i];
        ptr[i]->freq=freq[i];
    }
    nodeptr root[n];
    int j=0;
    int i=0;
    while(n!=1){
         if(n%2==0&&i<=n-1){
         root[j]=getNode();
         root[j]->left=ptr[i];
         i++;
         root[j]->right=ptr[i];
         i++;
         }
         else{
          root[j]=ptr[i];
          i++;
         }
         ptr[j]=root[j];
         j++;
        if(i==n){
            j=0;
            n=n/2;
            i=0;
            
        }
    }
    return ptr[0];
}

int main(){
    int a[10]={1,1,2,2,3,3};
 inOrder( huffman("abcdef",a));
  
}