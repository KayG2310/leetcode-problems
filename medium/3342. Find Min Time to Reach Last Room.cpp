// recursive force 
class Solution {
private:
    vector<int>r = {-1, 1, 0, 0};
    vector<int>c = {0, 0, -1, 1};
    int f(int n, int m, int i, int j, vector<vector<int>>& move, int t, vector<vector<int>>& vis, int l){
        if(i==n-1 && j==m-1) return t;
        int time = INT_MAX;
        for(int k=0; k<4; k++){
            int nr = i+r[k];
            int nc = j+c[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                if(t>=move[nr][nc]){
                    vis[nr][nc] = 1;
                    if(l==1) time = min(time, f(n, m, nr, nc, move, t+2, vis, 2));
                    else time = min(time, f(n, m, nr, nc, move, t+1, vis, 1));
                    vis[nr][nc] = 0;
                }
                else{
                    vis[nr][nc] = 1;
                    if(l==1)time = min(time, f(n, m, nr, nc, move, 2+move[nr][nc], vis, 2));
                    else time = min(time, f(n, m, nr, nc, move, 1+(move[nr][nc]-t)+t, vis, 1));
                    vis[nr][nc]=0;
                }
            }
        }
        return time;
    }
public:
    int minTimeToReach(vector<vector<int>>& move) {
        int n = move.size(), m = move[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vis[0][0] = 1;
        return f(n, m, 0, 0, move, 0, vis, 2);
    }
};

// let's see if it can be memoized 
#define ll long long
#define lm LLONG_MAX
class Solution {
private:
    vector<int>r = {-1, 1, 0, 0};
    vector<int>c = {0, 0, -1, 1};
public:
    int minTimeToReach(vector<vector<int>>& move) {
        int n = move.size(), m = move[0].size();
        vector<vector<ll>>time(n, vector<ll>(m, lm));
        time[0][0] = 0;
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>pq;
        pq.push({0, 0, 0, 1});
        while(!pq.empty()){
            auto it = pq.top();
            ll t = it[0];
            int i = it[1], j = it[2], k = it[3];
            pq.pop();
            if(i==n-1 && j==m-1) return t;
            for(int x=0; x<4; x++){
                int nr = i+r[x];
                int nc = j+c[x];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    // check if reaching there is better 
                    // case 1, our t is sufficient for that block 
                    if(t>=move[nr][nc]){
                        if(k==1 && time[nr][nc]>t+1){
                            pq.push({t+1, nr, nc, 2});
                            time[nr][nc] = t+1;
                        }
                        else if(k==2 && time[nr][nc]>t+2){
                            pq.push({t+2, nr, nc, 1});
                            time[nr][nc] = t+2;
                        }
                    }
                    // case 2 --> not sufficient 
                    else{
                        if(k==1 && time[nr][nc]>move[nr][nc]+1){
                            pq.push({move[nr][nc]+1, nr, nc, 2});
                            time[nr][nc] = move[nr][nc]+1;
                        }
                        else if(k==2 && time[nr][nc]>move[nr][nc]+2){
                            pq.push({move[nr][nc]+2, nr, nc, 1});
                            time[nr][nc] = move[nr][nc]+2;
                        }
                    }
                }
            }
        }
        return time[n-1][m-1];
    }
};
