#include<iostream>
#include<fstream>
using namespace std;
void Readfile(int a[20][20],int &n, string file){
	fstream FileIn;
	FileIn.open(file, ios::in);
	FileIn >> n;
		for(int i=0; i<n; i++){
			for(int j=0;j<n;j++){
				FileIn>>a[i][j];
			}
		}
	FileIn.close();
}
void PrintFile(int a[20][20],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void GhiMaTranKe(int a[20][20], int n,string file){
	fstream FileOut;
	FileOut.open(file,ios::out)
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				FileOut<<i<<","<<j<<"	";
			}
		}
		FileOut<<endl;
	}
	FileOut.close();
}
void DanhSachCanh(int a[20][20],int n,string file){
	fstream fileout;
    fileout.open(file, ios::out);
    for (int i = 1; i <= n; i++){
        cout << endl;
        for (int j = i+1; j <= n; j++){
            if (a[i][j] == 1) fileout << i << "\t" << j << endl;
        }
    }
    fileout.close();
}
int main(){
	int a[20][20],n;
	Readfile(a, n, "input1.txt");
	PrintFile(a,n);
	GhiMaTranKe(a,n,"input1_1.txt");
	DanhSachCanh(a,n,"input1_2.txt");
	return 0;
}