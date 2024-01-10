#include <mbl/io.h>

char *file_read (const char *path, size_t *len) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    *len = (size_t) ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buf = (char *) malloc((*len)+1);
    if (!buf) {
        fclose(file);
        return NULL;
    }
    size_t read = fread(buf, 1, *len, file);
    if (read < *len) {
        free(buf);
        fclose(file);
        return NULL;
    }
    buf[*len] = '\0';
    fclose(file);
    return buf;
}

char file_write (const char *path, const char *src, const size_t len) {
    FILE *file = fopen(path, "w");
    if (!file) {
        return 0;
    }
    size_t cnt = fwrite(src, 1, len, file);
    fclose(file);
    return cnt == len;
}