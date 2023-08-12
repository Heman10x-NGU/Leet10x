class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int m=version1.size();
        int n=version2.size();
        int sti=0,stj=0;
        int c,d;
        while(i<m && j<n){
          while(i<m && version1[i]!='.'){
            i++;
          }
          i++;
          while(j<n && version2[j]!='.'){
            j++;
          }
          j++;
          //cout<<i<<","<<j<<endl;
          string a=version1.substr(sti,i-sti-1);
          string b=version2.substr(stj,j-stj-1);
         cout<<a<<","<<b<<endl;
          sti=i;
          stj=j;
          c=stoi(a);
          d=stoi(b);
           

          //stoi ignores leading zeroes;

          if(c<d){
            return -1;
          }
          else if(c>d){
            return 1;
          }
          else if(i==n && j==m){
            return 0;
          }
        }
        //now to check if version1 and version2 had unqeual sizes
        while(j<n){
          if(version2[j]!='.' && version2[j]!='0'){
            return -1;
          }
          j++;
        }
        while(i<m){
          if(version1[i]!='.' && version1[i]!='0'){
            return 1;
          }
          i++;
        }
        return 0;
    }
};