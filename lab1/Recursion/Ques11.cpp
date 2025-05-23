#include <iostream>
#include <string>

using namespace std;


string reverseSentence(string s) {
    // STUDENT ANSWER
   int len = s.length();
   if(len <=1) return s;
   int l = s.find(" ");   
   if (l == -1) return s;  
   string left = s.substr(0,l);
   

   int r = s.rfind(" ");
   string right = s.substr(r+1);
   if(l==r) return right + " " + left;  
   string mid = reverseSentence(s.substr(l+1,r-l-1));
   return right + " " + mid + " " + left;
}