
#ifndef __SHELTER_H
#define __SHELTER_H
#include <vector>
#include <algorithm>
#include "animal.h"
#include "client.h"

class Shelter 
{
	public:
		Shelter(std::string name);                   // done
		std::string name();                          // done
		void add_animal(Animal& animal);             // done
		int num_animals();                           // done
		Animal& animal(int index);                   // done
		void add_client(Client& client);             // done
		int num_clients();                           // done
		Client& client(int index);                   // done
		void adopt(Client& client, Animal& animal);  // done-ISH
		
	private:
		std::string _name;
		std::vector<Animal*> _available;
		std::vector<Client> _clients;
};
#endif