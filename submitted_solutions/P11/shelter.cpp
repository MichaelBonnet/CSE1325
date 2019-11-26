#include "shelter.h"

Shelter::Shelter(std::string name) : _name{name},  filename{"untitled.ctp"} { }

std::string Shelter::name() 
{
	return _name;
}

void Shelter::add_animal(Animal& animal) 
{
	_available.push_back(&animal);
}

int Shelter::num_animals() 
{
	return _available.size();
}

Animal& Shelter::animal(int index) 
{
	return *(_available[index]);
}

void Shelter::add_client(Client& client) 
{
	_clients.push_back(client);
}

int Shelter::num_clients() 
{
	return _clients.size();
}

Client& Shelter::client(int index) 
{
	return _clients[index];
}

void Shelter::adopt(Client& client, Animal& animal)
{
	client.adopt(animal);
	_available.erase( std::remove(_available.begin(), _available.end(), &animal), _available.end() );
}

std::string Shelter::get_filename() 
{
	return filename;
}

void Shelter::set_filename(std::string filename) 
{
	this->filename = filename;
}

void Shelter::save(std::ostream& ost) 
{
  for (Animal* a : _available) 
  {
      //ost << typeid(*a).name() << ": " ; // Write the name of the actual type
      a->save(ost);
      ost << std::endl;  // one line per shape (this is ignored when loading)
  }
  //dirty = false;
}

void Shelter::load(std::istream& ist)
{
	while(ist)
	{
		int family;
		ist >> family;
		if (family == 0)
		{
			Dog d{ist};
			add_animal(d);
		}
		if (family == 1)
		{
			Cat c{ist};
			add_animal(c);
		}
		if (family == 2)
		{
			Rabbit r{ist};
			add_animal(d);
		}
		if (family == 3)
		{
			Client cl{ist};
			add_client(cl);
		}
	}
}