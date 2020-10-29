// https://leetcode.com/problems/word-ladder/

bool dist(string a, string b){
    int count=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]) count++; 
    }
    return count==1;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return 0;
        if(beginWord==endWord) return 1;

    if(dist(beginWord,endWord)) return 2;

    int n=wordList.size();
    vector<bool> visit(n,false);
    queue<pair<int,string> > q;

    q.push(make_pair(1,beginWord));
    while(!q.empty()){

        pair<int,string> pos=q.front();
        q.pop();
        int level=pos.first;
        if(dist(pos.second,endWord)) return pos.first+1;
        level++;
        for(int i=0;i<n;i++){
            if(!visit[i] && dist(wordList[i],pos.second)){
                visit[i]=true;
                q.push(make_pair(level,wordList[i]));
            }
        }
    }
    return 0;
    }
};
