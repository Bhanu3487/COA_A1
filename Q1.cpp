#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

unsigned long long recursion(int n) {
    if (n == 0 || n == 1)return n;
    return recursion(n - 1) + recursion(n - 2);
}

unsigned long long recursion_and_memoization(int n, vector<unsigned long long>& fibo){
    if (n == 0 || n == 1)return n;
    if(fibo[n] != -1)return fibo[n];
    return fibo[n] = recursion_and_memoization(n-1, fibo) + recursion_and_memoization(n-2, fibo);
}


int main() {
    struct timespec start, end;

    cout<< "Q1. List the first 50 fibonacci numbers: "<<endl;
    cout<< "a. Using Recursion"<<endl; 
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < 50; ++i) {
        cout << recursion(i) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "-->Time taken: " << time_taken << " seconds" << endl;

    cout<< "b.Using loop"<<endl; 
    clock_gettime(CLOCK_REALTIME, &start);

    unsigned long long prev = 0, prev2 = 1, cur = 0;
    cout<<prev<<" "<<prev2<<" ";
    for(int i = 2; i <= 50; i++){
        cur = prev+prev2;
        cout<<cur<<" ";
        prev2 = prev;
        prev = cur;
    }
    cout<<endl;

    clock_gettime(CLOCK_REALTIME, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "--> Time taken: " << time_taken << " seconds" << endl;

    cout<< "c.Using Recursion and Memoization"<<endl; 
    clock_gettime(CLOCK_REALTIME, &start);

    vector<unsigned long long> fibo(50, -1);
    for(int i = 0; i < 50; ++i) {
        cout << recursion_and_memoization(i, fibo) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "--> Time taken: " << time_taken << " seconds" << endl;

    cout<< "d.Using loop and Memoization"<<endl; 
    clock_gettime(CLOCK_REALTIME, &start);

    vector<unsigned long long> fibo2(50, -1);
    fibo2[0] = 0; fibo2[1] = 1;
    cout<<fibo[0]<<" "<<fibo[1]<<" ";
    for(int i = 2; i < 50; i++){
        fibo2[i] = fibo2[i-1] + fibo2[i-2];
        cout<<fibo2[i]<<" ";
    }
    cout<<endl;

    clock_gettime(CLOCK_REALTIME, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "--> Time taken: " << time_taken << " seconds" << endl<<endl;

    return 0;
}

