class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
         int lf[N],rt[N];
        lf[0]=A[0];
        for(int i=1;i<N;i++){
            lf[i]=max(lf[i-1],A[i]);
        }
        rt[N-1]=A[N-1];
        for(int i=N-2;i>=0;i--){
            rt[i]=min(rt[i+1],A[i]);
        }
        int answer=0;
        for(int i=1;i<N;i++){
            if(lf[i-1]+rt[i]>=K)answer++;
        }
        return answer;
    }
};