class Solution {
public:
    bool possible(vector<int> &piles, int k, int h){
        long long count = 0;
        for(int j=0; j<piles.size(); j++){
            count += (piles[j] + k - 1)/k;
        }
        if(count <= h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(possible(piles, mid, h)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1 ;
            }
        }
        return ans;
    }
};
