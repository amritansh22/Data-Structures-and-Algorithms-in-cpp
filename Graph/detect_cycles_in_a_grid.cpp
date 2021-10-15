class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),i,j;
        vector<vector<bool>> vis(n);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        vis[i].push_back(false);    
        
        bool ans=false;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(!vis[i][j])
        {
            ans=isCycle(i,j,grid,vis,-1,-1);
            if(ans) return ans;
        }
        return ans;
    }
    
    bool isCycle(int x,int y,vector<vector<char>>&a,vector<vector<bool>> &v,int px,int py) 
    { 
      
        v[x][y]=true; 
        int dx[]={-1,0,1,0 },dy[]={0,1,0,-1},i;  
        for(i=0;i<4;i++) 
        { 
            int nx=x+dx[i]; 
            int ny=y+dy[i]; 
  
            if(valid(nx,ny,a.size(),a[0].size()) && a[nx][ny]==a[x][y] && !(px==nx && py==ny))  
            { 
              
                if(v[nx][ny]) return true;
                else 
                { 
                    bool check=isCycle(nx,ny,a,v,x,y);
                    if(check) return true;
                }
            } 
        } 
        return false; 
    } 
    
    bool valid(int x,int y,int n,int m)
    {
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
};
