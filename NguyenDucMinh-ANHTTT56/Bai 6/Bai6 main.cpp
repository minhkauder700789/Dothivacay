#include <iostream>
#include <fstream>
using namespace std;

void ReadFile(){
    fstream file;
    file.open("input2_1.txt", ios::in); 
    string str;
    int i = 0 , j = 0, a[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            a[i][j] = 0;
    while (!file.eof()){
        i++;
        cout << i << " | ";
        j = 0;
        getline(file, str); //doc hang dau tien
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
    file.close();
    file.open("output2_1.txt", ios::out);
    int  b[20][20];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            b[i][j] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != 0) {
                b[i][(a[i][j])] = 1;
            }
        }
    }
    file << "Ma tran ke: \n";
    for (int  i = 1; i <= n; i++){
        file << endl;
        for (int j = 1; j <= n; j++)
            file << b[i][j] << "  ";
    }
    file << "\n\nDanh sach canh:\n";
    file << "Dau\tCuoi\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (b[i][j] == 1) file << i << "\t" << j << endl;
        }
    }

    file << "\nBac cua tung dinh: \n";
    int d[10];
    for (int i = 1; i <= 10; i++) d[i] = 0;
    for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++) if (b[i][j] == 1) {
        d[i]++;
        d[j]++;
    }
    }
    for (int i = 1; i <= 5; i++) file << "Bac dinh " << i  << " : " << d[i] << endl;
     file.close();

}

int main()
{
    ReadFile();
    return 0;
}
