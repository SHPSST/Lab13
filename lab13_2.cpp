#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool image[N][M],int s,int x,int y){
    for (int i = 0;i < N;i++){
        for (int j = 0;j < M;j++){
            if(pow(pow(i-x,2)+pow(j-y,2),0.5)<=s-1){
            image[i][j]=1;
            }
        }
    }
}
void showImage(const bool image[N][M]){
    for (int i = 0;i < N+1;i++){
        if(i==0){for (int j = 0;j < M+2;j++){
            cout << "-";
        }
        cout << endl;}
        if(i>0){for (int k=0;k < M+2;k++){
            if(k==0)cout << "|";
            else if(k<=M){
                if (image[i - 1][k - 1] == 1)cout << "*";
                else cout << " ";
            }
            else cout << "|";
        }
        cout << endl;}
    }
    for (int j = 0;j < M+2;j++){
            cout << "-";
    }
    cout << endl;
}
