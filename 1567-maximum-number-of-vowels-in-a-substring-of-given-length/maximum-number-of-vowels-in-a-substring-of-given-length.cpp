class Solution {
public:
    int maxVowels(string s, int k) {
        int mx=0,cnt=0,n=s.length();
        for(int i=0;i<n;i++){
            if(i>=k && (s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')) cnt--;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cnt++;
            mx=max(mx,cnt);
        }
        return mx;
    }
};