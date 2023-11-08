/*Define a undirected graph with adjacent matrices
and traverse the graph in BFS */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs_traversal(vector<vector<int>>& adjacencyMatrix, int starter){
    int nums = adjacencyMatrix.size();
    //nums is the number of the nodes in the graph
    vector<bool> visited(nums, false);
    queue<int> q;

    visited[starter] = true;
    q.push(starter);

    /*The starting point is needed to output first*/

    while(!(q.empty())){
        int current = q.front();
        q.pop();
        cout<<current<<" ";

        for(int i = 0; i < nums; i++)
            if(adjacencyMatrix[current][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
                /*To complete "BFS", we need a "FIFO"*/
            }
    }
}

int main(){
    vector<vector<int>> adjacencymatrix = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,1,0,0,0}
    };
    int starter = 0;
    bfs_traversal(adjacencymatrix, starter);
    return 0;
}
