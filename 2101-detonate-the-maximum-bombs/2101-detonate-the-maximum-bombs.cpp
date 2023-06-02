class Solution {
#define ll long long int
public:
    // Perform depth-first search (DFS) to count the number of detonations in a connected component
    void dfs(vector<vector<int>> &grid, vector<bool> &vis, int &c, int &i)
    {
        vis[i] = true;    // Mark the current node as visited
        c++;    // Increment the count of detonations
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (!vis[grid[i][j]])    // If the neighbor node has not been visited
                dfs(grid, vis, c, grid[i][j]);    // Recursively perform DFS on the neighbor node
        }
    }

    /*
     * Calculates the maximum number of bombs that can be detonated.
     *
     * @param bombs The vector of bomb coordinates and radii.
     *              Each element in the vector is a vector of three integers [x, y, r],
     *              where (x, y) represents the coordinates of a bomb and r is its radius.
     * @return The maximum number of bombs that can be detonated.
     */
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();    // Number of bombs
        vector<vector<int> > grid(n);    // Adjacency list to represent bomb connections

        // Construct a graph to represent bomb connections
        for (int i = 0; i < n; i++)
        {
            ll x1, y1, r1;
            x1 = bombs[i][0];    // x-coordinate of the current bomb
            y1 = bombs[i][1];    // y-coordinate of the current bomb
            r1 = bombs[i][2];    // Radius of the current bomb
            for (int j = 0; j < n; j++)
            {
                if (i != j)    // Exclude the current bomb itself
                {
                     ll x2, y2, r2;
                     x2 = abs(x1 - bombs[j][0]);    // Calculate the absolute difference of x-coordinates
                     y2 = abs(y1 - bombs[j][1]);    // Calculate the absolute difference of y-coordinates
                    if (x2 * x2 + y2 * y2 <= r1 * r1)    // Check if the distance between bombs is within the range of detonation
                    {
                        grid[i].push_back(j);    // Add the j-th bomb to the adjacency list of the i-th bomb
                    }
                }
            }
        }

        int res = INT_MIN;    // Initialize the maximum detonation count
        for (int i = 0; i < n; i++)
        {
            int c = 0;    // Initialize the detonation count for the current connected component
            vector<bool> vis(n, false);    // Array to track visited nodes during DFS
            dfs(grid, vis, c, i);    // Perform DFS on the i-th bomb
            res = max(res, c);    // Update the maximum detonation count
        }
        return res;    // Return the maximum detonation count
    }
};