//.............................for transvers>1.bfs
//...........................................2.dfs
//............................0 for blue
//............................1 for red
#include<bits/stdc++.h>//header files to use vectors, memset, and iostream
using namespace std;
const int MAXN = 100005;//maximum number of vertices
vector<int> adj[MAXN];// vector to store the edges of the graph
int color[MAXN];// store the color of each vertex in the graph
//recursive function->u=vertex,c=color
bool dfs(int u, int c){
    color[u] = c;//assigns the color c to the vertex u
    //traverses all its adjacent vertices v
    //V IS THE ELEMENT ADJACENCY START SE LAST TAK SARE ADJACENCY LIST KE ELEMENTS
    for(auto v: adj[u]){//auto itself decide datatype yaha pr int he  
        if(color[v] == -1){//color of v is not assigned
            if(dfs(v, 1 - c) == false){//we call the function //1-1=0 OR 1-0=1
	        //recursively with color 1-c for v. 
                return false;// two adjacent vertices with the same color
            }
        }
        else if(color[v] == color[u]){
            return false;
        }
    }//all the adjacent vertices of u without any issues
    return true;
}

bool isBipartite(int n){//number of vertices n as input
    memset(color, -1, sizeof color);//color array to -1 for all vertices
    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            if(dfs(i, 0) == false){
                return false;
            }
        }
    }
    return true;
}
// Print the graph
void printGraph( int v) {
	cout<<"\nGIVEN GRAPH WAS\n";
  for (int d = 1; d <= v; ++d) {
    cout << "\n VERTEX "
       << d << ":";
    for (auto x : adj[d])//used to iterate the values of vectors like loop
      cout << "-> " << x;
	  cout<<endl;
  }
}


int main(){
	cout<<"...............WELCOME IN BIPARTITE CHECKING GRAPH................\n";
    int n, m;
    cout<<"enter vertex\n";
    cin >> n ;
    cout<<"enter  edges\n";
	cin >> m;
    for(int i=0; i<m; i++){
    	cout<<"enter edge "<<"of "<<i+1<<" graph: ";
        int u, v;
        cin >> u >> v;
        //For each edge, we take two integers as input representing the vertices
		//that the edge connects. We then add this edge to the adjacency list vector 
		//by pushing the vertices to each other's adjacency list.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartite(n)){
        cout << "Graph is Bipartite\n";
    }
    else{
        cout << "Graph is not Bipartite\n";
    }
   // We then check its adjacent vertices, 2 and 4. Both are uncolored, so we call dfs(2, 1) and dfs(4, 1).
   //4 vertices and 4 edges: (1,2), (2,3), (3,4), (4,1).
    printGraph(n);
    return 0;
}
