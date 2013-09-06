/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){

 //Helpers for input and output

   int N, K;
   int C[N];

   cin >> N >> K;
   for(int i = 0; i < N; i++){
      cin >> C[i];
   }
   sort(C, C+N, std::greater<int>());
    for(int i = 0; i < N; i++){
      cout << C[i] <<" ";
   }
   /*int result;
   cout << result << "\n";
   */
   return 0;
}