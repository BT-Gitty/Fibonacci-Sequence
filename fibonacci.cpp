#include "fibonacci.hpp"

//Static global variables since they must stay initiated throughout runtime.
static int arg;
static int loop;
static std::string text;


void SetArg(){
  std::cout << "Enter a number.\n";
  std::cin >> arg;
  loop = 2;  //To compensate, otherwise two more lines than the given number would generate.
  text = "";
}

//Draw a fish as many times as the given parameter states.
void DrawFish(int num){
  for (int i = 0; i < num; i++){
    text += "><((º> ";
  }
  text += "\n";
}


void DoSequence(int prevCycle, int currCycle){

  if (loop <= arg){
    int newCycle = prevCycle + currCycle;
    loop++;

    DrawFish(currCycle);

    //Loop with new values if the number of loops the user stated is not reached.
    return DoSequence(currCycle, newCycle);
  }
  
}


void SaveText(){
  std::ofstream file("fish.out.txt");
  file << text;
  file.close();
}
