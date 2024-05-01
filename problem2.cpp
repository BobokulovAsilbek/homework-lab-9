//Bobokulov Asilbek 230092 FCS1
//CS 111 Data Structures and Algorithms
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited){
    queue<int> q; q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " current node \n";
        for(auto neighbour : adjList[currentNode]){

            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
void dfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited){
    visited[startNode] = true;
    cout << "current node " << startNode << '\n';
    for(auto neighbour : adjList[startNode]){
        if(!visited[neighbour]){
            dfs(adjList, neighbour, visited);
        }
    }
}
int solve()
{
    int n, e; cin >> n >> e;
    vector<vector<int>> adjList(n);
    vector<bool> visited(n);
    int v1, v2;
    for(int i = 0; i < e; i++){
        cin >> v1 >> v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    dfs(adjList, 0, visited);
}
int main()
{
    int m, n; cin >> m >> n;
    vector<vector<bool>> adjList(m, vector<bool>(m));
    for(int i = 0; i < n; i++){
        int v1, v2; cin >> v1 >> v2;
        adjList[v1][v2] = true;
        adjList[v2][v1] = true;
    }
    int t; cin >> t;
    while(t--){
        int v1, v2; cin >> v1 >> v2;
        if(adjList[v1][v2]) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*
6 8
0 2
0 4
0 5
1 4
1 5
2 3
2 4
4 5
*/
/*
0
2
3
4
5
1
*/
