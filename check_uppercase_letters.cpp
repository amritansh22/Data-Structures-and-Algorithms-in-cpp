#include <iostream>
#include <string>

using namespace std;

bool checking(string phrase);

int main()
{
   string phrase;
   int lung,ris;
   int cont=0;
   cout<<" enter the phrase: ";
   getline(cin,phrase);

   ris=checking(phrase);
   if(ris==0){
       cout<<"there are no capital letters"<<endl;
   }else{
       cout<<"there are capital letters"<<endl;
   }
   return 0;

}

bool checking(string phrase)
{
   bool check=false;

   for(int i=0; i<phrase.size();i++)
   {
       if(phrase[i]>='A'&&phrase[i]<='Z')
       {
           check=true;
       }
   }

   return check;
}
