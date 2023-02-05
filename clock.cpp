#include<iostream>
#include<unistd.h>
#include<windows.h>
#include<iomanip>

using namespace std;

int hour=0,min=0,sec=0;
string ampm;
int count = 0;


bool gotoxy(const int x, const int y) {
    COORD obj;
    obj.X = x;
    obj.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), obj);
}


void displayclock(){
    system("cls");
    gotoxy(4,9);
    cout<<setfill(' ')<<setw(60)<<"HEY I'M CLOCK"<<endl;
    cout<<setfill(' ')<<setw(60);
    gotoxy(52,15);cout<<setfill('0')<<setw(2)<<::hour<<":";
    gotoxy(56,15);cout<<setfill('0')<<setw(2)<<::min<<":";
    gotoxy(60,15);cout<<setfill('0')<<setw(2)<<::sec<<"  ";count%2==0?cout<<"AM":cout<<"PM";
}
void clock1(){

  while (1){
    displayclock();
    sleep(1);
    if(::hour<12){
      if(::min<60){
        if(::sec<60){
          sec++;
        }else{::min++;sec=0;}
      }else {::hour++; ::min=0;}
    }else {::hour=0;::count++;}
  }
}

int main(){


  cout<<setfill(' ')<<setw(60)<<"HEY I'M CLOCK\n\n\n"<<endl;
  cout<<setfill(' ')<<setw(60)<<"\t\tENTER THE CURRENT TIME as H:M:S and AM/PM"<<endl;
  cout<<"Hours : ";
  cin>>::hour;
  cout<<"minutes : ";
  cin>>::min;
  cout<<"Seconds : ";
  cin>>::sec;
  cout<<"am/pm : ";
  cin>>::ampm;
  if(::ampm=="am"){::count=2;}
  else if(::ampm=="pm"){::count=3;}
  else {
    cout<<"invalid input. Please enter 'am' or 'pm' properly"<<endl;
    return 0;
  }
  clock1();
}
