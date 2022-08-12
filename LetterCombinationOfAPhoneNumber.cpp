#include<iostream>
#include<vector>


using namespace std;

void helper(string arr, vector<string> &ans, int index, string temp, string mapping[]){
    if (index == arr.size()){
        ans.push_back(temp);
        return;
    }
    int digit = arr[index] - '0';
    string value = mapping[digit];
    for (int i = 0; i < value.length(); ++i) {
        temp.push_back(value[i]);
        helper(arr, ans, index + 1, temp, mapping);
        temp.pop_back();
    }
}

void solve( string arr, vector<string> &ans){
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    helper(arr, ans, 0, "", mapping);
}

int main()
{
    string s = "23";
    vector<string> ans;
    powerSet(s, ans);
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