#include "common.h"

#ifndef GRAPH_H_
#define GRAPH_H_

pair<vector<int>,bool> depth_first_search(vector<vector <int>> adjacency_matrix, int source, int destination);
pair<vector<int>,bool> breadth_first_search(vector<vector <int>> adjacency_matrix, int source, int destination);

#endif
