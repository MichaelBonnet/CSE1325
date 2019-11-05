#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"

const std::string VERSION{"0.1.0"};

const std::string APP_NAME{"edu.uta.cse1325.shelter.v0_1_0"};

class Mainwin : public Gtk::Window
{
	public:
		Mainwin();
		Mainwin(Shelter& shelter);
		~Mainwin();

	protected:
		void on_quit_click();
		void on_new_animal_click();
		void on_list_animals_click();

	private:
		Shelter *shelter;
		Gtk::Label *data;
		Gtk::Label *msg;
};
#endif



