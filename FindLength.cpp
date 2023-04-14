class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>>st1;
        for(int i=0;i<N;i++){
            if(st1.empty())  st1.push(make_pair(color[i],radius[i]));
            
            else{
                if(st1.top().first==color[i] && st1.top().second==radius[i]){
                    st1.pop();
                }
                else{
                    st1.push(make_pair(color[i],radius[i]));
                }
            }
        }
        return st1.size();
    }
};