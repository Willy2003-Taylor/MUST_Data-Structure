/*Define a undirected graph with adjacent matrices
and traverse the graph in DFS*/

#include<iostream>
#include<vector>
using namespace std;

void dfs_traversal(vector<vector<int>>& adjacencyMatrix, vector<bool>& visited,int current){
    visited[current] = true;
    cout<<current<<" ";
    for(int i = 0; i < adjacencyMatrix.size(); i++)
        if(!visited[i] && adjacencyMatrix[current][i])
            dfs_traversal(adjacencyMatrix,visited, i);
}
int main(){
    vector<vector<int>> adjacencyMatrix={
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };
    int nums = adjacencyMatrix.size();
    vector<bool> visited(nums, false);

    dfs_traversal(adjacencyMatrix, visited, 0);
    return 0;
}