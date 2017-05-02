/* -*- mode: c; coding: utf-8 -*-
 *
 * 	--input-charset=utf-8 --exec-charset=cp932
 *
 */

#if defined(WINDOWS) && (WINDOWS > 0)

#include <windows.h>
#include <stdio.h>
#include <sys/stat.h>
#include <io.h>

/*
 * ファイル名は一時的なバッファです。
 */
char *
makeTempFile()
{
    static char template[] = "TAGXXXXXX";

    strcpy(template, "TAGXXXXXX");

    _mktemp(template);

    return template;
}

BOOL
SetClipbordFromFile(char *lpFilename)
{
    HGLOBAL hMem;                               // 設定用のメモリ変数
    LPTSTR lpBuff;                              // 複写用のポインタ
    DWORD dwSize;                               // 複写元の長さ

    struct stat stat_buf;
    FILE *fp;

    if (0 != stat(lpFilename, &stat_buf)) {
        perror(lpFilename);
        return FALSE;
    }
    dwSize = (DWORD) stat_buf.st_size + 1;
    if (!(fp = fopen(lpFilename, "rb"))) {
        int err = errno;
        fprintf(stderr, "%s(%d): %s: %s\n",
                __FILE__, __LINE__, strerror(err), lpFilename);
        return FALSE;
    }

    // クリップボードにデータを設定
    if (NULL == (hMem = GlobalAlloc((GHND|GMEM_SHARE), dwSize))){
        return FALSE;
    }
    if (NULL == (lpBuff = (LPTSTR)GlobalLock(hMem))){
        GlobalFree(hMem);                    // ロックできないとき解放
        fclose(fp);
        return FALSE;
    }

    fread(lpBuff, 1, (size_t) stat_buf.st_size, fp);
    fclose(fp);

    GlobalUnlock(hMem);

    if (!OpenClipboard(NULL) ){
        GlobalFree(hMem);          // クリップボードが開けないとき解放
        return FALSE;
    }
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);          // データを設定
    CloseClipboard();
    // Windows によって管理されるのでメモリの解放は不要

    return TRUE;
}

#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ファイル名は一時的なバッファです。
 */
char *
makeTempFile()
{
    static char template[] = "TAGXXXXXX";

    strcpy(template, "TAGXXXXXX");

    mkstemp(template);

    return template;
}

int
SetClipbordFromFile(char *lpFilename)
{
    printf("未サポートです。(%s)\n", lpFilename);
    return 0;
}
#endif //WIN
