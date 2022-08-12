#include<iostream>
#include<vector>


using namespace std;

void helper(string &s, vector<string> &ans, int index){
    if(index == s.length()){
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.length(); ++i) {
        swap(s.at(i), s.at(index));
        helper(s, ans, index + 1);
        swap(s.at(i), s.at(index));
    }
}

void permutations(string &s, vector<string> &ans){
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    helper(s, ans, 0);
}

int main()
{
    string s = "abc";
    vector<string> ans;
    solve(s, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j  = 0; j < ans.at(i).size(); j++)
        {
            cout<<ans.at(i).at(j)<<" ";
        }
        cout<<endl;
    }


    return 0;
}