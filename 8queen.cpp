#include<iostream>
using namespace std;
int a[8][8];
int Ans(int x,int y,int *b)
{
	int m=0;
	for(int i=x,j=y;i<=7&&j<=7;++i,++j)
	{
		m+=b[i][j];
	}
	
	for(int i=x,j=y;i>=0&&j>=0;--i,--j)
	{
		m+=b[i][j];
	}
	return m-b[x][y];
}

int Bns(int x,int y,int b[8][8])
{
	int m=0;
	for(int i=x,j=y;i<=7&&j>=0;++i,--j)
	{
		m+=b[i][j];
	}
	
	for(int i=x,j=y;i>=0&&j<=7;--i,++j)
	{
		m+=b[i][j];
	}
	return m-b[x][y];
}
int main(){
    for(int i=0;i<=7;i++){
        for(int j=0;j<=7;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int m1,m2,n1,n2;
    cin>>m1>>m2>>n1>>n2;
    m1=Ans(m1-1,m2-1,a);
    m2=Bns(m1-1,m2-1,a);
    cout<<m1<<" "<<m2;
    return 0;   
}