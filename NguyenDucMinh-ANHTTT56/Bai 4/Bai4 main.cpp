#include <iostream>
#include <fstream>
using namespace std;

void ReadFile(){
    fstream file;
    file.open("input1_2.txt", ios::in);
    string str;
    int i = 0 , j = 0, a[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            a[i][j] = 0;
    int n = 0;
    while (!file.eof()){
        file >> i >> j;
        if (i > n) n = i;
        if (j > n) n = j;
        a[i][j] = a[j][i] = 1;
    }
    cout << "n = " << n;
    file.close();
    file.open("output1_2.txt", ios::out);
    file << "Ma tran ke :\n";
    for (int  i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            file << a[i][j] << "  ";
        file << endl;
    }
    file << "\n\nDanh sach ke: \n";
    for (int i = 1; i <= n; i++){
        file << i << " | ";
        for (int j = 1; j <=n; j++){
            if (a[i][j] == 1) file << j << "\t";
        }
        file << endl;
    }

    file << "\nBac cua tung dinh: \n";
    for (int i = 1; i <= n; i++){
        file << "Bac cua dinh " << i << " : ";
        int d = 0;
        for (int j = 1; j <= n; j++) if (a[i][j] == 1) d++;
        file << d << endl;
    }
    file.close();
}

int main()
{
    ReadFile();
    return 0;
}
