#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int timer=1;
	string temp;
	string name;
	string cardnum;
	string rslt;
	int douodd=0;
	int i;
	while(getline(cin,temp)){
        if (temp.length()!=0){
		douodd=0;
		if (timer%3==1){
			name=temp;
		}
		else if (timer%3==2){
			i=temp.length();
			cardnum=temp;
			int cardout[16];
            cardout[0]=cardnum[0]-48;
			if (((i==16) || (i==13))&&(cardout[0]==4)){
                for (int z=0;z<i;z++){
                    cardout[z]=temp[z]-48;
                }
				for (int j= 0;j<i;j++){
					if (j%2==1){
						douodd=douodd+((2*cardout[i-j-1])%10)+((2*cardout[i-j-1])/10);
					}else{
						douodd=douodd+cardout[i-j-1];
					}
				}
				if (douodd%10==0){
					rslt="valid";
				}else{
					rslt="invalid";
				}
			}
			else{
				rslt="invalid";
			}
		}
		else{
			int trannum[8];
			float amount;
			int t=0;
			istringstream iss(temp);
			while(!iss.eof()){
				if(t!=7){
					iss>>trannum[t];
					t++;
				}else{
					iss>>amount;
				}
			}
			cout<<setfill('0')<<setw(5)<<trannum[2]<<" ";
			cout<<setfill('0')<<setw(2)<<trannum[3]<<"/";
			cout<<setfill('0')<<setw(2)<<trannum[4]<<"/";
			cout<<trannum[5]<<" ";
			cout<<setfill('0')<<setw(2)<<trannum[6]/100<<":";
			cout<<setfill('0')<<setw(2)<<trannum[6]%100<<" "<<"$";
			cout<<setprecision(2)<<fixed<<amount;
			cout<<" (";
            cout<<cardnum;
			cout<<", "<<name<<", ";
            cout<<setfill('0')<<setw(2)<<trannum[0]<<"/";
            cout<<setfill('0')<<setw(2)<<trannum[1]<<") ";
			cout<<rslt<<endl;
		}
		timer++;
        }
	}
}









