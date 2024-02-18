#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <vector> 



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

int comp1 (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
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
  srand(time(0));

  int All = 100;
  long long Numbers[All];
  long long time_do[All];

  long long MAX_COUNT = 1000000;
  for (int i = 0;i<All;i++){
    long long N = (RAND_MAX - rand()) * MAX_COUNT / RAND_MAX + 1; 
    Numbers[i] = N;
    int average = 0;
    int reprize = 10;
    for(int j = 0; j < reprize; j++){
      int a[N];
     //Создание массива
      for(int k = 0; k < N; k++) {
          a[k] = (RAND_MAX - rand()) * MAX_COUNT / RAND_MAX + 1;

      }

      //сортировка массивка(только для бинпоиска)
      qsort (a, N, sizeof(int), comp1);

      // Элемент массива
     //int element = a[(RAND_MAX - rand()) * N / RAND_MAX] ;     
      int element = -1;

      //Начало чeго-то
      auto begin = std::chrono::steady_clock ::now();
      //int TIME_SPAN  = full_search(a, N, element);
      binary_search(a, 0, N - 1, element);

      auto end = chrono :: steady_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      int TIME_SPAN = time_span.count();
      average = average + TIME_SPAN;
      }

    time_do[i] = average/reprize;


  }

  for (int i = 0;i<All;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}


