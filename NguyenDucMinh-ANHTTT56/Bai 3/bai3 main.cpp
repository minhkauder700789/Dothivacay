#include <iostream>
#include <fstream>
using namespace std;

void ReadFile(){
    fstream filein;
    filein.open("input1_1.txt", ios::in); 
    string str;
    int i = 0 , j = 0, a[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            a[i][j] = 0;
    while (!filein.eof()){
        i++;
        cout << i << " | ";
        j = 0;
        getline(filein, str); 
        for (int k = 1; k < str.length(); k++){
            if (str[k] <= '9' && str[k] >= '1' ){
                j++;
                a[i][j] = str[k] - 48;
                cout  << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    int n = i - 1;
    for (int  i = 1; i <= n; i++){
        cout << endl;
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << "  ";
    }
    filein.close();
    filein.open("output1_1.txt", ios::out);
    int  b[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            b[i][j] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != 0) {
                b[i][(a[i][j])] = 1;
                b[(a[i][j])][i] = 1;
            }
        }
    }
    filein << "Ma tran ke: \n";
    for (int  i = 1; i <= n; i++){
        filein << endl;
        for (int j = 1; j <= n; j++)
            filein << b[i][j] << "  ";
    }
    filein << "\n\nDanh sach canh:\n";
    filein << "Dau\tCuoi\n";
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (b[i][j] == 1) filein << i << "\t" << j << endl;
        }
    }

    filein << "\nBac cua tung dinh: \n";
    for (int i = 1; i <= n; i++){
        filein << "Bac cua dinh " << i << " : ";
        int d = 0;
        for (int j = 1; j <= n; j++) if (b[i][j] == 1) d++;
        filein << d << endl;
    }
    filein.close();


}

int main()
{
    ReadFile();
    return 0;
}