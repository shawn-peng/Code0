#ifndef __CODE0WIN_H
#define __CODE0WIN_H

#include <gtkmm.h>
#include "application.h"


#define EXAMPLE_APP_WINDOW_TYPE (example_app_window_get_type ())
#define EXAMPLE_APP_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EXAMPLE_APP_WINDOW_TYPE, Code0Window))


typedef struct _Code0Window Code0Window;
typedef struct _Code0WindowClass Code0WindowClass;


GType example_app_window_get_type(void);
Code0Window *example_app_window_new(Code0App *app);
void example_app_window_open(Code0Window *win, GFile *file);


#endif /* __CODE0WIN_H */
