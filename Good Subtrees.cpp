class Solution{
public:
     unordered_map<int,int> solve(Node* root,int k,int &ans){
        unordered_map<int,int> map1,mm2,mm3;
        if(root->left)
        mm2=solve(root->left,k,ans);
        if(root->right)
        mm3=solve(root->right,k,ans);
        if(mm2.size()>k)return mm2;
        if(mm3.size()>k)return mm3;
        map1[root->data]++;
        for(auto x:mm2)map1[x.first]+=x.second;
        for(auto x:mm3)map1[x.first]+=x.second;
        if(map1.size()<=k)ans++;
        return map1;
    }
    int goodSubtrees(Node *root,int k){
       int answer=0;
        solve(root,k,answer);
        return answer;
    }
};