#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

int i;
void stat(const double A[],int N,double B[]){
    double B0=0,sum = 0, mean, standardDeviation = 0,Geo=1,Harmonic=0,Max=A[0],Min=A[0];
    for(i = 0;i < N;i++){
        B0 = B0+A[i];
        sum = sum+A[i];
        Geo = Geo*A[i]; 
        Harmonic = Harmonic+(1/A[i]);
        if(A[i]>Max) Max = A[i];
        if(A[i]<Min) Min = A[i];
    }
    mean = sum / N;
    for(i = 0;i < N;i++){
        standardDeviation =standardDeviation + pow(A[i] - mean, 2);
    }
    B[0] = B0/N;
    B[1] = sqrt(standardDeviation / N);
    B[2] = exp(log(Geo)/N);
    B[3] = N/Harmonic;
    B[4] = Max;
    B[5] = Min;
}