#include <iostream>
using namespace std;
void helper(int *input, int size, int *output , int len ,int k){
    if(size==0){
        int sum =0;
        for(int i = 0; i<len ;i++){
            sum += output[i];
        }
		if(sum==k){
            for(int i = 1; i<=len ;i++)   // When sum equals k print the output array
            {
            	cout<<output[i-1]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    //Every element has two choices : skipping or being included

    helper(input+1,size-1,output,len,k); //Skipping the current element
    output[len] = input[0];
    helper(input+1,size-1,output,len+1,k);// Including the current element
}

void print(int input[], int size, int k) {
    int output[1000];
    helper(input,size,output,0,k);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  print(input, length,k);
}
