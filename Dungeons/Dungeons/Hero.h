#pragma once

#include <string>
using namespace std;

class Hero
{
	public:
		string userName;

		int		level;
		int		health;
		float	xp;
		int		attack;
		int		strength;
		int		defence;

		Hero();
		~Hero();

		static Hero& Instance()
		{
			static Hero    mInstance; // Guaranteed to be destroyed.
										   // Instantiated on first use.
			return mInstance;
		}		

		// Getters
		string	getUserName();
		int		getLevel();
		int		getHealth();
		float	getXp();
		int		getAttack();
		int		getStrength();
		int		getDefence();

		// Setters
		int		increaseLevel(int value);
		int		removeHealth(int value);
		int		addHealth(int value);
		float	increaseXp(int value);
		int		increaseAttack(int value);
		int		increaseStrenght(int value);
		int		increaseDefence(int value);
		bool	setUserName(string inputUserName);

		// Methods
		void	getHeroStats();
	private:
		// Getters
		// N/A
		// Setters
		// N/A
};

