#include<iostream>
#include<vector>


using namespace std;

void helper(string arr, vector<string> &ans, int index, string temp){
    if (index == arr.size()){
        ans.push_back(temp);
        return;
    }
    helper(arr, ans, index + 1, temp);
    temp.push_back(arr[index]);
    helper(arr, ans, index + 1, temp);
}

void powerSet( string arr, vector<string> &ans){
    helper(arr, ans, 0, "");
}

int main()
{
    string s = "abc";
    vector<string> ans;
    powerSet(s, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.at(i).size(); j++)
        {
            cout<<ans.at(i).at(j)<<" ";
        }
        cout<<endl;

    }


    return 0;
}