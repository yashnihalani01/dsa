#include <bits/stdc++.h>
using namespace std;

  void solve(vector <string> & vec , map <int , string> &mp , string num , int i , set<string> & ans , string s)
  {
      if(i==num.size())
      {
    
     for(int k=0;k<vec.size();k++)
    {   string str=vec[k];
        
        size_t found = str.find(s);
    if (found != string::npos)
       {
           ans.insert(vec[k]);
       }

      }
      return ;
      }
      for(int j=i;j<num.size();j++)
      {
          int temp=stoi(num[j]);

          for(auto ele:mp[temp])
          {
            solve(vec,mp,num,i+1,ans,s+ ele );
          }
      }
      return ;
  }
 int main()
 {
	 map <int , string> mp;
	    m.insert({2,"abc"});
	    m.insert({3,"def"});
	    m.insert({4,"ghi"});
	    m.insert({5,"jkl"});
	    m.insert({6,"mno"});
	    m.insert({7,"pqrs"});
		m.insert({8,"tuv"});
		m.insert({9,"wxyz"});
		vector <string> vec;
	    vec = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
		string num;
		cin>>num;
		set <string> ans;
        string s;
		solve(vec,mp,num,0 ,ans ,s);
		for(auto i:ans)
		{
			cout<<i<<endl;
		}
       return 0;
	   
 }