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
  int Numbers[100];
  int time_do[100];
  srand(time(0));
  for (int i = 0;i<100;i++){
    int N = rand() % 1000000 + 1; 
    Numbers[i] = N;
    int average = 0;
    for(int j = 0; j < 100; j++){
      int a[N];
      for(int k = 0; k < N; k++) {
          a[k] = rand() % 100 + 1; 

      }

      int element = 200;
      //cout <<  "elem = " << element;

      //Начало чeго-то
      auto begin = std::chrono::steady_clock ::now();
      full_search(a, N, element);
      auto end = chrono :: steady_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      average = average + time_span.count();
      }

    time_do[i] = average/100;


  }

  for (int i = 0;i<100;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}