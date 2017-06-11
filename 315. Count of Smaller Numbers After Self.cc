// https://leetcode.com/problems/count-of-smaller-numbers-after-self/#/description
class Solution {
public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> temp;
            vector<int> res(nums.size());
            for (int i = nums.size() -1; i>=0; i--) {
               int d = distance(temp.begin(), lower_bound(temp.begin(), temp.end(), nums[i]));
                res[i] = d;
                temp.insert(temp.begin() + d, nums[i]);
                
            }
            return res;
        }

        // Solution 2
        vector<int> countSmaller2(vector<int>& nums) {
            vector<int> res (nums.size());
            vector<pair<int,int>> node(nums.size());
            for (int i = 0; i < nums.size(); i++) node[i] = make_pair(nums[i], i);
            mergeSort(node, 0, nums.size() -1, res);
            return res;
        }
        
        void mergeSort(vector<pair<int, int>>& nums, int lo, int hi, vector<int>& res) {
            if (lo >= hi) return;
            int mid = lo + (hi - lo) / 2;
            mergeSort(nums, lo, mid, res);
            mergeSort(nums, mid+1, hi, res);
            vector<pair<int, int>> t;
            int i = lo, j = mid +1;
            for (; i <= mid; ++i) {
                int l = mid + 1;
                while(l <= hi && nums[i] > nums[l++]) {
                    res[nums[i].second]++;
                }
            }
            i = lo;
            while (i <= mid && j <= hi) {
                if (nums[i] < nums[j]) {
                    t.push_back(nums[i++]);
                } else {
                    t.push_back(nums[j++]);
                }
            }
            while (i <= mid) {
                t.push_back(nums[i++]);
            }
            copy(t.begin(), t.end(), nums.begin() + lo);
        }
        
        
// Solution 3
class Node {
	public:
		int ll,rr,cnt; // 在范围[ll,rr]内的值有cnt个
		Node *left,*right;
		Node(int a,int b):ll(a),rr(b),cnt(0),left(NULL),right(NULL){}
};

class Tree//线段树
	{
		Node* buildtree(int begin,int end)
		{
			if(begin==end)
			{
				Node* res=new Node(begin,end);
				return res;
			}
			else
			{
				int mid=begin+(end-begin)/2;
				Node* r1=buildtree(begin,mid),*r2=buildtree(mid+1,end);
				Node* res=new Node(begin,end);
				res->left=r1;
				res->right=r2;
				return res;
			}
		}

		void update_core( Node* root,int val)
		{
			if(root==NULL || val<root->ll || val> root->rr)
				return;
			++root->cnt;
			update_core(root->left,val);
			update_core(root->right,val);
		}

		int search_core(Node* root,int  low,int up)
		{
			if(root==NULL  || up<root->ll || low>root->rr)
				return 0;
			if(root->ll>=low && root-> rr<=up)
				return root->cnt;
			return search_core(root->left,low,up)+search_core(root->right,low,up);
		}

	public:
		Node *root;
		Tree(int begin,int end)
		{
			root=buildtree(begin,end);
		}

		void update(int val)
		{
			update_core(root,val);
		}

		int search(int low,int up)
		{
			if(low>up)
				return 0;
			return search_core(root,low,up);
		}
	};
	
	int binarysearch(vector<int>& nums,int n)
	{
		int l=0,r=nums.size()-1;
		while(l<=r)
		{
			int mid=l+(r-l)/2;
			if(nums[mid]==n)
				return mid;
			else if(nums[mid]>n)
				r=mid-1;
			else
				l=mid+1;
		}
		return -1;
	}
	
    vector<int> countSmaller3(vector<int>& nums) {
      if(nums.empty())
			return nums;
		vector<int>tmp=nums;
		sort(tmp.begin(),tmp.end());
		for(int i=0;i<nums.size();++i)
		{
			nums[i]=binarysearch(tmp,nums[i]);
		}
		Tree tree(0,nums.size()-1);
		vector<int> res(nums.size(),0);
		//从右向左遍历（因为题目求的是右边比该值小的数的数量)
		for(int i=nums.size()-1;i>=0;--i)
		{
			if(nums[i]!=0) //nums[i]==0，即最小的数，此时不用更新res数组
				res[i]=tree.search(0,nums[i]-1);
			//每次遍历都往线段树压入对应的值
			tree.update(nums[i]);
		}
		return res;
    }
};
