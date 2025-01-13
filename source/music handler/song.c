#include "song.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

song_t *newSong(const char *path, const char *filename)
{
    song_t *res;

    res = malloc(sizeof(song_t));
    res->path = malloc(sizeof(char) * strlen(path)+1);
    res->filename = malloc(sizeof(char) * strlen(filename)+1);
    strcpy(res->path, path);
    strcpy(res->filename, filename);

    return res;
}
void destroySong(song_t *song)
{
    free(song->filename);
    free(song->path);
    free(song);

    return;
}
