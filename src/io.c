#include <mbl/io.h>

string_t file_read (const char *path) {
    string_t str = { NULL, 0 };
    FILE *file = fopen(path, "rb");
    if (!file) {
        return nullstr;
    }
    fseek(file, 0, SEEK_END);
    str.len = (size_t) ftell(file);
    fseek(file, 0, SEEK_SET);
    str.src = (char *) malloc(str.len + 1);
    if (!str.src) {
        fclose(file);
        return nullstr;
    }
    size_t read = fread(str.src, 1, str.len, file);
    if (read < str.len) {
        free(str.src);
        fclose(file);
        return nullstr;
    }
    str.src[str.len] = '\0';
    fclose(file);
    return str;
}

char file_write (const char *path, const string_t str) {
    FILE *file = fopen(path, "w");
    if (!file) {
        return 0;
    }
    size_t cnt = fwrite(str.src, 1, str.len, file);
    fclose(file);
    return cnt == str.len;
}