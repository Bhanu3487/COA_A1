#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void create_matrix(vector<vector<double>>& mat) {
    int N = mat.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i == j)mat[i][j] = 1.0;
        }
    }
}

void multiplyMatrices(int N) {
    vector<vector<double>> mat1(N, vector<double>(N, 0.0)), mat2(N, vector<double>(N, 0)), result(N, vector<double>(N, 0));
    create_matrix(mat1);
    mat2 = mat1;

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "-->Time taken: " << time_taken << " seconds" << endl;
}


int main() {
    // run this code for n = [64, 128, 256, 512, 1024]
    int n = 1024;
    cout<<"Multiplication of matrices of size " << n << "x" << n << " with elements of datatype double and in cpp" <<endl;
    multiplyMatrices(n);
    
    cout<<endl;
    return 0;
}
