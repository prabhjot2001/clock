#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>
#include <iomanip>
#include <windows.h>

using namespace std;
int hour,min,sec,i=10;

bool gotoxy(const int x, const int y) {
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void showclock(){
	system("cls");
  cout<<setfill(' ')<<setw(50)<<"-------------"<<endl;
	gotoxy(36,1);
	cout<<"/   "<<setfill('0')<<setw(2)<<::hour<<":";
	cout<<setfill('0')<<setw(2)<<::min<<":";
	cout<<setfill('0')<<setw(2)<<::sec<<"  /"<<endl;
cout<<setfill(' ')<<setw(50)<<"-------------";
}
void timer(){
	while (::min!=-1){
        showclock();
        sleep(1);
			 Beep(700,100);
        ::sec--;
        if(::sec==0){
        	::min--;
        	if(::min==0){
        		::hour--;
        		::min=60;
        	}
        	::sec=60;
        }
	}
	gotoxy(50,10);
	cout<<"TIMER UP!!!";
	while(::i!=0){
		//for(short i=0;i<3;i++){
			Beep(500,300);
			//sleep(1);
			i--;
		//}
	}
  cout<<"\nPress any key to continue";
  system("pause");


}
int main() {

  cout<<"Set the timer in the format of-(Hour:minute:second)";
  cin>>::hour>>::min>>::sec;
  timer();
  }
