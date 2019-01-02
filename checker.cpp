// checker-practice4.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
#include <iostream>
#include <fstream> //要開啟檔案時用的標頭檔
#include <Windows.h>
#include <cmath>
using namespace std;
void read();
//void aims_coordinate(); //目標的座標範圍
void kind_my_another();//分辨敵我方
void search(); //找棋子的位置
void choose_chess(int x_destination, int y_destination);  //指定這一局要移動的座標並輸出，指定棋子與目的地座標的距離
const int N = 17;
int A[N][N];
//char coordinate[15][15];
HWND hwnd;
int Color_Name;//棋子的顏色

struct Chess 
{
	int x; //棋子的x座標
	int y; //棋子的y座標
	int c; //顏色
};
struct Chess my_checker[15];//存放自己棋子所在位置的座標的陣列
struct Chess another_checker[15];//存放敵方棋子所在位置的座標的陣列


void read()  //讀取棋盤
{
	ifstream board; //建立可讀的檔案物件
	board.open("board.txt");
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			board >> A[i][j];
		}
	}
	board.close();
}

/*void aims_coordinate()
{
	if (Color_Name == 2) {
		int coordinate[15][15] = { {12,4},{12,5},{12,6},{12,7},{12,8},{13,4},{13,5},{13,6},{13,7},{14,4},{14,5},{14,6},{15,4},{15,5},{16,4} };
	}
}*/

void kind_my_another()
{
	int my = 0;
	int another=0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (A[i][j]== Color_Name) {
				my_checker[my].x=i;//把i放入struct的x裡
				my_checker[my].y=j;//把j放入struct的y裡
				my_checker[my].c = Color_Name;
			}
			else if ((A[i][j] != 0) && (A[i][j] != 1)) {
				my_checker[another].x = i;//把i放入struct的x裡
				my_checker[another].y = j;//把j放入struct的y裡
			}
		}
	}
}

void search() 
{
	for (int i = 0; i < 15; i++) {
		int x;
		int y;
		x = my_checker[i].x; //把struct裡面的位置取出來，放入x裡
		y = my_checker[i].y;  //把struct裡面的位置取出來，放入y裡
	}
}


void choose_chess(int x_destination, int y_destination) //選定要下的棋子，把座標輸出"1072016.txt"裡，且換行
{
	int x = 0;
	int y = 0;
	int m = 0;
	int n = 0;
	double r = 0.0; //棋子與所要下的目標的距離
	double r_min = 9999.0; //距離最小
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (A[i][j] == Color_Name) {
				//---選一個棋子的過程----//
				for (int b = (-1); b <= 1; b++) {
					for (int a = (-1); a <= 1; a++) {
						if ((a != 1 && b != (-1)) || (a != (-1) && b != 1)) {
							if (A[i + a][j + b] == 1) {
								r = sqrt(pow((x_destination - (i + a)), 2) + pow((y_destination - (j + b)), 2));
								if (r_min > r) {
									r_min = r;
									m = i;
									n = j;
									x = i + a;
									y = j + b;
								}
								else if(A[i + a][j + b] != 0){
									for (int c = (-1); c <= 1; c++) {
										for (int d = (-1); d <= 1; d++) {
											if ((a != 1 && b != (-1)) || (a != (-1) && b != 1)) {
												if (A[i + a + c][j + b + d] == 1) {
													r = sqrt(pow((x_destination - (i + a + c)), 2) + pow((y_destination - (j + b + d)), 2));
													if (r_min > r) {
														r_min = r;
														m = i;
														n = j;
														x = i + a + c;
														y = j + b + d;
													}
												}
											}
										}
									}
								}
								else {
									continue;
								}
							}
						}
					}
				}
			}
			else {
				continue;
			}
		}
	}
	fstream file;
	file.open("1072016.txt", ios::out | ios::app);
	file << m << " " << n << "\n"; //將這局要下的棋子座標寫入檔案
	file << x << " " << y << "\n"; //將這局要下的棋子要移動的座標寫入檔案
	file.close();
}

int main()
{
	cin >> Color_Name;
	read();
	kind_my_another();
	search();
	if (Color_Name == 2) {  //red
		choose_chess(16, 4);
	}
	else if (Color_Name == 3) {  //green
		choose_chess(4, 16);
	}
	else { //yellow
		choose_chess(4, 4);
	}
}
   

