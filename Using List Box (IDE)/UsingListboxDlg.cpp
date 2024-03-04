#include "UsingListboxDlg.h"
#include <iostream>
#include <vector>	
#include <string>
 
//2 ����� ��������� ������� �������� ����� ������ �� ����� �������� � �������� �������������� ���������� .�������� ����� �������������.
// ����� �������� ��������� �� ����������� � � ������� � ��������� .
using namespace std;





vector<TCHAR> buffer; // ���������� ���������� buffer 
UsingListboxDlg* UsingListboxDlg::ptr = NULL;

UsingListboxDlg::UsingListboxDlg(void)
{
	ptr = this;
}

void UsingListboxDlg::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL UsingListboxDlg::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) 
{
	//1 ������� ������ �������� ����������� ���� ������ ��������� � ��� � ����� ��� �������� � ���� ������� ���������� �������� .
	//  ��� ������ ���������� � ����������� ������
	




	//// ������� ����������� ��������� ����������
	//hList1 = GetDlgItem(hwnd, IDC_LIST1);
	//hList2 = GetDlgItem(hwnd, IDC_LIST2);
	//hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
	//hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);

	//// ������� 8 ��������� � ������ � ��������� �������
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("����� ������")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("��������� ������")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("������� ��������")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("��������� �������")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("������� ������")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("���� �������")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("����� ������")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("���� �������")));

	//// ��������� ������ ������� ��� ������ � ������������� �������
	//SendMessage(hList2, LB_SETCOLUMNWIDTH, 170, 0);

	//// ������� 8 ��������� � ������ � ������������� �������
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("���� ������")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("��������� ������� ������")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("������ ��������")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("�������� �������")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("����� ������")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("������� �������")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("������� ������")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("�������� �������")));
	//



	items1.push_back(TEXT("����� ������"));
	items1.push_back(TEXT("��������� ������"));
	items1.push_back(TEXT("������� ��������"));
	items1.push_back(TEXT("��������� �������"));
	items1.push_back(TEXT("������� ������"));
	items1.push_back(TEXT("���� �������"));
	items1.push_back(TEXT("����� ������"));
	items1.push_back(TEXT("���� �������"));

	
	items2.push_back(TEXT("���� ������"));
	items2.push_back(TEXT("��������� ������� ������"));
	items2.push_back(TEXT("������ ��������"));
	items2.push_back(TEXT("�������� �������"));
	items2.push_back(TEXT("����� ������"));
	items2.push_back(TEXT("������� �������"));
	items2.push_back(TEXT("������� ������"));
	items2.push_back(TEXT("�������� �������"));


	hList1 = GetDlgItem(hwnd, IDC_LIST1);
	hList2 = GetDlgItem(hwnd, IDC_LIST2);
	hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
	hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
	hEdit3 = GetDlgItem(hwnd, IDC_EDIT3);
	hSaveButton = GetDlgItem(hwnd, IDC_FIND2);


	for (const auto& item : items1) {
		SendMessage(hList1, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>(item.c_str()));
	}

	for (const auto& item : items2) {
		SendMessage(hList2, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>(item.c_str()));
	}


	return TRUE;

}

void UsingListboxDlg::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id)
	{
	case IDCANCEL:
		EndDialog(hwnd, 0);
		break;

	case IDC_ADD: 
		{
			// ��������� ����� ������ (�������� �����), ��������� � ��������� ����
			int length = SendMessage(hEdit1, WM_GETTEXTLENGTH, 0, 0);
			// ������� ������ ������������ �������
			TCHAR *pBuffer = new TCHAR[length + 1];
			// � ���������� ������ ��������� �����, �������� � �������� ����
			GetWindowText(hEdit1, pBuffer, length + 1);
			if(lstrlen(pBuffer))
			{
				// �������, ������� �� ��� � ������ �������� �������� ����� 
				int index = SendMessage(hList1, LB_FINDSTRINGEXACT, -1, LPARAM(pBuffer));
				if(index == LB_ERR)
					// ������� �������� ����� � ������
					SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(pBuffer));
				else
					MessageBox(hwnd, TEXT("����� ���� ��� ����������!"), TEXT("���������� �����"), MB_OK | MB_ICONSTOP);
			}
			delete[] pBuffer;
		}
		break;
	case IDC_DEL:
		{
			// ������� ������ ���������� �������� ������
			int index = SendMessage(hList1, LB_GETCURSEL, 0, 0);
			if(index != LB_ERR) // ������ �� ������� ������?
			{
				// ��������� ����� �������� ���������� �����
				int length = SendMessage(hList1, LB_GETTEXTLEN, index, 0);
				// ������� ������ ������������ �������
				TCHAR *pBuffer = new TCHAR[length + 1];
				// ��������� �������� ����� � ���������� ������
				SendMessage(hList1, LB_GETTEXT, index, LPARAM(pBuffer));
				MessageBox(hwnd, pBuffer, TEXT("�������� �����"), MB_OK | MB_ICONINFORMATION);
				// ������ ������ �� ������
				SendMessage(hList1, LB_DELETESTRING, index, 0);
			
				// ������ �������� ����� �� �������
				if (index < items1.size()) {
					items1.erase(items1.begin() + index);
				}

				delete[] pBuffer;
			}
			else
				MessageBox(hwnd, TEXT("���� �� ������!"), TEXT("�������� �����"), MB_OK | MB_ICONSTOP);
		}
		break;
	case IDC_FIND:
		{
			// ��������� ����� �������� ��������, ��������� � ��������� ����
			int length = SendMessage(hEdit2, WM_GETTEXTLENGTH, 0, 0);
			// ������� ������ ������������ �������
			TCHAR *pBuffer = new TCHAR[length + 1];
			// ��������� �������� ����� � ���������� ������
			GetWindowText(hEdit2, pBuffer, length + 1);
			if(lstrlen(pBuffer))
			{
				// ���������, ������� �� � ������ ������� �������� �����
				int index = SendMessage(hList1, LB_SELECTSTRING, -1, LPARAM(pBuffer));
				if(index == LB_ERR)
					MessageBox(hwnd, TEXT("���� �� ������!"), TEXT("����� �����"), MB_OK | MB_ICONSTOP);
			}
			delete[] pBuffer;
		}
		break;
	case IDC_DELALL:
		// ������� ���������� ������
		SendMessage(hList1, LB_RESETCONTENT, 0, 0);
		// ������� ������ ���������
		items1.clear();
		break;
	case IDC_GETSELITEMS:
		{
			// ��������� ���������� ��������� ��������� � ������ � ������������� �������
			int nCount = SendMessage(hList2, LB_GETSELCOUNT, 0, 0);
			// ������� ������ ������������ ������� ��� �������� �������� ��������� ��������� ������
			int *p = new int[nCount];
			// �������� ������������ ������ ��������� ���������� ��������� ������ 
			SendMessage(hList2, LB_GETSELITEMS, nCount, LPARAM(p));
			for(int i = 0; i < nCount; i++)
			{
				// ��������� ������ ������ �������� ������
				int length = SendMessage(hList2, LB_GETTEXTLEN, p[i], 0);
				// ������� ������ ������������ �������
				TCHAR *pBuffer = new TCHAR[length + 1];
				// � ���������� ������ ��������� ����� ���������� �������� ������
				SendMessage(hList2, LB_GETTEXT, p[i], LPARAM(pBuffer));
				MessageBox(hwnd, pBuffer, TEXT("������ � ������������� �������"), MB_OK | MB_ICONINFORMATION);
				delete[] pBuffer;
			}
		}
		break;
	case IDC_LIST1:
		if (codeNotify == LBN_SELCHANGE)
		{
			int index = SendMessage(hList1, LB_GETCURSEL, 0, 0);
			if (index != LB_ERR)
			{
				int length = SendMessage(hList1, LB_GETTEXTLEN, index, 0);
				TCHAR* pBuffer = new TCHAR[length + 1];
				SendMessage(hList1, LB_GETTEXT, index, LPARAM(pBuffer));
				SetWindowText(hEdit3, pBuffer);
				delete[] pBuffer;
			}
		}
		break;
	case IDC_FIND2:
	{
		int selectedIndex = SendMessage(hList1, LB_GETCURSEL, 0, 0);
		if (selectedIndex != LB_ERR)
		{
			int length = GetWindowTextLength(hEdit3);
			buffer.resize(length +1 ); // ��������� ������� ������
			GetWindowText(hEdit3, buffer.data(), length + 1);

			if (selectedIndex < items1.size())
			{
				items1[selectedIndex] = buffer.data();
				SendMessage(hList1, LB_DELETESTRING, selectedIndex, 0); // �������� ������ ������
				SendMessage(hList1, LB_INSERTSTRING, selectedIndex, LPARAM(buffer.data())); // ������� ����� ������ � ������������ �������
			}

			MessageBox(hwnd, TEXT("��������� ���������!"), TEXT("���������� ���������"), MB_OK | MB_ICONINFORMATION);

		}
	}
	break;
}
	






	// � ������ � ��������� ������� ������� ����� ��� ������
	if(id == IDC_LIST1 && codeNotify == LBN_SELCHANGE)
	{
		// ������� ������ ���������� �������� ������
		int index = SendMessage(hList1, LB_GETCURSEL, 0, 0);
		if(index != LB_ERR) // ������ �� ������� ������?
		{
			// ��������� ����� �������� �����
			int length = SendMessage(hList1, LB_GETTEXTLEN, index, 0);
			// ������� ������ ������������ �������
			TCHAR *pBuffer = new TCHAR[length + 1];
			// � ���������� ������ ��������� ����� ���������� �������� ������
			SendMessage(hList1, LB_GETTEXT, index, LPARAM(pBuffer));
			// ��������� ����� � ��������� �������� ����
			SetWindowText(hwnd, pBuffer);
			delete[] pBuffer;
		}
	}
}

BOOL CALLBACK UsingListboxDlg::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}