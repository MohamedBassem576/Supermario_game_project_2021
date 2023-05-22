# include <iostream>
#include <conio.h>

using namespace std ;

class Champion{
private:
  int x;
  int y;
  int health;
  int gems;
  int score;
  int totalGems;
public:
Champion(){
 cout<< "Constructor champion() is called" <<endl;

health =100;
gems =0;
 x =0;
 y =0;
score =0;
}


void print_champ_info(){

cout<<"Champion Pos is "<<" x = "<<x<<" y = "<<y<<" Champion Health: "<<health<<" Champion Score: "<<score<<" Collected Gems: " <<gems<< "/"<< totalGems <<endl;
}
void settotalGems (int k){
totalGems = k ;
}

int getX(){
return x;
}
int getY(){
return y;
}
void setX(int i ){
x=i;
}

void setY(int i ){
y=i;
}
int getH(){
return health;
}
void setH(int h){
health =h;

}
int getgem(){
return gems;
}
void setgem(int g){
gems =g;

}

int getScore(){
return score;
}
void setscore(int s){
score =s;

}
};
class mapp{
    public:
  char **map;
  Champion*c;





public:
mapp(){
cout<<"Constructor map() is called"<<endl;
c = new Champion();

map = new char * [10];
for(int i =0 ; i < 10 ; i++)
{
    map[i] = new char[10];
}
for(int x = 0 ; x <10 ; x++){
    for(int y =0;y <10;y++){
     map[x][y] = '.';
    }
}




}



 void print_map(){


    map[0][0] == 'c';
for(int i =9 ; i>=0;i--){
    for(int j = 0; j < 10;j++){
      cout <<map[i][j]<<" ";

    }
    cout<<endl;

}
cout<<"print_map is called"<<endl;
c->print_champ_info();
}



 void randomize_map(){

 cout<<"randomize_map() called" <<endl;

 int i =0;
 int total = 0 ;
int r = 40 + (rand() % 10);
 while( i <= r){
  int x = 1+(rand() % 9);
 int y = 1+(rand() % 9);
 if(map[x][y] =='.' ){
  map[x][y] = '$';
  total ++ ;
  i++;
 }

 }
 c -> settotalGems ( total);

int r1 = 20 + (rand() % 10);
int  o =0;
 while( o < r1){
  int x = 1 + (rand() % 9);
 int y = 1 + (rand() % 9);
 if(map[x][y] == '.'){
  map[x][y] = 'x';
  o++;
 }
 }
map[0][0]='C';
 }

 bool gameover(){

int count =0;
for(int i = 0;i <10;i++){
    for(int j = 0; j < 10 ;j++){
        if(map[i][j] == '$'){
            count++;
        }

    }
}
if(c->getH() <= 0){
    return true;
}
else if(count == 0){
    return true;
}
else
    return false;
 }


void moving(){

char m = getch();

if(m == '8' || m == '6'|| m=='4'|| m=='5'){


if(m =='8'){

 system("cls");


  int x = c->getX();
  int y = c->getY();

if(x != 9 && y !=0 || x != 9&& y!=9){

  if(map[x+1][y] == 'x'){

  c->setH(c->getH()-40);
   map[x][y] = '.';
    map[x+1][y] = 'c';
    c->setX(x+1);
    c->setY(y);

    system("cls");
    print_map();

  }
  else if(map[x+1][y] == '$'){

c->setgem(c->getgem()+1);
c->setscore(c->getScore()+10);
 map[x][y] = '.';
    map[x+1][y] = 'c';
    c->setX(x+1);
    c->setY(y);
    system("cls");
    print_map();

  }
else if(map[x+1][y] == '.'){

    map[x][y] = '.';
    map[x+1][y] = 'c';
    c->setX(x+1);
    c->setY(y);
    system("cls");
    print_map();




}
}
else{
    system("cls");
    print_map();
}
}

if(m =='5'){
       system("cls");
  int x = c->getX();
  int y = c->getY();
if(x != 0 && y != 0 || x!=0 && y!=9){

  if(map[x-1][y] == 'x'){
  c->setH(c->getH()-40);
   map[x][y] = '.';
    map[x-1][y] = 'c';
    c->setX(x-1);
    c->setY(y);
    system("cls");
    print_map();
  }
  else if(map[x-1][y] == '$'){
c->setgem(c->getgem()+1);
c->setscore(c->getScore()+10);
 map[x][y] = '.';
    map[x-1][y] = 'c';
    c->setX(x-1);
    c->setY(y);
    system("cls");
    print_map();
  }
else if(map[x-1][y] == '.'){
    map[x][y] = '.';
    map[x-1][y] = 'c';
     c->setX(x-1);
    c->setY(y);
    system("cls");
    print_map();

}
}
else{
    system("cls");
    print_map();
}
}

if(m =='6'){
        system("cls");
  int x = c->getX();
  int y = c->getY();
if(c->getY()!=9){
  if(map[x][y+1] == 'x'){
  c->setH(c->getH()-40);
   map[x][y] = '.';
    map[x][y+1] = 'c';
    c->setX(x);
    c->setY(y+1);
    system("cls");
    print_map();
  }
  else if(map[x][y+1] == '$'){
c->setgem(c->getgem()+1);
c->setscore(c->getScore()+10);
 map[x][y] = '.';
    map[x][y+1] = 'c';
    c->setX(x);
    c->setY(y+1);
    system("cls");
    print_map();
  }
else if(map[x][y+1] == '.'){
    map[x][y] = '.';
    map[x][y+1] = 'c';
    c->setX(x);
    c->setY(y+1);
    system("cls");
    print_map();

}


}
else{
    system("cls");
    print_map();
}
}
}
if(m =='4'){
  int x = c->getX();
  int y = c->getY();
if(c->getY() != 0){


  if(map[x][y-1] == 'x'){
  c->setH(c->getH()-40);
   map[x][y] = '.';
    map[x][y-1] = 'c';
    c->setX(x);
    c->setY(y-1);
    system("cls");
    print_map();
  }
  else if(map[x][y-1] == '$'){
c->setgem(c->getgem()+1);
c->setscore(c->getScore()+10);
 map[x][y] = '.';
    map[x][y-1] = 'c';
    c->setX(x);
    c->setY(y-1);
    system("cls");
    print_map();
  }
else if(map[x][y-1] == '.'){
    map[x][y] = '.';
    map[x][y-1] = 'c';
    c->setX(x);
    c->setY(y-1);
    system("cls");
    print_map();

}
}

else{
    system("cls");
    print_map();
}


}
}
};





int main(){
int x;
mapp m;
m.randomize_map();
m.print_map();


cout<<"press 1 to start the game , 2 to re-randomize the map"<<endl;
cin>>x;

if(x == 2){
system("cls");
mapp m2;
m2.randomize_map();
m2.print_map();
while(m2.gameover()!= true){
m2.moving();
}

cout<<"game over"<<endl;
}

else if(x==1){



while(m.gameover()!= true){
m.moving();
}

cout<<" GAME OVER !"<<endl;
}

   return 0;
};




