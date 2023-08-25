#include<bits/stdc++.h>
using namespace std;
char node(int op){
    switch(op){
        case 0:
        return 'A';
        break;
        case 1:
        return 'B';
        break;
        case 2:
        return 'C';
        break;
          case 3:
        return 'D';
        break;
          case 4:
        return 'E';
        break;
          case 5:
        return 'F';
        break;
          case 6:
        return 'G';
        break;
          case 7:
        return 'j';
        break;  case 8:
        return 'k';
        break;
        default:
        return '0';
        break;

    }
}
class graph{
    private:
    int v;
    vector<int> *adj;
    public:
    graph(int v){
        this->v=v;
        adj = new vector<int> [v];
    }
    void dEdge(int u,int v){
        adj[u].push_back(v);
    }
      void unDEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printPath( int source,int dest);
    bool BFS(int source,int dest,int parent[]);
};
void graph::printPath(int  source,int dest){
    int parent[v];
    if(BFS(source,dest,parent)==false){
        cout<<"from source to destinaton not reachable!";
        return;
    }
    stack<int> st;
     while(parent[dest]!=-1){
        st.push(dest);
        dest=parent[dest];
     }
     cout<<node(source);
     while(!st.empty()){
        cout<<"->"<<node(st.top());
        st.pop();
     }
     return; 
}

bool graph::BFS(int source,int dest,int parent[]){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        parent[i]=-1;
    }
    queue<int> q;
    q.push(source);
    visited[source]=true;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int k:adj[temp]){
            if(visited[k]==false){
                visited[k]=true;
                q.push(k);
                parent[k]=temp;
                if(k==dest){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(int x){
    cout<<"Enter vertex number :";
   cin>>x;
   int edge;
   cout<<"Enter edge number :";
   cin>>edge;
   graph gg(x);
   int s,d;
   while(edge--){
    cin>>s>>d;
    gg.dEdge(s,d);
   }
   cout<<"\n\n";
   while(1){
    cin>>s>>d;
    gg.printPath(s,d);
    cout<<"\n";
   }
}