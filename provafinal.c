#include <windows.h>
#include <stdio.h>

#define IDC_AV1_EDIT 101
#define IDC_AV2_EDIT 102
#define IDC_RESULT_TEXT 103
#define IDC_CALCULATE_BUTTON 104

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hAv1Edit, hAv2Edit, hResultText, hCalculateButton;
    char av1Text[10], av2Text[10], resultText[100];
    double av1, av2, media, notaNecessaria;

    switch (uMsg) {
        case WM_CREATE:
            // Create AV1 edit box
            CreateWindow("STATIC", "Nota AV1:", WS_VISIBLE | WS_CHILD, 10, 10, 100, 20, hwnd, NULL, NULL, NULL);
            hAv1Edit = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 10, 100, 20, hwnd, (HMENU)IDC_AV1_EDIT, NULL, NULL);

            // Create AV2 edit box
            CreateWindow("STATIC", "Nota AV2:", WS_VISIBLE | WS_CHILD, 10, 40, 100, 20, hwnd, NULL, NULL, NULL);
            hAv2Edit = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 40, 100, 20, hwnd, (HMENU)IDC_AV2_EDIT, NULL, NULL);

            // Create result text
            hResultText = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD, 10, 100, 300, 40, hwnd, (HMENU)IDC_RESULT_TEXT, NULL, NULL);

            // Create calculate button
            hCalculateButton = CreateWindow("BUTTON", "Calcular", WS_VISIBLE | WS_CHILD, 10, 70, 100, 20, hwnd, (HMENU)IDC_CALCULATE_BUTTON, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDC_CALCULATE_BUTTON) {
                GetWindowText(hAv1Edit, av1Text, 10);
                GetWindowText(hAv2Edit, av2Text, 10);

                av1 = atof(av1Text);
                av2 = atof(av2Text);
                media = (av1 + av2) / 2;

                if (media >= 7) {
                    sprintf(resultText, "Aprovado com média %.2f", media);
                } else if (media >= 4.0 && media < 7.0) {
                    notaNecessaria = 5 * 2 - media;
                    if (notaNecessaria > 10) notaNecessaria = 10; // Nota máxima é 10
                    if (notaNecessaria < 0) notaNecessaria = 0; // Evita notas negativas
                    sprintf(resultText, "Precisa de %.2f na prova final para ser aprovado", notaNecessaria);
                } else {
                    sprintf(resultText, "Reprovado com media %.2f", media);
                }

                SetWindowText(hResultText, resultText);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "github.com/brenoloa",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 350, 200,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
