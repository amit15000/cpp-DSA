#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{

public:
    TrieNode *root = nullptr;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child = nullptr;

        // present
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            // terminal ki value 1 hai --> word present   ==> return value of termianl that is 1 otherwise terminal val = 0
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child = nullptr;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // not present
            return 0;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child = nullptr;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            cout << "Word Already Not Present" << endl;
            return;
        }
        removeUtil(child, word.substr(1));
    }

    void removeWord(string word)
    {
        removeUtil(root, word);
    }
};
int main()
{
    // Trie *t = new Trie();
    Trie t;
    t.insertWord("AMIT");
    t.insertWord("AMYTU");
    t.insertWord("TIMER");
    t.insertWord("TIM");

    // // search word
    bool x = t.searchWord("TIM");
    if (x)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    // remove word
    t.removeWord("TIM");

    // search again
    x = t.searchWord("TIM");
    if (x)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}
