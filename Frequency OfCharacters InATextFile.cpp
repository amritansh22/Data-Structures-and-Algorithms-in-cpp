#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   int freq[128];     // frequencies of letters
   ifstream inFile;   // input file
   char ch; 

   inFile.open("text.txt");
   if (!inFile)
   {
      cout << "The input file could not be opened."<<endl;
      return 1;
   }

   // initialize frequency counts to zero for each possible letter
   for (int i = 0; i < 128; i++)
   {
      freq[i] = 0;
   }

   // Read the file, keeping track of frequency with which each letter occurs
   ch = inFile.get();
   while (ch != EOF)
   {
      cout << ch;
      //ch = toupper(ch);
      freq[ch]++;
      ch = inFile.get();
   }
   // Print the output table
  cout << endl << "Letter frequencies in this file are as follows." << endl;
  for (char ch = 'A'; ch <= 'Z'; ch++)
  {
      cout << ch << " : " << freq[ch] << endl;
  }
  for (char ch = 'a'; ch <= 'z'; ch++)
  {
      cout << ch << " : " << freq[ch] << endl;
  }
  return 0;
}