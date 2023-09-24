class TopVotedCandidate {
public:
    vector<int> time;
    vector<int> ans;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        time = times; // 모든 time할당
        int mpx = -1;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++){ // n이랑 time이랑 index가 matching이 됨
            mp[persons[i]]++;
            if(mp[persons[i]] >= mp[mpx]){
                mpx = persons[i]; // 더큰걸 할당
            }
            ans.push_back(mpx);
        }
    }
    
    int q(int t) {
        // iterator 를 반환해서 idx로 변환, 그런데 초과하는 첫번째 index를 변환해주는거라 1빼줘야함
        int idx = (upper_bound(time.begin(), time.end(), t) - time.begin()) - 1;
        return ans[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */