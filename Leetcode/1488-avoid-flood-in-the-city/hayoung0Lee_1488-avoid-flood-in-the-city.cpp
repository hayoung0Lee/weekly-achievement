class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(), -1); // initialize with -1
        unordered_map<int, int> m;
        set<int> zero;
        
        for(int i= 0; i < rains.size(); i++){
            if(rains[i] == 0){
                zero.insert(i);
                res[i] = 1; // 왜?
            } else {
                if(m.count(rains[i])){ // 이미 앞에 온게 있으면 그거부터 처리
                    int lastIndex = m[rains[i]]; // 1번째에 1번에 비가 왔다
                    auto zeroIndex = zero.upper_bound(lastIndex); // zero중에 1번째보다 큰 가장 첫번째 날 2일에 안왔으면 2가 나온다. 
                    if(zeroIndex == zero.end()){ // 남아
                        return {}; // 1일에 비왔는데, 1일보다 뒤에 비가 안왔으면 실패
                    }
                    
                    res[*zeroIndex] = rains[i];
                    zero.erase(zeroIndex);
                }
                m[rains[i]] = i; // 다시 새로운걸 넣어준다. 
            }
        }
        
        return res; // result
    }
};