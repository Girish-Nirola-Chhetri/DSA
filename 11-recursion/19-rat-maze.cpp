#include<iostream>
#include<vector>   
#include<algorithm>
using namespace std;

class Solution {
private:

    bool isSafe( int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited ) {
        
        if( x>=0 && y>=0 && x < maze.size() && y < maze.size()&& maze[x][y] == 1 && visited[x][y] == 0 ) {
            return true;
        }
        return false;
    }


    void solve( int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited, string path, vector<string>& ans ) {
        
        int n = maze.size();
        
        if( x == n-1 && y == n-1 ) {
            ans.push_back( path );
            return ;
        }
        
        visited[x][y] = 1;
        
        
        // dowm
        int newX = x+1, newY = y;
        if( isSafe( newX, newY, maze, visited )) {
            path.push_back('D');
            
            solve( newX, newY, maze, visited, path, ans );
            
            path.pop_back();
        }
        
        
        // left
        newX = x, newY = y-1;
        if( isSafe( newX, newY, maze, visited )) {
            path.push_back('L');
            
            solve( newX, newY, maze, visited, path, ans );
            
            path.pop_back();
        }
        
        //Right
        newX = x, newY = y+1;
        if( isSafe( newX, newY, maze, visited )) {
            path.push_back('R');
            
            solve( newX, newY, maze, visited, path, ans );
            
            path.pop_back();
        }
        
        //up
        newX = x-1, newY = y;
        if( isSafe( newX, newY, maze, visited )) {
            path.push_back('U');
            
            solve( newX, newY, maze, visited, path, ans );
            
            path.pop_back();
        }
        
        
        
        visited[x][y] = 0;
        
        
    }
    

  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        vector<string> ans;

        
        if( maze[0][0] == 0 ) return ans;
        
        int srcX = 0, srcY = 0;
        
        vector<vector<int>> visited = maze;
        
        for ( int i = 0; i< maze.size(); i++ ) {
            for( int j = 0; j< maze.size(); j++ ) {
                visited[i][j] = 0;
            }
        }
         
         
        string path = "";
        

        solve( srcX, srcY, maze, visited, path, ans );
         
        //Return the paths in lexicographically increasing order
        sort( ans.begin(), ans.end() );
        
        return ans;
    }
};