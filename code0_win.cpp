#include "code0_win.h"
#include <iostream>

#include <gtkmm/builder.h>

using namespace std;

Code0Win::Code0Win()
{
	//auto builder = Gtk::Builder::create_from_resource(
	//		"/code0/gears-menu.ui");
	
	
	Gtk::Window *pCode0Win;
}

Code0Win::Code0Win(BaseObjectType* cobject,
		const Glib::RefPtr<Gtk::Builder>& builder) :
	Gtk::Window(cobject), m_builder(builder)
{
	//m_settings = Glib::RefPtr<Gio::Settings>::cast_dynamic();
	m_builder->get_widget("stack", m_stack);
	m_builder->get_widget("search", m_search);
	m_builder->get_widget("searchbar", m_searchbar);
	m_builder->get_widget("searchentry", m_searchentry);
	m_builder->get_widget("gears", m_gears);
	m_builder->get_widget("sidebar", m_sidebar);
	m_builder->get_widget("words", m_words);
	m_builder->get_widget("lines", m_lines);
	m_builder->get_widget("lines_label", m_lines_label);
	
	//m_stack
	//m_search
	//m_searchbar
	//m_searchentry
	//m_gears
	//m_sidebar
	//m_words
	//m_lines
	//m_lines_label
}

Code0Win::~Code0Win()
{
}

void Code0Win::open(Glib::RefPtr<Gio::File> file)
{
	gchar *contents;
	gsize length;
	
	cout << __FUNCTION__ << " called." << endl;
	
	//auto view = new Gtk::TextView();
	//view->set_editable(TRUE);
	//view->set_cursor_visible(TRUE);
	//view->show();
	//
	//auto buffer = view->get_buffer();
	//
	//auto basename = file->get_basename();
	//cout << basename << endl;
	//if (file->load_contents(contents, length))
	//{
	//	buffer->set_text(contents);
	//}
}
