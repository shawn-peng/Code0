#ifndef __CODE0_WIN_H
#define __CODE0_WIN_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/stack.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/searchbar.h>
#include <gtkmm/searchentry.h>
#include <gtkmm/menubutton.h>
#include <gtkmm/revealer.h>
#include <gtkmm/listbox.h>
#include <gtkmm/label.h>
#include <gtkmm/textview.h>
#include <gtkmm/builder.h>

#include <giomm/file.h>
#include <giomm/settings.h>

class Code0Win : public Gtk::Window
{

public:
	Code0Win();
	Code0Win(BaseObjectType* cobject,
			const Glib::RefPtr<Gtk::Builder>& refGlade);
	virtual ~Code0Win();
	void open(Glib::RefPtr<Gio::File> file);

protected:
	Glib::RefPtr<Gtk::Builder> m_builder;
	
private:
	// Glib::RefPtr<Gio::Settings>		m_settings;
	// Glib::RefPtr<Gtk::Stack>			m_stack;
	// Glib::RefPtr<Gtk::ToggleButton>	m_search;
	// Glib::RefPtr<Gtk::SearchBar>		m_searchbar;
	// Glib::RefPtr<Gtk::SearchEntry>	m_searchentry;
	// Glib::RefPtr<Gtk::MenuButton>	m_gears;
	// Glib::RefPtr<Gtk::Revealer>		m_sidebar;
	// Glib::RefPtr<Gtk::ListBox>		m_words;
	// Glib::RefPtr<Gtk::Label>			m_lines;
	// Glib::RefPtr<Gtk::Label>			m_lines_label;
	
	Gio::Settings		*m_settings;
	Gtk::Stack			*m_stack;
	Gtk::ToggleButton	*m_search;
	Gtk::SearchBar		*m_searchbar;
	Gtk::SearchEntry	*m_searchentry;
	Gtk::MenuButton		*m_gears;
	Gtk::Revealer		*m_sidebar;
	Gtk::ListBox		*m_words;
	Gtk::Label			*m_lines;
	Gtk::Label			*m_lines_label;
};

#endif // __CODE0_WIN_H