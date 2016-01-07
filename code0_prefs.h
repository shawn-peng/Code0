#ifndef __CODE0APPPREFS_H
#define __CODE0APPPREFS_H

#include <gtk/gtk.h>
#include "exampleappwin.h"


#define EXAMPLE_APP_PREFS_TYPE (example_app_prefs_get_type ())
#define EXAMPLE_APP_PREFS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EXAMPLE_APP_PREFS_TYPE, Code0AppPrefs))


typedef struct _Code0AppPrefs Code0AppPrefs;
typedef struct _Code0AppPrefsClass Code0AppPrefsClass;


GType example_app_prefs_get_type(void);
Code0AppPrefs *example_app_prefs_new(Code0Window *win);


#endif /* __CODE0APPPREFS_H */
