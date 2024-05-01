//Bobokulov Asilbek 230092 FCS1
//CS 111 Data Structures and Algorithms
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited){
    visited[startNode] = true;
    for(auto neighbour : adjList[startNode]){
        if(!visited[neighbour]){
            dfs(adjList, neighbour, visited);
        }
    }
}
int main()
{
    int n, m, cnt = 0; cin >> n >> m;
    vector<vector<int>> adjList(n);
    vector<bool> visited(n, false);
    for(int i = 0; i < m; i++){
        int v1, v2; cin >> v1 >> v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(adjList, i, visited);
        }
        cnt ++;
    }
    cout << cnt;
}
