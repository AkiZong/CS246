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
int bad = 0;
int i = 0;

bool is_digit(string s) {
    int l = s.length();
    for (int i=0; i<l; i++) {
        if (isdigit(s[i])) {
            return true;
        } else if (s[i] == 32){
            i++;
        } else {
            return false;
        }
    }
    return false;
}


void readVotes(int maxnum,int argu){
    string tempin;
    int ifvote=0;
    while (getline(cin,tempin)){
        if(argu==1){
            maxnum=i;
        }
        if ((is_digit(tempin))||(ifvote==1)){
            ifvote=1;
            istringstream iss(tempin);
            int temp[i+1];
            int timer=0;
            total++;
            while (!iss.eof()) {
                if (timer>i){
                    break;
                }
                iss >> temp[timer];
                timer++;
            }
            if((timer==i+1)||(timer<i)){
                bad++;
            }else{
                int sum=0;
                for (int j=0;j<i;j++){
                    sum=temp[j]+sum;
                }
                if (sum>maxnum){
                    bad++;
                }else{
                    for (int j=0;j<i;j++){
                        votes[j]=votes[j]+temp[j];
                    }
                }
            }
        }else{
            ifvote=0;
            candidates[i]=tempin;
            i++;
        }
    }
}


void printResults(){
    cout<<"Number of voters: "<<total<<endl;
    int good=total - bad;
    cout<<"Number of valid ballots: "<<good<<endl;
    cout<<"Number of spoilt ballots: "<<bad<<endl;
    cout<<endl;
    cout<<"Candidate      Score"<<endl;
    cout<<endl;
    for (int j=0; j<=i-1; j++){
        cout<<left<<setw(15)<<candidates[j];
        cout<<right<<setw(3)<<votes[j]<<endl;;
    }
}
int main(int argc, char *argv[]) {
    if (argc==2){
        int maxnum;
        istringstream iss(argv[1]);
        iss>>maxnum;
        readVotes(maxnum,argc);
        printResults();
    }else{
        readVotes(0,argc);
        printResults();
    }
}
