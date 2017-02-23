#ifndef __TRIE_H__
#define __TRIE_H__
#include <string>

const int NumChars = 26;

/* TrieNode is a class to maintain a dictionary of available words, 
   and use them to autocomplete prefixes that you provide.
   A trie is an N-ary tree data-structure with a branching factor 
   equal to the number of different characters in the associated 
   alphabet. For simplicity, assume the dictionary only consists 
   of lowercase letters, resulting in a branching factor of 26.
 */
struct TrieNode {
    bool isWord;
    TrieNode *letters[NumChars];
    TrieNode();
    ~TrieNode();

    void insert(const std::string &word);
    void remove(const std::string &word);
    std::string find(const std::string &word);
    int size();
}; // TrieNode

#endif
