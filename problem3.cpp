//Bobokulov Asilbek 230092 FCS1
//CS 111 Data Structures and Algorithms
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &adjList, int startNode, vector<int> &gradeFriend, vector<bool> &visited){
    queue<int> q; q.push(startNode); gradeFriend[startNode] = 0;
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        for(auto neighbour:adjList[currentNode]){
            if(!visited[neighbour]){
                gradeFriend[neighbour] = gradeFriend[currentNode] + 1;
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
}
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> adjList(n);
    vector<int> gradeFriend(n, -1);
    vector<bool> visited(n, false);
    for(int i = 0; i < m; i++){
        int v1, v2; cin >> v1 >> v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    bfs(adjList, 0, gradeFriend, visited); gradeFriend[0] = 0;
    for(auto x:gradeFriend) cout << x << ' ';
}
