#include "code0_app.h"
#include "code0_win.h"

#include <gtkmm/application.h>
#include <gtkmm/builder.h>
#include <gtkmm/menu.h>
#include <giomm/application.h>

#include <iostream>

using namespace std;

Code0App::Code0App() :
		Gtk::Application("org.code0", Gio::APPLICATION_HANDLES_OPEN)
{
}

Code0App::Code0App(int argc, char *argv[]) :
		Gtk::Application(argc, argv, "org.code0", Gio::APPLICATION_HANDLES_OPEN)
{
}

Code0App::~Code0App()
{
	
}

void Code0App::on_activate()
{
	cout << __FUNCTION__ << " called" << endl;
	Code0Win *win;
	auto builder = Gtk::Builder::create_from_resource("/org/code0/code0_win.ui");
	builder->get_widget_derived("code0_win", win);
	add_window(*win);
	win->present();
	
	Gtk::Application::on_activate();
}

void Code0App::on_startup()
{
	cout << __FUNCTION__ << " called" << endl;
	Gtk::Application::on_startup();
	
	auto builder = Gtk::Builder::create_from_resource("/org/code0/app-menu.ui");
	auto menuobj = builder->get_object("appmenu");
	auto menu = Glib::RefPtr<Gio::MenuModel>::cast_dynamic(menuobj);
	set_app_menu(menu);
}

void Code0App::on_open(const type_vec_files &files, const Glib::ustring &hint)
{
	cout << __FUNCTION__ << " called" << endl;
	//Code0Win *win;
	Code0Win *win;
	int i;
	auto windows = get_windows();
	
	if (!windows.empty())
	{
		cout << "find window." << endl;
		win = (Code0Win *)windows[0];
	}
	else
	{
		cout << "didn't find window." << endl;
		auto builder = Gtk::Builder::create_from_resource("/org/code0/code0_win.ui");
		builder->get_widget_derived("code0_win", win);
	}

	for (auto file = files.begin(); file != files.end(); file++)
		win->open(*file);

	add_window(*win);
	win->present();
}

// int Code0App::run()
// {
	// Code0Win *pCode0Win = nullptr;
	// auto builder = Gtk::Builder::create_from_resource("/org/code0/code0_win.ui");
	// builder->get_widget_derived("code0_win", pCode0Win);
	
	// pCode0Win->present();
	
	// cout << __FUNCTION__ << " called" << endl;
	// return Gtk::Application::run(*pCode0Win);
// }