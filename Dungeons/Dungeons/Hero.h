#pragma once

#include <string>
#include "Room.h"
using namespace std;

class Hero
{
	public:
		string userName;

		~Hero();

		static Hero* Instance()
		{
			static Hero mInstance; // Guaranteed to be destroyed. - Instantiated on first use.
			return &mInstance;
		}		

		// Getters
		const string	getUserName()	{ return userName;	}
		const int		getLevel()		{ return level;		}
		const int		getHealth()		{ return health;	}
		const float		getXp()			{ return xp;		}
		const int		getAttack()		{ return attack;	}
		const int		getStrength()	{ return strength;	}
		const int		getDefence()	{ return defence;	}
		Room*			getRoom()		{ return curroom;   }
		const bool		getStairway()	{ return isonstairway; }

		// Setters
		void	increaseLevel();
		void	removeHealth(int value);
		void	addHealth(int value);
		void	increaseXp(int value);
		void	increaseAttack(int value);
		void	increaseStrenght(int value);
		void	increaseDefence(int value);
		bool	setUserName(string inputUserName);
		void	setRoom(Room* room);
		void	setStairway(bool ios);
		string	getRoomDescription();
		bool	healHero();

		// Methods
		void	getHeroStats();
		void	getHeroStatsFight();
		bool	moveHero(int direction);
		bool	gameOver;
		bool	gameWon;
		bool	gamePlaying();
	
	protected:
		Hero();
		Hero(const Hero&);
		Hero& operator= (const Hero&);

	private:
		Room*	curroom;
		bool	isonstairway;
		int		level;
		int		health;
		int		maxHealth;
		float	xp;
		int		attack;
		int		strength;
		int		defence;

		// Getters
		
		// Setters
};

