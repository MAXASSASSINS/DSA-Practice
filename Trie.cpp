#include<iostream>

using namespace std;

#include<iostream>

using namespace std;

class TrieNode{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word){
        if (word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word.at(0) - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word.at(0));
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));

    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word){
        if (word.length() == 0 ){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index] != nullptr){
            return searchUtil(root->children[index], word.substr(1));
        }
        return false;

    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *root, string word){
        if (word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int index = word.at(0) - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word.at(0));
            root->children[index] = child;
        }
        removeUtil(child, word.substr(1));

    }

    void removeWord(string word){
        removeUtil(root, word);
    }
};




int main()
{
    Trie *t = new Trie();
    t->insertWord("hello");
    cout<<t->searchWord("hello")<<endl;
    t->removeWord("hello");
    cout<<t->searchWord("hello")<<endl;


    return 0;
}
