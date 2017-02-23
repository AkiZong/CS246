#include "trie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// TrieNode(): create a TrieNode, set isWord is false and the 26 letters are NULL
TrieNode::TrieNode(): isWord(false) {
    for (int i=0; i<NumChars; i++) {
        letters[i] = NULL;
    }
}

// ~TrieNode(): destructure
TrieNode::~TrieNode() {
    for (int i=0; i<NumChars; i++) {
        delete letters[i];
    }
}

// insert(word): add word to the dictionary
void TrieNode::insert(const string &word) {
    TrieNode *tmp = this;
    for (int i=0; i<word.length(); i++) {
        if (tmp->letters[word[i]-'a'] == NULL) {
            tmp->letters[word[i]-'a'] = new TrieNode();
        }
        tmp = tmp->letters[word[i]-'a'];
    }
    tmp->isWord = true;
}

// remove(word): removes word from the dictionary
void TrieNode::remove(const string &word) {
    TrieNode *tmp = this;
    for (int i=0; i<word.length(); i++){
        tmp = tmp->letters[word[i]-'a'];
        if (tmp == NULL){
            tmp = new TrieNode();
        }
    }
    tmp->isWord = false;
}

/* find(word): finds a list of possible autocompletions for word,
               in alphabetical order sep- arate by a single space
 */
string TrieNode::find(const string &word) {
    string outcome;
    string nothing;
    string copy;
    TrieNode *tmp = this;
    
    for (int i=0; i<word.length(); i++) {
        tmp = tmp->letters[word[i]-'a'];
        if (tmp == NULL) {
            return nothing;
        }
    }
    if (tmp->isWord == true) {
        outcome = outcome+word;
        outcome.append(" ");
    }
    for (int i=0; i<NumChars; i++) {
        copy = word;
        char index = i+97;
        copy +=index;
        outcome = outcome + this->find(copy);
    }
    return outcome;
}

// size(): return the total number of nodes in the dictionary data structure
int TrieNode::size() {
    TrieNode *tmp = this;
    int outcome = 0;
    for (int i=0; i<NumChars; i++) {
        if (tmp->letters[i] != NULL) {
            outcome++;
            outcome += tmp->letters[i]->size();
        }
    }
    return outcome;
}



