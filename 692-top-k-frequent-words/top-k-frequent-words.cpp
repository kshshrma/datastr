class Solution {
public:
    struct cmp{
       bool operator()(const pair<int,string>&p1,const pair<int,string>&p2) const{
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
       } 
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(int i=0;i<words.size();++i){
            m[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>min_heap;
        for(auto element:m){
            min_heap.push({element.second,element.first});
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        vector<string>v(k,"");
        while(min_heap.size()){
            v[k-1]=min_heap.top().second;
            min_heap.pop();
            k--;
        }
  return v;
    }
};