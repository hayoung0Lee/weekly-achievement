class TopVotedCandidate {
public:
    // https://leetcode.com/problems/online-election/discuss/3806741/Easy-implementation-using-upper-bound-oror-C%2B%2B-Solution
    vector<int> time;
    vector<int> ans;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        time = times; // 모든 time넣기
        int mxp = -1;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++){
            mp[persons[i]]++;
            if(mp[persons[i]] >= mp[mxp]){
                // 현재 최대 후보 보다 값이 큰지 확인
                mxp = persons[i];
            }
            ans.push_back(mxp); // 각 타임마다 큰걸 넣어준다. 
        }
        

        
    }
    
    int q(int t) {
        // iterator를 반환해서 idx로 변환. 그리고 그거보다 하나 작아야함. 
        int idx = (upper_bound(time.begin(), time.end(), t) - time.begin()) - 1;
        return ans[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */