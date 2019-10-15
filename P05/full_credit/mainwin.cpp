#include "mainwin.h"
#include "entrydialog.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store}
{
    // /////////////////
    // G U I   S E T U P
    // /////////////////
	set_default_size(400, 400);
    set_title("Mav's Ultimate Sweet Shop");

    // Set up a vertical box to hold the main window elements
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
  	add(*vbox);


    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
	Gtk::MenuBar *main_menu_bar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*main_menu_bar, Gtk::PACK_SHRINK, 0);


 	/////////////
 	// FILE STUFF
    // create file submenu
 	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    main_menu_bar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

	// create quit and new store options
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	Gtk::MenuItem *menuitem_new_store = Gtk::manage(new Gtk::MenuItem("_New Store", true));

	// Link options and functions
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    menuitem_new_store->signal_activate().connect([this] {this->on_new_store_click();});

    // Link menu items
    filemenu->append(*menuitem_quit);
    filemenu->append(*menuitem_new_store);


    ///////////////
    // SWEETS STUFF
    // create sweets submenu
    Gtk::MenuItem *menuitem_sweets = Gtk::manage(new Gtk::MenuItem("_Sweets", true));
    main_menu_bar->append(*menuitem_sweets);
    Gtk::Menu *sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(*sweetsmenu);

	// Create add sweet & list sweet options
	Gtk::MenuItem *menuitem_add_sweet = Gtk::manage(new Gtk::MenuItem("_Add", true));
	Gtk::MenuItem *menuitem_list_sweets = Gtk::manage(new Gtk::MenuItem("List Sweets", true));

	// Link options and functions
    menuitem_add_sweet->signal_activate().connect([this] { this->on_add_sweet_click(); });
    menuitem_list_sweets->signal_activate().connect( [this] { this->on_list_sweets_click(); } );

    // Link menu items
    sweetsmenu->append(*menuitem_add_sweet);
    sweetsmenu->append(*menuitem_list_sweets);


    /////////////
    // HELP STUFF
    // Create help submenu
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    main_menu_bar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    // add about button
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);


    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)



    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders



    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible
 	vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// ///////////////// 


void Mainwin::on_quit_click()
{
    close();
}

void Mainwin::on_new_store_click()
{
	_store = new Store(); // I feel like maybe this needs to be more complex
}

void Mainwin::on_add_sweet_click()
{
    // getting name of sweet from user
    EntryDialog name_dialog{*this, "Enter Sweet Name"};
    name_dialog.run();
    std::string name = name_dialog.get_text();

    // getting price of sweet from user
    EntryDialog price_dialog{*this, "Enter Price of " + name};
    price_dialog.run();
    double price = std::stod(price_dialog.get_text());
    _store->add( *(new Sweet(name, price)) );

	// Gtk::MessageDialog* name_dialog = new Gtk::MessageDialog(*this, "Enter Sweet Name");
	// name_dialog->show();
	// Gtk::Entry* name_entry{new Gtk::Entry{}}; 
	// name_dialog->get_content_area()->pack_start(*name_entry);
	// name_entry->show();
	// std::string name = name_entry->get_text();
	// name_entry->hide();

	// Gtk::MessageDialog* price_dialog = new Gtk::MessageDialog(*this, "Enter " + name + " Price");
	// price_dialog->show();
	// Gtk::Entry* price_entry{new Gtk::Entry{}}; 
	// price_dialog->get_content_area()->pack_start(*price_entry);
	// price_entry->show();
	// double price = std::stod(price_entry->get_text());
	// price_entry->hide();
	// _store->add( *(new Sweet(name, price)) );
}

void Mainwin::on_about_click()
{
	Gtk::MessageDialog{*this, R"(

    Mav's Ultra Sweet Shop (MUSS)
    =============================

    Manage a sweet shop filled with sweets.
    Copyright 2019 Michael A. Bonnet

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	)"}.run();
}


void Mainwin::on_list_sweets_click() // cant figure out how to use overloaded operator
{                                    // but lord help me this works.
	std::string sweets_list;
	for (int i = 0; i < _store->num_sweets(); i++)
	{
		Sweet sweet1 = _store->sweet(i);
		sweets_list += sweet1.name() + " ";
		sweets_list += std::to_string(sweet1.price());
		sweets_list += "\n";
	}
	Gtk::MessageDialog{*this, sweets_list}.run();
}

// =====================================

    ///////////////
    // ORDERS STUFF
    // Create orders submenu
    // Gtk::MenuItem menuitem_orders = Gtk::manage(new Gtk::MenuItem("Orders", true));
    // main_menu_bar->append(menuitem_orders);
    // Gtk::Menu ordersmenu = Gtk::manage(new Gtk::Menu());
    // menuitem_orders->set_submenu(ordersmenu);

    // Create place order button
    // Gtk::ToolButton place_order_button = Gtk::manage(new Gtk::ToolButton("Place Order", true));
    // place_order_button->signal_activate().connect( [this] { this->on_place_order_click(); } );
    // ordersmenu->append(place_order_button);

    // Create list orders button
    // Gtk::ToolButton list_orders_button = Gtk::manage(new Gtk::ToolButton("List Orders", true));
    // place_order_button->signal_activate().connect( [this] { this->on_list_orders_click(); } );
    // ordersmenu->append(list_orders_button);