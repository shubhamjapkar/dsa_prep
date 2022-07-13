#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> vis;

int maximumInvitations(vector<int> &favorite)
{
    int len = favorite.size();
    vis = vector<bool>(len, false);
    G.resize(len);

    for (int i = 0; i < len; ++i)
        G[i] = vector<int>();

    vector<int> armLength(len, 1), indegree(len, 0);

    int i{};

    for (; i < len; ++i)
    {
        G[i].emplace_back(favorite[i]);
        indegree[favorite[i]]++;
    }

    queue<int> q;

    i = 0;
    for (; i < len; ++i)
        if (!indegree[i])
            q.push(i);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        vis[parent] = true;

        for (int &x : G[parent])
        {
            armLength[x] = armLength[parent] + 1;
            indegree[x]--;
            if (!indegree[x])
                q.push(x);
        }
    }

    int maxCycleLength = 0, totalCoupleWithArmLength = 0;

    i = 0;
    for (; i < len; ++i)
    {
        if (!vis[i])
        {
            if (i == favorite[favorite[i]])
            {
                int curArmLength = armLength[i] + armLength[favorite[i]];
                totalCoupleWithArmLength += curArmLength;
                vis[i] = true;
                vis[favorite[i]] = true;
            }
            else
            {
                int currCycleLength = getCycleLength(i);
                maxCycleLength = max(maxCycleLength, currCycleLength);
            }
        }
    }

    return max(maxCycleLength, totalCoupleWithArmLength);
}

int getCycleLength(int node)
{
    int count = 0;
    while (!vis[node])
    {
        vis[node] = true;
        for (int x : G[node])
            count = 1 + getCycleLength(x);
    }
    return count;
}

static const auto io_syc_off = []()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();

int main()
{
}