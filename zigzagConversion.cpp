//leetcode soln.

class Solution {
public:
    string convert(string s, int numRows) {
int n=s.length();
if(numRows==1)return s;
string ans="";
int i=0;
while(i<numRows){
int j=i;
//for normal jumps
int inc=2*(numRows-1);
while(j<n){
ans+=s[j];
//for middle rows
if(i>0 && i<numRows-1 && (j+inc- 2*i) <n)
{
ans+=s[j+2* (numRows-1)-2*i];
}
j+=inc;
}
i++;
}
return ans;
}
};