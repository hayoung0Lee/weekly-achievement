class Solution {
public:  
    int arr[64];
    
    bool checkBit(int h, int m, int turnedOn){
        
        
        int h_bits=0;
        while (h)
        {
            if ((h & 1) == 1)
                h_bits++;
            h=h>>1;
        }
        
        int m_bits=0;
        while (m)
        {
            if ((m & 1) == 1)
                m_bits++;
            m=m>>1;
        }
        
        if(h_bits + m_bits == turnedOn){
            return true;
        }
        
        return false;
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
       
        for(int i = 0; i <= 11; i++){
            for(int j = 0; j <= 59; j++){
               if(checkBit(i, j, turnedOn)){
                    string h = to_string(i);
                    string m = to_string(j);
                    if(j < 10) {
                        m = "0" + m;
                    }                
                    ans.push_back(h + ":" + m);
                } 
            }   
        }
        
        return ans;
    }
};