//Phần 2 (Lập trình hướng đối tượng C++). Tự xây dựng một lớp (class) Graph cho đồ thị 
//(vô hướng hoặc có hướng). Graph object bao gồm Data members (dữ liệu, thuộc tính), và 
//Members functions (các hàm, phương thức). Lớp Graph có các hàm đọc dữ liệu từ file input (
//có thể có các option như là ma trận kề, danh sách kề, etc), có các hàm in ra/tìm bậc của một 
//đỉnh trong đồ thị, hàm tìm/in ra tất cả các đỉnh kề của đỉnh v nào đó (v là input của hàm), 
//có hàm in ra số đỉnh, số cạnh của đồ thị. Ngoài ra có thể tự thêm các chức năng khác/hàm cho lớp Graph.
#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
	private:
		int n;
		int a[30][30];
	public:
		Graph();
		void inMaTranKe();
		void docMaTranKe(string tenFile);
		void docDSKe(string tenFile);
		void docDSCanh(string tenFile);
		int timBac(int);
		void timDinhKe(int);
		int soDinh();
		int soCanh();
};
Graph::Graph()
{
	n=0;
	for(int i = 1; i<= n; i++)
	{
    	for(int j = 1; j <= n; i++)
    	{  
        	a[i][j] = 0;
    	}
	}
}
void Graph::inMaTranKe()
{
	cout<<"MA TRAN KE"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}

void Graph::docMaTranKe(string tenFile)
{
	fstream file;
	file.open(tenFile,ios::in);
	if(file.fail())
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
	file>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			file>>a[i][j];
	}
	file.close();
}
void Graph::docDSKe(string tenFile)
{
	fstream file;
	string s; 
	file.open(tenFile,ios::in);
	if(file.fail())
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
	getline(file,s);
	n=s[0]-48;
	for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++)
            a[i][j] = 0;
    int i=0,j=0;  
    int m;
	while(!file.eof())
	{
		getline(file,s);
		i=s[0]-48;
		for (int k = 1; k < s.length(); k++){
			if (s[k] <= '9' && s[k] >= '1' ){
                m=s[k] - 48;
                a[i][m] = 1;
            }  
		}
    }
}
void Graph::docDSCanh(string tenFile)
{
	fstream file;
	file.open(tenFile,ios::in);
	if(file.fail())
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
    int g,h;
	file>>n;
	for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++)
            a[i][j] = 0;
	while(!file.eof())
	{
		file>>g;
		file>>h;
		a[g][h]=1;
		a[h][g]=1;
	}
}
int Graph::timBac(int b)
{
	for (int i = 1; i <= n; i++)
	{
        int sum= 0;
        for (int j = 1; j <= n; j++) 
			if (a[i][j] == 1) 
				sum++;
		if(i==b)
			return sum;
    }
}
void Graph::timDinhKe(int b)
{
	cout<<"Cac dinh ke dinh "<<b<<" :\t";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1 && i==b)
			{
				cout<<j<<"\t";
			}
		}	
	}
}
int Graph::soDinh()
{
	return n;
}
int Graph::soCanh()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=timBac(i);
	return sum;
}
int main()
{
	
	cout<<"MENU"<<endl;
	cout<<"1. In ma tran ke"<<endl;
	cout<<"2. Tim bac cua dinh"<<endl;
	cout<<"3. Tim dinh ke cua mot dinh"<<endl;
	cout<<"4. So dinh cua do thi"<<endl;
	cout<<"5. So canh cua do thi"<<endl;
	cout<<"6. Thoat"<<endl;
	int q;
	
	do
	{
		do
		{
			cout<<"Nhap lua chon: ";
			cin>>q;
		}while(q>6 || q<1);
		Graph d;
		d.docMaTranKe("input1.txt");
		switch(q)
		{
			case 1:
			{
				d.inMaTranKe();
				break;
			}
			case 2:
				{
					int f;
					do
					{
						cout<<"Nhap dinh can tim: ";
						cin>>f;
					}while(f<0||f>d.soDinh());
					cout<<"Bac cua dinh "<<f<<" la: "<<d.timBac(f)<<endl;
					break;
				}
			case 3:
				{
					int f;
					do
					{
						cout<<"Nhap dinh can tim: ";
						cin>>f;
					}while(f<0||f>d.soDinh());
					d.timDinhKe(f);
					cout<<endl;
					break;
				}
			case 4:
				{
					cout<<"So dinh cua do thi: "<<d.soDinh()<<endl;
					break;
				}
			case 5:
				{
					cout<<"So canh cua do thi: "<<d.soCanh()<<endl;
					break;
				}
			default : return 0;
		}
	}while(q!=6);
}