//Keith Mooney-k00224076
//16-Jan-2018
//Calculator project-Week 3

#define UNICODE  //support extended character sets

#include <windows.h>  //Holds all info and is properitary

LPCWSTR g_szClassName = L"myWindowClass"; //Wide string that will use Unicode. L signifies its a widestring. myWindowClass is user defined name

HWND hEdit;
#define IDC_BUTTON_1 101 //1
#define IDC_BUTTON_2 102 //2 
#define IDC_BUTTON_3 103 //3
#define IDC_BUTTON_4 104 //4
#define IDC_BUTTON_5 105 //5
#define IDC_BUTTON_6 106 //6
#define IDC_BUTTON_7 107 //7
#define IDC_BUTTON_8 108 //8
#define IDC_BUTTON_9 109 //9
#define IDC_BUTTON_0 100 //0
#define IDC_BUTTON_EQ 1010 //Equals
#define IDC_BUTTON_PS 1011 //Plus
#define IDC_BUTTON_MS 1012 //Minus
#define IDC_BUTTON_DVD 1013 //Divide
#define IDC_BUTTON_MX 1014 //Multiply
#define IDC_BUTTON_15 1015 //SPARE
#define IDC_MAIN_EDIT 1111 //Text box
#define IDC_BUTTON_CLR 1112 //Clear button

long long int output = 0; //Output to main screen
int val = 0; //value for numbered buttons
long int tempnum1 = 0; //Temporary storage for calculations
long int fnaction = 0; //Decider for what type of calculation needed

void putNumInEditBox(long long int num)
{
	wchar_t numbuffer[100];
	_i64tow_s(num, numbuffer,100, 10); 
	SendMessage(hEdit, WM_SETTEXT, NULL, (LPARAM)numbuffer);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		//Create text box
		hEdit = CreateWindowEx(
			WS_EX_CLIENTEDGE, L"EDIT", L"", //Name of edit box
			WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL|ES_AUTOHSCROLL | ES_RIGHT | ES_READONLY, 
			20, 10, 240, 25, 
			hwnd, (HMENU)IDC_MAIN_EDIT, 
			GetModuleHandle(NULL), NULL);

		//Creating button 1
		CreateWindowEx(
			NULL, L"Button", L"1",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			20, 156, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_1,
			GetModuleHandle(NULL), NULL);

		//Creating button 2
		CreateWindowEx(
			NULL, L"Button", L"2",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			80, 156, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_2,
			GetModuleHandle(NULL), NULL);
		
		//Creating button 3
		CreateWindowEx(
			NULL, L"Button", L"3",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			140, 156, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_3,
			GetModuleHandle(NULL), NULL);
	
		//Creating button 4
		CreateWindowEx(
			NULL, L"Button", L"4",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			20, 108, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_4,
			GetModuleHandle(NULL), NULL);

		//Creating button 5
		CreateWindowEx(
			NULL, L"Button", L"5",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			80, 108, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_5,
			GetModuleHandle(NULL), NULL);

		//Creating button 6
		CreateWindowEx(
			NULL, L"Button", L"6",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			140, 108, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_6,
			GetModuleHandle(NULL), NULL);
		//Creating button 7
		CreateWindowEx(
			NULL, L"Button", L"7",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			20, 60, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_7,
			GetModuleHandle(NULL), NULL);

		//Creating button 8
		CreateWindowEx(
			NULL, L"Button", L"8",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			80, 60, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_8,
			GetModuleHandle(NULL), NULL);

		//Creating button 9
		CreateWindowEx(
			NULL, L"Button", L"9",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			140, 60, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_9,
			GetModuleHandle(NULL), NULL);

		//Creating button 0
		CreateWindowEx(
			NULL, L"Button", L"0",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			80, 204, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_0,
			GetModuleHandle(NULL), NULL);
		
		//Creating equals button
		CreateWindowEx(
			NULL, L"Button", L"=",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			140, 204, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_EQ,
			GetModuleHandle(NULL), NULL);
		
		//Creating plus button
		CreateWindowEx(
			NULL, L"Button", L"+",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			200, 60, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_PS,
			GetModuleHandle(NULL), NULL);

		//Creating minus button
		CreateWindowEx(
			NULL, L"Button", L"-",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			200, 156, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_MS,
			GetModuleHandle(NULL), NULL);
		
		//Creating divide button
		CreateWindowEx(
			NULL, L"Button", L"/",  //Name of button.UI
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			200, 204, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_DVD,
			GetModuleHandle(NULL), NULL);

		//Creating multiply
		CreateWindowEx(
			NULL, L"Button", L"*",  
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			200, 108, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_MX,
			GetModuleHandle(NULL), NULL);

		//Create Clear button
		CreateWindowEx(
			NULL, L"Button", L"CE",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //Child of other window
			20, 204, 60, 48,            //Position & size
			hwnd, (HMENU)IDC_BUTTON_CLR,
			GetModuleHandle(NULL), NULL);
		break;

	    case WM_COMMAND:
		switch (LOWORD(wParam))
		{		

		//Case for pressing button 1
		case IDC_BUTTON_1:
			val = 1;
			output = (output * 10) + val;
			break;

			//Case for pressing button 2
		case IDC_BUTTON_2:
			val =  2;
			output = (output * 10) + val;
			break;

			//Case for pressing button 3
		case IDC_BUTTON_3:
			val = 3;
			output = (output * 10) + val;
			break;

			//Case for pressing button 4
		case IDC_BUTTON_4:
			val = 4;
			output = (output * 10) + val;
			break;

		case IDC_BUTTON_5:
			//Case for pressing button 5
			val = 5;
			output = (output * 10) + val;
			break;

			//Case for pressing button 6
		case IDC_BUTTON_6:
			val = 6;
			output = (output * 10) + val;
			break;

			//Case for pressing button 7
		case IDC_BUTTON_7:
			val = 7;	
			output = (output * 10) + val;
			break;

			//Case for pressing button 8
		case IDC_BUTTON_8:
			val = 8;
			output = (output * 10) + val;
			break;

			//Case for pressing button 9
		case IDC_BUTTON_9:
			val = 9;
			output = (output * 10) + val;
			break;

			//Case for pressing button 0
		case IDC_BUTTON_0:
			val = 0;
			output = (output * 10) + val;
			break;

					//Case for pressing button equals
				case IDC_BUTTON_EQ:
			
					if (fnaction == 0)
					{
				
					}
					else if (fnaction == 1)
					{
						output = tempnum1+output;
					}
					else if (fnaction == 2)
					{
						output = tempnum1 - output;

					}
					else if (fnaction == 3)
					{
						output = tempnum1 / output;
					}
					else if (fnaction == 4)
					{
						output = tempnum1 * output;

					}
					tempnum1 = 0;
					fnaction = 0;
					break;
			//Case for pressing button CE
		case IDC_BUTTON_CLR:
			output = 0;
			tempnum1 = 0;
			fnaction = 0;

			//Case for pressing button plus
		case IDC_BUTTON_PS:
			tempnum1 += output;
			output = 0;
			fnaction = 1;
		    break;

			//Case for pressing button minus
		case IDC_BUTTON_MS:
			tempnum1 = output - tempnum1;
			output = 0;
			fnaction = 2;
			break;
						//Case for pressing button divide
					case IDC_BUTTON_DVD:
						if (tempnum1 == 0)
						{
							tempnum1 = output;
						}
			
						else
						{
							tempnum1 = tempnum1 / output;
				
						}
						output = 0;
						fnaction = 3;
						break;
			//Case for pressing button multiply
		case IDC_BUTTON_MX:
			if (tempnum1 == 0)
			{
				tempnum1 = output;
			}
			else
			{
				tempnum1 = tempnum1 * output;
			}
			output = 0;
			fnaction = 4;
			break;
		}
		putNumInEditBox(output);
		break;
			break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)  //WinMain is main function
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	//Step 1:Registering the window class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Window Registration Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	//Step 2: Creating the window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		L"Keiths Calculator",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 300, 300,
		NULL, NULL, hInstance, NULL);
	if (hwnd == NULL)
	{
		MessageBox(NULL, L"Window Creation Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0)>0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}