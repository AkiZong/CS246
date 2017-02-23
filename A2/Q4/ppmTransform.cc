#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

struct Pixel {
    unsigned int r;  // value for red
    unsigned int g;  // value or green
    unsigned int b;  // value for blue
};

struct PpmArray {
    int size;      // number of pixels the array currently holds
    int capacity;  // number of pixels the array could hold, given current
                   // memory allocation to pixels
    int width;     // width of image
    int height;    // height of image
    Pixel *pixels;
};

void flipHorizontal(PpmArray &ppm){
	Pixel *temp1=new Pixel[ppm.size];
	for (int i=0;i<ppm.height;i++){
		for(int j=0;j<ppm.width;j++){
			temp1[i*ppm.width+j]=ppm.pixels[i*ppm.width+(ppm.width-j-1)];
		}
	}
    delete [] ppm.pixels;
    ppm.pixels=temp1;
}

void rotate(PpmArray &ppm){
	int temw=ppm.width;
	Pixel *temp2=new Pixel[ppm.size];
	for (int i=0;i<ppm.width;i++){
		for(int j=0;j<ppm.height;j++){
			temp2[i*ppm.height+j]=ppm.pixels[ppm.width*(ppm.height-j-1)+i];
		}
	}
    delete [] ppm.pixels;
    ppm.pixels=temp2;
	ppm.width=ppm.height;
	ppm.height=temw;
}

void sepia(PpmArray &ppm){
    int tempr;
    int tempg;
    int tempb;
    for (int i = 0; i < (ppm.width*ppm.height); ++i)
    {
        tempr = ppm.pixels[i].r * 0.393 + ppm.pixels[i].g * 0.769 + ppm.pixels[i].b * 0.189;
        if (tempr > 255) {
            tempr = 255;
        }
        tempg = ppm.pixels[i].r * 0.349 + ppm.pixels[i].g * 0.686 + ppm.pixels[i].b * 0.168;
        if (tempg > 255) {
            tempg = 255;
        }
        tempb = ppm.pixels[i].r * 0.272 + ppm.pixels[i].g * 0.534 + ppm.pixels[i].b * 0.131;
        if (tempb > 255) {
            tempb = 255;
        }
        
        ppm.pixels[i].r = tempr;
        ppm.pixels[i].g = tempg;
        ppm.pixels[i].b = tempb;
    }
}


void exten(PpmArray &ppm){
	Pixel *nt=new Pixel[ppm.capacity];
	for (int i=0;i<ppm.capacity/2;i++){
		nt[i]=ppm.pixels[i];
	}
    delete []ppm.pixels;
    ppm.pixels=nt;
}

int main(){
	int lastone=0;
	int lasttwo=0;
	int temp;
	string in;
	string instr;
	int timer=0;
	Pixel *a;
	PpmArray bone={0,0,0,0,a};
	bone.pixels = new Pixel[bone.capacity];
	while(cin>>in){
		if(isdigit(in[0])){
			istringstream iss(in);
			iss>>temp;
			timer++;
			if (timer%3==1){
				bone.size++;
			}
			if (bone.capacity==0){
				bone.capacity=1;
                exten(bone);
			}
			else if (bone.size>bone.capacity){
				bone.capacity=bone.capacity*2;
                exten(bone);
			}
			if (timer%3==1){
				bone.pixels[(timer-1)/3].r=temp;
				lasttwo=lastone;
				lastone=temp;
			}else if(timer%3==2){
				bone.pixels[(timer-1)/3].g=temp;
				lasttwo=lastone;
				lastone=temp;
			}else{
				bone.pixels[(timer-1)/3].b=temp;
				lasttwo=lastone;
				lastone=temp;
			}
			bone.width=lasttwo;
			bone.height=lastone;
		}else{
			if (in=="rotate"){
				rotate(bone);
			}else if(in=="flip"){
				flipHorizontal(bone);
			}else if(in=="sepia"){
				sepia(bone);
			}
		}
	}
	cout<<"P3"<<endl;
	cout<<bone.width<<" "<<bone.height<<endl;
	cout<<"255"<<endl;
	for (int i=0;i<bone.size-1;i++){
		if(i==bone.width*bone.height-1){
			cout<<bone.pixels[i].r<<" "<<bone.pixels[i].g<<" "<<bone.pixels[i].b<<endl;
		}else if(i%bone.width==bone.width-1){
			cout<<bone.pixels[i].r<<" "<<bone.pixels[i].g<<" "<<bone.pixels[i].b<<endl;
		}else{
			cout<<bone.pixels[i].r<<" "<<bone.pixels[i].g<<" "<<bone.pixels[i].b<<" ";
		}
	}
//    delete a;
    delete [] bone.pixels;
}





