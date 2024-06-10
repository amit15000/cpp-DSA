// class Trie
// {
// public:
//     Trie *children[26];
//     bool isEnd;

//     Trie()
//     {
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = nullptr;
//         }
//         isEnd = false;
//     }
// };

// class Solution
// {
// public:
//     Trie *root;

//     Solution()
//     {
//         root = new Trie();
//     }

//     void insert(string word)
//     {
//         Trie *node = root;
//         for (char c : word)
//         {
//             int i = c - 'a';
//             if (node->children[i] == nullptr)
//             {
//                 node->children[i] = new Trie();
//             }
//             node = node->children[i];
//         }
//         node->isEnd = true;
//     }

//     string search(string word)
//     {
//         Trie *node = root;
//         string result;
//         for (char c : word)
//         {
//             int i = c - 'a';
//             if (node->children[i] == nullptr)
//             {
//                 return word;
//             }
//             result += c;
//             if (node->children[i]->isEnd)
//             {
//                 return result;
//             }
//             node = node->children[i];
//         }
//         return word;
//     }

//     string replaceWords(vector<string> &dictionary, string sentence)
//     {
//         for (string word : dictionary)
//         {
//             insert(word);
//         }

//         stringstream ss(sentence);
//         string word, result;
//         while (ss >> word)
//         {
//             if (!result.empty())
//             {
//                 result += " ";
//             }
//             result += search(word);
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         set<string> st;
//         string word="",ans="";
//         sentence += ' ';

//         for(auto i: dictionary)
//             st.insert(i);

//         for(auto i: sentence){
//             if(i==' '){
//                 if(ans.size()>0) ans += ' ';

//                 string temp = "";
//                 for(auto j: word){
//                     temp += j;
//                     if(st.count(temp)) {
//                         break;
//                     }
//                 }
//                 ans += temp;
//                 word = "";
//             } else word += i;
//         }

//         return ans;
//     }
// };