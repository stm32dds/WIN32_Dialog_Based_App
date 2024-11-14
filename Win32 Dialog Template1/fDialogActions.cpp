#include "main.h"

void onCancel(HWND hDlg)
{
    SendMessage(hDlg, WM_CLOSE, 0, 0);
}

void onClose(HWND hDlg)
{
    if (MessageBox(hDlg, TEXT("Close the program?"), TEXT("Close"),
        MB_ICONQUESTION | MB_YESNO) == IDYES)
    {
        DestroyWindow(hDlg);
    }
}