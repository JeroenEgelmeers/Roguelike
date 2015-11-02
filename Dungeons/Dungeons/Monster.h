#pragma once
#include <string>
using namespace std;

class Monster
{
public:
	Monster();
	~Monster();

	// Getters
	const int		getLevel()			{ return level;				}
	const int		getHealth()			{ return health;			}
	const int		getAttack()			{ return attack;			}
	const int		getStrength()		{ return strength;			}
	const int		getDefence()		{ return defence;			}
	const string	getMonsterName()	{ return monsterName;		}
	const string	getMonsterDesc()	{ return monsterDescription; }

	// Setters
	void			removeHealth(int value);
	void			addHealth(int value);

	const void		setMonsterName(string name)				{ monsterName = name; }
	const void		setMonsterDescription(string desc)		{ monsterDescription = desc; }
	const void		setStats(int setLevel, int setHealth, int setAttack, int setStrength, int setDefence) { level = setLevel; health = setHealth; attack = setAttack; strength = setStrength; defence = setDefence; }

	// Methods
	void			getMonsterStats();
	void			showMonsterHealth();
	void			attackPlayer();		// Should attack the player

private:
	string	monsterName;
	int		level;
	int		health;
	int		attack;
	int		strength;
	int		defence;

	string	monsterDescription;
	// Getters

	// Setters

};

