#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <vector> 
#include <thread>


using namespace std;

int MASSIVE[1000000];
void mass(){
  for(int i =0; i<1000000; i++){
    MASSIVE[i]=i;
  }
}
int func(){
  return 0;
}
int time(){
    auto begin = std::chrono::steady_clock ::now();
    func();
    auto end = chrono :: steady_clock ::now();
    auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
    long long TIME_SPAN = time_span.count();
    return TIME_SPAN;
}

int full_search(int a[], int N, int element){
  for(int i = 0; i < N; i++){
    if(a[i] == element){
      return i;
    } 
  }

  return -1;
}


int binary_search(int arr[], int low, int high, int target) {   
    if (low > high) {

        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {

        return mid;
    } else if (arr[mid] > target) {


        return binary_search(arr, low, mid - 1, target );
    } else {

        return binary_search(arr, mid + 1, high, target);
    }
}

int search_sum(int a[], int N, int sum){
  for (int i = 0; i < N - 1; i++){
    //cout << "i = " <<i <<  endl;
    //cout << "j  = ";
    for(int j = i + 1; j < N; j++){
      //cout  << j <<" ";

      if(a[i] + a[j] == sum){
        //cout << "i =  " << i << " j = " << j << endl;
        return i;
      }
    }//cout << endl;
  }//cout << -1 << endl;
  return -1;

}

int search_bin_sum(int arr[], int low, int high, int summ){
  if (low > high) {
      //cout << "-1" << endl;
      return -1;
  }
  if (summ > arr[high] + arr[low]){
    return search_bin_sum(arr, low + 1, high, summ);
  }else if (summ < arr[high] + arr[low]){
    return search_bin_sum(arr, low , high - 1, summ);
  }else if(summ == arr[high] + arr[low]){
      //cout << "low = " << low << " high = " << high << endl;
    return low;
  }return 0;
}



int main_full_search(int reprize = 1,int MAX_COUNT = 100){

  int All = 10;

  long long seed = 100001;
  default_random_engine rng(seed);

  uniform_int_distribution<unsigned> dstr(1, MAX_COUNT);
  long long Numbers[All];
  long long time_do[All];
  for (int i = 0;i<All;i++){
    long long N = MASSIVE[dstr(rng)];
    uniform_int_distribution<unsigned> dstr1(0, N-1);
    Numbers[i] = N;
    int average = 0;
    for(int j = 0; j < reprize; j++){
      int a[MAX_COUNT];
     //Создание массива
      for(int k = 0; k < N; k++) {
          a[k] = MASSIVE[dstr(rng)];

      }
      // Элемент массива
      int element = a[MASSIVE[dstr1(rng)]];  
      //int element = -1;

      auto begin = std::chrono::high_resolution_clock ::now();
      full_search(a, N, element);
      auto end = chrono :: high_resolution_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      long long TIME_SPAN = time_span.count();
      average = average + TIME_SPAN;
      }

    time_do[i] = average/reprize;


  }

  for (int i = 0;i<All;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}


int main_bin_search(int reprize = 1,int MAX_COUNT = 100){
  int All = 10;



  long long seed = 100010;
  default_random_engine rng(seed);
  uniform_int_distribution<unsigned> dstr(1, MAX_COUNT - 1);

  long long Numbers[All];
  long long time_do[All];
  for (int i = 0;i<All;i++){
    long long N = MASSIVE[dstr(rng)];
    uniform_int_distribution<unsigned> dstr1(0, N-1);
    Numbers[i] = N;
    int average = 0;

    for(int j = 0; j < reprize; j++){
      int a[MAX_COUNT];
     //Создание массива
      //cout << "N = " << N << " Massive = ";
      for(int k = 0; k < N; k++) {
          a[k] = k;
          //cout << a[k] << " ";
      }
      // Элемент массива
      int element = a[dstr1(rng)];  
      //int element = -1;
      //cout << "element = " << element <<" i = " << binary_search(a, 0, N-1, element)<< endl;
      auto begin = std::chrono::high_resolution_clock ::now();
      binary_search(a, 0, N-1, element);
      auto end = chrono :: high_resolution_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      long long TIME_SPAN = time_span.count();
      //cout << "TIME_SPAN = " << TIME_SPAN << " i = " << i << endl;


      average = average + TIME_SPAN;

      }
      time_do[i] = average/reprize;


  }

  for (int i = 0;i<All;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}


int main_search_sum(int reprize = 1,int MAX_COUNT = 10){
  time();

  int All = 10;
  long long seed = 100010;
  default_random_engine rng(seed);
  uniform_int_distribution<unsigned> dstr(1, MAX_COUNT - 1);

  long long Numbers[All];
  long long time_do[All];
  for (int i = 0;i<All;i++){
    long long N = MASSIVE[dstr(rng)];
    uniform_int_distribution<unsigned> dstr1(0, N-1);
    Numbers[i] = N;
    int average = 0;

    for(int j = 0; j < reprize; j++){
      int a[MAX_COUNT];
     //Создание массива
      //cout << "N = " << N << " Massive = ";
      for(int k = 0; k < N; k++) {
          a[k] =MASSIVE[dstr(rng)];
          //cout << a[k] << " ";
      }
      // Элемент массива
      int summ = MASSIVE[dstr(rng)];  
      //int element = -1;
      //cout << "summ = " << summ << endl;
      auto begin = std::chrono::high_resolution_clock ::now();
      search_sum(a, N, summ);
      auto end = chrono :: high_resolution_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      long long TIME_SPAN = time_span.count();
      //cout << "TIME_SPAN = " << TIME_SPAN << " i = " << i << endl;


      average = average + TIME_SPAN;

      }
      time_do[i] = average/reprize;


  }

  for (int i = 0;i<All;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}



int main_bin_two_search(int reprize = 1,int MAX_COUNT = 100){
  int All = 10;


  long long seed = 100010;
  default_random_engine rng(seed);
  uniform_int_distribution<unsigned> dstr(1, MAX_COUNT - 1);

  long long Numbers[All];
  long long time_do[All];
  for (int i = 0;i<All;i++){
    long long N = MASSIVE[dstr(rng)];
    uniform_int_distribution<unsigned> dstr1(0, N-1);
    Numbers[i] = N;
    int average = 0;

    for(int j = 0; j < reprize; j++){
      int a[MAX_COUNT];
     //Создание массива
      //cout << "N = " << N << " Massive = ";
      for(int k = 0; k < N; k++) {
          a[k] = k;
          //cout << a[k] << " ";
      }
      // Элемент массива
      int summ = MASSIVE[dstr(rng)];  
      //int element = -1;
      //cout << "summ = " << summ << endl;
      auto begin = std::chrono::high_resolution_clock ::now();
      search_bin_sum(a, 0, N-1, summ);
      auto end = chrono :: high_resolution_clock ::now();
      auto time_span = chrono :: duration_cast < chrono :: nanoseconds > (end - begin);
      long long TIME_SPAN = time_span.count();
      //cout << "TIME_SPAN = " << TIME_SPAN << " i = " << i << endl;


      average = average + TIME_SPAN;

      }
      time_do[i] = average/reprize;


  }

  for (int i = 0;i<All;i++){
    cout << Numbers[i] << " " << time_do[i] << endl;
  }


  return 0;
}





int main() {
  mass();

  //main_full_search();



  //main_bin_search();

  //main_search_sum();
  //main_bin_two_search();

//12

}


