#include "bits/stdc++.h"
using namespace std;
void JustifyText(vector<string>& words,int L)
{
    int ss=words.size();
    
    if(ss%2 != 0)
    {
    for(int i=0;i<words.size()-1;i=i+2)
    {
        string first,second,ans="";
        int spaces;
        if(i+1!=words.size())
        {
            first=words[i];
            second=words[i+1];
            spaces=L-(first.length()+second.length());
        }
        else
        {
            first=words[i];
            second="";
            spaces=L-first.length();
        }
        ans+=first;
        for(int j=0;j<spaces;j++)
        {
            ans+=" ";
        }
        ans+=second;
        cout<<ans<<"\n";
    }
    string res="";
    int si=words[ss-1].length();
        int val=L-si;
        int v2=val/2;
    for(int i=0;i<v2;i++)
        res+=" ";
        res+=words[ss-1];
        cout<<res<<"\n";
    }

}
vector<string> splitWords(string str){

vector<string> words;
    string a = "";
    for (int i = 0; str[i]; i++) {
  
        if (str[i] != ' ') {
            a += str[i];
        }
  
        else {
            words.push_back(a);
            a = "";
        }
    }
  
    words.push_back(a);
  
    return words;
}
  
void justifyTheText(string str, int L)
{
  
    vector<string> words;
  
    words = splitWords(str);
  
    JustifyText(words, L);
  
}



int main()
{
    string str;
        // = "The quick brown";
        cin>>str;
    int L = 7;
  
    justifyTheText(str, L);
  
    return 0;
}