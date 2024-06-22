#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

bool visited[200][200];
int level[200][200];
int cnt[200][200];
int lengthcnt[200][200];
vector<pair<int, int> > movements;
bool isValid(int n, int m, int x, int y)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m))
    {
        return true;
    }
    return false;
}
// bfs method should return the minimum movements
void bfs(int startX, int startY, int k, int n, int m)
{
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            visited[i][j] = false;
            level[i][j] = 0;
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;
    cnt[startX][startY] += 1;
    level[startX][startY] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int ParentX = v.first;
        int ParentY = v.second;
        q.pop();

        for (int movementIdx = 0; movementIdx < movements.size(); movementIdx++)
        {
            pair<int, int> movement = movements[movementIdx];

            int childX = movement.first + ParentX;
            int childY = movement.second + ParentY;
            if (!isValid(n, m, childX, childY) || visited[childX][childY])
            {
                continue;
            }

            q.push(make_pair(childX, childY));
            visited[childX][childY] = true;
            cnt[childX][childY] = cnt[childX][childY] + 1;
            level[childX][childY] = level[ParentX][ParentY] + 1;
            lengthcnt[childX][childY] += ceil(((float)level[childX][childY]) / (float)k);
        }
    }
}

int main()
{
    movements.push_back(make_pair(1, 2));
    movements.push_back(make_pair(-1, 2));
    movements.push_back(make_pair(-1, -2));
    movements.push_back(make_pair(1, -2));
    movements.push_back(make_pair(2, 1));
    movements.push_back(make_pair(-2, 1));
    movements.push_back(make_pair(-2, -1));
    movements.push_back(make_pair(2, -1));
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            lengthcnt[i][j] = 0;
            cnt[i][j] = 0;
        }
    }
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, q; // q number of riders

    cin >> n >> m >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        bfs(x, y, k, n, m);
    }

    int result = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((result > lengthcnt[i][j]) && cnt[i][j] == q)
            {
                result = lengthcnt[i][j];
            }
        }
    }
    if (result == INT_MAX)
        cout << -1;
    else
        cout << result << endl;

    return 0;
}