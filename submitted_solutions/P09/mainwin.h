#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"

const std::string VERSION{"0.0.1"};

const std::string APP_NAME{"UTA_CSE1325_SHELTER_v0.0.1"};

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
		void on_new_client_click();
		void on_list_clients_click();

	private:
		Shelter *shelter;
		Gtk::Label *data;
		Gtk::Label *msg;
};
#endif