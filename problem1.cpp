//Bobokulov Asilbek 230092 FCS1
//CS 111 Data Structures and Algorithms
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> adjList, vector<vector<int>> vec, int startNode){
    int sum = 0;
    for(auto x:adjList[startNode]){
        sum += vec[startNode][x];
    }
    cout << sum;
}
int main()
{
    int n, e; //cin >> n >> e;
    vector<vector<int>> vec(6, vector<int>(6));
    vector<vector<int>> adjList;
    adjList = { {1, 5}, {0, 2, 3}, {1, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}  };
    vec[0][5] = 25; vec[5][0] = 25;
    vec[1][0] = 12; vec[0][1] = 12;
    vec[1][2] = 13; vec[2][1] = 13;
    vec[1][3] = 15; vec[3][1] = 15;
    vec[3][5] = 13; vec[5][3] = 13;
    vec[2][4] = 5; vec[4][2] = 5;
    vec[2][5] = 2; vec[5][2] = 2;
    vec[4][3] = 5; vec[3][4] = 5;
    /*
    for(int i = 0; i < e; i++){
        int u, v, w; cin >> u >> v >> w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        vec[u][v] = w;
        vec[v][u] = w;
    }
    */
    int startNode;
    cin >> startNode;
    bfs(adjList, vec, startNode);
}
/*
6 8
0 1 12
0 5 25
1 2 13
2 4 5
2 5 2
4 3 5
1 3 15
5 3 13
0
*/
