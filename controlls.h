#include <string>

class input{
  private:
    //de nuvarande koordinaterna
    std::string coordinates;
  public:


    char getValidDirection(int x,int y,int n, char b[11][11]);

    bool validInput(std::string notValidated);
    void getCords();

    int cordX();
    int cordY();
};
