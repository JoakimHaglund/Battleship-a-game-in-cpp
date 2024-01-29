#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "bot.h"
void bot::shoot(char target[11][11]){
  srand(time(NULL));
  int number;
  int number2;
  int arr[9] ={1,3,5,7,9,2,4,6,8};
  number = rand() % 9 + 1;
int i;
  if (number % 2 == 0){

    i = rand() % 5 + 1;
  }
  else{

  i = rand() % 9 + 6;
  }
  number2 = arr[i];
if (target[number][number2] == 'O'||target[number][number2] == 'X'){
  cout << "ERROR!" << endl;
  shoot(target);
}
else if (target[number][number2] == '#' ){
  target[number][number2] = 'X';
}
else{
  target[number][number2] = 'O';
}
cin.get();
}
