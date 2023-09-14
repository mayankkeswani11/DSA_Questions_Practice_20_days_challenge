/*Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1*/


#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isSafePath(vector<vector<int>>&m,vector<vector<int>>&visited,int x,int y,int n)
    {
        if((x>=0&&x<=n-1 )&& (y>=0&&y<=n-1) && visited[x][y]==0 && m[x][y]==1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m,vector<vector<int>> &visited,string path,vector<string> &ans,int x,int y,int n)
    {
        //intuition behind this problem  when this function calls that solve for one condition and remaining will solve recursion
        
        if(x==n-1&&y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        //mark visited as first position is always true
        
        visited[x][y]=1;
        
        //NOW check the four condition of movement of rat
        
        //case 1
        int newx=x+1;
        int newy=y;
        if(isSafePath(m,visited,newx,newy,n))
        {
            path.push_back('D');
            solve(m,visited,path,ans,newx,newy,n);
            path.pop_back();
        }
        
        //case2
         newx=x;
         newy=y+1;
        if(isSafePath(m,visited,newx,newy,n))
        {
              path.push_back('R');
            solve(m,visited,path,ans,newx,newy,n);
            path.pop_back();
        }
        
        //case3
        newx=x-1;
         newy=y;
        if(isSafePath(m,visited,newx,newy,n))
        {
              path.push_back('U');
            solve(m,visited,path,ans,newx,newy,n);
            path.pop_back();
        }
        
        //case4
         newx=x;
         newy=y-1;
        if(isSafePath(m,visited,newx,newy,n))
        {
             path.push_back('L');
            solve(m,visited,path,ans,newx,newy,n);
            path.pop_back();
        }
        
        
        visited[x][y]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        //step1 condition if starting element is zero then how can rat start his way
        vector<string> ans;
        if(m[0][0]==0)
        {
            return ans;
        }
        
        //step2 to know the path whether it is right,left,down,up
        string path="";
        
        //step3 Rat previously visited or not on that place and inititally mark zeros
        
        vector<vector<int>>visited=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        
        // step4 starting position
        int srcx=0;
        int srcy=0;
        
        //step5 recursively solve this problem 
        
        solve(m,visited,path,ans,srcx,srcy,n);
        sort(ans.begin(),ans.end());
        return ans;
           
    }
};