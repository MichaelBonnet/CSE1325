#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{ *( new Store ) } { }

Mainwin::Mainwin( Store& store ) : _store{ &store }
{

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 400);
    set_title("Mav's Ultimate Sweet Shop");

    // Set up a vertical box to hold the main window elements

    Gtk::Box vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(vbox);

    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
 
    // Create menu bar
    Gtk::MenuBar menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(menubar, Gtk::PACK_SHRINK, 0);

    // Create and manage File dropdown
    Gtk::MenuItem menuitem_file = Gtk::manage(new Gtk::MenuItem("File", true));
    menubar->append(menuitem_file);
    Gtk::Menu filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(filemenu);

    // Create quit option
    Gtk::MenuItem menuitem_quit = Gtk::manage(new Gtk::MenuItem("Quit", true));
    menuitem_quit->signal_activate().connect( [this] { this->on_quit_click(); } );
    filemenu->append(menuitem_quit);

    // Create about option
    Gtk::MenuItem menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect( [this] { this->on_about_click(); } );
    filemenu->append(menuitem_about);

    // Create new store option
    Gtk::MenuItem menuitem_new_store = Gtk::manage(new Gtk::MenuItem("New Store", true));
    menuitem_new_store->signal_activate().connect( [this] { this->on_new_store_click(); } );
    filemenu->append(menuitem_new_store);

    
	// SWEETS STUFF
    // Create sweets submenu
    Gtk::MenuItem menuitem_sweets = Gtk::manage(new Gtk::MenuItem("Sweets", true));
    menubar->append(menuitem_sweets);
    Gtk::Menu sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(sweetsmenu);

    // Create add sweet option
    Gtk::ToolButton add_sweet_button = Gtk::manage(new Gtk::ToolButton("Add Sweets", true));
    menuitem_add_sweet->signal_activate().connect( [this] { this->on_add_sweet_click(); } );
    // sweetsmenu->append(menuitem_add_sweet);

    // Create list sweets option
    Gtk::ToolButton list_sweets_button = Gtk::manage(new Gtk::ToolButton("List Sweets", true));
    menuitem_list_sweets->signal_activate().connect( [this] { this->on_list_sweets_click(); } );
    // sweetsmenu->append(menuitem_list_sweets);


    // ORDERS STUFF
    // Create orders submenu
    Gtk::MenuItem menuitem_orders = Gtk::manage(new Gtk::MenuItem("Orders", true));
    menubar->append(menuitem_orders);
    Gtk::Menu ordersmenu = Gtk::manage(new Gtk::Menu());
    menuitem_orders->set_submenu(ordersmenu);

    // Create place order button
    Gtk::ToolButton place_order_button = Gtk::manage(new Gtk::ToolButton("Place Order", true));
    place_order_button->signal_activate().connect( [this] { this->on_place_order_click(); } );
    ordersmenu->append(place_order_button);

    // Create list orders button
    Gtk::ToolButton list_orders_button = Gtk::manage(new Gtk::ToolButton("List Orders", true));
    place_order_button->signal_activate().connect( [this] { this->on_list_orders_click(); } );
    ordersmenu->append(list_orders_button);

    //                 Gtk::Label data = 
    //                 Gtk::Label msg = 

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

Mainwin::reset_sensitivity()
{
	// pass
}

Mainwin::on_new_store_click()
{
	_store = new Store();
}

Mainwin::on_add_sweet_click()
{
    std::string name;
    double price;

    EntryDialog ndialog{*this, "Create Name for Sweet: "};
    ndialog.set_text("Enter a name");
    ndialog.run();

    name = ndialog.get_text();
    EntryDialog pdialog{*this, "Create Price for " + name + ": "};
    pdialog.set_text("Enter a price");
    
    pdialog.run();
}

Mainwin::on_list_sweets_click()
{
	// pass
}

Mainwin::on_place_order_click()
{
	//
}

Mainwin::on_list_orders_click()
{
	// pass
}

Mainwin::on_about_click()
{
	Gtk::MessageDialog{*this, R"(

    Mav's Ultra Sweet Shop (MUSS)
    =============================

    Manage a sweet shop filled with sweets.
    Copyright 2019 George F. Rice

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

Mainwin::on_quit_click()
{
	hide();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////



// /////////////////
// U T I L I T I E S
// /////////////////


