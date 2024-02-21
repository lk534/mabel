#ifndef MBL_LOGGER_H
#define MBL_LOGGER_H

#include <stdio.h>

#define ANSI_RST "\033[00m"
#define ANSI_RED "\033[31m"
#define ANSI_YEL "\033[33m"
#define ANSI_BLU "\033[34m"
#define ANSI_CYN "\033[36m"

#ifdef MBL_DBG_ENABLE
#define MBL_DBG(fmt, ...) printf("[%sDBG%s] %s: " fmt "\n", ANSI_CYN, ANSI_RST, __FILE__, ##__VA_ARGS__)
#else
#define MBL_DBG(fmt, ...)
#endif

#define MBL_INF(fmt, ...) printf("[%sINF%s] %s: " fmt "\n", ANSI_BLU, ANSI_RST, __FILE__, ##__VA_ARGS__)
#define MBL_WRN(fmt, ...) printf("[%sWRN%s] %s: " fmt "\n", ANSI_YEL, ANSI_RST, __FILE__, ##__VA_ARGS__)
#define MBL_ERR(fmt, ...) printf("[%sERR%s] %s: " fmt "\n", ANSI_RED, ANSI_RST, __FILE__, ##__VA_ARGS__)

#define MBL_TRM(fmt, ...) do { \
        MBL_ERR(fmt, ##__VA_ARGS__); \
        exit(1); \
    } while(0)

#endif