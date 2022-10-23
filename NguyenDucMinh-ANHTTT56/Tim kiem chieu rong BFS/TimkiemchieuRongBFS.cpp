#include<iostream>
#include<conio.h>
#include<io.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
using namespace std;
//Doc File de lay so Dinh va ma tran Ke
void Init(int G[][MAX], int *n, int *chuaxet){
	FILE *fp;
	fp=fopen("BFS.txt","r");
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
	for(int i=1;i<=*n;i++)
		chuaxet[i]=0;
	fclose(fp);
}
//Thuat toan tim kiem chieu rong BFS
void BFS( int G[][MAX], int n,int i, int chuaxet[], int QUEUE[MAX]){
	int u, dauQ, cuoiQ, j;
	dauQ=1;
	cuoiQ=1;
	QUEUE[cuoiQ]=i;
	chuaxet[i]=FALSE;
/* thiết lập hàng đợi với đỉnh đầu là i*/
	while(dauQ<=cuoiQ){
		u=QUEUE[dauQ];
		getch();
		cout<<" "<<u;
		dauQ=dauQ+1; /* duyệt đỉnh đầu hàng đợi*/
		for(j=1; j<=n;j++){
			if(G[u][j]==1 && chuaxet[j])
			{
				cuoiQ=cuoiQ+1;
				QUEUE[cuoiQ]=j;
				chuaxet[j]=FALSE;
			}
		}
	}
}
int main(){
	int G[MAX][MAX], n, chuaxet[MAX], QUEUE[MAX], i;
	Init(G, &n, chuaxet); cout<<"\n\n";
	for(i=1; i<=n; i++)
		chuaxet[i]= TRUE;
	for(i=1; i<=n; i++)
		if (chuaxet[i])
			BFS(G, n, i, chuaxet, QUEUE);
	getch();
	return 0;
}