#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

const int maxn = 1005; 
const int n = 1005;
vector<vector<int> > adj, adj_t;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;
// bool assignment[1000];
void dfs1(int v)
{
    used[v] = true;
    for (int u : adj[v])
    {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl)
{
    comp[v] = cl;
    for (int u : adj_t[v])
    {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT()
{
    order.clear();
    //used.assign(n, false);
    for (int i = 0; i < 2*n; ++i)
    {
        if (!used[i])
            dfs1(i);
    }

    //comp.assign(2*n, -1);
    int j = 0;
    for (int i = 0; i < 2*n; ++i)
    {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j);
        j++;
    }

    // assignment.assign(n / 2, false);
    for (int i = 0; i < n; i = i + 2)
    {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
        // assignment[i]=true;
    }
    return true;
}

void addAdjacent(int a, bool na, int b, bool nb)
{

    a = 2 * a + (na ? 1 : 0);
    b = 2 * b + (nb ? 1 : 0);

    int neg_a = a ^ 1;
    int neg_b = b ^ 1;

    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

int convertChartoInt(char c)
{
    int n = c - 'a';
    return n;
}
char convertIntToChar(int n) {
    return 'a' + n;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    getchar();
    adj.assign(2 * maxn, vector<int>());
    adj_t.assign(2 * maxn, vector<int>());
    used.assign(2 * maxn, false);
    comp.assign(2 * maxn, -1);
    assignment.assign(maxn / 2, false);

    // SCC n);
    for (int i = 0; i < n; i++)
    {
        string str;
        // cin >> str;
        getline(cin, str);
        if (str.length() == 1)
        {
            addAdjacent(convertChartoInt(str[0]), false, convertChartoInt(str[0]), false);
        }
        else if (str.length() == 2)
        {
            addAdjacent(convertChartoInt(str[1]), true, convertChartoInt(str[1]), true);
        }
        else if (str.length() == 3)
        {
            addAdjacent(convertChartoInt(str[0]), false, convertChartoInt(str[2]), false);
        }
        else if (str.length() == 4)
        {
            if (str[0] == '~')
            {
                addAdjacent(convertChartoInt(str[1]), true, convertChartoInt(str[3]), false);
            }
            else if (str[2] == '~')
            {
                addAdjacent(convertChartoInt(str[0]), false, convertChartoInt(str[3]), true);
            }
        }
        else if (str.length() == 5)
        {
            addAdjacent(convertChartoInt(str[1]), true, convertChartoInt(str[4]), true);
        }
    }
    /*solve_2SAT();
    if (solve_2SAT())
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    for (int i = 0; i < 50; i++)
    {
        if (assignment[i])
            cout << "true"
                 << " ";
        else
            cout << "false"
                 << " ";
    }
    cout << endl;
    for (int i = 0; i < 150; i++)
    {
        cout << comp[i] << " ";
    }
    for (int i = 0; i < 50; i++)
    {
        cout << "Adjacency list for variable " << i / 2 << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
*/
if(solve_2SAT()){
    for (int i = 0; i < n; i++) {
        char var = convertIntToChar(i);
        bool truth = assignment[i];
        if (adj[2 * i].empty() && adj[2 * i + 1].empty()) {
            continue; // Skip variables not in the adjacency list
        }
        cout << var << " " << (truth ? "true" : "false") << endl;
    }
} else cout<<"No assignment possible";
    return 0;
}
