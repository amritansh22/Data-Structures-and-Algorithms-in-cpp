#include <queue> // for priority_queue on line 7
#include <vector> // for vector on line 5

/* Problem
Given a reference to a vector of values, sort the vector using a pqSort.
*/

template <typename T>
void pqSort(std::vector<T>& v)
{
   
   //Step 1) Define a priority queue such that the ordering uses std::greater
   std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
   
   //Step 2) Push all values in the vector onto the priority queue
   while(!v.empty())
   {
      pq.push(v.back());
      v.pop_back();
   }
   
   //Step 3) Pop all vlaues in the priority queue onto the vector
   //        - Because the priority queue uses the std::greater ordering function
   //        - to decide where to insert the value in the tree to maintain increasing
   //        - order, the least value is stored at the top always.
   while(!pq.empty())
   {
      v.emplace_back(pq.top());
      pq.pop();
   }
   
}

/* Notes
 - pqSort is a relatively efficient and rarely mentioned, since it moreso demonstrates the quality of priority queues to sort at insertion.
 - > and also because faster sorting algorithms exist.
 - If studying DS&A, this is a good example of priority queues primary functionality.
 - You can write your own comparison function to use on your own datatypes, etc, and implement them painlessly.
 - > for more info on how to do that, check out std::greater
*/
