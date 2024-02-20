//Khan's algorithim for topological sort

#include <bits/stdc++.h> 
using namespace std;

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // Create an adjacency list from edge list
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);  // Add edge to adjacency list
    }

    // Initialize indegree of all vertices to 0
    vector<int>indegree(v, 0);

    // Calculate indegree of all vertices
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    // Initialize an empty vector to store the topological order
    vector<int> ans;

    // Create a queue to store vertices with indegree 0
    queue<int>q;
    for(int i = 0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);  // If indegree is 0, add vertex to queue
        }
    }

    // Process vertices in the queue
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // Add vertex to topological order
        ans.push_back(front);

        // Reduce indegree of all neighbors by 1
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;

            // If indegree becomes 0, add neighbor to queue
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // Return the topological order
    return ans;
}

int main() {
    // Number of vertices and edges
    int v = 6, e = 6;

    // Edge list
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    // Perform topological sort
    vector<int> result = topologicalSort(edges, v, e);

    // Print the topological order
    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}
