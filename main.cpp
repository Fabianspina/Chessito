/******************* Chessito 16 ************************/
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include "decs.h"

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    wincl.hInstance = hInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WndProc;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (hInstance, "champ");
    wincl.hIconSm = LoadIcon (hInstance, "champ");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = "Menu";                 /* Si menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;    /* color */
    if (!RegisterClassEx (&wincl))
        return 0;
        hwnd = CreateWindowEx (
               0,                   /* Extended possibilites for variation */
               szClassName,         /* Classname */
               _T("Ajedrez full"),       /* Title Text */
               WS_OVERLAPPEDWINDOW, /* default window */
               1000,     /* Windows decides the position */
               0,    /* where the window ends up on the screen */
               560,                 /* The programs width */
               400,                 /* and height in pixels */
               HWND_DESKTOP,        /* The window is a child-window to desktop */
    LoadMenu(hInstance, "Menu"),                 /* No menu */
               hInstance,           /* Program Instance handler */
               NULL                 /* No Window Creation data */
               );
    ShowWindow (hwnd, nCmdShow);
    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message){
			case WM_COMMAND:
				switch (LOWORD(wParam)){
				case CM_VT: {// 102
					presentacion();
					break;}
                case CM_VTAMENAZAS:{
                    vtamenaza();
                    break;}
                case CM_MOVIDASPOSIBLES:{
                    movidasposibles();
                break;}
                case CM_TURNO:{
                    turno();
                    decir turn;
                    break;}
                case CM_MOVER:{
                    jugar();
                    decir "turn: " << turn << endl;
                    vt();
                    turno();
                    decir turn;
                    break;
                }
                case CM_VERTABLERO:{
                    vt();
                    // tablero.mostrar();
                    break;
                }
                case CM_AMBITOREY:{
                    ambitorey();
                    break;}
                case CM_CHESSITO:{
                    if (turn==2)
                    chessito();
                    break;}
                case CM_ELO:{
                        EloRating(Ra, Rb, K, outcome);
                    break;}
                case CM_TABCHES:{
                    tablero.mostrar();
                    const Casilla& c = tablero.getCasilla(53);
                    break;}
                case CM_GUARDAR: {
                        escribe(ori, dest);
                    break;}
                case CM_AYUDA:{
                    ayuda();
                    break;}
                case CM_TUTOR: {
                        decir "\
                                Se pudo jugar 1. e4, d5 2 exd5 \n \
                                Se pudo jugar 1. e4, e6 2. d4, d5 3. e5, c5 \n \
                                Se jugó también 1. e4, e5 2. Cf3, Cb6 3. Ab5, Ae7 \n \
                                Humano contra Chessito 1. e4, d5 2. d4, Cc6 3. e*d5 \n \
                                Humano contra Chessito 1. e4, a6 2. d4, Cc6 3. Cf3, d5 4. e5, g6 \n \
                                Inicialmente cuenta las 20 movidas blancas. \
                                ";

                    break;
                    }
/*                    case WM_DRAWITEM:
                    if (wParam == IDC_TABLERO) {
                    LPDRAWITEMSTRUCT pDIS = (LPDRAWITEMSTRUCT)lParam;
                    dibujarTablero(hwnd,pDIS->hDC, tablero);

                    return TRUE;}
                    case WM_INITDIALOG:
                    SetDlgItemText(hwnd, IDC_LABEL_TURNO, "Turno: Blancas");
                    return TRUE;*/

                case CM_JAQUEMATE:{
                    jaquemate(4);
                    break;
                    }
                case CM_JAQUE:{
                    jaque();
                    break;
                    }
                case CM_SALIR:{
					PostQuitMessage (0);
					break;
                    }
                break;
                }
                case WM_CREATE:{
                break;
                }
                case WM_PAINT: {
                    PAINTSTRUCT ps;
                    HDC hdc = BeginPaint(hwnd, &ps);
                    dibujarTablero(hwnd, hdc, tablero);
                    EndPaint(hwnd, &ps);
                break;
                }

                case WM_DESTROY:{
                    PostQuitMessage (0);
                break;}
                default: {
                return DefWindowProc (hwnd, message, wParam, lParam);}
                }
            return 0;
            }

/*void dibujarTablero(HWND hwnd, HDC hdc, Tablero tablero) {
for (int y = 0; y < 8; ++y) {
for (int x = 0; x < 8; ++x) {
RECT rect = { x * 60, y * 60, (x + 1) * 60, (y + 1) * 60 };
HBRUSH brush = CreateSolidBrush((x + y) % 2 ? RGB(240, 240, 240) : RGB(100, 100, 100));
FillRect(hdc, &rect, brush);
DeleteObject(brush);
// Dibujar piezas
Pieza* p = tablero->getPieza(x, y);
if (p) {
char simbolo = p->getSimbolo();
std::string texto(1, simbolo);
TextOut(hdc, x * 60 + 25, y * 60 + 15, texto.c_str(), 1);
}
}
}
}*/

char obtenerpieza(const Casilla& c) {
    char piezaChar = ' ';
    switch (c.pieza) {
        case 1: piezaChar = 'R'; break; // Rey
        case 2: piezaChar = 'D'; break; // Dama
        case 3: piezaChar = 'T'; break; // Torre
        case 4: piezaChar = 'A'; break; // Alfil
        case 5: piezaChar = 'C'; break; // Caballo
        case 6: piezaChar = 'P'; break; // Peón
        default: return ' ';
    }

    // Blancas en mayúsculas, negras en minúsculas
    return (c.color == 1) ? piezaChar : tolower(piezaChar);
}

void dibujarTablero(HWND hwnd, HDC hdc, Tablero& tablero) {
    for (int fila = 0; fila < 8; ++fila) {
        for (int col = 0; col < 8; ++col) {
            // Calcular posición en píxeles
            RECT rect = { col * 60, fila * 60, (col + 1) * 60, (fila + 1) * 60 };

            // Dibujar casilla (blanca/gris)
            HBRUSH brush = CreateSolidBrush((col + fila) % 2 ? RGB(240, 240, 240) : RGB(100, 100, 100));
            FillRect(hdc, &rect, brush);
            DeleteObject(brush);

            // Obtener casilla del tablero (índice 1D)
            int i = indiceDesdeXY(col + 1, 8 - fila); // fila 8 en top → fila 1 en bottom
            if (i < 1 || i > 64) continue;

            const Casilla& c = tablero.getCasilla(i);

            // Si hay una pieza, dibujar su símbolo
            if (c.pieza != 0) {
                char simbolo = obtenerpieza(c); // Función que convierte pieza+color a char
                std::string texto(1, simbolo);
                TextOut(hdc, col * 60 + 20, fila * 60 + 15, texto.c_str(), 1);
            }
        }
    }
}

/*INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_INITDIALOG:
                SetDlgItemText(hwndDlg, IDC_LABEL_TURNO, "Turno: Blancas");
            return TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDC_BUTTON_MOVER) {
                char buffer[5];
                GetDlgItemText(hwndDlg, IDC_EDIT_JUGADA, buffer, 5);
                if (strlen(buffer) == 4) {
 //                   procesarJugada(buffer);
                    SetDlgItemText(hwndDlg, IDC_EDIT_JUGADA, "");
                    InvalidateRect(GetDlgItem(hwndDlg, IDC_TABLERO), NULL, TRUE);
                }

                case CM_VT: {// 102
					presentacion();
					break;}
                case CM_VTAMENAZAS:{
                    vtamenaza();
                    break;}
                case CM_MOVIDASPOSIBLES:{
                    movidasposibles();
                break;}
                case CM_TURNO:{
                    turno();
                    decir turn;
                    break;}
                case CM_MOVER:{
                    jugar();
                    decir "primero turn" << turn << endl;
                    break;
                }
                case CM_VERTABLERO:{
                    vt();
                    tablero.mostrar();
                    InvalidateRect(GetDlgItem(hwndDlg, IDC_TABLERO), NULL, TRUE);
                    break;
                }
                case CM_AMBITOREY:{
                    ambitorey();
                    break;}
                case CM_CHESSITO:{
                    if (turn==2)
                    chessito();
                    break;}
                case CM_ELO:{
                        EloRating(Ra, Rb, K, outcome);
                    break;}
                case CM_TABCHES:{
                    tablero.mostrar();
                    const Casilla& c = tablero.getCasilla(53);
                    break;}
                case CM_AYUDA:{
                    ayuda();
                    break;}
                case CM_TUTOR: {
                        decir "\
                                Se pudo jugar 1. e4, d5 2 exd5 \n \
                                Se pudo jugar 1. e4, e6 2. d4, d5 3. e5, c5 \n \
                                Se jugó también 1. e4, e5 2. Cf3, Cb6 3. Ab5, Ae7 \n \
                                Humano contra Chessito 1. e4, d5 2. d4, Cc6 3. e*d5 \n \
                                Humano contra Chessito 1. e4, a6 2. d4, Cc6 3. Cf3, d5 4. e5, g6 \n \
                                Inicialmente cuenta las 20 movidas blancas. \
                                ";
                    break;}
                case CM_JAQUE:{
                    jaque();
                    break;}
                case CM_SALIR:{
					PostQuitMessage (0);
					break;}
                }

        case WM_DRAWITEM:
            if (wParam == IDC_TABLERO) {
                LPDRAWITEMSTRUCT pDIS = (LPDRAWITEMSTRUCT)lParam;
//                dibujarTablero(pDIS->hDC, pDIS->rcItem);
            }
            return TRUE;

        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;
    }
    return FALSE;
}*/

void jugar() {
//      turno();
        vt();
//      vtamenaza();
        jaque();
        eligepieza();
}

void vtamenaza() {
    blanca;
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 1; i <= 8; i++)   { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 9; i <= 16; i++)  { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 17; i <= 24; i++) { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 25; i <= 32; i++) { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 33; i <= 40; i++) { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 41; i <= 48; i++) { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 49; i <= 56; i++) { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|" << endl;
	decir "\n\t\t";
	for (i = 57; i <= 64; i++) { aux2(i); }
	decir "\n\t\t";
    decir "|+------+-------+-------+-------+-------+-------+-------+-------+|\n\n\n";
}

void vtaux(){
for (int i=1;i<=64;i++) { ti.tocab=0; ti.tocan=0; }
i=1;
	for bucle {
    // acá empieza la asignación de amenazas
    if(ti.color==1){
        if(ti.pieza==6){
            if (ti.columna > 1 && ti.fila<8 ) {t[i-9].tocab++;} // amenaza de peón blanco a la izquierda // limitado 20-8
            if (ti.columna < 8 && ti.fila<8 ) {t[i-7].tocab++;} // amenaza de peón blanco a la derecha-  // limitado 20-8
                }
        if(ti.pieza==5){
            if (ti.columna == 1){
                    if(ti.fila == 1) { t[i - 6].tocab++; t[i - 15].tocab++; } // caballo desde casilla a1
                    if(ti.fila == 2) { t[i - 6].tocab++; t[i - 15].tocab++; t[i + 10].tocab++; } // caballo desde casilla a2
                    if(ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6)
                        { t[i - 15].tocab++; t[i - 6].tocab++; t[i + 10].tocab++; t[i + 17].tocab++; }// caballo desde casilla a3, a4, a5, a6
                    if(ti.fila == 7) { t[i - 6].tocab++; t[i + 10].tocab++; t[i + 17].tocab++; } // caballo desde casilla a7
                    if(ti.fila == 8) { t[i + 10].tocab++; t[i + 17].tocab++; }// caballo desde casilla a8
                            }
            if(ti.columna == 2){
                    if( ti.fila == 1){ t[i - 6].tocab++; t[i - 15].tocab++; t[i - 17].tocab++; }
                    if( ti.fila == 2){ t[i - 6].tocab++; t[i - 15].tocab++; t[i - 17].tocab++; t[i + 10].tocab++;}
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){
                        t[i - 6].tocab++; t[i - 15].tocab++; t[i - 17].tocab++; t[i + 10].tocab++;
                        t[i + 17].tocab++; t[i + 15].tocab++;}
                    if(ti.fila == 7) { t[ i - 6 ].tocab++; t[ i +10 ].tocab++; t[ i + 17].tocab++; t[ i + 15].tocab++;}
                    if(ti.fila == 8) { t[ i + 10].tocab++; t[ i + 17].tocab++; t[ i + 15].tocab++;}
                            }
            if(ti.columna == 3 || ti.columna == 4 || ti.columna == 5 || ti.columna == 6 ){
                    if( ti.fila == 1){ t[i - 6].tocab++; t[i - 15].tocab++; t[i - 17].tocab++; t[i - 10].tocab++;}
                    if( ti.fila == 2){ t[i - 6].tocab++; t[i - 15].tocab++; t[i - 17].tocab++; t[i + 10].tocab++; t[i + 6].tocab++;t[i - 10].tocab++;}
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){ t[i - 6 ].tocab++; t[i - 15].tocab++; t[i - 17].tocab++; t[i + 10].tocab++; t[i + 17].tocab++; t[i + 15].tocab++;  t[i + 6].tocab++; t[i - 10].tocab++; }
                    if( ti.fila == 7) { t[i - 6 ].tocab++; t[i + 10].tocab++; t[i + 17].tocab++; t[i + 15].tocab++; t[i + 6].tocab++; t[i - 10].tocab++;}
                    if( ti.fila == 8) {t[i +10].tocab++; t[i + 6].tocab++; t[i + 17].tocab++; t[i + 15].tocab++;}
                            }
            if(ti.columna == 7){
                    if( ti.fila == 1){ t[i - 15].tocab++; t[i - 17].tocab++; t[i - 10].tocab++;} //ya
                    if( ti.fila == 2){ t[i + 6].tocab++; t[i - 10].tocab++; t[i - 15].tocab++; t[i - 17].tocab++;} //ya
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){
                    t[i - 15].tocab++; t[i - 17].tocab++; t[i + 17].tocab++; t[i + 15].tocab++;  t[i + 6].tocab++; t[i - 10].tocab++;}//ya
                    if( ti.fila == 7){ t[i + 17].tocab++; t[i + 15].tocab++;  t[i + 6].tocab++; t[i - 10].tocab++;}//ya
                    if( ti.fila == 8){ t[i + 17].tocab++; t[i + 15].tocab++;  t[i + 6].tocab++ ;} //ya
                        }
            if(ti.columna == 8){
                    if( ti.fila == 1){ t[i - 17].tocab++; t[i - 10].tocab++;}
                    if( ti.fila == 2){t[i - 17].tocab++; t[i - 10].tocab++;t[i + 6].tocab++; }
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){t[i - 17].tocab++; t[i - 10].tocab++;t[i + 6].tocab++;t[i + 15].tocab++;  }
                    if( ti.fila == 7){t[i + 15].tocab++;  t[i + 6].tocab++;t[i - 10].tocab++;}
                    if( ti.fila == 8){ t[i + 15].tocab++;  t[i + 6].tocab++; }
                        }
                    }
 /********************************* Alfil *********************************************************/
       if(ti.pieza == 4){
					if (ti.columna <= 7) {t[i - 7].tocab++;}
					if (ti.columna <= 6 && t[i - 7].pieza == 0) {t[i - 14].tocab++;}
					if (ti.columna <= 5 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0) {t[i - 21].tocab++;}
					if (ti.columna <= 4 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0){t[i - 28].tocab++;}
					if (ti.columna <= 3 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0){t[i - 35].tocab++;}
					if (ti.columna <= 2 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0) {t[i - 42].tocab++;}
					if (ti.columna == 1 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0 && t[i - 42].pieza == 0) {t[i - 49].tocab++;}

					if (ti.columna >= 2)t[i - 9].tocab++;
					if (ti.columna >= 3 && t[i - 9].pieza == 0) {t[i - 18].tocab++;}
					if (ti.columna >= 4 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0) {t[i - 27].tocab++;}
					if (ti.columna >= 5 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0){t[i - 36].tocab++;}
					if (ti.columna >= 6 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0){t[i - 45].tocab++;}
					if (ti.columna >= 7 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0){t[i - 54].tocab++;}
					if (ti.columna == 8 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0 && t[i - 54].pieza == 0) {t[i - 63].tocab++;}

					if (ti.columna >= 2)t[i + 7].tocab++;
					if (ti.columna >= 3 && t[i + 7].pieza == 0)t[i + 14].tocab++;
					if (ti.columna >= 4 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0)t[i + 21].tocab++;
					if (ti.columna >= 5 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0)t[i + 28].tocab++;
					if (ti.columna >= 6 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0)t[i + 35].tocab++;
					if (ti.columna >= 7 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0)t[i + 42].tocab++;
					if (ti.columna == 8 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0 && t[i + 42].pieza == 0) {t[i + 49].tocab++;}

					if (ti.columna <= 7)t[i + 9].tocab++;
					if (ti.columna <= 6 && t[i + 9].pieza == 0) t[i + 18].tocab++;
					if (ti.columna <= 5 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0) {t[i + 27].tocab++;}
					if (ti.columna <= 4 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0) {t[i + 36].tocab++;}
					if (ti.columna <= 3 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0) {t[i + 45].tocab++;}
					if (ti.columna <= 2 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0) {t[i + 54].tocab++;}
					if (ti.columna == 1 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0 && t[i + 54].pieza == 0) {t[i + 63].tocab++;}
                  } //termina alfil
        if(ti.pieza == 3){
					if (ti.fila <= 7)t[i - 8].tocab++;
					if (ti.fila <= 6 && t[i - 8].pieza == 0)t[i - 16].tocab++;
					if (ti.fila <= 5 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0)t[i - 24].tocab++;
					if (ti.fila <= 4 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0)t[i - 32].tocab++;
					if (ti.fila <= 3 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0) t[i - 40].tocab++;
					if (ti.fila <= 2 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0) t[i - 48].tocab++;
					if (ti.fila == 1 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0 && t[i - 48].pieza == 0) t[i - 56].tocab++;

					if (ti.fila >= 2)t[i + 8].tocab++;
					if (ti.fila >= 3 && t[i + 8].pieza == 0)t[i + 16].tocab++;
					if (ti.fila >= 4 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0)t[i + 24].tocab++;
					if (ti.fila >= 5 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0)t[i + 32].tocab++;
					if (ti.fila >= 6 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0) t[i + 40].tocab++;
					if (ti.fila >= 7 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0) t[i + 48].tocab++;
					if (ti.fila == 8 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0 && t[i + 48].pieza == 0) t[i + 56].tocab++;

					if (ti.columna >= 2)t[i - 1].tocab++;
					if (ti.columna >= 3 && t[i - 1].pieza == 0) t[i - 2].tocab++;
					if (ti.columna >= 4 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0) t[i - 3].tocab++;
					if (ti.columna >= 5 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0) t[i - 4].tocab++;
					if (ti.columna >= 6 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0) t[i - 5].tocab++;
					if (ti.columna >= 7 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0) t[i - 6].tocab++;
					if (ti.columna == 8 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0 && t[i - 6].pieza == 0) t[i - 7].tocab++;

					if (ti.columna <= 7)t[i + 1].tocab++;
					if (ti.columna <= 6 && t[i + 1].pieza == 0) t[i + 2].tocab++;
					if (ti.columna <= 5 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0) t[i + 3].tocab++;
					if (ti.columna <= 4 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0) t[i + 4].tocab++;
					if (ti.columna <= 3 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0) t[i + 5].tocab++;
					if (ti.columna <= 2 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0) t[i + 6].tocab++;
					if (ti.columna == 1 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0 && t[i + 6].pieza == 0) t[i + 7].tocab++;

            }
        if(ti.pieza == 2){
					if (ti.columna <= 7) {t[i - 7].tocab++;}
					if (ti.columna <= 6 && t[i - 7].pieza == 0) {t[i - 14].tocab++;}
					if (ti.columna <= 5 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0) {t[i - 21].tocab++;}
					if (ti.columna <= 4 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0){t[i - 28].tocab++;}
					if (ti.columna <= 3 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0){t[i - 35].tocab++;}
					if (ti.columna <= 2 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0) {t[i - 42].tocab++;}
					if (ti.columna == 1 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0 && t[i - 42].pieza == 0) {t[i - 49].tocab++;}

					if (ti.columna >= 2)t[i - 9].tocab++;
					if (ti.columna >= 3 && t[i - 9].pieza == 0) {t[i - 18].tocab++;}
					if (ti.columna >= 4 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0) {t[i - 27].tocab++;}
					if (ti.columna >= 5 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0){t[i - 36].tocab++;}
					if (ti.columna >= 6 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0){t[i - 45].tocab++;}
					if (ti.columna >= 7 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0){t[i - 54].tocab++;}
					if (ti.columna == 8 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0 && t[i - 54].pieza == 0) {t[i - 63].tocab++;}

					if (ti.columna < 2){t[i + 7].tocab++;}
					if (ti.columna >= 3 && t[i + 7].pieza == 0)t[i + 14].tocab++;
					if (ti.columna >= 4 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0)t[i + 21].tocab++;
					if (ti.columna >= 5 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0)t[i + 28].tocab++;
					if (ti.columna >= 6 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0)t[i + 35].tocab++;
					if (ti.columna >= 7 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0)t[i + 42].tocab++;
					if (ti.columna == 8 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0 && t[i + 42].pieza == 0) {t[i + 49].tocab++;}

					if (ti.columna <= 7)t[i + 9].tocab++;
					if (ti.columna <= 6 && t[i + 9].pieza == 0) t[i + 18].tocab++;
					if (ti.columna <= 5 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0) {t[i + 27].tocab++;}
					if (ti.columna <= 4 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0) {t[i + 36].tocab++;}
					if (ti.columna <= 3 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0) {t[i + 45].tocab++;}
					if (ti.columna <= 2 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0) {t[i + 54].tocab++;}
					if (ti.columna == 1 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0 && t[i + 54].pieza == 0) {t[i + 63].tocab++;}

					if (ti.fila <= 7)t[i - 8].tocab++;
					if (ti.fila <= 6 && t[i - 8].pieza == 0)t[i - 16].tocab++;
					if (ti.fila <= 5 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0)t[i - 24].tocab++;
					if (ti.fila <= 4 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0)t[i - 32].tocab++;
					if (ti.fila <= 3 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0) t[i - 40].tocab++;
					if (ti.fila <= 2 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0) t[i - 48].tocab++;
					if (ti.fila == 1 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0 && t[i - 48].pieza == 0) t[i - 56].tocab++;

					if (ti.fila >= 2)t[i + 8].tocab++;
					if (ti.fila >= 3 && t[i + 8].pieza == 0)t[i + 16].tocab++;
					if (ti.fila >= 4 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0)t[i + 24].tocab++;
					if (ti.fila >= 5 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0)t[i + 32].tocab++;
					if (ti.fila >= 6 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0) t[i + 40].tocab++;
					if (ti.fila >= 7 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0) t[i + 48].tocab++;
					if (ti.fila == 8 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0 && t[i + 48].pieza == 0) t[i + 56].tocab++;

					if (ti.columna >= 2)t[i - 1].tocab++;
					if (ti.columna >= 3 && t[i - 1].pieza == 0) t[i - 2].tocab++;
					if (ti.columna >= 4 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0) t[i - 3].tocab++;
					if (ti.columna >= 5 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0) t[i - 4].tocab++;
					if (ti.columna >= 6 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0) t[i - 5].tocab++;
					if (ti.columna >= 7 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0) t[i - 6].tocab++;
					if (ti.columna == 8 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0 && t[i - 6].pieza == 0) t[i - 7].tocab++;

					if (ti.columna <= 7)t[i + 1].tocab++;
					if (ti.columna <= 6 && t[i + 1].pieza == 0) t[i + 2].tocab++;
					if (ti.columna <= 5 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0) t[i + 3].tocab++;
					if (ti.columna <= 4 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0) t[i + 4].tocab++;
					if (ti.columna <= 3 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0) t[i + 5].tocab++;
					if (ti.columna <= 2 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0) t[i + 6].tocab++;
					if (ti.columna == 1 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0 && t[i + 6].pieza == 0) t[i + 7].tocab++;

            }
        if(ti.pieza == 1){
                    if (ti.columna >= 2) t[i - 1].tocab++; // rey a la izquierda comprobado
					if (i > 9 && ti.columna >= 2 && ti.fila <= 7) t[i - 9].tocab++;// rey en diagonal izq adelante comprobado
					if (ti.columna <= 7) t[i + 1].tocab++; // rey a la derecha comprobado
					if (i > 6 && ti.columna <= 7 && ti.fila <= 7) t[i - 7].tocab++; // rey en diagonal de adelante comprobado
					if (i >= 9) t[i - 8].tocab++; // rey adelante comprobado
					if (ti.fila <= 8) t[i + 8].tocab++; //rey atrás comprobado
					if (ti.columna >= 2 && ti.fila >= 2) t[i + 7].tocab++; // rey atrás izq comprobado
					if (ti.columna <= 7 && ti.fila >= 2) t[i + 9].tocab++; // rey atrás der comprobado
            }
              }
//////////////// termina color 1  //  empieza piezas negras  ///////////
    if(ti.color==2){
               if(ti.pieza == 1){
					if (ti.columna >= 2) t[i - 1].tocan++; // rey a la izquierda comprobado
					if (i > 9 && ti.columna >= 2 && ti.fila <= 7) t[i - 9].tocan++; // rey en diagonal izq adelante comprobado
					if (ti.columna <= 7) t[i + 1].tocan++; // rey a la derecha comprobado
					if (i > 6 && ti.columna <= 7 && ti.fila <= 7) t[i - 7].tocan++; // rey en diagonal der adelante comprobado
					if (i >= 9) t[i - 8].tocan++; // rey adelante comprobado
					if (ti.fila <= 8) t[i + 8].tocan++; //rey atrás * * *  no * * * comprobado
					if (ti.columna >= 2 && ti.fila >= 2) t[i + 7].tocan++; // rey atrás izq comprobado
					if (ti.columna <= 7 && ti.fila >= 2) t[i + 9].tocan++; // rey atrás der comprobadoif(ti.pieza==6){
                    }
        if(ti.pieza == 2){
					if (ti.fila <= 7)t[i - 8].tocan++;
					if (ti.fila <= 6 && t[i - 8].pieza == 0)t[i - 16].tocan++;
					if (ti.fila <= 5 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0)t[i - 24].tocan++;
					if (ti.fila <= 4 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0)t[i - 32].tocan++;
					if (ti.fila <= 3 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0) t[i - 40].tocan++;
					if (ti.fila <= 2 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0) t[i - 48].tocan++;
					if (ti.fila <= 1 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0 && t[i - 48].pieza == 0) t[i - 56].tocan++;

					if (ti.fila >= 2)t[i + 8].tocan++;
					if (ti.fila >= 3 && t[i + 8].pieza == 0)t[i + 16].tocan++;
					if (ti.fila >= 4 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0)t[i + 24].tocan++;
					if (ti.fila >= 5 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0)t[i + 32].tocan++;
					if (ti.fila >= 6 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0) t[i + 40].tocan++;
					if (ti.fila >= 7 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0) t[i + 48].tocan++;
					if (ti.fila >= 8 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0 && t[i + 48].pieza == 0) t[i + 56].tocan++;

					if (ti.columna >= 2)t[i - 1].tocan++;
					if (ti.columna >= 3 && t[i - 1].pieza == 0) t[i - 2].tocan++;
					if (ti.columna >= 4 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0) t[i - 3].tocan++;
					if (ti.columna >= 5 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0) t[i - 4].tocan++;
					if (ti.columna >= 6 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0) t[i - 5].tocan++;
					if (ti.columna >= 7 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0) t[i - 6].tocan++;
					if (ti.columna >= 8 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0 && t[i - 6].pieza == 0) t[i - 7].tocan++;

					if (ti.columna <= 7)t[i + 1].tocan++;
					if (ti.columna <= 6 && t[i + 1].pieza == 0) t[i + 2].tocan++;
					if (ti.columna <= 5 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0) t[i + 3].tocan++;
					if (ti.columna <= 4 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0) t[i + 4].tocan++;
					if (ti.columna <= 3 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0) t[i + 5].tocan++;
					if (ti.columna <= 2 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0) t[i + 6].tocan++;
					if (ti.columna <= 1 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0 && t[i + 6].pieza == 0) t[i + 7].tocan++;

                    if (ti.fila <= 7)t[i - 7].tocan++;
					if (ti.fila <= 6 && t[i - 7].pieza == 0)t[i - 14].tocan++;
					if (ti.fila <= 5 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0)t[i - 21].tocan++;
					if (ti.fila <= 4 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0)t[i - 28].tocan++;
					if (ti.fila <= 3 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0)t[i - 35].tocan++;
					if (ti.fila <= 2 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0)t[i - 42].tocan++;
					if (ti.fila <= 1 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0 && t[i - 42].pieza == 0) t[i - 49].tocan++;

					if (ti.fila <= 7)t[i - 9].tocan++;
					if (ti.fila <= 6 && t[i - 9].pieza == 0) t[i - 18].tocan++;
					if (ti.fila <= 5 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0) t[i - 27].tocan++;
					if (ti.fila <= 4 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0)t[i - 36].tocan++;
					if (ti.fila <= 3 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0)t[i - 45].tocan++;
					if (ti.fila <= 2 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0)t[i - 54].tocan++;
					if (ti.fila <= 1 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0 && t[i - 54].pieza == 0) t[i + 63].tocan++;

					if (ti.fila >= 2 && ti.columna >= 2) t[i + 7].tocan++;
					if (ti.fila >= 3 && ti.columna >= 3 && t[i + 7].pieza == 0)t[i + 14].tocan++;
					if (ti.fila >= 4 && ti.columna >= 4 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0)t[i + 21].tocan++;
					if (ti.fila >= 5 && ti.columna >= 5 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0)t[i + 28].tocan++;
					if (ti.fila >= 6 && ti.columna >= 6 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0)t[i + 35].tocan++;
					if (ti.fila >= 7 && ti.columna >= 7 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0)t[i + 42].tocan++;
					if (ti.fila == 8 && ti.columna == 8 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0 && t[i + 42].pieza == 0) t[i + 49].tocan++;

					if (ti.columna <= 7)t[i + 9].tocan++;
					if (ti.columna <= 6 && t[i + 9].pieza == 0) t[i + 18].tocan++;
					if (ti.columna <= 5 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0) t[i + 27].tocan++;
					if (ti.columna <= 4 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0)t[i + 36].tocan++;
					if (ti.columna <= 3 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0)t[i + 45].tocan++;
					if (ti.columna <= 2 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0)t[i + 54].tocan++;
					if (i == 1 && ti.columna == 1 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0 && t[i + 54].pieza == 0) t[i + 63].tocan++;

            }
         if(ti.pieza == 3){
					if (ti.fila <= 7)t[i - 8].tocan++;
					if (ti.fila <= 6 && t[i - 8].pieza == 0)t[i - 16].tocan++;
					if (ti.fila <= 5 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0)t[i - 24].tocan++;
					if (ti.fila <= 4 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0)t[i - 32].tocan++;
					if (ti.fila <= 3 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0) t[i - 40].tocan++;
					if (ti.fila <= 2 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0) t[i - 48].tocan++;
					if (ti.fila <= 1 && t[i - 8].pieza == 0 && t[i - 16].pieza == 0 && t[i - 24].pieza == 0 && t[i - 32].pieza == 0 && t[i - 40].pieza == 0 && t[i - 48].pieza == 0) t[i - 56].tocan++;

					if (ti.fila >= 2)t[i + 8].tocan++;
					if (ti.fila >= 3 && t[i + 8].pieza == 0)t[i + 16].tocan++;
					if (ti.fila >= 4 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0)t[i + 24].tocan++;
					if (ti.fila >= 5 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0)t[i + 32].tocan++;
					if (ti.fila >= 6 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0) t[i + 40].tocan++;
					if (ti.fila >= 7 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0) t[i + 48].tocan++;
					if (ti.fila >= 8 && t[i + 8].pieza == 0 && t[i + 16].pieza == 0 && t[i + 24].pieza == 0 && t[i + 32].pieza == 0 && t[i + 40].pieza == 0 && t[i + 48].pieza == 0) t[i + 56].tocan++;

					if (ti.columna >= 2)t[i - 1].tocan++;
					if (ti.columna >= 3 && t[i - 1].pieza == 0) t[i - 2].tocan++;
					if (ti.columna >= 4 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0) t[i - 3].tocan++;
					if (ti.columna >= 5 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0) t[i - 4].tocan++;
					if (ti.columna >= 6 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0) t[i - 5].tocan++;
					if (ti.columna >= 7 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0) t[i - 6].tocan++;
					if (ti.columna >= 8 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i - 4].pieza == 0 && t[i - 5].pieza == 0 && t[i - 6].pieza == 0) t[i - 7].tocan++;

					if (ti.columna <= 7)t[i + 1].tocan++;
					if (ti.columna <= 6 && t[i + 1].pieza == 0) t[i + 2].tocan++;
					if (ti.columna <= 5 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0) t[i + 3].tocan++;
					if (ti.columna <= 4 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0) t[i + 4].tocan++;
					if (ti.columna <= 3 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0) t[i + 5].tocan++;
					if (ti.columna <= 2 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0) t[i + 6].tocan++;
					if (ti.columna <= 1 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 0 && t[i + 4].pieza == 0 && t[i + 5].pieza == 0 && t[i + 6].pieza == 0) t[i + 7].tocan++;

            }
        if (ti.pieza==4){
                    if (ti.fila <= 7)t[i - 7].tocan++;
					if (ti.fila <= 6 && t[i - 7].pieza == 0)t[i - 14].tocan++;
					if (ti.fila <= 5 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0)t[i - 21].tocan++;
					if (ti.fila <= 4 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0)t[i - 28].tocan++;
					if (ti.fila <= 3 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0)t[i - 35].tocan++;
					if (ti.fila <= 2 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0)t[i - 42].tocan++;
					if (ti.fila <= 1 && t[i - 7].pieza == 0 && t[i - 14].pieza == 0 && t[i - 21].pieza == 0 && t[i - 28].pieza == 0 && t[i - 35].pieza == 0 && t[i - 42].pieza == 0) t[i - 49].tocan++;

					if (ti.fila <= 7)t[i - 9].tocan++;
					if (ti.fila <= 6 && t[i - 9].pieza == 0) t[i - 18].tocan++;
					if (ti.fila <= 5 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0) t[i - 27].tocan++;
					if (ti.fila <= 4 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0)t[i - 36].tocan++;
					if (ti.fila <= 3 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0)t[i - 45].tocan++;
					if (ti.fila <= 2 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0)t[i - 54].tocan++;
					if (ti.fila <= 1 && t[i - 9].pieza == 0 && t[i - 18].pieza == 0 && t[i - 27].pieza == 0 && t[i - 36].pieza == 0 && t[i - 45].pieza == 0 && t[i - 54].pieza == 0) t[i + 63].tocan++;

					if (ti.fila >= 2 && ti.columna >= 2) t[i + 7].tocan++;
					if (ti.fila >= 3 && ti.columna >= 3 && t[i + 7].pieza == 0)t[i + 14].tocan++;
					if (ti.fila >= 4 && ti.columna >= 4 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0)t[i + 21].tocan++;
					if (ti.fila >= 5 && ti.columna >= 5 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0)t[i + 28].tocan++;
					if (ti.fila >= 6 && ti.columna >= 6 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0)t[i + 35].tocan++;
					if (ti.fila >= 7 && ti.columna >= 7 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0)t[i + 42].tocan++;
					if (ti.fila == 8 && ti.columna == 8 && t[i + 7].pieza == 0 && t[i + 14].pieza == 0 && t[i + 21].pieza == 0 && t[i + 28].pieza == 0 && t[i + 35].pieza == 0 && t[i + 42].pieza == 0) t[i + 49].tocan++;

					if (ti.columna <= 7)t[i + 9].tocan++;
					if (ti.columna <= 6 && t[i + 9].pieza == 0) t[i + 18].tocan++;
					if (ti.columna <= 5 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0) t[i + 27].tocan++;
					if (ti.columna <= 4 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0)t[i + 36].tocan++;
					if (ti.columna <= 3 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0)t[i + 45].tocan++;
					if (ti.columna <= 2 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0)t[i + 54].tocan++;
					if (i == 1 && ti.columna == 1 && t[i + 9].pieza == 0 && t[i + 18].pieza == 0 && t[i + 27].pieza == 0 && t[i + 36].pieza == 0 && t[i + 45].pieza == 0 && t[i + 54].pieza == 0) t[i + 63].tocan++;
                        }
        if(ti.pieza==5){
            if (ti.columna == 1){
                    if(ti.fila == 1) { t[i - 6].tocan++; t[i - 15].tocan++; }  //
                    if(ti.fila == 2) { t[i - 6].tocan++; t[i - 15].tocan++; t[i + 10].tocan++; }  //
                    if(ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6)
                        { t[i - 15].tocan++; t[i - 6].tocan++; t[i + 10].tocan++; t[i + 17].tocan++; }  //
                    if(ti.fila == 7) { t[i - 6].tocan++; t[i + 10].tocan++; t[i + 17].tocan++; }        //
                    if(ti.fila == 8) { t[i + 10].tocan++; t[i + 17].tocan++; }                          //
                            }
            if(ti.columna == 2){
                    if( ti.fila == 1){ t[i - 6].tocan++; t[i - 15].tocan++; t[i - 17].tocan++; }  //
                    if( ti.fila == 2){ t[i - 6].tocan++; t[i - 15].tocan++; t[i - 17].tocan++; t[i + 10].tocan++;}  //
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){
                        t[i - 6].tocan++; t[i - 15].tocan++; t[i - 17].tocan++; t[i + 10].tocan++;
                        t[i + 17].tocan++; t[i + 15].tocan++;}
                    if(ti.fila == 7) { t[ i - 6 ].tocan++; t[ i +10 ].tocan++; t[ i + 17].tocan++; t[ i + 15].tocan++;}
                    if(ti.fila == 8) { t[ i + 10].tocan++; t[ i + 17].tocan++; t[ i + 15].tocan++;}
                            }
            if(ti.columna == 3 || ti.columna == 4 || ti.columna == 5 || ti.columna == 6 ){
                    if( ti.fila == 1){ t[i - 6].tocan++; t[i - 15].tocan++; t[i - 17].tocan++; t[i - 10].tocan++;}
                    if( ti.fila == 2){ t[i - 6].tocan++; t[i - 15].tocan++; t[i - 17].tocan++; t[i + 10].tocan++; t[i + 6].tocan++;t[i - 10].tocan++;}
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){ t[i - 6 ].tocan++; t[i - 15].tocan++; t[i - 17].tocan++; t[i + 10].tocan++; t[i + 17].tocan++; t[i + 15].tocan++;  t[i + 6].tocan++; t[i - 10].tocan++; }
                    if( ti.fila == 7) { t[i - 6 ].tocan++; t[i + 10].tocan++; t[i + 17].tocan++; t[i + 15].tocan++; t[i + 6].tocan++; t[i - 10].tocan++;}
                    if( ti.fila == 8) {t[i +10].tocan++; t[i + 6].tocan++; t[i + 17].tocan++; t[i + 15].tocan++;}
                            }
            if(ti.columna == 7){
                    if( ti.fila == 1){ t[i - 15].tocan++; t[i - 17].tocan++; t[i - 10].tocan++;} //ya
                    if( ti.fila == 2){ t[i + 6].tocan++; t[i - 10].tocan++; t[i - 15].tocan++; t[i - 17].tocan++;} //ya
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){
                    t[i - 15].tocan++; t[i - 17].tocan++; t[i + 17].tocan++; t[i + 15].tocan++;  t[i + 6].tocan++; t[i - 10].tocan++;}//ya
                    if( ti.fila == 7){ t[i + 17].tocan++; t[i + 15].tocan++;  t[i + 6].tocan++; t[i - 10].tocan++;}//ya
                    if( ti.fila == 8){ t[i + 17].tocan++; t[i + 15].tocan++;  t[i + 6].tocan++; } //ya
                        }
            if(ti.columna == 8){
                    if( ti.fila == 1){ t[i - 17].tocan++; t[i - 10].tocan++;}
                    if( ti.fila == 2){t[i - 17].tocan++; t[i - 10].tocan++;t[i + 6].tocan++; }
                    if( ti.fila == 3 || ti.fila == 4 || ti.fila==5 || ti.fila== 6){t[i - 17].tocan++; t[i - 10].tocan++;t[i + 6].tocan++;t[i + 15].tocan++;  }
                    if( ti.fila == 7){}
                    if( ti.fila == 8){ t[i + 15].tocan++;  t[i + 6].tocan++; }
                        }
                    }
        if(ti.pieza==6){
            if (ti.columna > 1 ) {t[i+7].tocan++;} // amenaza de peón negro a la izquierda
            if (ti.columna < 8 ) {t[i+9].tocan++;} // amenaza de peón negro a la derecha
                }
          	}
	}
}

void validadama() {
	if (
(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila + 1 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila + 2 && t[ori - 7].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila + 3 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila + 4 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila + 5 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila + 6 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[ori - 35].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila + 7 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[ori - 35].pieza == 0 && t[ori - 42].pieza == 0 && t[dest].color != turn) ||

(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila + 1 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila + 2 && t[ori - 9].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila + 3 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila + 4 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila + 5 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila + 6 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[ori - 45].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila + 7 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[ori - 45].pieza == 0 && t[ori - 54].pieza == 0 && t[dest].color != turn) ||

(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila - 1 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila - 2 && t[ori + 9].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila - 3 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila - 4 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila - 5 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila - 6 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[ori + 45].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila - 7 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[ori + 45].pieza == 0 && t[ori + 54].pieza == 0 && t[dest].color != turn) ||

(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila - 1 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila - 2 && t[ori + 7].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila - 3 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila - 4 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila - 5 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila - 6 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[ori + 35].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila - 7 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[ori + 35].pieza == 0 && t[ori + 42].pieza == 0 && t[dest].color != turn) ||
/*verticales*/

(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 1 && t[dest].color != turn )|| //
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 2 && t[ori - 8].pieza == 0 && t[dest].color != turn) || //
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 3 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[dest].color != turn) || //
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 4 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[dest].color != turn) || //
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 5 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[ori - 32].pieza == 0 && t[dest].color != turn) ||//
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 6 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[ori - 32].pieza == 0 && t[ori - 40].pieza == 0 && t[dest].color != turn) ||//
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 7 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[ori - 32].pieza == 0 && t[ori - 40].pieza == 0 && t[ori - 48].pieza == 0 && t[dest].color != turn) ||

(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 1 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 2 && t[ori + 8].pieza == 0 && t[dest].color != turn) || //
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 3 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[dest].color != turn) ||//
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 4 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 5 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[ori + 32].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 6 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[ori + 32].pieza == 0 && t[ori + 40].pieza == 0 && t[dest].color != turn) || //
(t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 7 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[ori + 32].pieza == 0 && t[ori + 40].pieza == 0 && t[ori + 48].pieza == 0 && t[dest].color != turn) || //
/*horizontales*/
(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[ori + 4].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[ori + 4].pieza == 0 && t[ori + 5].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[ori + 4].pieza == 0 && t[ori + 5].pieza == 0 && t[ori + 6].pieza == 0 && t[dest].color != turn) ||

(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila  && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[ori - 4].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[ori - 4].pieza == 0 && t[ori - 5].pieza == 0 && t[dest].color != turn) ||
(t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[ori - 4].pieza == 0 && t[ori - 5].pieza == 0 && t[ori - 6].pieza == 0 && t[dest].color != turn)
		)
	{
		actualiza();
	}
	else
	{
		decir "\tmovida incorrecta, validando de dama\n";
		eligepieza();
	}

	/*
	Función completa excepto porque, al igual que con validapeon.	Por ahora queda así.
	*/
}


/************************************ CHESSITO *****************************************************************/
void chessito() {
decir "\n\tTodavia no se mover, pero voy a pensar un poco";
pausa;
decir "\n\tChessito piensa su movida";
pausa;
decirnt "podria mover mi rey?" << endl;
pausa;
//if (jaque()) { decir n; pausa;}
extraejugada();
decide();
vt();
turno();
}
void jugarconchessito(){
//do {
m++;
//turno();
vt();
if (turn == 1) { eligepieza(); }
// else if (jake) { decir jake; }
else
 { extraejugada(); }
} //while (movidasposibles() >= 0 );
//}

int decide(){
srand((unsigned int)time( NULL ));
int lista_movidas = (rand() % 6);
decir "movidas a elegir : " << lista_movidas << endl ;
switch (lista_movidas){
case 1: ori = 7 ; if (t[ori].pieza!=0) dest = 22 ; break;
case 2: ori = 9; dest=17; break;
case 3: ori = 12 ; dest = 28; break;
case 4: ori = 15 ; dest = 23; break;
case 5: ori = 6; if (t[ori].pieza == 4 && t[15].pieza==0) dest = 15 ; break;
default: ori = 2; dest= 19; break;
//validar cada una;
}
return lista_movidas;
}

void extraejugada(){
decide();
decir "ori : " << ori << endl ;
decir "dest : " << dest << endl ;
	if(t[ori].color == 2) {
		int pieza = t[ori].pieza;
		actualiza();
	}
	else {
 	decir "mal";
	}
    decir "bien";
}
