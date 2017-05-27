// https://leetcode.com/problems/ipo/#/description
class Solution {
public:
    struct Node {int profit, capital;};
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        if(Profits.empty() || Capital.empty()) return W;
        vector<Node*> projects;
        for(int i = 0; i < Profits.size(); i++) 
            projects.push_back(new Node({Profits[i], Capital[i]}));

        priority_queue<int> pq;
        sort(projects.begin(), projects.end(), [](Node* n1, Node* n2) {return n1->capital < n2->capital;});
        for(auto start = projects.begin(); k > 0; k--) {
            for(; start != projects.end() && (*start)->capital <= W; start++) pq.push((*start)->profit);
            if(pq.empty()) break;
            W += pq.top(); pq.pop();
        }
        return W;
    }
};
