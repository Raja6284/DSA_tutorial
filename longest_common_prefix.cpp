#include <iostream>
using namespace std;

 string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans = "";
        for(int i = 0; i<arr[0].length(); i++){
            char ch = arr[0][i];
            
            bool match = true;
            
            for(int j = 1; j<N; j++){
                if(arr[j].size() < i || ch != arr[j][i]){
                    match = false;
                    break;
                }
            }
            if(match == false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        if(ans.length()){
            return ans;
        }
        
        return "-1";
    }
int main(){
    int n = 4;
    string arr[] = {"geeksforgeeks", "geeks", "geek","geezer"};

    string strs[] = {"flower","flow","flight"};

    
    //string ans =  longestCommonPrefix (strs,3);
    string ans =  longestCommonPrefix (arr,n);

    cout<<"Required longest common prefix is : "<<ans<<endl;

    return 0;
}