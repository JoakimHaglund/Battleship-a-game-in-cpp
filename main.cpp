/*Som fördjupningsuppgift valde jag att göra ett litet spel.
 *
 *spelet är sänka skepp och det går på att sänka motståndarens
 *skepp innan denna har sänkt dina. Tyvärr hade jag inte tid
 *att lägga till en datorstyrd spelare så för tillfället är det
 *för 2 spelare detta i sig är lite problematiskt då jag inte har någon
 *funktion för att rensa skärmen (vilket gör det lätt att fuska)
 *utöver detta så funkar det som jag tänkt.
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

  //skaffar namn på spelare 1 och låter den lägga ut skepp
  player1.playerName();
  common.setUpBoard(player1.board);

  //gör samma sak för spelare 2
  player2.playerName();
  common.setUpBoard(player2.board);

  //fortsätter spelet tills en spelare är död
  while (player1.isAlive() == true && player2.isAlive() == true ){
    //skriv ut spelarnas bräden och låter spelare 1 bomba spelare 2 och skriver ut brädena igen
    common.displayBoards(player2.board, player2.name, player1.board, player1.name);
    common.bomb(player2.board);
    common.displayBoards(player2.board, player2.name, player1.board, player1.name);

    //skriv ut spelarnas bräden och låter spelare 2 bomba spelare 1 och skriver ut brädena igen
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
