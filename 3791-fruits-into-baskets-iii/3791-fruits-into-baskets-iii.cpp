class Solution {
    void build(int i,int l,int r,vector<int> &baskets,vector<int> &segment_tree){
     if(l==r){
     segment_tree[i]=baskets[l];
     return;
     }
     int mid=(l+r)/2;
     build((2*i+1),l,mid,baskets,segment_tree);
     build((2*i+2),mid+1,r,baskets,segment_tree);
     segment_tree[i]=max(segment_tree[2*i+1],segment_tree[2*i+2]);

    }
    bool query(int i,int l,int r,vector<int> &segment_tree,int fruit){
        if(segment_tree[i]<fruit){
          return false;
        }
        if(l==r){
            segment_tree[i]=-1;
            return true;
        }
        int mid=(l+r)/2;
        bool placed=false;
        if(segment_tree[2*i+1]>=fruit){
            placed=query(2*i+1,l,mid,segment_tree,fruit);
        }
        else{
            placed=query(2*i+2,mid+1,r,segment_tree,fruit);
        }
        segment_tree[i]=max(segment_tree[2*i+1],segment_tree[2*i+2]);
        return placed;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<int> segment_tree(4*n);
        build(0,0,n-1,baskets,segment_tree);
       int res=0;
        for(auto &fruit:fruits){
           if(query(0,0,n-1,segment_tree,fruit)==false){
            res++;
           }
        }
        return res;
    }
};