#include<bits/stdc++.h>
using namespace std;
class graph{
    private :
    int v;
    vector<int> *adj;
    public:
    graph(int v){
        this->v=v;
        adj =new vector<int> [v];
    }
    void dEdge(int u,int v){
        adj[u].push_back(v);
    }
    void undEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print_path(int source,int dest);
    bool BFS(int sourse,int dest,int parent[]);
};
void graph::print_path(int sourse,int dest){
    int parent[v];
    if(BFS( sourse, dest, parent)==false){
cout<<"unreachable\n";
return;
    }

    stack<int> st;
    while(parent[dest]!=-1){
        st.push(dest);
        dest=parent[dest];
    }
    cout<<sourse;
    while(!st.empty()){
        cout<<"-->"<<st.top();
        st.pop();
    }
    return;
}
bool graph::BFS(int sourse,int dest,int parent[]){
   queue<int> q;
   bool visited[v];
   for(int i=0;i<v;i++){
    visited[i]=false;
    parent[i]=-1;
   }
   q.push(sourse);
   visited[sourse]=true;
   while(!q.empty()){
    int temp= q.front();
    q.pop();
    for(int k:adj[temp]){
        if(visited[k]==false){
            q.push(k);
            visited[k]=true;
            parent[k]=temp;
            if(k==dest)
            return true;
        }
    }
   }
   return false;
}
int main(){
       cout<<"Number of vertics :";
    int v;
    cin >> v;
 int x,y;
 cout<<"Enter edges:";
 int n;
 cin>>n;
    
 graph gg(v);
 int edge=n;
 while(n--){
    cin>>x>>y;
    gg.dEdge(x,y);
 }
 int s,d;
 cin>>s>>d;
 gg.print_path(s,d);
}