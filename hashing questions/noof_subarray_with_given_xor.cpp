int Solution::solve(vector<int> &a, int k) {
    unordered_map<int,int>m;
    int xorr = 0;
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        xorr = xorr^a[i];

        if(xorr==k){
            cnt++;
        }
        int y = k^xorr;
        if(m.find(y)!=m.end()){
            cnt+=m[y];
        }
        if(m.find(xorr)==m.end()){
            m[xorr]=1;
        }
        else{
            m[xorr]++;
        }
    }  
    return cnt;
}
