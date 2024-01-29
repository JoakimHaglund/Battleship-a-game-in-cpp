/*Som f�rdjupningsuppgift valde jag att g�ra ett litet spel.
 *
 *spelet �r s�nka skepp och det g�r p� att s�nka motst�ndarens
 *skepp innan denna har s�nkt dina. Tyv�rr hade jag inte tid
 *att l�gga till en datorstyrd spelare s� f�r tillf�llet �r det
 *f�r 2 spelare detta i sig �r lite problematiskt d� jag inte har n�gon
 *funktion f�r att rensa sk�rmen (vilket g�r det l�tt att fuska)
 *ut�ver detta s� funkar det som jag t�nkt.
 */

#include <iostream>
#include "controlls.h"
#include "essentials.h"

using namespace std;

int main(){
  //Skapar objekt
  player player1;
  player player2;
  gameboard common;

  //skaffar namn p� spelare 1 och l�ter den l�gga ut skepp
  player1.playerName();
  common.setUpBoard(player1.board);

  //g�r samma sak f�r spelare 2
  player2.playerName();
  common.setUpBoard(player2.board);

  //forts�tter spelet tills en spelare �r d�d
  while (player1.isAlive() == true && player2.isAlive() == true ){
    //skriv ut spelarnas br�den och l�ter spelare 1 bomba spelare 2 och skriver ut br�dena igen
    common.displayBoards(player2.board, player2.name, player1.board, player1.name);
    common.bomb(player2.board);
    common.displayBoards(player2.board, player2.name, player1.board, player1.name);

    //skriv ut spelarnas br�den och l�ter spelare 2 bomba spelare 1 och skriver ut br�dena igen
    common.displayBoards(player1.board, player1.name, player2.board, player2.name);
    common.bomb(player1.board);
    common.displayBoards(player1.board, player1.name, player2.board, player2.name);


  }
  //kollar vem som vann om ingen har vunnit skrivs en error ut
  if(player1.isAlive()){
    cout << "\n" << player1.name << " WINS!"<<endl;
  }
  else if (player2.isAlive()){
    cout << "\n" << player2.name << " WINS!"<< endl;
  }
  else {
    cout << "\nIt seems like something went wrong..."<< endl;
  }
  return 0;
}
