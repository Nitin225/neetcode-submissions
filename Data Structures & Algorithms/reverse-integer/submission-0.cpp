class Solution {
public:
    int reverse(int x) {
        double num = 0;
        int i = 0;
        while(x != 0){
            int digit = x % 10;
            x /= 10;
            num = num*10 + digit;
            i++;
        }
        if(num >= INT_MIN && num <= INT_MAX)
            return num;

        else return 0;
    }
};
