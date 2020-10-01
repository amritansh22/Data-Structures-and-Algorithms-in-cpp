
// CPP program for Sparse Matrix Representation 
#include <bits/stdc++.h>
using namespace std;
struct Node 
{ 
    int value; 
    int row; 
    int col; 
    struct Node *next; 
}; 

void getNewNode(struct Node** st, int value, int row_pos, int column_pos ) 
{ 
  struct Node *temp, *r; 
  temp = *st; 
  if (temp == NULL) 
  {
    temp = (struct Node *) malloc (sizeof(struct Node)); 
    temp->value = value; 
    temp->col = column_pos; 
    temp->row = row_pos; 
    temp->next = NULL; 
    *st = temp; 
  } 
  else
  { 
    while (temp->next != NULL) 
    temp = temp->next;
    
    r = (struct Node *) malloc (sizeof(struct Node)); 
    r->value = value; 
    r->col = column_pos; 
    r->row = row_pos; 
    r->next = NULL; 
    temp->next = r; 
  } 
} 

void PrintList(struct Node* st) 
{ 
    struct Node *temp, *r, *s; 
    temp = st;
    r = st;
    s = st; 
  
    cout<<"Row Positions: "; 
    while(temp != NULL) 
    { 
      cout<<" "<<temp->row; 
      temp = temp->next; 
    } 
    cout<<"\n";
  
    cout<<"Column Positions: "; 
    while(r != NULL) 
    { 
      cout<<" "<<r->col; 
      r = r->next; 
    } 
    cout<<"\n";

    cout<<"Values: ";

    while(s != NULL) 
    { 
      cout<<" "<<s->value; 
      s = s->next; 
    } 
    cout<<"\n";
} 

int main() 
{
  int m[4][5] = 
  { 
    {0 , 0 , 1 , 0 , 2 }, 
    {1 , 0 , 1 , 7 , 6 }, 
    {0 , 0 , 0 , 0 , 0 },
    {0 , 6 , 1 , 0 , 9 } 
  }; 

  struct Node* st = NULL; 

  for (int i = 0; i < 4; i++) 
  for (int j = 0; j < 5; j++) 
  if (m[i][j] != 0) 
  getNewNode(&st, m[i][j], i, j); 

  PrintList(st); 

  return 0; 
} 