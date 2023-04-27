vector<vector<int>> segment;
class Solution{
public:
    void create(int index,int left,int right,string s){
        if(left==right){
            segment[index][s[right]-'a']=1;
            return;
        }
        int mid = (left+right)/2;
        create(2*index+1,left,mid,s);
        create(2*index+2,mid+1,right,s);
        for(int i=0;i<26;i++){
            segment[index][i]=segment[2*index+1][i]+segment[2*index+2][i];
        }
    }
    void update(int index,int left,int right,int Uindex,char c,string s){
        if(Uindex<left or Uindex>right)return;
        segment[index][s[Uindex]-'a']--;
        segment[index][c-'a']++;
        if(left==right)return;
        int mid = (left+right)/2;
        update(2*index+1,left,mid,Uindex,c,s);
        update(2*index+2,mid+1,right,Uindex,c,s);
    }
    void exclude(int index,int left,int right,int s,int e,int temp[]){
        if(left>e or right<s)return;
        if(left>=s and right<=e){
            for(int i=0;i<26;i++){
                temp[i]+=segment[index][i];
            }
            return;
        }
        int mid = (left+right)/2;
        exclude(2*index+1,left,mid,s,e,temp);
        exclude(2*index+2,mid+1,right,s,e,temp);
    }
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        vector<char> ans;
        segment = vector<vector<int>> (4*n,vector<int>(26,0));
        create(0,0,n-1,s);
        for(int i=0;i<q;i++){
            if(queries[i][0]=="1"){
                int Uindex = stoi(queries[i][1]);
                char c = queries[i][2][0];
                update(0,0,n-1,Uindex,c,s);
                s[Uindex]=c;
            }
            else{
                int s = stoi(queries[i][1]);
                int e = stoi(queries[i][2]);
                int k = stoi(queries[i][3]);
                int temp[26]={0};
                exclude(0,0,n-1,s,e,temp);
                int i;
                for(i=25;i>=0;i--){
                    k-=temp[i];
                    if(k<=0)break;
                }
                ans.push_back('a'+i);
            }
        }
        return ans;
    }
};