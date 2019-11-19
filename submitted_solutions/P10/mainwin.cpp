#include "mainwin.h"
#include "shelter.h"
#include "dog.h"
#include "cat.h"
#include "rabbit.h"
#include "family.h"
#include <string>
#include <sstream>

Mainwin::Mainwin() : Mainwin{*(new Shelter("Team Apocalips"))} { }

Mainwin::Mainwin(Shelter& shelter) : shelter{&shelter} 
{
	set_default_size(640, 480);
	set_title("Mavs Animal Shelter Software - Team Apocalips");


	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);

	// Menu Bar
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	// File megamenu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	// Quit option
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Exit", true));
	menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
	filemenu->append(*menuitem_quit);

	// Animal megamenu
	Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
	menubar->append(*menuitem_animal);
	Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
	menuitem_animal->set_submenu(*animalmenu);

	// Add animal option
	Gtk::MenuItem *menuitem_new_animal = Gtk::manage(new Gtk::MenuItem("_New", true));
	menuitem_new_animal->signal_activate().connect([this] {this->on_new_animal_click();});
	animalmenu->append(*menuitem_new_animal);

	// List animals option
	Gtk::MenuItem *menuitem_list_animals = Gtk::manage(new Gtk::MenuItem("_List", true));
	menuitem_list_animals->signal_activate().connect([this] {this->on_list_animals_click();});
	animalmenu->append(*menuitem_list_animals);

    // Adopt animals option
    Gtk::MenuItem *menuitem_adopt_animal = Gtk::manage(new Gtk::MenuItem("_Adopt", true));
    menuitem_adopt_animal->signal_activate().connect([this] {this->on_adopt_animal_click();});
    animalmenu->append(*menuitem_adopt_animal);

    // Client megamenu
    Gtk::MenuItem *menuitem_client = Gtk::manage(new Gtk::MenuItem("Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);

    // Add client option
    Gtk::MenuItem *menuitem_new_client = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new_client->signal_activate().connect([this] {this->on_new_client_click();});
    clientmenu->append(*menuitem_new_client);

    // List clients option
    Gtk::MenuItem *menuitem_list_clients = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_list_clients->signal_activate().connect([this] {this->on_list_clients_click();});
    clientmenu->append(*menuitem_list_clients);

    // List clients' adopted animals
    Gtk::MenuItem *menuiutem_list_adopted = Gtk::manage(new Gtk::MenuItem("_List Adopted", true));
    menuiutem_list_adopted->signal_activate().connect([this] {this->on_list_adopted_click();});
    clientmenu->append(*menuiutem_list_adopted);

    // data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->pack_start(*data, Gtk::PACK_EXPAND_WIDGET, 0);

    // msg
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // show that shit
	vbox->show_all();
}

// Destructor
Mainwin::~Mainwin() { }

// Quit implementation
void Mainwin::on_quit_click() 
{
    close();
}

void Mainwin::on_new_client_click()
{
    Gtk::Dialog dialog {"New Client", *this};

    // Name
    Gtk::HBox name_box;

    Gtk::Label name_label{"Name:"};
    name_label.set_width_chars(20);
    name_box.pack_start(name_label, Gtk::PACK_SHRINK);

    Gtk::Entry name_entry;
    name_entry.set_max_length(50);
    name_box.pack_start(name_entry, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(name_box, Gtk::PACK_SHRINK);

    // Phone
    Gtk::HBox phone_box;

    Gtk::Label phone_label{"Phone:"};
    phone_label.set_width_chars(20);
    phone_box.pack_start(phone_label, Gtk::PACK_SHRINK);

    Gtk::Entry phone_entry;
    phone_entry.set_max_length(50);
    phone_box.pack_start(phone_entry, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(phone_box, Gtk::PACK_SHRINK);

    // Email
    Gtk::HBox email_box;

    Gtk::Label email_label{"Email:"};
    email_label.set_width_chars(20);
    email_box.pack_start(email_label, Gtk::PACK_SHRINK);

    Gtk::Entry email_entry;
    email_entry.set_max_length(50);
    email_box.pack_start(email_entry, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(email_box, Gtk::PACK_SHRINK);

    dialog.add_button("Cancel", 0);
    dialog.add_button("Create", 1);

    // Showing it all
    dialog.show_all();
 

    while (dialog.run()) 
    {

        // allocate the dog and add to shelter
        Client* client = new Client{name_entry.get_text(), phone_entry.get_text(), email_entry.get_text()}; // jesus fuck this took a long time to unfuck
        shelter->add_client(*client);
        Gtk::MessageDialog{*this, "Sucessfully added a client but I'm too god damn lazy to implement a reset of the window. Just change the fields, it's all good. Also hit cancel to close the window."}.run();
    
    }
}

// Add animal impplementation
void Mainwin::on_new_animal_click()
{

    Gtk::Dialog animalDialog{"Choose Your Fighter", *this};
    Gtk::HBox animalBox;
    Gtk::ComboBoxText combobox_animal;
    Gtk::Label label_animal{"Animal: "};
    animalBox.pack_start(label_animal, Gtk::PACK_SHRINK);
    for(int i=0; i < family_to_string.size(); ++i) 
    {
        combobox_animal.append(family_to_string[i]); 
    }
    combobox_animal.set_active(0);
    animalBox.pack_start(combobox_animal, Gtk::PACK_SHRINK);
    animalDialog.get_vbox()->pack_start(animalBox, Gtk::PACK_SHRINK);
    animalDialog.add_button("Continue", 1);
    animalDialog.add_button("Cancel", 0);
    animalDialog.show_all();
    animalDialog.run();

    Gtk::Dialog dialog{"Enter Info", *this};
    
    Gtk::HBox name_box;
    Gtk::Label name_label{"Name:"};
    Gtk::Entry name_entry;
    name_box.pack_start(name_label, Gtk::PACK_SHRINK);
    name_box.pack_start(name_entry, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(name_box, Gtk::PACK_SHRINK);

    Gtk::HBox breed_box;
    Gtk::Label breed_label{"Breed:"};
    breed_box.pack_start(breed_label, Gtk::PACK_SHRINK);
    Gtk::ComboBoxText combobox_breed;
    if(combobox_animal.get_active_row_number() == 0)
    {
        for (auto b : dog_breeds)
        {
            combobox_breed.append(to_string(b));
        }
    }
    else if(combobox_animal.get_active_row_number() == 1)
    {
        for (auto b : cat_breeds)
        {
            combobox_breed.append(to_string(b));
        }
    }
    else if(combobox_animal.get_active_row_number() == 2)
    {
        for (auto b : rabbit_breeds)
        {
            combobox_breed.append(to_string(b));
        }
    }
    combobox_breed.set_active(0);
    breed_box.pack_start(combobox_breed, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(breed_box, Gtk::PACK_SHRINK);

    Gtk::HBox gender_box;
    Gtk::Label gender_label{"Gender:"};
    Gtk::ComboBoxText combobox_gender;
    /*  rip, I tried
    for (auto b : genders)
    {
        combobox_gender.append(gender_to_string(b));
    }
    */
    
    for(int i=0; i < gender_to_string.size(); ++i) // this worked but didnt jive with my logic further south
    {
        combobox_gender.append(gender_to_string[i]); 
    }
    
    // combobox_gender.append("FEMALE");
    // combobox_gender.append("MALE");
    combobox_gender.set_active(0);
    gender_box.pack_start(gender_label, Gtk::PACK_SHRINK);
    gender_box.pack_start(combobox_gender, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(gender_box, Gtk::PACK_SHRINK);

   
    Gtk::HBox age_box;
    Gtk::Label age_label{"Age:"};
    Gtk::SpinButton spinbutton_age; // god help me
    spinbutton_age.set_range(0,50);
    spinbutton_age.set_increments(1,5);
    spinbutton_age.set_value(1);
    age_box.pack_start(age_label, Gtk::PACK_SHRINK);
    age_box.pack_start(spinbutton_age, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(age_box, Gtk::PACK_SHRINK);

    // Buttons
    dialog.add_button("Cancel", 0);
    dialog.add_button("Add", 1);

    // Showing it all
    dialog.show_all();

    while(dialog.run()) 
    {
        int result = combobox_animal.get_active_row_number();
        if(result == 0) // user chose dog
        {
            if(name_entry.get_text().size() == 0)
            {
                name_entry.set_text("Must Fill"); 
                continue;
            }
            Dog* dog = new Dog{ dog_breeds[combobox_breed.get_active_row_number()], name_entry.get_text(), (combobox_gender.get_active_row_number() ? Gender::FEMALE : Gender::MALE), static_cast<int>(spinbutton_age.get_value())};
            shelter->add_animal(*dog);
            // something to tell user successful addition?
            Gtk::MessageDialog{*this, "Sucessfully Added"}.run();
            break; // really dont like having to do this
        }
        else if(result == 1) // user chose cat
        {
            if(name_entry.get_text().size() == 0) 
            {
                name_entry.set_text("Must Fill");
                continue;
            }
            Cat* cat = new Cat{ cat_breeds[combobox_breed.get_active_row_number()], name_entry.get_text(), (combobox_gender.get_active_row_number() ? Gender::FEMALE : Gender::MALE), static_cast<int>(spinbutton_age.get_value())};
            shelter->add_animal(*cat);
            // something to tell user successful addition?
            Gtk::MessageDialog{*this, "Sucessfully Added"}.run();
            break; // really dont like having to do this
        }
        else if(result == 2) // user chose rabbit
        {
            if(name_entry.get_text().size() == 0) 
            {
                name_entry.set_text("Must Fill");
                continue;
            }
            Rabbit* rabbit = new Rabbit{rabbit_breeds[combobox_breed.get_active_row_number()], name_entry.get_text(), (combobox_gender.get_active_row_number() ? Gender::FEMALE : Gender::MALE), static_cast<int>(spinbutton_age.get_value())};
            shelter->add_animal(*rabbit);
            // something to tell user successful addition?
            Gtk::MessageDialog{*this, "Sucessfully Added"}.run();
            break; // really dont like having to do this
        }
    }
}

// List animals implementation
void Mainwin::on_list_animals_click()
{
    std::stringstream animals_list;
    animals_list << "ANIMALS AVAILABLE FOR ADOPTION" << std::endl;
    for (int i = 0; i < shelter->num_animals(); i++)
    {
        animals_list << shelter->animal(i) << std::endl;
    }
    //Gtk::MessageDialog{*this, animals_list.str()}.run();
    data->set_text(animals_list.str());
}

void Mainwin::on_list_clients_click()
{
    std::stringstream clients_list;
    clients_list << "CLIENTS CURRENTLY REGISTERED" << std::endl;
    for (int i = 0; i < shelter->num_clients(); i++)
    {
        clients_list << shelter->client(i) << std::endl;
    }
    //Gtk::MessageDialog{*this, clients_list.str()}.run();
    data->set_text(clients_list.str());
}

void Mainwin::on_list_adopted_click()
{
    if((shelter->num_clients() == 0) || (shelter->num_animals() == 0))
    {
        Gtk::MessageDialog{*this, "No Clients/Animals Added"}.run();
    }
    else {

    Gtk::Dialog dialog{"Clients and their Adoptions", *this};

    Gtk::HBox client_box;
    Gtk::Label client_label{"Client:"};
    Gtk::ComboBoxText combobox_client;
    for(int i=0; i < shelter->num_clients(); ++i)
    {
        combobox_client.append(shelter->client(i).to_string()); 
    }
    combobox_client.set_active(0);
    client_box.pack_start(client_label, Gtk::PACK_SHRINK);
    client_box.pack_start(combobox_client, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(client_box, Gtk::PACK_SHRINK);

    dialog.add_button("Cancel", 0);
    dialog.add_button("List", 1);

    // Showing it all
    dialog.show_all();

    while(dialog.run())
    {
        int client_result = combobox_client.get_active_row_number();

        std::stringstream result;
        result << shelter->client(client_result).name() << "'s Adoptions:" << std::endl;
        for ( int i = 0; i < shelter->client(client_result).num_adopted(); ++i )
        {
            result << shelter->client(client_result).animal(i).to_string() << std::endl;
        }
        //Gtk::MessageDialog{*this, result.str()}.run();
        data->set_text(result.str());
        //status("");
        //break; // REAAALLLYYYY do not like doing this
    }
    // if(dialog.run() == 0)
    // {
    //     dialog.close();
    // }

    // int client_result = combobox_client.get_active_row_number();

    // std::stringstream result;
    // for ( int i = 0; i < shelter->client(client_result).num_adopted(); ++i )
    // {
    //     result << shelter->client(client_result).animal(i).to_string() << std::endl;
    // }
    // Gtk::MessageDialog{*this, result.str()}.run();
    }
}

        
void Mainwin::on_adopt_animal_click()
{
    if((shelter->num_clients() == 0) || (shelter->num_animals() == 0))
    {
        Gtk::MessageDialog{*this, "No Clients/Animals Added"}.run();
    }
    else {

    Gtk::Dialog dialog{"Adopt an Animal", *this};

    Gtk::HBox client_box;
    Gtk::Label client_label{"Client:"};
    Gtk::ComboBoxText combobox_client;
    for(int i=0; i < shelter->num_clients(); ++i)
    {
        combobox_client.append(shelter->client(i).to_string()); 
    }
    combobox_client.set_active(0);
    client_box.pack_start(client_label, Gtk::PACK_SHRINK);
    client_box.pack_start(combobox_client, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(client_box, Gtk::PACK_SHRINK);

    Gtk::HBox animal_box;
    Gtk::Label animal_label{"Animal:"};
    Gtk::ComboBoxText combobox_animal;
    for(int i=0; i < shelter->num_animals(); ++i)
    {
        combobox_animal.append(shelter->animal(i).to_string()); 
    }
    combobox_animal.set_active(0);
    animal_box.pack_start(animal_label, Gtk::PACK_SHRINK);
    animal_box.pack_start(combobox_animal, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(animal_box, Gtk::PACK_SHRINK);

    dialog.add_button("Cancel", 0);
    dialog.add_button("Adopt", 1);

    // Showing it all
    dialog.show_all();

    while(dialog.run())
    {
        shelter->adopt(shelter->client(combobox_client.get_active_row_number()), shelter->animal(combobox_animal.get_active_row_number()) );
        break;
    }
    
    }
}