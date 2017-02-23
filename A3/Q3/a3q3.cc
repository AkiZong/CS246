#include "trie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main () {
    string cmd;
    string word;
    string outco;
    TrieNode *tmp = new TrieNode();
    
    while (cin >> cmd) {
        if (cmd == "+") {
            cin >> word;
            tmp->insert(word);
            
        } else if (cmd=="-") {
            cin >> word;
            tmp->remove(word);
            
        } else if (cmd=="?") {
            cin >> word;
            outco = tmp->find(word);
            
            if (outco.length()) {
                outco = outco.substr(0,outco.length()-1);
                cout << outco << endl;
                
            } else {
                cout << outco << endl;
                TrieNode *remover = tmp;
                int longenough = 1;
                
                for (int i=0; i<word.length(); i++) {
                    if (remover->letters[word[i]-'a'] == NULL) {
                        longenough = 0;
                        break;
                    } else {
                        remover = remover->letters[word[i]-'a'];
                    }
                }
                
                if (longenough) {
                    for (int i=0; i<NumChars; i++){
                        delete remover->letters[i];
                        remover->letters[i]=NULL;
                    }
                }
            }
            
        } else if (cmd == "$") {
            cout << tmp->size()+1 << endl;
            
        } else if (cmd == "include") {
            cin >> word;
            string line;
            ifstream filename (word.c_str());
            
            while (getline(filename,line)) {
                istringstream iss(line);
                
                while (iss >> cmd) {
                    if (cmd == "+") {
                        iss >> word;
                        tmp->insert(word);
                        
                    } else if (cmd == "-") {
                        iss >> word;
                        tmp->remove(word);
                        
                    } else if (cmd == "$") {
                        cout << tmp->size()+1 << endl;
                        
                    } else if (cmd == "?") {
                        iss >> word;
                        outco = tmp->find(word);
                        
                        if (outco.length()) {
                            outco = outco.substr(0,outco.length()-1);
                            cout << outco << endl;
                            
                        } else {
                            cout << outco << endl;
                            TrieNode *remover = tmp;
                            int longenough = 1;
                            
                            for (int i=0; i<word.length(); i++){
                                if (remover->letters[word[i]-'a'] == NULL) {
                                    longenough = 0;
                                    break;
                                    
                                } else {
                                    remover = remover->letters[word[i]-'a'];
                                }
                            }
                            
                            if (longenough) {
                                for (int i=0; i<NumChars; i++){
                                    delete remover->letters[i];
                                    remover->letters[i]=NULL;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    delete tmp;
}


    