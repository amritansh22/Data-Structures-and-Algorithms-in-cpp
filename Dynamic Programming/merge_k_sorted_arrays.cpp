#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

vector<int> mergeKSortedArr(vector<vector<int>>& arrays) {
  priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
  vector<int> result;

  for (int i = 0; i < arrays.size(); i++) {
    pq.push({arrays[i][0], {i, 0}});
  }

  while (pq.top().first != INT_MAX) {
    pair<int, pair<int,int>> p = pq.top();
    pq.pop();

    result.push_back(p.first);
     
    p.second.second += 1;
    if (p.second.second >= arrays[p.second.first].size())
      p.first = INT_MAX;
    else 
      p.first = arrays[p.second.first][p.second.second];
    
    pq.push(p);
  }

  return result;
}

int main() {
  vector<vector<int>> arrays = {
    {1, 10, 11, 15},
    {2, 4, 9, 14},
    {5, 6, 8, 16},
    {3, 7, 12, 13}
  };

  vector<int> result = mergeKSortedArr(arrays);

  for (auto r : result) 
    cout << r << " ";

  return 0;
}
