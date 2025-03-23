#ifndef __LOGGER_DEF_H__
#define __LOGGER_DEF_H__

#define COLOR_RESET "\033[0m"

#define when_true(c, l) do { if (c) goto l; } while(0)

#define when_true_status(c, l, e) do { if (c) { goto l; e;} } while(0)

#define when_null(c, l) do { if (c == NULL) goto l; } while(0)

#define when_null_status(c, l, e) do { if (c == NULL) { goto l; e;} } while(0)

#endif /* __LOGGER_DEF_H__ */