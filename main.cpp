#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <random>
using namespace std;
int full_search(int a[], int N, int element){
  for(int i = 0; i < N; i++){
    if(a[i] == element){
      return i;

    }
  }return -1;
}
int main() {
  int Numbers[10];
  int time_do[10];
  srand(time(0));
  for (int i = 0;i<10;i++){
    int N = rand() % 100 + 1; 
    Numbers[i] = N;
    int average = 0;
    for(int j = 0; j < 100; j++){
      int a[N];
      for(int k = 0; k < N; k++) {
          a[k] = rand() % 1000 + 1; 

      }

      int element =  rand() % 1000 + 1;
      //cout <<  "elem = " << element;

      //Начало чeго-то
      auto begin = std::chrono::steady_clock ::now();
      full_search(a, N, element);
      auto end = chrono :: steady_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      average = average + time_span.count();
      }

    time_do[i] = average/5;


  }

  for (int i = 0;i<10;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}