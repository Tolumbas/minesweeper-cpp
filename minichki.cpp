#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <windows.h>
using namespace std;
int mreja[16][16];
int used[16][16], mina=0;
bool flag = false, nachalo = true,game = true;

void nule(){
for (int a=0;a<16;a++){
for (int b=0;b<16;b++){
mreja[a][b] = 0;
used[a][b] =0;
mina = 0;
}}}
void prov(){
system("cls");
for (int a=0;a<16;a++){
for (int b=0;b<16;b++){cout << used[a][b] << " ";}cout << endl;}}
int cifri(string vhod){
if(vhod == "1"|| vhod == "a"){return 0;}
if(vhod == "2"|| vhod == "b"){return 1;}
if(vhod == "3"|| vhod == "c"){return 2;}
if(vhod == "4"|| vhod == "d"){return 3;}
if(vhod == "5"|| vhod == "e"){return 4;}
if(vhod == "6"|| vhod == "f"){return 5;}
if(vhod == "7"|| vhod == "g"){return 6;}
if(vhod == "8"|| vhod == "h"){return 7;}
if(vhod == "9"|| vhod == "i"){return 8;}
if(vhod == "10"|| vhod == "j"){return 9;}
if(vhod == "11"|| vhod == "k"){return 10;}
if(vhod == "12"|| vhod == "l"){return 11;}
if(vhod == "13"|| vhod == "m"){return 12;}
if(vhod == "14"|| vhod == "n"){return 13;}
if(vhod == "15"|| vhod == "o"){return 14;}
if(vhod == "16"|| vhod == "p"){return 15;}
}
void mini(){
for (int a=0;a<16;a++){
for (int b=0;b<16;b++){
if (rand()%6 == 1){
    mina++;
    mreja[a][b] = 90;
    if (a > 0 && mreja[a-1][b] != 90){mreja[a-1][b] += 10;}
    if (a < 15 && mreja[a+1][b] != 90){mreja[a+1][b] += 10;}
    if (b > 0 && mreja[a][b-1] != 90){mreja[a][b-1] += 10;}
    if (b < 15 && mreja[a][b+1] != 90){mreja[a][b+1] += 10;}
    if (a > 0 && b>0 && mreja[a-1][b-1] != 90){mreja[a-1][b-1] += 10;}
    if (a < 15 && b >0 && mreja[a+1][b-1] != 90){mreja[a+1][b-1] += 10;}
    if (a > 0 && b < 15 && mreja[a-1][b+1] != 90){mreja[a-1][b+1] += 10;}
    if (a < 15 && b < 15 && mreja[a+1][b+1] != 90){mreja[a+1][b+1] += 10;}
    }
    used[a][b] =0;
}}

}
void nuli(int x,int y){
used[x][y]=1;
if (x > 0 && used[x-1][y] == 0 && mreja[x-1][y] >= 10){mreja[x-1][y] /= 10;used[x-1][y]= 2;}
if (x < 15 && used[x+1][y] == 0 && mreja[x+1][y] >= 10){mreja[x+1][y] /= 10;used[x+1][y]= 2;}
if (y > 0 && used[x][y-1] == 0 && mreja[x][y-1] >= 10){mreja[x][y-1] /= 10;used[x][y-1]= 2;}
if (y < 15 && used[x][y+1] == 0 && mreja[x][y+1] >= 10){mreja[x][y+1] /= 10;used[x][y+1]= 2;}
if (x > 0 && y>0&& used[x-1][y-1] == 0 && mreja[x-1][y-1] >= 10){mreja[x-1][y-1] /= 10;used[x-1][y-1]= 2;}
if (x < 15 && y >0&& used[x+1][y-1] == 0 && mreja[x+1][y-1] >= 10){mreja[x+1][y-1] /= 10;used[x+1][y-1]= 2;}
if (x > 0 && y < 15&& used[x-1][y+1] == 0 && mreja[x-1][y+1] >= 10){mreja[x-1][y+1] /= 10;used[x-1][y+1]= 2;}
if (x < 15 && y < 15&& used[x+1][y+1] == 0 && mreja[x+1][y+1] >= 10){mreja[x+1][y+1] /= 10;used[x+1][y+1]= 2;}

    if(x < 15 && mreja[x+1][y] == 0 && used[x+1][y] == 0){
    nuli(x+1,y);
    }
    if(x > 0 && mreja[x-1][y] == 0 && used[x-1][y] == 0){
    nuli(x-1,y);
    }
    if(y < 15 && mreja[x][y+1] == 0 && used[x][y+1] == 0 ){
    nuli(x,y+1);
    }
    if(y > 0 && mreja[x][y-1] == 0 && used[x][y-1] == 0 ){
    nuli(x,y-1);
    }
    if(x < 15 && y>0 && mreja[x+1][y-1] == 0 && used[x+1][y-1] == 0 ){
    nuli(x+1,y-1);
    }
    if(x > 0 && y < 15 && mreja[x-1][y+1] == 0 && used[x-1][y+1] == 0){
    nuli(x-1,y+1);
    }
    if(y < 15 && x < 15 && mreja[x+1][y+1] == 0 && used[x+1][y+1] == 0 ){
    nuli(x+1,y+1);
    }
    if(y > 0 && x > 0 && mreja[x-1][y-1] == 0 && used[x-1][y-1] == 0){
    nuli(x-1,y-1);
    }

}
void plot(){
    int br=1;
    system("cls");
    if (game == false){cout << endl << "                     GAME OVER" << endl;}
    cout << "     a b c d e f g h i j k l m n o p" << endl << endl;
    for (int a=0;a<16;a++){
    if (br < 10) {cout <<br<<"    ";}
    else {cout <<br<<"   ";}
    for (int b=0;b<16;b++){
    if (mreja[a][b] == 0 && used [a][b] == 1){cout << "  ";}
    else if (mreja[a][b] == 1){cout << "1 ";}
    else if (mreja[a][b] == 2){cout << "2 ";}
    else if (mreja[a][b] == 3){cout << "3 ";}
    else if (mreja[a][b] == 4){cout << "4 ";}
    else if (mreja[a][b] == 5){cout << "5 ";}
    else if (mreja[a][b] == 6){cout << "6 ";}
    else if (mreja[a][b] == 7){cout << "7 ";}
    else if (mreja[a][b] == 8){cout << "8 ";}
    else if (mreja[a][b] == 90 && game == false){cout << char(31) <<" ";}
    else{cout << "* ";}
    }cout <<"  "<<br<< endl;br ++;}
    cout << endl << "     a b c d e f g h i j k l m n o p" << endl << endl;
}
void quit(){
game = false;
plot();
system("pause");
nule();
game = true;
nachalo = true;
}
int main(){
srand(time(0));
string vhod1,vhod2;
long long x,y;
system ("title Anton's minesweeper!");
nule();
plot();
prov();
while (true){
    cin >> vhod1 >> vhod2;

    flag = false;
    for (int a = 97; a<123;a++){if ( vhod1[0] == char(a) ){flag = true;}}
    if (flag){y = cifri(vhod1);x = cifri(vhod2);}else{x = cifri(vhod1);y = cifri(vhod2);}

    if (nachalo){
    while (mreja[x][y] != 0 || mina != 40){nule();mini();}
    nachalo = false;
    }
    if (mreja[x][y] == 90){quit();}
    else if (mreja[x][y] == 0){nuli(x,y);}
    else if (used[x][y]>=10) {mreja[x][y] /=10;}
    plot();
    //prov();

}
cout << "Kak uspq da izleznesh?!?!?!?!?";
return 0;
}
