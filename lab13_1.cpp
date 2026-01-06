#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    for(int i = 0;i < N;i++){
        B[0] += A[i];
    }
    B[0] /= N; /*Arithmetic Mean*/

    double sum = 0, sum_sqrt = 0;
    for(int i = 0; i < N;i++) sum = sum + A[i];
    for(int i = 0; i < N;i++) sum_sqrt = sum_sqrt + pow(A[i],2);
    double mean = sum/N;
    B[1] = sqrt((sum_sqrt/N) - pow(mean,2)); /*Standard Deviation*/
    
    double s = 1;
    for(int i = 0;i < N;i++) s *= A[i];
    B[2] = pow(s,1.0/N); /*Geometric Mean*/ 

    for(int i = 0;i < N;i++) B[3] += 1/A[i];
    B[3] = N / B[3]; /*Harmonic Mean*/

    for(int i = 0;i < N;i++){
        if (A[i] > B[4]){
            B[4] = A[i];
        }
    } /*Max*/

    B[5] = A[0];
    for(int i = 0;i < N;i++){
        if (B[5] < A[i]){
            continue;
        }else{
            B[5] = A[i];
        }
    } /*Min*/
}
