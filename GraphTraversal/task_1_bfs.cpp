#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class bfs
{
    vector<int> *adjList; // adjacency list for storing the the graph edges in 2D vector
    int vertices;         // number of vertices
    int *predecessor;     // predecessor of each vertex to be stored
    int *dist;            // and its distance from the source
    bool *visited;        // bool array stores the information whether ints vertex is visited at least once in bfs

public:
    bfs(int verNum);
    void addEdge(int src, int dest);
    bool BFS(int source, int destination);
    void printShortestPath(int src, int dest);
    ~bfs();
};
bfs ::bfs(int verNum)
{
    vertices = verNum;
    adjList = new vector<int>[verNum];
    predecessor = new int[verNum];
    dist = new int[verNum];
    visited = new bool[verNum];
}
void bfs::addEdge(int src, int dest)
{
    adjList[src].push_back(dest); // Uni directional graph
}

bool bfs ::BFS(int source, int destination)
{
    queue<int> q; // a queue to maintain queue of vertices for adjancency list
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        predecessor[i] = -1;
    } // all arrays initialised

    visited[source] = true; // source to be visisted first
    dist[source] = 0;       // setting distance of source from itself to 0
    q.push(source);         // putting source in queue first

    // basic BFS opertion
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adjList[u].size(); i++)
        {
            if (visited[adjList[u][i]] == false)
            {
                visited[adjList[u][i]] = true;
                dist[adjList[u][i]] = dist[u] + 1; // distance from prdecessor getting incremented by one
                predecessor[adjList[u][i]] = u;    // predecessor getting updated
                q.push(adjList[u][i]);

                if (adjList[u][i] == destination)
                    return true; // break when destination reached
            }
        }
    }
    return false;
}

void bfs ::printShortestPath(int src, int dest)
{
    if (!BFS(src, dest))
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

bfs::~bfs()
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
    bfs BFS(n);

    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        BFS.addEdge(src, dest);
    }
    cin >> source >> destination;

    BFS.printShortestPath(source, destination);
    return 0;
}