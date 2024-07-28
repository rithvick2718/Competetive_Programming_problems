#include<bits/stdc++.h>
using namespace std;
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}
// Function to color the graph using a greedy algorithm
void greedyColoring(vector<vector<int>>& graph, int V) {
    vector<int> color(V, -1); // Color assignments for all vertices
    color[0] = 1; // Assign the first color to the first vertex
    vector<bool> available(V + 1, true); // Colors that are available
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        // Mark colors of adjacent vertices as unavailable
        fill(available.begin(), available.end(), true);
        
        for (int i = 0; i < V; i++) {
            if (graph[u][i] && color[i] != -1) {
                available[color[i]] = false;
            }
        }

        // Find the first available color
        int cr;
        for (cr = 1; cr <= V; cr++) {
            if (available[cr]) {
                break;
            }
        }

        color[u] = cr; // Assign the found color to the vertex u
    }
    cout<<*max_element(color.begin(),color.end())<<"\n";
    // Print the result
    for (int u = 0; u < V; u++) {
        cout<<color[u]<<" ";
    }
    cout<<"\n";
}
bool checkPrime (int n)
{
    if(n==2 || n==3 || n== 5 || n==7)
    return true;
    else if(n%2==0 || n%3 == 0)
    return false;
    else
    {
        int i=1;
        bool p= (n%(6*i-1)!=0 && n%(6*i+1)!=0);
        while(p && (6*i-1)*(6*i-1)<=n)
        {
            i++;
            p=p&&(n%(6*i-1)!=0)&&(n%(6*i+1)!=0);
        }
        return p;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n;
        cin>>n;
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(checkPrime((i+1)^(j+1))) graph[i][j]=1;
                else graph[i][j]=0;
            }
        }
        greedyColoring(graph,n);
    }
}