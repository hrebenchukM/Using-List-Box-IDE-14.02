#pragma once
#include "header.h"
#include <iostream>
#include <vector>	
#include <string>
using namespace std;

class UsingListboxDlg
{
private:
	vector<wstring> items1;
	vector<wstring> items2;

public:
	UsingListboxDlg(void);

	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);

	static UsingListboxDlg* ptr;
	HWND hDialog, hEdit1, hEdit2, hList1, hList2,hEdit3, hSaveButton;

	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
};
