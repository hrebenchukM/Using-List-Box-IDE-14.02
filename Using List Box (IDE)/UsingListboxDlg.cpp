#include "UsingListboxDlg.h"
#include <iostream>
#include <vector>	
#include <string>
 
//2 Когда выбираете элемент например Милан Италия он сразу попадает в листбокс редактирования передается .Название можно редактировать.
// Когда нажимаем сохранить то сохраняется и в векторе и визуально .
using namespace std;





vector<TCHAR> buffer; // Объявление переменной buffer 
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
	//1 Сделать вектор стрингов рефакторинг либо вектор встрингов и уже в цикле все передать в єтот єлемент управления листбокс .
	//  Все должно сохранятся в оперативной памяти
	




	//// получим дескрипторы элементов управления
	//hList1 = GetDlgItem(hwnd, IDC_LIST1);
	//hList2 = GetDlgItem(hwnd, IDC_LIST2);
	//hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
	//hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);

	//// добавим 8 элементов в список с единичным выбором
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Милан Италия")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Ливерпуль Англия")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Бавария Германия")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Барселона Испания")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Арсенал Англия")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Лион Франция")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Интер Италия")));
	//SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(TEXT("Реал Испания")));

	//// установим ширину колонки для списка с множественным выбором
	//SendMessage(hList2, LB_SETCOLUMNWIDTH, 170, 0);

	//// добавим 8 элементов в список с множественным выбором
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Рома Италия")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Манчестер Юнайтед Англия")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Вердер Германия")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Валенсия Испания")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Челси Англия")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Марсель Франция")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Ювентус Италия")));
	//SendMessage(hList2, LB_ADDSTRING, 0, LPARAM(TEXT("Атлетико Испания")));
	//



	items1.push_back(TEXT("Милан Италия"));
	items1.push_back(TEXT("Ливерпуль Англия"));
	items1.push_back(TEXT("Бавария Германия"));
	items1.push_back(TEXT("Барселона Испания"));
	items1.push_back(TEXT("Арсенал Англия"));
	items1.push_back(TEXT("Лион Франция"));
	items1.push_back(TEXT("Интер Италия"));
	items1.push_back(TEXT("Реал Испания"));

	
	items2.push_back(TEXT("Рома Италия"));
	items2.push_back(TEXT("Манчестер Юнайтед Англия"));
	items2.push_back(TEXT("Вердер Германия"));
	items2.push_back(TEXT("Валенсия Испания"));
	items2.push_back(TEXT("Челси Англия"));
	items2.push_back(TEXT("Марсель Франция"));
	items2.push_back(TEXT("Ювентус Италия"));
	items2.push_back(TEXT("Атлетико Испания"));


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
			// определим длину текста (названия клуба), введённого в текстовое поле
			int length = SendMessage(hEdit1, WM_GETTEXTLENGTH, 0, 0);
			// выделим память необходимого размера
			TCHAR *pBuffer = new TCHAR[length + 1];
			// в выделенную память скопируем текст, введённый в тестовое поле
			GetWindowText(hEdit1, pBuffer, length + 1);
			if(lstrlen(pBuffer))
			{
				// уточним, имеется ли уже в списке введённое название клуба 
				int index = SendMessage(hList1, LB_FINDSTRINGEXACT, -1, LPARAM(pBuffer));
				if(index == LB_ERR)
					// добавим название клуба в список
					SendMessage(hList1, LB_ADDSTRING, 0, LPARAM(pBuffer));
				else
					MessageBox(hwnd, TEXT("Такой клуб уже существует!"), TEXT("Добавление клуба"), MB_OK | MB_ICONSTOP);
			}
			delete[] pBuffer;
		}
		break;
	case IDC_DEL:
		{
			// получим индекс выбранного элемента списка
			int index = SendMessage(hList1, LB_GETCURSEL, 0, 0);
			if(index != LB_ERR) // выбран ли элемент списка?
			{
				// определим длину названия выбранного клуба
				int length = SendMessage(hList1, LB_GETTEXTLEN, index, 0);
				// выделим память необходимого размера
				TCHAR *pBuffer = new TCHAR[length + 1];
				// скопируем название клуба в выделенную память
				SendMessage(hList1, LB_GETTEXT, index, LPARAM(pBuffer));
				MessageBox(hwnd, pBuffer, TEXT("Удаление клуба"), MB_OK | MB_ICONINFORMATION);
				// удалим строку из списка
				SendMessage(hList1, LB_DELETESTRING, index, 0);
			
				// удалим название клуба из массива
				if (index < items1.size()) {
					items1.erase(items1.begin() + index);
				}

				delete[] pBuffer;
			}
			else
				MessageBox(hwnd, TEXT("Клуб не выбран!"), TEXT("Удаление клуба"), MB_OK | MB_ICONSTOP);
		}
		break;
	case IDC_FIND:
		{
			// определим длину искомого названия, введённого в текстовое поле
			int length = SendMessage(hEdit2, WM_GETTEXTLENGTH, 0, 0);
			// выделим память необходимого размера
			TCHAR *pBuffer = new TCHAR[length + 1];
			// скопируем название клуба в выделенную память
			GetWindowText(hEdit2, pBuffer, length + 1);
			if(lstrlen(pBuffer))
			{
				// определим, имеется ли в списке искомое название клуба
				int index = SendMessage(hList1, LB_SELECTSTRING, -1, LPARAM(pBuffer));
				if(index == LB_ERR)
					MessageBox(hwnd, TEXT("Клуб не найден!"), TEXT("Поиск клуба"), MB_OK | MB_ICONSTOP);
			}
			delete[] pBuffer;
		}
		break;
	case IDC_DELALL:
		// очистим содержимое списка
		SendMessage(hList1, LB_RESETCONTENT, 0, 0);
		// очистим массив элементов
		items1.clear();
		break;
	case IDC_GETSELITEMS:
		{
			// определим количество выбранных элементов в списке с множественным выбором
			int nCount = SendMessage(hList2, LB_GETSELCOUNT, 0, 0);
			// выделим память необходимого размера для хранения индексов выбранных элементов списка
			int *p = new int[nCount];
			// Заполним динамический массив индексами выделенных элементов списка 
			SendMessage(hList2, LB_GETSELITEMS, nCount, LPARAM(p));
			for(int i = 0; i < nCount; i++)
			{
				// определим размер текста элемента списка
				int length = SendMessage(hList2, LB_GETTEXTLEN, p[i], 0);
				// выделим память необходимого размера
				TCHAR *pBuffer = new TCHAR[length + 1];
				// в выделенную память скопируем текст выбранного элемента списка
				SendMessage(hList2, LB_GETTEXT, p[i], LPARAM(pBuffer));
				MessageBox(hwnd, pBuffer, TEXT("Список с множественным выбором"), MB_OK | MB_ICONINFORMATION);
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
			buffer.resize(length +1 ); // Изменение размера буфера
			GetWindowText(hEdit3, buffer.data(), length + 1);

			if (selectedIndex < items1.size())
			{
				items1[selectedIndex] = buffer.data();
				SendMessage(hList1, LB_DELETESTRING, selectedIndex, 0); // Удаление старой строки
				SendMessage(hList1, LB_INSERTSTRING, selectedIndex, LPARAM(buffer.data())); // Вставка новой строки с обновленными данными
			}

			MessageBox(hwnd, TEXT("Изменения сохранены!"), TEXT("Сохранение изменений"), MB_OK | MB_ICONINFORMATION);

		}
	}
	break;
}
	






	// в списке с единичным выбором текущий выбор был изменён
	if(id == IDC_LIST1 && codeNotify == LBN_SELCHANGE)
	{
		// получим индекс выбранного элемента списка
		int index = SendMessage(hList1, LB_GETCURSEL, 0, 0);
		if(index != LB_ERR) // выбран ли элемент списка?
		{
			// определим длину названия клуба
			int length = SendMessage(hList1, LB_GETTEXTLEN, index, 0);
			// выделим память необходимого размера
			TCHAR *pBuffer = new TCHAR[length + 1];
			// в выделенную память скопируем текст выбранного элемента списка
			SendMessage(hList1, LB_GETTEXT, index, LPARAM(pBuffer));
			// установим текст в заголовок главного окна
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