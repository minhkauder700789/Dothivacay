#include<iostream>
#include<conio.h>
#include<io.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
using namespace std;
//Doc File de lay so Dinh va ma tran Ke
void Init(int G[][MAX], int *n){
	FILE *fp;
	fp=fopen("DFS.txt","r");
	if(fp == NULL){
		cout<<"\n Khong the mo duoc file!!!!";
		return;
	}
	fscanf(fp,"%d",n);
	//Lay so Dinh tu do thi trong file
	cout<<"\n So dinh Do thi: "<<*n;
	cout<<"\n Ma tran ke cua Do thi: ";
	for(int i=1;i<=*n;i++){
		cout<<"\n";
		for(int j=1;j<=*n;j++){
			fscanf(fp,"%d",&G[i][j]);
			cout<<". "<<G[i][j];
		}
	}
}
//Thuat toan tim kiem chieu sau
void DFS (int G[][MAX],int n, int v,int chuaxet[]){
	getch();
	cout<<" "<<v;
	chuaxet[v] = FALSE;
	for(int u=1;u<=n;u++){
		if(G[v][n]==1&&chuaxet[u])
			DFS(G,n,u,chuaxet);
	}
}
int main(){
	int G[MAX][MAX],n,chuaxet[MAX];
	Init(G,&n);
	for(int i=1;i<=n;i++)
		chuaxet[i]=TRUE;
	cout<<"\n \n";
	for(int i=1;i<=n;i++)
		if(chuaxet[i])
			DFS(G,n,i,chuaxet);
	getch();
	return 0;
}