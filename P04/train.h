#ifndef __TRAIN_H
#define __TRAIN_H

class Train
{
	private:
		vector<Locomotive*> _locomotives;
		vector<Coach*> _coaches;

	public:
		void add_locomotive(Locomotive& locomotive);
		void add_coach(Coach& coach);
		double speed(double minutes);
		string to_art();
}

#endif