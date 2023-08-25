#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *left;
    node *right;
};
typedef struct node *nodeptr;
nodeptr getNode(){
    nodeptr p= (nodeptr)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    return p;
}
nodeptr root=NULL;
nodeptr tail=NULL;

void preOrder(nodeptr p){
    if(p==NULL){
        return;
    }
     cout<<p->data<<" ";
    preOrder(p->left);
    preOrder(p->right);
}
void inOrder(nodeptr p){
    if(p==NULL){
        return;
    }
    inOrder(p->left);
    cout<<p->data<<" ";
    inOrder(p->right);
}
void postOrder(nodeptr p){
    if(p==NULL){
        return;
    }
    postOrder(p->left);
    postOrder(p->right);
     cout<<p->data<<" ";
}
void preOrderAl(nodeptr ptr){
    stack<nodeptr> st;
    st.push(NULL);
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        if(ptr->right!=NULL){
            st.push(ptr->right);
        }
        if(ptr->left!=NULL){
            ptr=ptr->left;
        }
        else {
            ptr=st.top();
            st.pop();
        }
    }
}
void inOderAl(nodeptr ptr){
    stack<nodeptr> st;
    st.push(NULL);
    XXX:
    while(ptr!=NULL){
        st.push(ptr);
        ptr=ptr->left;
    }
    ptr=st.top();
    st.pop();
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        if(ptr->right!=NULL){
            ptr=ptr->right;
            goto XXX;
        }
        ptr=st.top();
        st.pop();
    }
}
void postOrderAl(nodeptr ptr){
    stack<nodeptr>st;
    stack<bool> bo;
    st.push(NULL);
    bo.push(false);
    XXX:
    while(ptr!=NULL){
        st.push(ptr);
        bo.push(false);
        if(ptr->right!=NULL){
            st.push(ptr->right);
            bo.push(true);
        }
        ptr=ptr->left;
    }
    ptr=st.top();
    st.pop();
    bool x=bo.top();
    bo.pop();
    while(x!=true){
        cout<<ptr->data<<" ";
        if(!st.empty()){
         ptr= st.top();
         st.pop();
         x=bo.top();
         bo.pop(); 
        }
        else{
            return;
            }
    }
     if(x==true){
            goto XXX;
        }
}
void insert(){
    root=getNode();
   nodeptr ptr=root;
   stack<nodeptr> st;
   while(1){
    char x,y;
    cin>>x>>y;
    if(x=='.'&& y=='.'){
        break;
    }
     ptr->data=x;
    if(y=='>'){
       ptr->right=getNode();
       st.push(ptr->right);
       cin>>y;
       if(y=='<')
       goto XXX;
       else if(y=='/')
       goto YYY;
    }
    else if(y=='<'){
        XXX:
    ptr->left=getNode();
     ptr=ptr->left;
    }
      else if(y=='/'){
        YYY:
        if(!st.empty()){
     ptr=st.top();
     st.pop();
     }
     continue;
    }
   }
}
int main(){
insert();
preOrder(root);
cout<<"\n";
inOrder(root);
cout<<"\n";
postOrder(root);

cout<<"\n\n";
preOrderAl(root);
cout<<"\n\n";
inOderAl(root);
cout<<"\n\n";
postOrderAl(root);
/*
A > <
B <
W > <
N /
Q > <
L /
M /
C > <
P > /
Z <
X /
S /
*/
}
