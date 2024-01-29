#include <iostream>
#include <stdlib.h>
#include "controlls.h"
using namespace std;


//skaffar en giltig riktning av anv�ndaren
char input::getValidDirection(int x,int y,int length, char board[11][11]){
  //initsierar variabler
  string rawDirection;
  char dir;

  //dessa blir sanna om n�got g�r fel
  bool willOverlap = false;
  bool outOfBounds = false;

  //ta in en riktning fr�n anv�ndaren
  cout << "Enter direction: "<< endl;
  cin >> rawDirection;

  //kollar s� att riktningen faktiskt finns
  if (rawDirection.find_first_not_of("nsweNSWE") != string::npos){
    //om riktningen inte finns s� skrivs ett error ut och funktionen k�rs igen
    cout << "Unknown direction" << endl;
    return getValidDirection(x,y,length,board);
  }

  //g�r om anv�ndarens input till en stor bokstav
  dir = toupper(rawDirection[0]);

  //kollar om anv�ndarens val �r utanf�r br�det
  if ((dir == 'E' && (x +length) > 10 )||(dir == 'W' && (x -length) < 1)){
    outOfBounds = true;
  }
  else if ((dir == 'S' && (y +length) > 10 )||(dir == 'N' && (y -length) < 1)){
    outOfBounds = true;
  }
  //om anv�ndarens val inte g�r utanf�r br�det s� kollar den att inga "skepp" krockar
  else{
    for (int i = 0; i <= length ; i++){
      if ((dir == 'E' && board[y][x +i] == '#')||(dir == 'W' && board[y][x -i] == '#')){
        willOverlap = true;
        break;
      }
      else if ((dir == 'N' && board[y -i][x] == '#')||(dir == 'S' && board[y +i][x] == '#')){
        willOverlap = true;
        break;
      }
    }
  }

  //om n�got g�tt fel
  if (outOfBounds == true || willOverlap == true){
    //skriver ut olika errors beroende p� vad som gick fel
    if (outOfBounds == true){
      cout << "Out of bounds" << endl;
    }
    else if (willOverlap == true){
      cout << "Ships will overlap." << endl;
    }
    //Kollar om anv�ndaren vill �ndra kordinater
    cout << "do you want to select new cordinates(y/n)?";
    string selectNew;
    cin >> selectNew;
    //om anv�ndaren vill �ndra kordinater
    if (selectNew[0] == 'y'){
      getCords();
    }
    return getValidDirection(cordX(),cordY(),length,board);
  }
  return dir;
}

//validerar kordinaterna
bool input::validInput(string notValidated){
 //kollar att anv�ndaren inte gett f�r m�nga eller f�r f� kordimater
 if(notValidated.size() < 2 ){
   cout << "Not enough coordinates entered.\n Please re-enter coordinates..."<< endl;
   getCords();
 }
 else if(notValidated.size() > 2 ){
   cout << "Too many coordinates entered.\n Please re-enter coordinates..."<< endl;
   getCords();
 }
 //och att inget i input �r ogiltiga tecken
 else if (notValidated.find_first_not_of("1234567890abcdefghijABCDEFGHIJ") != string::npos){
   cout << "The coordinate is unknown.\n Please re-enter coordinates..."<< endl;
   getCords();
 }
 else{
   //annars kollar det om input bara ineh�ller bokst�ver eller siffror
   if (isdigit(notValidated[0]) && isdigit(notValidated[1])){
     cout << "Input contains only numbers" << endl;
     getCords();
   }
   else if (isalpha(notValidated[0]) && isalpha(notValidated[1])){
     cout << "Input contains only charactars" << endl;
     getCords();
   }
   else{
     return true;
   }
 }
 return false;
}

//tar in koordinater fr�n anv�ndaren
void input::getCords(){
  cout << "Enter the coordinates" << endl;
  cout << "The coordinates are: ";
  string rawInput;
  cin >> rawInput;
  //kollar att kordinaterna �r giltiga
  if (validInput(rawInput) == true){
    //kollar om kordinaterna beh�ver byta plats
    if (isalpha(rawInput[1])){
      char temp;
      temp = rawInput[0];
      rawInput[0] = rawInput[1];
      rawInput[1] = temp;
    }
    coordinates = rawInput;
  }
}

//tar in x kordinaten som string och retunerar den som int
int input::cordX(){
  string XCord;
  XCord = coordinates[1];
  int X = atoi(XCord.c_str());
  X++;
  return X;
}

//tar in y kordinaten och retunerar dess motsvarighet som int
int input::cordY(){
  char Ycord;
  int y;

  Ycord = coordinates[0];

  switch(Ycord){
    case 'A':
    case 'a':
      y = 1;
      break;

    case 'B':
    case 'b':
      y = 2;
      break;

    case 'C':
    case 'c':
      y = 3;
      break;

    case 'D':
    case 'd':
      y = 4;
      break;

    case 'E':
    case 'e':
      y = 5;
      break;

    case 'F':
    case 'f':
      y = 6;
      break;

    case 'G':
    case 'g':
      y = 7;
      break;

    case 'H':
    case 'h':
      y = 8;
      break;

    case 'I':
    case 'i':
      y = 9;
      break;

    case 'J':
    case 'j':
      y = 10;
      break;

    default:
      cout << "Y coordinate is invalid.\n Please re-enter coordinates" << endl;
      getCords();
  }
  return y;
}


