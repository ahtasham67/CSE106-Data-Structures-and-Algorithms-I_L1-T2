#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class dfs
{
    vector<int> *adjList; // adjacency list for storing the the graph edges in 2D vector
    int vertices;         // number of vertices
    int *predecessor;     // predecessor of each vertex to be stored
    int *dist;            // and its distance from the source
    bool *visited;        // bool array stores the information whether ints vertex is visited at least once in dfs

public:
    dfs(int verNum);
    void addEdge(int src, int dest);
    bool DFS(int source, int destination);
    bool DFSrecursion(int v, int destination);
    void printShortestPath(int src, int dest);
    ~dfs();
};
dfs ::dfs(int verNum)
{
    vertices = verNum;
    adjList = new vector<int>[verNum];
    predecessor = new int[verNum];
    dist = new int[verNum];
    visited = new bool[verNum];
}
void dfs::addEdge(int src, int dest)
{
    adjList[src].push_back(dest); // Uni directional graph
}

bool dfs ::DFSrecursion(int v, int destination)
{
    if (v == destination)
        return true; // break when destination reached

    for (int i = 0; i < adjList[v].size(); i++)
    {
        if (!visited[adjList[v][i]])
        {
            visited[adjList[v][i]] = true;
            dist[adjList[v][i]] = dist[v] + 1; // distance from prdecessor getting incremented by one
            predecessor[adjList[v][i]] = v;    // predecessor getting updated

            if (DFSrecursion(adjList[v][i], destination))
                return true;
        }
    }
    return false;
}

bool dfs ::DFS(int source, int destination)
{
    // using recursion for depth search function
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        predecessor[i] = -1;
    } // all arrays initialised

    visited[source] = true; // source to be visisted first
    dist[source] = 0;       // setting distance of source from itself to 0

    if (DFSrecursion(source, destination))
        return true;
    return false;
}

void dfs ::printShortestPath(int src, int dest)
{
    if (!DFS(src, dest))
    {
        cout << -1 << endl; // Source Destiation not connected
        return;
    }

    vector<int> path;      // vector path stores the shortest path
    int back_track = dest; // Start from the destination vertex

    path.push_back(back_track); // Add the destination vertex to the path

    // Reconstruct the path by following the predecessors
    while (back_track > 0)
    {                                            // iterates as long as there is a valid predecessor for the current vertex back_track
        path.push_back(predecessor[back_track]); // Add the predecessor to the path
        back_track = predecessor[back_track];    // update the predecessor
    }

    cout << dist[dest] << endl; // print distance from source in distance array
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
}

dfs::~dfs()
{
    delete[] adjList;
    delete[] predecessor;
    delete[] dist;
    delete[] visited;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m; // number of vertices n, number of edges e
    int source, destination;
    cin >> n >> m;
    dfs dfs(n);

    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        dfs.addEdge(src, dest);
    }
    cin >> source >> destination;

    dfs.printShortestPath(source, destination);
    return 0;
}