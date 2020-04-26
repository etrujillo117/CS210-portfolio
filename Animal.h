/*
 * Animal.h
 *
 *  Created on: Apr 19, 2020
 *      Author: 1683780_snhu
 */

#pragma once
#include <string>
#ifndef ANIMAL_H_
#define ANIMAL_H_


class Animal
{
public:
	Animal(int trackNum, std::string inputName, std::string inputType, std::string inputSubType, int inputEggs, int inputNurse);
	std::string name;
	int TrackNum;
	std::string type;
	std::string subType;
	int eggs;
	int nurse;
};

Animal::Animal(int trackNum, std::string inputName, std::string inputType, std::string inputSubType, int inputEggs, int inputNurse)
		{
			TrackNum = trackNum;
			name = inputName;
			type = inputType;
			subType = inputSubType;
			eggs = inputEggs;
			nurse = inputNurse;
		};

class Mammal : public Animal {
public:
	Mammal(int trackNum, std::string inputName, std::string inputType, std::string inputSubType, int inputEggs, int inputNurse)
		: Animal(trackNum, inputName, inputType, inputSubType, inputEggs, inputNurse)
	{
		}
};

class Bat: public Mammal {
public:
	Bat(int trackNum, std::string inputName, int inputNurse, std::string inputType = "Mammal", std::string inputSubType = "Bat", int inputEggs = 0)
		: Mammal (trackNum, inputName, "Mammal", "Bat", 0, inputNurse)
	{
		}
};

class Whale: public Mammal {
public:
	Whale(int trackNum, std::string inputName, int inputNurse, std::string inputType = "Mammal", std::string inputSubType = "Whale", int inputEggs = 0)
		: Mammal (trackNum, inputName, "Mammal", "Whale", 0, inputNurse)
	{
		}
};

class SeaLion: public Mammal {
public:
	SeaLion(int trackNum, std::string inputName, int inputNurse, std::string inputType = "Mammal", std::string inputSubType = "SeaLion", int inputEggs = 0)
		: Mammal (trackNum, inputName, "Mammal", "SeaLion", 0, inputNurse)
	{
		}
};

class Oviparous : public Animal {
public:
	Oviparous(int trackNum, std::string inputName, std::string inputType, std::string inputSubType, int inputEggs, int inputNurse)
		: Animal(trackNum, inputName, inputType, inputSubType, inputEggs, inputNurse)
	{
		}
};

class Crocodile: public Oviparous {
public:
	Crocodile(int trackNum, std::string inputName, int inputEggs, std::string inputType = "Oviparous", std::string inputSubType = "Crocodile", int inputNurse = 0)
		: Oviparous (trackNum, inputName, "Oviparous", "Crocodile", inputEggs, 0)
	{
		}
};

class Goose: public Oviparous {
public:
	Goose(int trackNum, std::string inputName, int inputEggs, std::string inputType = "Oviparous", std::string inputSubType = "Goose", int inputNurse = 0)
		: Oviparous (trackNum, inputName, "Oviparous", "Goose", inputEggs, 0)
	{
		}
};

class Pelican: public Oviparous {
public:
	Pelican(int trackNum, std::string inputName, int inputEggs, std::string inputType = "Oviparous", std::string inputSubType = "Pelican", int inputNurse = 0)
		: Oviparous (trackNum, inputName, "Oviparous", "Pelican", inputEggs, 0)
	{
		}
};

/*
void setName(std::string inputName){
name = inputName;
}
std::string getName(){
	return(name);
}

void setTrackNum(int inputNum){
	TrackNum = inputNum;
}
int getTrackNum(){
	return(TrackNum);
}
*/


#endif /* ANIMAL_H_ */
