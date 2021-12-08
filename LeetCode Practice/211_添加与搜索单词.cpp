#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

/*
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
实现词典类 WordDictionary ：
WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。
word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
示例：
输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]
解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-add-and-search-words-data-structure
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//该方法超时
class WordDictionary1 {
public:
    WordDictionary1() {

    }

    void addWord(string word) {
        v_Word.push_back(word);
        return;
    }

    bool search(string word) {
        for (int i = 0; i < v_Word.size(); i++) {
            bool flag = true;
            string temp = v_Word[i];
            int j = 0;
            while (temp[j] != '\0' && word[j] != '\0') {
                if (temp.size() == word.size()) {
                    if ((temp[j] == word[j]) || word[j] == '.') {
                        j++;
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
private:
    vector<string> v_Word;
};

//用字典树实现
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie(int size) {
        this->children = vector<Trie*>(size, nullptr);
        this->isEnd = false;
    }
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->isEnd = false;
    }
};
void insert(Trie* root, string& word) {
    Trie* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (node->children[word[i] - 'a'] == nullptr) {
            node->children[word[i] - 'a'] = new Trie();
        }
        node = node->children[word[i] - 'a'];
    }
    node->isEnd = true;
    return;
}
class WordDictionary {
public:
    WordDictionary() {
        this->word = new Trie();
    }
    void addWord(string word) {
        insert(this->word, word);
        return;
    }
    bool search(string word) {
        return dfs(word, 0, this->word);
    }
    bool dfs(const string& word, int index, Trie* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            Trie* child = node->children[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        }
        else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                Trie* children = node->children[i];
                if (children != nullptr && dfs(word, index + 1, children)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    Trie* word;
};
int main() {
    WordDictionary* wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    cout << wordDictionary->search("padd") << endl; // return False
    cout << wordDictionary->search("bad") << endl; // return True
    cout << wordDictionary->search(".ad") << endl; // return True
    cout << wordDictionary->search("b..") << endl; // return True
    return 0;
}