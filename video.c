#include <windows.h>
#include <stdio.h>

#define BTN_IMPRIMIR 1
#define BTN_EDITAR 2
#define BTN_LIMPAR 3
#define BTN_ALTERAR_TAMANHO 4
#define BTN_ADD_ITEM 5

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddControls(HWND);
void InicializarLista(HWND);
void AdicionarItem(HWND);
void ImprimirLista(HWND);
void EditarItem(HWND);
void LimparLista(HWND);
void AlterarTamanho(HWND);

HWND hEdit, hDisplay, hSizeInput, hAddItemInput, hEditPosInput;
char LISTA[99][99];
int qntd = 0;
int contador = 0;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = { 0 };

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass", L"Lista de Itens", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            switch (wp) {
                case BTN_IMPRIMIR:
                    ImprimirLista(hWnd);
                    break;
                case BTN_EDITAR:
                    EditarItem(hWnd);
                    break;
                case BTN_LIMPAR:
                    LimparLista(hWnd);
                    break;
                case BTN_ALTERAR_TAMANHO:
                    AlterarTamanho(hWnd);
                    break;
                case BTN_ADD_ITEM:
                    AdicionarItem(hWnd);
                    break;
            }
            break;
        case WM_CREATE:
            AddControls(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}

void AddControls(HWND hWnd) {
    CreateWindowW(L"Static", L"Tamanho da Lista:", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 20, 150, 20, hWnd, NULL, NULL, NULL);
    hSizeInput = CreateWindowW(L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 210, 20, 100, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"Definir Tamanho", WS_VISIBLE | WS_CHILD, 320, 20, 120, 20, hWnd, (HMENU)BTN_ALTERAR_TAMANHO, NULL, NULL);

    CreateWindowW(L"Static", L"Display", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 50, 400, 20, hWnd, NULL, NULL, NULL);
    hDisplay = CreateWindowW(L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY, 50, 80, 400, 150, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"Adicionar Item:", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 240, 100, 20, hWnd, NULL, NULL, NULL);
    hAddItemInput = CreateWindowW(L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 160, 240, 200, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"Adicionar", WS_VISIBLE | WS_CHILD, 370, 240, 80, 20, hWnd, (HMENU)BTN_ADD_ITEM, NULL, NULL);

    CreateWindowW(L"Static", L"Editar Posição:", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 270, 100, 20, hWnd, NULL, NULL, NULL);
    hEditPosInput = CreateWindowW(L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 160, 270, 40, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"Editar", WS_VISIBLE | WS_CHILD, 210, 270, 80, 20, hWnd, (HMENU)BTN_EDITAR, NULL, NULL);

    CreateWindowW(L"Button", L"Imprimir", WS_VISIBLE | WS_CHILD, 50, 300, 80, 40, hWnd, (HMENU)BTN_IMPRIMIR, NULL, NULL);
    CreateWindowW(L"Button", L"Limpar", WS_VISIBLE | WS_CHILD, 150, 300, 80, 40, hWnd, (HMENU)BTN_LIMPAR, NULL, NULL);
}

void InicializarLista(HWND hWnd) {
    char tamanho[10];
    GetWindowText(hSizeInput, tamanho, 10);
    qntd = atoi(tamanho);
    if (qntd <= 0) {
        MessageBox(hWnd, "Por favor, insira um tamanho válido para a lista.", "Erro", MB_OK);
        return;
    }
    contador = 0;
    SetWindowText(hDisplay, "");
    SetWindowText(hAddItemInput, "");
    SetWindowText(hSizeInput, "");
}

void AdicionarItem(HWND hWnd) {
    if (qntd <= 0) {
        MessageBox(hWnd, "Defina o tamanho da lista primeiro.", "Erro", MB_OK);
        return;
    }
    if (contador >= qntd) {
        MessageBox(hWnd, "A lista já está cheia.", "Erro", MB_OK);
        return;
    }
    char item[99];
    GetWindowText(hAddItemInput, item, 99);
    strcpy(LISTA[contador], item);
    contador++;
    SetWindowText(hAddItemInput, "");
}

void ImprimirLista(HWND hWnd) {
    if (qntd <= 0) {
        MessageBox(hWnd, "Defina o tamanho da lista primeiro.", "Erro", MB_OK);
        return;
    }

    char buffer[4096] = "LISTA DE ITENS:\r\n";
    for (int i = 0; i < qntd; i++) {
        char item[128];
        sprintf(item, "%d. %s\r\n", i, LISTA[i]);
        strcat(buffer, item);
    }
    SetWindowText(hDisplay, buffer);
}

void EditarItem(HWND hWnd) {
    if (qntd <= 0) {
        MessageBox(hWnd, "Defina o tamanho da lista primeiro.", "Erro", MB_OK);
        return;
    }

    char pos[10], item[99];
    GetWindowText(hEditPosInput, pos, 10);
    int editar = atoi(pos);

    if (editar >= 0 && editar < qntd) {
        GetWindowText(hAddItemInput, item, 99);
        strcpy(LISTA[editar], item);
        MessageBox(hWnd, "Item editado com sucesso!", "Editar", MB_OK);
    } else {
        MessageBox(hWnd, "Posição inválida.", "Erro", MB_OK);
    }
    SetWindowText(hAddItemInput, "");
    SetWindowText(hEditPosInput, "");
}

void LimparLista(HWND hWnd) {
    if (qntd <= 0) {
        MessageBox(hWnd, "Defina o tamanho da lista primeiro.", "Erro", MB_OK);
        return;
    }

    MessageBox(hWnd, "Lista deletada! Adicione novos itens.", "Limpar", MB_OK);
    contador = 0;
    for (int i = 0; i < qntd; i++) {
        strcpy(LISTA[i], "");
    }
    SetWindowText(hDisplay, "");
    SetWindowText(hAddItemInput, "");
}

void AlterarTamanho(HWND hWnd) {
    char novoTamanho[10];
    GetWindowText(hSizeInput, novoTamanho, 10);
    int novoQntd = atoi(novoTamanho);

    if (novoQntd <= 0) {
        MessageBox(hWnd, "Por favor, insira um tamanho válido para a lista.", "Erro", MB_OK);
        return;
    }

    qntd = novoQntd;
    char mensagem[50];
    sprintf(mensagem, "Tamanho atualizado para %d itens!", qntd);
    MessageBox(hWnd, mensagem, "Alterar Tamanho", MB_OK);
    SetWindowText(hAddItemInput, "");
    SetWindowText(hSizeInput, "");
}
