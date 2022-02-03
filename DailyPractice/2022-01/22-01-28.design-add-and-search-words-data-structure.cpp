#include "../leetcode.h"

class WordDictionary {
    unordered_map<int, vector<string>> m;
public:
    WordDictionary() {

    }

    void addWord(string word) {
        m[word.length()].push_back(word);
    }

    bool search(string word) {
        bool flag = false;
        for(auto w: m[word.size()]) {
            flag = true;
            for(int i=0;i<w.length();i++) {
                if(w[i]!=word[i] && word[i]!='.') {
                    flag =false;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
