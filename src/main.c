/*
 * $Id$
 *
 * オプションスイッチは以下に準拠したつもりです。
 * http://www.gnu.org/prep/standards/html_node/Option-Table.html
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

#include "base64.h"

#define VERSION "1.00"
#define BUILD "(internal: $Rev$ Build: "  __DATE__ " " __TIME__ ")"

typedef struct {
    const char *lpszMimeType;
    unsigned char magic[3];
} IMG_MAGIC, *PIMG_MAGIC;

static void
help()
{
    printf(
        "Usage: img2html [options] [画像ファイル...]"
        "\n画像ファイルから html の img タグを作成します。\n"
        "\n      --help     このメッセージを表示します。"
        "\n  -v, --version  version情報を表示して終了します。"
        "\n\n画像データを標準入力から得る場合は画像ファイルに"
        " - を指定します。"
        "\n\n" BUILD
        "\n");
}

static void
version()
{
    printf("img2html %s\n"
           "Copyright (C) 2017 T. Furukawa\n", VERSION);
}

static const char *
getMimeType(const unsigned char* buf)
{
   static IMG_MAGIC tblImage[] = {
        {"png", {0x89, 0x50, 0x4E}},
        {"jpeg", {0xFF, 0xD8, 0xDD}},
        {"jpeg", {0xFF, 0xD8, 0xff}},
        {"gif", {0x47, 0x49, 0x46}},
        {NULL, {0, 0, 0}}
    };
   int i;

   for (i = 0; tblImage[i].lpszMimeType; i++) {
       if (0 == memcmp(tblImage[i].magic, buf, 3)) {
           return tblImage[i].lpszMimeType;
       }
   }
   return NULL;
}

static int
generate(const char *filename)
{
    FILE *fp;
    unsigned char buf[4];
    char szB64[8];
    int c;
    int cb;

    printf("<!-- %s -->", filename);

    if (0 == strcmp("-", filename)) {
        fp = stdin;
    } else {
        fp = freopen(filename, "rb", stdin);
    }
    if (!fp) {
        int err = errno;
        perror(filename);
        return err;
    }

    cb = 0;
    while (EOF != (c = getc(fp))) {
        buf[cb % 3] = (unsigned char) c;
        if (2 == (cb % 3)) {
            if (2 == cb) {
                const char *lpszMime = getMimeType(buf);

                if (!lpszMime) {
                    printf("<!-- unknown image file -->");
                    break;
                }
                printf("<img src=\"data:image/%s;base64,", lpszMime);
            }

            EncodeBase64(buf, (size_t) ((cb % 3) + 1), szB64);
            printf("%s", szB64);
        }
        cb++;
    }

    if (0 != (cb % 3)) {
        EncodeBase64(buf, (size_t) ((cb % 3)), szB64);
        printf("%s", szB64);
    }

    printf("\" />\n");

    fclose(fp);
    return 0;
}

/*
 * エントリ
 */
int
main(int argc, char *argv[])
{
    int i;

    while (1) {
        int c;
        static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"version", no_argument, 0, 'v'},
            {0, 0, 0, 0,}
        };

        int option_index = 0;
        if (-1 == (c = getopt_long(argc, argv, "hv",
                                   long_options, &option_index))) {
            break;
        }

        switch (c) {
        case 'v':
            version();
            return 0;
        case 'h':
            help();
            return 0;
        default:
            fprintf(stderr, "不明なオプション[%c]\n", c);
            return 1;
        }
    }

    for (i = optind; i < argc; i++) {
        int err;
        if (0 != (err = generate(argv[i]))) {
            return err;
        }
    }

    return 0;
}
/*
 * Local Variables:
 * mode: c
 * coding: utf-8-unix
 * End:
 */
