#include <windows.h>
#include <commdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Windows API constants that might be missing in older SDK versions */
#ifndef EM_REDO
#define EM_REDO 119
#endif

#ifndef EN_SELCHANGE
#define EN_SELCHANGE 2
#endif

/* =========================================================
   IDs
   ========================================================= */

#define ID_EDIT         100
#define ID_STATUS       101

#define ID_NEW          200
#define ID_OPEN         201
#define ID_SAVE         202
#define ID_SAVE_AS      203
#define ID_EXIT         204

#define ID_UNDO         300
#define ID_REDO         301
#define ID_CUT          302
#define ID_COPY         303
#define ID_PASTE        304
#define ID_DELETE       305
#define ID_SELECT_ALL   306
#define ID_FIND         307

#define ID_WORD_WRAP    400
#define ID_FONT         401

#define ID_FIND_EDIT    500
#define ID_FIND_BUTTON  501
#define ID_FIND_CLOSE   502

#define ID_FIND_WINDOW  503

/* =========================================================
   Global variables
   ========================================================= */

HWND hEdit;
HWND hStatus;

HFONT hFont = NULL;

char currentFile[MAX_PATH] = "";

BOOL modified = FALSE;
BOOL wordWrap = TRUE;

/* Find window */
HWND hFindWindow = NULL;
HWND hFindEdit = NULL;


/* =========================================================
   Colors
   ========================================================= */

COLORREF editorBackground = RGB(30, 30, 30);
COLORREF editorText = RGB(235, 235, 235);

HBRUSH hEditorBrush = NULL;


/* =========================================================
   Update title
   ========================================================= */

void UpdateTitle(HWND hwnd)
{
    char title[MAX_PATH + 50];

    if (currentFile[0] == '\0')
    {
        if (modified)
            strcpy(title, "*Untitled - My Notepad");
        else
            strcpy(title, "Untitled - My Notepad");
    }
    else
    {
        char *name = strrchr(currentFile, '\\');

        if (name != NULL)
            name++;
        else
            name = currentFile;

        if (modified)
            sprintf(
                title,
                "*%s - My Notepad",
                name
            );
        else
            sprintf(
                title,
                "%s - My Notepad",
                name
            );
    }

    SetWindowTextA(hwnd, title);
}


/* =========================================================
   Update status bar
   ========================================================= */

void UpdateStatus()
{
    DWORD start = 0;
    DWORD end = 0;

    SendMessageA(
        hEdit,
        EM_GETSEL,
        (WPARAM)&start,
        (LPARAM)&end
    );

    int line = (int)SendMessageA(
        hEdit,
        EM_LINEFROMCHAR,
        start,
        0
    );

    int lineStart = (int)SendMessageA(
        hEdit,
        EM_LINEINDEX,
        line,
        0
    );

    int column = (int)start - lineStart;

    char status[100];

    sprintf(
        status,
        "Ln %d, Col %d    %s",
        line + 1,
        column + 1,
        modified ? "Modified" : "Saved"
    );

    SetWindowTextA(
        hStatus,
        status
    );
}


/* =========================================================
   Clear document
   ========================================================= */

void ClearDocument(HWND hwnd)
{
    SetWindowTextA(
        hEdit,
        ""
    );

    currentFile[0] = '\0';

    modified = FALSE;

    UpdateTitle(hwnd);
    UpdateStatus();
}


/* =========================================================
   Save file
   ========================================================= */

BOOL SaveFile(HWND hwnd)
{
    /*
        If there is no filename,
        ask user where to save.
    */

    if (currentFile[0] == '\0')
    {
        OPENFILENAMEA ofn;

        char filename[MAX_PATH] = "";

        ZeroMemory(
            &ofn,
            sizeof(ofn)
        );

        ofn.lStructSize = sizeof(ofn);

        ofn.hwndOwner = hwnd;

        ofn.lpstrFilter =
            "Text Files (*.txt)\0*.txt\0"
            "C Files (*.c)\0*.c\0"
            "All Files (*.*)\0*.*\0";

        ofn.lpstrFile = filename;

        ofn.nMaxFile = MAX_PATH;

        ofn.lpstrDefExt = "txt";

        ofn.Flags =
            OFN_OVERWRITEPROMPT;

        if (!GetSaveFileNameA(&ofn))
            return FALSE;

        strcpy(
            currentFile,
            filename
        );
    }


    /* Open file */

    FILE *file = fopen(
        currentFile,
        "wb"
    );

    if (file == NULL)
    {
        MessageBoxA(
            hwnd,
            "Could not save the file.",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return FALSE;
    }


    /* Get text length */

    int length =
        GetWindowTextLengthA(hEdit);


    /* Allocate memory */

    char *text =
        malloc(length + 1);

    if (text == NULL)
    {
        fclose(file);

        MessageBoxA(
            hwnd,
            "Not enough memory.",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return FALSE;
    }


    /* Get text */

    GetWindowTextA(
        hEdit,
        text,
        length + 1
    );


    /* Write */

    fwrite(
        text,
        sizeof(char),
        length,
        file
    );


    /* Cleanup */

    free(text);

    fclose(file);


    /* Update state */

    modified = FALSE;

    UpdateTitle(hwnd);
    UpdateStatus();

    return TRUE;
}


/* =========================================================
   Save As
   ========================================================= */

BOOL SaveAsFile(HWND hwnd)
{
    OPENFILENAMEA ofn;

    char filename[MAX_PATH] = "";

    ZeroMemory(
        &ofn,
        sizeof(ofn)
    );

    ofn.lStructSize = sizeof(ofn);

    ofn.hwndOwner = hwnd;

    ofn.lpstrFilter =
        "Text Files (*.txt)\0*.txt\0"
        "C Files (*.c)\0*.c\0"
        "All Files (*.*)\0*.*\0";

    ofn.lpstrFile = filename;

    ofn.nMaxFile = MAX_PATH;

    ofn.lpstrDefExt = "txt";

    ofn.Flags =
        OFN_OVERWRITEPROMPT;


    if (!GetSaveFileNameA(&ofn))
        return FALSE;


    strcpy(
        currentFile,
        filename
    );


    return SaveFile(hwnd);
}


/* =========================================================
   Open file
   ========================================================= */

BOOL OpenTextFile(HWND hwnd)
{
    OPENFILENAMEA ofn;

    char filename[MAX_PATH] = "";

    ZeroMemory(
        &ofn,
        sizeof(ofn)
    );

    ofn.lStructSize = sizeof(ofn);

    ofn.hwndOwner = hwnd;

    ofn.lpstrFilter =
        "Text Files (*.txt)\0*.txt\0"
        "C Files (*.c)\0*.c\0"
        "All Files (*.*)\0*.*\0";

    ofn.lpstrFile = filename;

    ofn.nMaxFile = MAX_PATH;

    ofn.Flags =
        OFN_FILEMUSTEXIST;


    if (!GetOpenFileNameA(&ofn))
        return FALSE;


    /* Open */

    FILE *file = fopen(
        filename,
        "rb"
    );

    if (file == NULL)
    {
        MessageBoxA(
            hwnd,
            "Could not open the file.",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return FALSE;
    }


    /* Get size */

    fseek(
        file,
        0,
        SEEK_END
    );

    long size =
        ftell(file);

    rewind(file);


    if (size < 0)
    {
        fclose(file);

        return FALSE;
    }


    /* Allocate */

    char *text =
        malloc((size_t)size + 1);

    if (text == NULL)
    {
        fclose(file);

        MessageBoxA(
            hwnd,
            "Not enough memory.",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return FALSE;
    }


    /* Read */

    size_t bytesRead =
        fread(
            text,
            1,
            (size_t)size,
            file
        );

    text[bytesRead] = '\0';


    fclose(file);


    /* Put text into editor */

    SetWindowTextA(
        hEdit,
        text
    );


    free(text);


    /* Update filename */

    strcpy(
        currentFile,
        filename
    );


    modified = FALSE;


    UpdateTitle(hwnd);
    UpdateStatus();

    return TRUE;
}


/* =========================================================
   Unsaved changes
   ========================================================= */

BOOL CheckUnsavedChanges(HWND hwnd)
{
    if (!modified)
        return TRUE;


    int result = MessageBoxA(
        hwnd,

        "You have unsaved changes.\n\n"
        "Do you want to save them?",

        "My Notepad",

        MB_YESNOCANCEL |
        MB_ICONWARNING
    );


    /* Save */

    if (result == IDYES)
    {
        return SaveFile(hwnd);
    }


    /* Don't save */

    if (result == IDNO)
    {
        return TRUE;
    }


    /* Cancel */

    return FALSE;
}


/* =========================================================
   New document
   ========================================================= */

void NewDocument(HWND hwnd)
{
    if (!CheckUnsavedChanges(hwnd))
        return;

    ClearDocument(hwnd);
}


/* =========================================================
   Open document
   ========================================================= */

void OpenDocument(HWND hwnd)
{
    if (!CheckUnsavedChanges(hwnd))
        return;

    OpenTextFile(hwnd);
}


/* =========================================================
   Font dialog
   ========================================================= */

void OpenFontDialog(HWND hwnd)
{
    CHOOSEFONTA cf;

    LOGFONTA lf;

    ZeroMemory(
        &cf,
        sizeof(cf)
    );

    ZeroMemory(
        &lf,
        sizeof(lf)
    );


    /* Default font */

    lf.lfHeight = -18;

    strcpy(
        lf.lfFaceName,
        "Consolas"
    );


    cf.lStructSize =
        sizeof(cf);

    cf.hwndOwner =
        hwnd;

    cf.lpLogFont =
        &lf;

    cf.Flags =
        CF_SCREENFONTS |
        CF_INITTOLOGFONTSTRUCT;


    if (ChooseFontA(&cf))
    {
        HFONT newFont =
            CreateFontIndirectA(&lf);


        if (newFont != NULL)
        {
            if (hFont != NULL)
                DeleteObject(hFont);


            hFont = newFont;


            SendMessageA(
                hEdit,
                WM_SETFONT,
                (WPARAM)hFont,
                TRUE
            );
        }
    }
}


/* =========================================================
   Find text
   ========================================================= */

void FindNext()
{
    if (hFindEdit == NULL)
        return;


    char query[256];

    GetWindowTextA(
        hFindEdit,
        query,
        sizeof(query)
    );


    if (query[0] == '\0')
        return;


    int textLength =
        GetWindowTextLengthA(hEdit);


    if (textLength <= 0)
        return;


    char *text =
        malloc(textLength + 1);


    if (text == NULL)
        return;


    GetWindowTextA(
        hEdit,
        text,
        textLength + 1
    );


    DWORD start = 0;
    DWORD end = 0;


    SendMessageA(
        hEdit,
        EM_GETSEL,
        (WPARAM)&start,
        (LPARAM)&end
    );


    char *found =
        strstr(
            text + start,
            query
        );


    /* Search from beginning if not found */

    if (found == NULL)
    {
        found =
            strstr(
                text,
                query
            );
    }


    if (found != NULL)
    {
        int position =
            (int)(found - text);


        int queryLength =
            (int)strlen(query);


        SendMessageA(
            hEdit,
            EM_SETSEL,
            position,
            position + queryLength
        );


        SendMessageA(
            hEdit,
            EM_SCROLLCARET,
            0,
            0
        );


        SetFocus(hEdit);
    }
    else
    {
        MessageBoxA(
            hFindWindow,
            "Text not found.",
            "Find",
            MB_OK | MB_ICONINFORMATION
        );
    }


    free(text);
}


/* =========================================================
   Find window procedure
   ========================================================= */

LRESULT CALLBACK FindWindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            hFindEdit = CreateWindowExA(
                WS_EX_CLIENTEDGE,

                "EDIT",

                "",

                WS_CHILD |
                WS_VISIBLE |
                ES_AUTOHSCROLL,

                20,
                20,
                300,
                25,

                hwnd,

                (HMENU)ID_FIND_EDIT,

                GetModuleHandle(NULL),

                NULL
            );


            CreateWindowA(
                "BUTTON",

                "Find Next",

                WS_CHILD |
                WS_VISIBLE,

                20,
                60,
                100,
                30,

                hwnd,

                (HMENU)ID_FIND_BUTTON,

                GetModuleHandle(NULL),

                NULL
            );


            CreateWindowA(
                "BUTTON",

                "Close",

                WS_CHILD |
                WS_VISIBLE,

                135,
                60,
                100,
                30,

                hwnd,

                (HMENU)ID_FIND_CLOSE,

                GetModuleHandle(NULL),

                NULL
            );


            SetFocus(hFindEdit);

            break;
        }


        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case ID_FIND_BUTTON:

                    FindNext();

                    break;


                case ID_FIND_CLOSE:

                    DestroyWindow(hwnd);

                    break;
            }

            break;
        }


        case WM_CLOSE:

            DestroyWindow(hwnd);

            break;


        case WM_DESTROY:

            hFindWindow = NULL;
            hFindEdit = NULL;

            break;


        default:

            return DefWindowProcA(
                hwnd,
                msg,
                wParam,
                lParam
            );
    }


    return 0;
}


/* =========================================================
   Open find window
   ========================================================= */

void OpenFindDialog(HWND hwnd)
{
    if (hFindWindow != NULL)
    {
        SetForegroundWindow(
            hFindWindow
        );

        return;
    }


    hFindWindow = CreateWindowExA(
        WS_EX_DLGMODALFRAME,

        "MyFindWindow",

        "Find",

        WS_OVERLAPPED |
        WS_CAPTION |
        WS_SYSMENU,

        CW_USEDEFAULT,
        CW_USEDEFAULT,

        360,
        140,

        hwnd,

        NULL,

        GetModuleHandle(NULL),

        NULL
    );


    if (hFindWindow == NULL)
        return;


    ShowWindow(
        hFindWindow,
        SW_SHOW
    );


    UpdateWindow(
        hFindWindow
    );
}


/* =========================================================
   Toggle word wrap
   ========================================================= */

void ToggleWordWrap(HWND hwnd)
{
    LONG style =
        GetWindowLongA(
            hEdit,
            GWL_STYLE
        );


    if (wordWrap)
    {
        /* Turn OFF */

        style &= ~ES_AUTOHSCROLL;

        SetWindowLongA(
            hEdit,
            GWL_STYLE,
            style
        );

        wordWrap = FALSE;
    }
    else
    {
        /* Turn ON */

        style |= ES_AUTOHSCROLL;

        SetWindowLongA(
            hEdit,
            GWL_STYLE,
            style
        );

        wordWrap = TRUE;
    }


    SetWindowPos(
        hEdit,

        NULL,

        0,
        0,
        0,
        0,

        SWP_NOMOVE |
        SWP_NOSIZE |
        SWP_NOZORDER |
        SWP_FRAMECHANGED
    );


    UpdateStatus();
}


/* =========================================================
   Create menu
   ========================================================= */

HMENU CreateMainMenu()
{
    HMENU menu =
        CreateMenu();


    /* ================= FILE ================= */

    HMENU file =
        CreatePopupMenu();


    AppendMenuA(
        file,
        MF_STRING,
        ID_NEW,
        "New"
    );


    AppendMenuA(
        file,
        MF_STRING,
        ID_OPEN,
        "Open..."
    );


    AppendMenuA(
        file,
        MF_STRING,
        ID_SAVE,
        "Save"
    );


    AppendMenuA(
        file,
        MF_STRING,
        ID_SAVE_AS,
        "Save As..."
    );


    AppendMenuA(
        file,
        MF_SEPARATOR,
        0,
        NULL
    );


    AppendMenuA(
        file,
        MF_STRING,
        ID_EXIT,
        "Exit"
    );


    /* ================= EDIT ================= */

    HMENU edit =
        CreatePopupMenu();


    AppendMenuA(
        edit,
        MF_STRING,
        ID_UNDO,
        "Undo"
    );


    AppendMenuA(
        edit,
        MF_STRING,
        ID_REDO,
        "Redo"
    );


    AppendMenuA(
        edit,
        MF_SEPARATOR,
        0,
        NULL
    );


    AppendMenuA(
        edit,
        MF_STRING,
        ID_CUT,
        "Cut"
    );


    AppendMenuA(
        edit,
        MF_STRING,
        ID_COPY,
        "Copy"
    );


    AppendMenuA(
        edit,
        MF_STRING,
        ID_PASTE,
        "Paste"
    );


    AppendMenuA(
        edit,
        MF_STRING,
        ID_DELETE,
        "Delete"
    );


    AppendMenuA(
        edit,
        MF_SEPARATOR,
        0,
        NULL
    );


    AppendMenuA(
        edit,
        MF_STRING,
        ID_SELECT_ALL,
        "Select All"
    );


    AppendMenuA(
        edit,
        MF_STRING,
        ID_FIND,
        "Find..."
    );


    /* ================= VIEW ================= */

    HMENU view =
        CreatePopupMenu();


    AppendMenuA(
        view,
        MF_STRING,
        ID_WORD_WRAP,
        "Word Wrap"
    );


    AppendMenuA(
        view,
        MF_STRING,
        ID_FONT,
        "Font..."
    );


    /* ================= MAIN MENU ================= */

    AppendMenuA(
        menu,
        MF_POPUP,
        (UINT_PTR)file,
        "File"
    );


    AppendMenuA(
        menu,
        MF_POPUP,
        (UINT_PTR)edit,
        "Edit"
    );


    AppendMenuA(
        menu,
        MF_POPUP,
        (UINT_PTR)view,
        "View"
    );


    return menu;
}


/* =========================================================
   Main window procedure
   ========================================================= */

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (msg)
    {
        /* =================================================
           CREATE
           ================================================= */

        case WM_CREATE:
        {
            /* Text editor */

            hEdit = CreateWindowExA(
                WS_EX_CLIENTEDGE,

                "EDIT",

                "",

                WS_CHILD |
                WS_VISIBLE |
                WS_VSCROLL |
                ES_MULTILINE |
                ES_AUTOVSCROLL |
                ES_WANTRETURN |
                ES_NOHIDESEL,

                0,
                0,
                0,
                0,

                hwnd,

                (HMENU)ID_EDIT,

                GetModuleHandle(NULL),

                NULL
            );


            /* Font */

            hFont = CreateFontA(
                -18,

                0,
                0,
                0,

                FW_NORMAL,

                FALSE,
                FALSE,
                FALSE,

                DEFAULT_CHARSET,

                OUT_DEFAULT_PRECIS,

                CLIP_DEFAULT_PRECIS,

                CLEARTYPE_QUALITY,

                FIXED_PITCH |
                FF_MODERN,

                "Consolas"
            );


            SendMessageA(
                hEdit,
                WM_SETFONT,
                (WPARAM)hFont,
                TRUE
            );


            /* Status bar */

            hStatus = CreateWindowExA(
                0,

                "STATIC",

                "Ln 1, Col 1    Saved",

                WS_CHILD |
                WS_VISIBLE |
                SS_LEFT,

                0,
                0,
                0,
                0,

                hwnd,

                (HMENU)ID_STATUS,

                GetModuleHandle(NULL),

                NULL
            );


            /* Menu */

            SetMenu(
                hwnd,
                CreateMainMenu()
            );


            UpdateTitle(hwnd);

            UpdateStatus();

            break;
        }


        /* =================================================
           RESIZE
           ================================================= */

        case WM_SIZE:
        {
            int width =
                LOWORD(lParam);

            int height =
                HIWORD(lParam);


            int statusHeight = 25;


            MoveWindow(
                hEdit,

                0,
                0,

                width,
                height - statusHeight,

                TRUE
            );


            MoveWindow(
                hStatus,

                0,
                height - statusHeight,

                width,
                statusHeight,

                TRUE
            );


            break;
        }


        /* =================================================
           COMMANDS
           ================================================= */

        case WM_COMMAND:
        {
            /* Text changed */

            if (
                LOWORD(wParam) == ID_EDIT &&
                HIWORD(wParam) == EN_CHANGE
            )
            {
                modified = TRUE;

                UpdateTitle(hwnd);

                UpdateStatus();

                break;
            }


            /* Selection changed */

            if (
                LOWORD(wParam) == ID_EDIT &&
                HIWORD(wParam) == EN_SETFOCUS
            )
            {
                UpdateStatus();

                break;
            }


            switch (LOWORD(wParam))
            {
                case ID_NEW:

                    NewDocument(hwnd);

                    break;


                case ID_OPEN:

                    OpenDocument(hwnd);

                    break;


                case ID_SAVE:

                    SaveFile(hwnd);

                    break;


                case ID_SAVE_AS:

                    SaveAsFile(hwnd);

                    break;


                case ID_EXIT:

                    if (
                        CheckUnsavedChanges(hwnd)
                    )
                    {
                        DestroyWindow(hwnd);
                    }

                    break;


                case ID_UNDO:

                    SendMessageA(
                        hEdit,
                        EM_UNDO,
                        0,
                        0
                    );

                    break;


                case ID_REDO:

                    SendMessageA(
                        hEdit,
                        EM_REDO,
                        0,
                        0
                    );

                    break;


                case ID_CUT:

                    SendMessageA(
                        hEdit,
                        WM_CUT,
                        0,
                        0
                    );

                    break;


                case ID_COPY:

                    SendMessageA(
                        hEdit,
                        WM_COPY,
                        0,
                        0
                    );

                    break;


                case ID_PASTE:

                    SendMessageA(
                        hEdit,
                        WM_PASTE,
                        0,
                        0
                    );

                    break;


                case ID_DELETE:

                    SendMessageA(
                        hEdit,
                        WM_CLEAR,
                        0,
                        0
                    );

                    break;


                case ID_SELECT_ALL:

                    SendMessageA(
                        hEdit,
                        EM_SETSEL,
                        0,
                        -1
                    );

                    break;


                case ID_FIND:

                    OpenFindDialog(hwnd);

                    break;


                case ID_WORD_WRAP:

                    ToggleWordWrap(hwnd);

                    break;


                case ID_FONT:

                    OpenFontDialog(hwnd);

                    break;
            }

            break;
        }


        /* =================================================
           Dark editor
           ================================================= */

        case WM_CTLCOLOREDIT:
        {
            HDC hdc =
                (HDC)wParam;


            SetTextColor(
                hdc,
                editorText
            );


            SetBkColor(
                hdc,
                editorBackground
            );


            if (hEditorBrush == NULL)
            {
                hEditorBrush =
                    CreateSolidBrush(
                        editorBackground
                    );
            }


            return (LRESULT)hEditorBrush;
        }


        /* =================================================
           CLOSE
           ================================================= */

        case WM_CLOSE:
        {
            if (
                CheckUnsavedChanges(hwnd)
            )
            {
                DestroyWindow(hwnd);
            }

            break;
        }


        /* =================================================
           DESTROY
           ================================================= */

        case WM_DESTROY:
        {
            if (hFont != NULL)
            {
                DeleteObject(hFont);
                hFont = NULL;
            }


            if (hEditorBrush != NULL)
            {
                DeleteObject(hEditorBrush);
                hEditorBrush = NULL;
            }


            PostQuitMessage(0);

            break;
        }


        default:

            return DefWindowProcA(
                hwnd,
                msg,
                wParam,
                lParam
            );
    }


    return 0;
}


/* =========================================================
   Register Find window class
   ========================================================= */

BOOL RegisterFindWindowClass(
    HINSTANCE hInstance
)
{
    WNDCLASSA wc;

    ZeroMemory(
        &wc,
        sizeof(wc)
    );


    wc.lpfnWndProc =
        FindWindowProc;

    wc.hInstance =
        hInstance;

    wc.lpszClassName =
        "MyFindWindow";

    wc.hCursor =
        LoadCursor(
            NULL,
            IDC_ARROW
        );


    wc.hbrBackground =
        (HBRUSH)(
            COLOR_BTNFACE + 1
        );


    return RegisterClassA(&wc);
}


/* =========================================================
   Main
   ========================================================= */

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    const char CLASS_NAME[] =
        "MyCoolNotepad";


    /* Register find window */

    RegisterFindWindowClass(
        hInstance
    );


    /* Main window class */

    WNDCLASSA wc;

    ZeroMemory(
        &wc,
        sizeof(wc)
    );


    wc.lpfnWndProc =
        WindowProc;

    wc.hInstance =
        hInstance;

    wc.lpszClassName =
        CLASS_NAME;

    wc.hCursor =
        LoadCursor(
            NULL,
            IDC_ARROW
        );

    wc.hbrBackground =
        (HBRUSH)(
            COLOR_WINDOW + 1
        );


    if (!RegisterClassA(&wc))
    {
        MessageBoxA(
            NULL,
            "Could not register window.",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return 0;
    }


    /* Create window */

    HWND hwnd =
        CreateWindowExA(
            0,

            CLASS_NAME,

            "Untitled - My Notepad",

            WS_OVERLAPPEDWINDOW,

            CW_USEDEFAULT,
            CW_USEDEFAULT,

            1000,
            700,

            NULL,
            NULL,

            hInstance,

            NULL
        );


    if (hwnd == NULL)
    {
        MessageBoxA(
            NULL,
            "Could not create window.",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return 0;
    }


    /* Show */

    ShowWindow(
        hwnd,
        nCmdShow
    );


    UpdateWindow(hwnd);


    /* Message loop */

    MSG msg;


    while (
        GetMessageA(
            &msg,
            NULL,
            0,
            0
        ) > 0
    )
    {
        TranslateMessage(&msg);

        DispatchMessageA(&msg);
    }


    return 0;
}