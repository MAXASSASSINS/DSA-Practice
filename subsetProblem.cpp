#include<iostream>
#include<vector>


using namespace std;

void helper(vector<int> &arr, vector<vector<int>> &ans, int index, vector<int> temp){
    if (index == arr.size()){
        ans.push_back(temp);
        return;
    }
    helper(arr, ans, index + 1, temp);
    temp.push_back(arr[index]);
    helper(arr, ans, index + 1, temp);
}

void powerSet(vector<int> &arr, vector<vector<int>> &ans){
    vector<int> temp;
    helper(arr, ans, 0, temp);
}

int main()
{
    vector<int> arr = {1,2,3};

    vector<vector<int>> ans;
    powerSet(arr, ans);
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