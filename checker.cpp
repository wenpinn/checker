// checker.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
const int N=17;
int A[N][N];
void readboard(int A[N][N]);
void showBoard();
void go();
void main()
{

	readboard(A);
	showBoard();
	go();
}

void readboard(int A[N][N])
{
	ifstream file;
	file.open("board.txt");
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			file>>A[i][j];
		}
		file.close();

}
void go()
{
	char A[1024];
	cin>>A;

}
void showBoard()
{
	HWND hwnd=CreateWindow(L"static", L"wp",WS_VISIBLE|WS_BORDER|WS_OVERLAPPED,10,10,1024,768,0,0,0,0);
	ShowWindow(hwnd,SW_SHOW);
	HDC hdc=GetDC(hwnd);
	double l=50;
	double dx=l*cos(60*3.14159/180.);
	double dy=l*sin(60*3.14159/180.);
	int Ox=100;
	int Oy=100;
	int r=20;
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			int x=Ox+(2*i+j)*dx;
			int y=Oy+j*dy;
			if(A[i][j]>0)
				Ellipse(hdc,x-r,y-r,x+r,y+r);

		}
}