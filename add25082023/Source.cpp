#include <iostream>


enum Size {
	SMALL,
	MIDDLE,
	LARGE
};


class Harvest {

	std::string name;

	double weight;

	std::string color;

public:
	Harvest(std::string name, double weight, std::string color) {
		this->name = name;
		this->weight = weight;
		this->color = color;
	}
	Harvest() :name("no name"), weight(0.0), color("green") {}

	std::string getName() {
		return name;
	}

	double getWeight() {
		return weight;
	}

	std::string getColor() {
		return color;
	}
};


class Apple : public Harvest {
public:
	Apple() = default;
	Apple(std::string name, double weight, std::string color) : Harvest(name, weight, color) {}
};


class Plant{

	
	Size size;

	std::string color;

	int maxHarvest;

protected:

	Harvest* harvest;

public:
	Plant(Size size, std::string color, int  maxHarvest) {
		this->size = size;
		this->color = color;
		this->maxHarvest = maxHarvest;
		this->harvest = nullptr;
	}
	Plant(): size(SMALL), color("red") , maxHarvest(10), harvest(nullptr){}
	Size getSize() {
		return size;
	}
	std::string getColor() {
		return color;
	}

	int getHarvest() {
		return maxHarvest;
	}
	virtual Harvest* throw_harvest() = 0;
};


class Apple_tree : public Plant {
public:
	
	Apple_tree() = default;
	Apple_tree(Size size, std::string color, int  maxHarvest) : Plant(size, color, maxHarvest) {
		harvest = new Apple;
	}

	~Apple_tree() {
		delete harvest;
	}

	Harvest* throw_harvest() override {

		return new Apple("No name", 0.1, "yelow");
	}
};



int main() {


	Plant* tree = new Apple_tree();
	Harvest* plod = tree->throw_harvest();

	std::cout << plod->getName() << std::endl;
}