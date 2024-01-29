#include <string>

//Klassen player inehåller allt specifikt till spelaren
class player{
public:
  //Spelarens namn
  std::string name;

  void playerName();

  //Spelarens bräde
  char board[11][11]={{' ','0','1','2','3','4','5','6','7','8','9',},
                      {'A','_','_','_','_','_','_','_','_','_','_',},
                      {'B','_','_','_','_','_','_','_','_','_','_',},
                      {'C','_','_','_','_','_','_','_','_','_','_',},
                      {'D','_','_','_','_','_','_','_','_','_','_',},
                      {'E','_','_','_','_','_','_','_','_','_','_',},
                      {'F','_','_','_','_','_','_','_','_','_','_',},
                      {'G','_','_','_','_','_','_','_','_','_','_',},
                      {'H','_','_','_','_','_','_','_','_','_','_',},
                      {'I','_','_','_','_','_','_','_','_','_','_',},
                      {'J','_','_','_','_','_','_','_','_','_','_',},
                     };

  bool isAlive();
};
//Klassen gameboard inehåller allt som ändrar eller skriver ut spelbrädet
class gameboard{
public:
  void printBoard(char board[11][11],bool isPublic );
  void bomb(char target[11][11]);
  void displayBoards(char board1[11][11],std::string name1, char board2[11][11], std::string name2);
  void setUpBoard(char board[11][11]);
  void setUpBoard(char board[11][11],int shipLenght,bool thirdShipIsPlaced);

};
