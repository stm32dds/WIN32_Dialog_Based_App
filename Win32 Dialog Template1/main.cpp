#include "main.h"
#pragma comment(linker, \
  "\"/manifestdependency:type='Win32' "\
  "name='Microsoft.Windows.Common-Controls' "\
  "version='6.0.0.0' "\
  "processorArchitecture='*' "\
  "publicKeyToken='6595b64144ccf1df' "\
  "language='*'\"")

#pragma comment(lib, "ComCtl32.lib")



INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) /* more compact, each "case" through a single line, easier on the eyes */
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDCANCEL: onCancel(hDlg); return TRUE; /* call subroutine */
        }
        break;

    case WM_CLOSE:   onClose(hDlg); return TRUE; /* call subroutine */
    case WM_DESTROY: PostQuitMessage(0); return TRUE;
    }

    return FALSE;
}

int WINAPI wWinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE h0, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
    HWND hDlg;
    MSG msg;
    BOOL ret;

    InitCommonControls();
    hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_STM32PSU_DIALOG), 0, DialogProc, 0);
    ShowWindow(hDlg, nCmdShow);

    while ((ret = GetMessage(&msg, 0, 0, 0)) != 0) {
        if (ret == -1)
            return -1;

        if (!IsDialogMessage(hDlg, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}