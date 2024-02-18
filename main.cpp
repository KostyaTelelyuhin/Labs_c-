#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <random>
using namespace std;


int full_search(int a[], int N, int element){
  auto begin = std::chrono::steady_clock ::now();
  for(int i = 0; i < N; i++){
    if(a[i] == element){
      auto end = chrono :: steady_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      return time_span.count();
    } 
  }
  auto end = chrono :: steady_clock ::now();
  auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
  return time_span.count();
}





int binary_search(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binary_search(arr, low, mid - 1, target);
    } else {
        return binary_search(arr, mid + 1, high, target);
    }
}
int main() {
  int All = 100;
  int Numbers[All];
  int time_do[All];
  srand(time(0));
  for (int i = 0;i<All;i++){
    int N = rand() % 1000000 + 1; 
    Numbers[i] = N;
    int average = 0;
    int reprize = 100;
    for(int j = 0; j < reprize; j++){
      int a[N];

      for(int k = 0; k < N; k++) {
          a[k] = rand() % 100000 + 1;
      }

      int element = rand() % 100000 + 1;


      //Начало чeго-то

      int TIME_SPAN  = full_search(a, N, element);
      average = average + TIME_SPAN;
      }

    time_do[i] = average/reprize;


  }

  for (int i = 0;i<All;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}


