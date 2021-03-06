// GTS1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#define MAX 100
using namespace std;
#pragma warning(disable:4996)
struct GRAPH
{
	int n;
	int a[MAX][MAX];
	char label[MAX][20];
};
bool docfile(GRAPH& g) {
	FILE *f;
	f = fopen("input.txt", "rt");
	fscanf(f, "%d", &g.n);
	for (int i = 0; i < g.n; i++)
		fscanf(f, "%s", &g.label[i]);
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			fscanf(f, "%d", &g.a[i][j]);
	return true;
}
int xdDinhKeTiep(int vtDinhBatDau, GRAPH g, int w[])
{
	int duongNganNhat = INT_MAX;
	int vtDinhCanToi = 0;
	for (int vtDinhKetThuc = 0; vtDinhKetThuc < g.n; vtDinhKetThuc++)
		if (g.a[vtDinhBatDau][vtDinhKetThuc] < duongNganNhat && vtDinhBatDau != vtDinhKetThuc && w[vtDinhKetThuc] == 1)
		{
			duongNganNhat = g.a[vtDinhBatDau][vtDinhKetThuc];
			vtDinhCanToi = vtDinhKetThuc;
		}
	return vtDinhCanToi;
}
void gts1(int vtDinhBatDau, GRAPH g) {
	int cost = 0;
	int tour[100];
	int w[100];
	for (int i = 0; i < g.n; i++)
		w[i] = 1;
	w[vtDinhBatDau] = 0;
	int soDinhDaDiQua = 0;
	int vtDinhHienTai = vtDinhBatDau;
	int j = 0;
	tour[j++] = vtDinhBatDau;
	while (soDinhDaDiQua < g.n - 1)
	{
		int vtDinhKeTiep = xdDinhKeTiep(vtDinhHienTai, g, w);
		cost += g.a[vtDinhHienTai][vtDinhKeTiep];
		cout << g.label[vtDinhHienTai] << "->" << g.label[vtDinhKeTiep] << ":" << g.a[vtDinhHienTai][vtDinhKeTiep] << endl;
		vtDinhHienTai = vtDinhKeTiep;
		tour[j++] = vtDinhHienTai;
		w[vtDinhHienTai] = 0;
		soDinhDaDiQua++;
	}
	cout << g.label[vtDinhHienTai] << "->" << g.label[vtDinhBatDau] << ":" << g.a[vtDinhHienTai][vtDinhBatDau] << endl;
	cost += g.a[vtDinhHienTai][vtDinhBatDau];
	for (int i = 0; i < g.n; i++)
		cout << g.label[tour[i]] << " ";
	cout << endl;
	cout << "cost: " << cost << endl;
}
int main()
{
	GRAPH g;
	bool isRead = docfile(g);
	if (isRead)
	{
		cout << g.n << endl;
		for (int i = 0; i < g.n; i++)
			cout << g.label[i] << " ";
		cout << endl;
		for (int i = 0; i < g.n; i++)
		{
			for (int j = 0; j < g.n; j++)
				cout << g.a[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		cout << "Xu ly ham GTS1" << endl;
		int vtDinhBatDau = 3;
		gts1(vtDinhBatDau, g);
	}
	else
		cout << "Khong doc duoc file";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
