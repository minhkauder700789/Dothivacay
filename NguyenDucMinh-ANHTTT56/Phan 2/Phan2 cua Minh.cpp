#include<iostream>
#include<fstream>
using namespace std;
class Graph{
	private:
		int n;
		int a[20][20];
	public:
		Graph();
		void inMaTranKe();
		void docMaTranKe(string tenFile);
		void docDanhSachKe(string tenFile);
		void docDanhSachCanh(string tenFile);
		int timBac(int);
		void timDinhKe(int);
		int timSoDinh();
		int timSoCanh();
};
Graph::Graph(){
	n=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=0;
		}
	}
}
void Graph::inMaTranKe(){
	cout<<"MA TRAN KE:"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void Graph::docMaTranKe( string tenFile){
	fstream file;
	file.open(tenFile,ios::in);
	if(file.fail()){
		cout<<"Khong the mo duoc File";return;
	}
	file>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			file>>a[i][j];
		}
	}
	file.close();
}
void Graph::docDanhSachKe(string tenFile){
	fstream file;
	string s;string d;int m;
	file.open(tenFile,ios::in);
	if(file.fail()){
		cout<<"Khong the mo duoc file";return;
	}
	getline(file,s);
	n= s[0]-48;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	while(!file.eof()){
		for(int i=1;i<=n;i++){
			getline(file,d);
			for(int j=1;j<=n;j++){
				if( d[j] <= '9'&& d[j]>='1'){
					m = d[j] - 48;
					a[i][j] = m;
				}
			}
		}
	}
}
void Graph::docDanhSachCanh(string tenFile){
	fstream file;string s;
	file.open(tenFile,ios::in);
	if(!file.fail()){
		cout<<"Khong the mo File!!!";return;
	}
	getline(file,n);
	file>>s;n=s[0]-48;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	int g,h;
	while(!file.eof()){
		file>>g;
		file>>h;
		a[g][h]=1;
		a[h][g]=1;
	}
}
void Graph::timBac(int b){
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
				sum++;
			}
		}
		if(i==b){
			return sum;
		}
	}
}
void timDinhKe(int b){
	cout<<"Cac dinh ke voi dinh "<<b<<" la:";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1 && i==b){
				cout<< j<<"\t";
			}
		}
	}
}

