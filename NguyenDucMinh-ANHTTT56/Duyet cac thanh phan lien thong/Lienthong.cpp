#include<iostream>
#include<conio.h>
#include<io.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
using namespace std;
//Đọc File để lấy số đỉnh và lấy ma trận kề
void Init(int G[][MAX],int *n, int *solt, int *chuaxet){
	FILE *fp;
	fp = fopen("lienthong.txt","r");
	if(fp==NULL){
		cout<<"\n Khong the mo File !!!!!!!";
		return;
	}
	fscanf(fp,"%d",n);
	//Lấy số đỉnh của đồ thị
	cout<<"\n So dinh cua do thi: "<<*n;
	cout<<"\n Ma tran ke cua do thi: ";
	for(int i=1;i<=*n;i++){
		cout<<" \n";
		for(int j=1;j<=*n;j++){
			fscanf(fp,"%d",&G[i][j]);
			cout<<". "<<G[i][j];
		}
	}
	for(int i=1;i<=*n;i++){
		chuaxet[i]=0;
	}
	*solt =0;
	fclose(fp);
}
void result(int *chuaxet, int n, int solt){
	cout<<"\n\n";
	if(solt == 1){
		cout<<"Do thi la lien thong";
		getch();
		return;
	}
	for(int i=1;i<=solt; i++){
		cout<<"Thanh phan lien thong thu "<<i<<":";
		for(int j=1;j<=n;j++){
			if(chuaxet[j]==i)
				cout<<" "<<j;
		}
		cout<<endl;
	}
}
void BFS( int G[][MAX], int n, int i, int *solt, int chuaxet[], int QUEUE[MAX]){
	int u, dauQ, cuoiQ, j;
	dauQ=1;
	cuoiQ =1;
	QUEUE[cuoiQ]=i;
	chuaxet[i]=*solt;
	while(dauQ<=cuoiQ){
		u = QUEUE[dauQ];
		cout<<" "<<u;
		dauQ=dauQ+1;
		for(int j=1;j<=n;j++){
			if(G[u][i]==1&&chuaxet[j]==0){
				cuoiQ=cuoiQ+1;
				QUEUE[cuoiQ]=j;
				chuaxet[j]=*solt;
			}
		}
	}
}
void LienThong(void){
	int G[MAX][MAX],n,chuaxet[MAX],QUEUE[MAX],solt,i;
	Init(G, &n,&solt, chuaxet);
	cout<<"\n\n";
	for(int i=1;i<=n;i++)
		if(chuaxet[i]==0){
			solt = solt+1;
			BFS(G,n,i,&solt,chuaxet,QUEUE);
		}
	result(chuaxet,n,solt);
	getch();
}
int main(){
	LienThong();
	return 0;
}