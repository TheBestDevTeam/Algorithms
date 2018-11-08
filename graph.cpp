#include "graph.h"

/* depth first Search implementation
name: depth_first_search
input: vector<vector <int>> adjacency_matrix, int source, int destination
output: pair<bool, int> indicating the status of search and position if successful else -1
*/
pair<vector<int>,bool> depth_first_search(vector<vector<int>> adjacency_matrix, int source, int destination)
{
    vector<bool> visited(adjacency_matrix[0].size(),false);
    vector<int> node_visited;
    return depth_first_search_wrapper(adjacency_matrix,source,destination,visited, node_visited);
}

/* wrapper function for dfs implementation. The Actual logic for dfs
name: depth_first_search_wrapper
input: vector<vector <int>> adjacency_matrix, int source, int destination, vector<bool> visited, vector<int> node_visited
output: pair<bool, int> indicating the status of search and position if successful else false
*/
pair<vector<int>,bool> depth_first_search_wrapper(vector<vector<int>> adjacency_matrix, int source, int destination, vector<bool> visited, vector<int>node_visited)
{
    visited[source]=true;
    node_visited.push_back(source);
    if(source==destination)
        return make_pair(node_visited,true);
    for(int i=0; i<adjacency_matrix[source].size();i++)
    {
        if(i==source)
            continue;
        if(adjacency_matrix[source][i]==true && visited[i]==false)
        {
            visited[i]=true;
            depth_first_search_wrapper(adjacency_matrix,source,destination,visited,node_visited);
        }
    }
    return make_pair(node_visited,false);
}

/* Bread first Search implementation
name: breadth_first_search
input: vector<vector <int>> adjacency_matrix, int source, int destination
output: pair<bool, int> indicating the status of search and position if successful else -1
*/
pair<vector<int>,bool> breadth_first_search(vector<vector <int>> adjacency_matrix, int source, int destination)
{
    vector<bool> visited(adjacency_matrix[0].size(),false);
    vector<int> node_visited;
    queue<int> next_to_visit;

    next_to_visit.push(source);
    node_visited.push_back(source);
    while(!next_to_visit.empty())
    {
        int node = next_to_visit.front();
        next_to_visit.pop();
        node_visited.push_back(node);
        if(node==destination)
        {
            visited.push_back(true);
            return make_pair(node_visited,true);
        }
        if(visited[node]);
        else
            for(auto it=adjacency_matrix[node].begin();it!=adjacency_matrix[node].end();it++)
                next_to_visit.push(*it);
    }
    return make_pair(node_visited,false);
}