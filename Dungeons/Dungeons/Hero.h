#pragma once

#include <string>
using namespace std;

class Hero
{
	public:
		string userName;

		Hero();
		~Hero();

		static Hero& Instance()
		{
			static Hero    mInstance; // Guaranteed to be destroyed. - Instantiated on first use.
			return mInstance;
		}		

		// Getters
		const string	getUserName()	{ return userName;	}
		const int		getLevel()		{ return level;		}
		const int		getHealth()		{ return health;	}
		const float		getXp()			{ return xp;		}
		const int		getAttack()		{ return attack;	}
		const int		getStrength()	{ return strength;	}
		const int		getDefence()	{ return defence;	}

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
		int		level;
		int		health;
		float	xp;
		int		attack;
		int		strength;
		int		defence;

		// Getters
		
		// Setters
};

