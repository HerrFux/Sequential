#ifndef HELP_FLAG_INDEX
#define HELP_FLAG_INDEX 0
#endif
#ifndef VERBOSE_FLAG_INDEX
#define VERBOSE_FLAG_INDEX 1
#endif
#ifndef VERSION_FLAG_INDEX
#define VERSION_FLAG_INDEX 2
#endif

#ifndef VERBOSE_ACTIVE // todo: as mentioned in main.c already maybe implement a prettier solution
#define VERBOSE_ACTIVE flags_ptr[VERBOSE_FLAG_INDEX]
#endif

char *flags_ptr;