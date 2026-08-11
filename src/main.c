#include <stdio.h>

#ifdef __has_include
#if __has_include(<SDL_ttf.h>)
#include <SDL_ttf.h>
#define HAS_SDL_TTF 1
#endif
#endif

#ifndef HAS_SDL_TTF
#define HAS_SDL_TTF 0
#endif

int main(void) {
    printf("===========================\n");
    printf("hello world");
#if HAS_SDL_TTF
    printf("SDL_ttf version: %d.%d.%d\n",
           SDL_TTF_MAJOR_VERSION, SDL_TTF_MINOR_VERSION, SDL_TTF_PATCHLEVEL);
    if (TTF_Init() == 0) {
        int major = 0, minor = 0, patch = 0;
        TTF_Linked_Version();
        const SDL_version* v = TTF_Linked_Version();
        major = v->major;
        minor = v->minor;
        patch = v->patch;
        printf("Linked SDL_ttf: %d.%d.%d\n", major, minor, patch);
        TTF_Quit();
    }
#else
    printf("SDL_ttf headers not available at build time\n");
#endif
    return 0;
}
