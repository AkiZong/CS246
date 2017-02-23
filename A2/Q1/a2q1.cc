#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int maxCandidates = 10;

string candidates[maxCandidates];
int votes[maxCandidates];
int temp = 0;
int total = 0;
int valid = 0;
int inval = 0;
int i = 0;
int indic = 0;

void readVotes() {
    while (getline(cin,candidates[i])) {
        indic=0;
        i++;
        int len=candidates[i-1].length();
        for (int z=0;z<len;z++){
            if (isdigit(candidates[i-1][z])){
                indic=1;
                break;
            }
        }
        if (indic==1) {
            istringstream iss(candidates[i-1]);
            int n;
            while (!iss.eof()) {
                iss >> n;
                total++;
                if ((n >= 1) && (n <= i-1)) {
                    valid++;
                    votes[n-1]++;
                } else {
                    inval++;
                }
            }
            i--;
            break;
        }
        if (i == 10) {
            break;
        }
    }
    while (cin >> temp) {
        total++;
        if ((1 <= temp) && (temp <= i)) {
            valid++;
            votes[temp-1]++;
        } else {
            inval++;
        }
    }
}

void printResults(){
    cout<<"Number of voters: "<<total<<endl;
    cout<<"Number of valid votes: "<<valid<<endl;
    cout<<"Number of spoilt votes: "<<inval<<endl;
    cout<<endl;
    cout<<"Candidate      Score"<<endl;
    cout<<endl;
    for (int j=0; j<i; j++){
        cout<<left<<setw(15)<<candidates[j];
        cout<<right<<setw(3)<<votes[j]<<endl;
    }
}

int main() {
    readVotes();
    printResults();
}