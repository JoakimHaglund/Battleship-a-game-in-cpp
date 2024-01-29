#include <iostream>
#include "essentials.h"
#include "controlls.h"

using namespace std;

//frågar efter spelarens namn
void player::playerName(){
  cout << "What is your name?"<< endl;
  cin >> name;
  //Ändra första bokstaven i namnet till stor bokstav
  name[0] = toupper(name[0]);
}

//kollar om spelaren lever (retunerar true om spelaren lever)
bool player::isAlive(){
  //söker efter "skepp" i board
  for (int i = 0; i < 11 ;i++){
    for (int j = 0; j < 11 ;j++){
      if (board[i][j] == '#'){
        return true;
      }
    }
  }
  return false;
}


//skriver ut en spelares bräde
void gameboard::printBoard(char board[11][11],bool isPublic ){
  //loopar igenom vektorn "board"
  for (int i = 0; i < 11 ;i++){
    for (int j = 0; j < 11 ;j++){
      //om en "#" hittas och inte ska synas så skrivs  "_|" ut istället
      if (isPublic == false && board[i][j] == '#'){
        cout << "_|";
      }
      //annars skrivs inehållet i board[i][j] ut
      else{
        cout << board[i][j] << "|" ;
      }
      //skapar ny rad
      if (j == 10) {
        cout << "\n";
      }
    }
  }
}

//Funktion för att attackera motståndaren
void gameboard::bomb(char target[11][11]){
  input input;
  int xCord;
  int yCord;
  //tar in kordinater från användaren
  input.getCords();
  //hämtar x och y kordinaterna
  xCord = input.cordX();
  yCord = input.cordY();

  //kollar om det var en träff om det var en träff markeras platsen med ett 'X'
  if (target[yCord][xCord] == '#'){
    cout << "Hit!" << endl;
    target[yCord][xCord] = 'X';
  }
  //kollar om användaren redan skjutit där om användaren har det så körs funktionen igen
  else if (target[yCord][xCord] == 'X' || target[yCord][xCord] == 'O'){
    cout << "You have already bombed that spot select another one"<< endl;
    bomb(target);
  }
  //annars var det en miss och kordinaten markeras med ett 'O'
  else{
    cout << "No hit!"<< endl;
    target[yCord][xCord] = 'O';
  }
}

//skriver ut båda spelarnas bräden och namn
void gameboard::displayBoards(char board1[11][11], string name1, char board2[11][11], string name2){

  cout << "PLAYER: " << name1 << endl;
  cout << "//////////////////////" << endl;
  //skriver ut board1 utan att man kan se spelarens skepp
  printBoard(board1,false);
  cout << "//////////////////////" << endl;
  cout << "PLAYER: " << name2 << endl;
  cout << "//////////////////////" << endl;
  //skriver ut board2 och man kan se spelarens skepp
  printBoard(board2,true);
  cout << "//////////////////////" << endl;
}

//Funktion för att lägga ut skepp
void gameboard::setUpBoard(char board[11][11]){
  //skapa objekt
  input inOut;
  //initierar variabler
  int xCord;
  int yCord;
  char direction;

  int shipLenght = 4;



  //skriv ut "Set up gameboard" och spelarens bräde
  cout << "\nSet up gameboard"<< endl;
  printBoard( board,true );

  //ta in kordinater
  inOut.getCords();
  xCord = inOut.cordX();
  yCord = inOut.cordY();

  //ta in riktningen som skeppet kommer vara i
  direction = inOut.getValidDirection(xCord,yCord,shipLenght,board);

  //skriver ut ett skepp i riktningen av "direction"
  switch(direction){
    case 'E':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord][xCord+i] = '#';
      }
      break;
    case 'W':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord][xCord-i] = '#';
      }
      break;
    case 'S':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord+i][xCord] = '#';
      }
      break;
    case 'N':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord-i][xCord] = '#';
      }
      break;
    default:
      cout << "Something went wrong please try again" << endl;
      setUpBoard(board,shipLenght,false);
      break;
  }

  shipLenght--;

  setUpBoard(board,shipLenght,false);
}

//Överlagrad funktion för att lägga ut skepp
void gameboard::setUpBoard(char board[11][11],int shipLenght,bool thirdShipIsPlaced){
  //skapa objekt
  input inOut;

  //initierar variabler
  int xCord;
  int yCord;
  char direction;

  //skriv ut spelarens bräde
  printBoard( board,true );

  //ta in nya kordinater så länge som det finns skepp på de nuvarande kordinaterna
  do{
    inOut.getCords();
    xCord = inOut.cordX();
    yCord = inOut.cordY();
    if (board[yCord][xCord] == '#'){
      cout << "A ship is already placed there" << endl;
    }
  }while (board[yCord][xCord] == '#');

  //ta in riktningen som skeppet kommer vara i
  direction = inOut.getValidDirection(xCord,yCord,shipLenght,board);

  xCord = inOut.cordX();
  yCord = inOut.cordY();
  //skriver ut ett skepp i riktningen av "direction"
  switch(direction){
    case 'E':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord][xCord+i] = '#';
      }
      break;
    case 'W':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord][xCord-i] = '#';
      }
      break;
    case 'S':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord+i][xCord] = '#';
      }
      break;
    case 'N':
      for (int i = 0; i <= shipLenght ; i++){
        board[yCord-i][xCord] = '#';
      }
      break;
    default:
      cout << "Something went wrong please try again" << endl;
      setUpBoard(board,shipLenght,thirdShipIsPlaced);
      break;
  }

  //om skeppets längd är 3 och det bara finns ett ute
  //så ska ett lika långt skepp läggas ut
  if (shipLenght == 2 && thirdShipIsPlaced == false ){
    thirdShipIsPlaced = true;
    setUpBoard(board,shipLenght,thirdShipIsPlaced);
  }
  //om skeppets längd är större än 1 kör funktionen igen
  else if (shipLenght > 1 ){
    shipLenght--;
    setUpBoard(board,shipLenght,thirdShipIsPlaced);
  }
  //annars skriv ut brädet och vänta på att användaren trycker på enter
  else{
    printBoard( board,true );
    cout << "Press enter to finish setup phase" << endl;

    cin.get();
    cin.ignore();
  }
}
