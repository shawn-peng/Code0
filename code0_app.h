#ifndef __CODE0_APP_H
#define __CODE0_APP_H

#include <gtkmm/window.h>

class Code0App : public Gtk::Application
{

public:
	Code0App();
	Code0App(int argc, char *argv[]);
	virtual ~Code0App();
	
	//int run();
	void on_activate() override;
	void on_startup() override;
	void on_open(const type_vec_files &files,
			const Glib::ustring &hint) override;
};

#endif // __CODE0_APP_H