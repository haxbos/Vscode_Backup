#include <bits/stdc++.h>
using namespace std;

struct TireNode{
    vector<TireNode*> child;
    bool isEnd;
    TireNode() {
        this->child = vector<TireNode*>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(string &word, TireNode* root){
    TireNode* node = root;
    for(auto& ch : word){
        if(node->child[ch - 'a'] == nullptr){
            node->child[ch - 'a'] = new TireNode();
        }
        node = node->child[ch - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary {
    TireNode* root;
public:
    WordDictionary() {
        root = new TireNode();
    }
    
    void addWord(string word) {
        insert(word,root);
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(TireNode* root, const string& word, int idx){
        if(idx == word.size()){
            return root->isEnd;
        } 

        char ch = word[idx];
        if(ch == '.'){
            for(int i=0; i<26; ++i){
                TireNode* node = root->child[i];
                if(node != nullptr && dfs(node, word, idx+1)){
                    return true;
                }
            }
        }
        else{
            TireNode* node = root->child[ch - 'a'];
            if(node != nullptr && dfs(node, word, idx+1)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    WordDictionary sol;
    vector<string> words = {"oath","pea","eat","rain"};
    for(auto& word : words){
        sol.addWord(word);
    }
    vector<string> search = {"oath","pea","eat","rain","oath.","oath..",".oath"};
    for(auto& word : search){
        cout << word << " : " << sol.search(word) << endl;
    }
}
