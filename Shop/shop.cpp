#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
	string Name;
public:
	Product(string name) {
		this->Name = name;
	}

	string name() {
		return this->Name;
	}
};

class Visiter {
private:
	string Group;
	string Name;
public:
	Visiter(string name, string group) {
		this->Group = group;
		this->Name = name;
	}

	string group() {
		return this->Group;
	}
	string name() {
		return this->Name;
	}
};



class ShopManager {
private:
	map<string, int> stock;
	map<string, map<string, int> > prices;
	int money;
public:
	ShopManager(map<string, int> stock, map <string, map<string,int>> prices) {
		this->stock = stock;
		this->prices = prices;
		this->money = 0;
	};

	void new_price(string  pr, string vis, int disc) {
		this->prices[pr][vis] = disc;
		cout << "New price: product - " << pr << "; group of visitors - " << vis << "; value - " << disc << endl;
	}
	void show_prices() {
		for (map <string, map<string, int>>::iterator i = this->prices.begin(); i != this->prices.end(); i++) {
			cout << (*i).first << endl;
			for (map<string, int>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++) {
				cout << "          " << (*j).first << ":   " << (*j).second << endl;

			}
		}

	}


	bool order(string prod, int how_much) {
		if (this->money >= 0.75*this->prices[prod]["basic"]) {
			this->money -= this->prices[prod]["basic"] * 3 / 4;
			this->stock[prod] += how_much;
			return true;
		}
		cout << "Мало денег" << endl;
		return false;
	}
	bool sell(string prod, string group, int how_much) {
		if (this->stock[prod] >= how_much) {
			money += this->prices[prod][group];
			return true;
		}
		cout << "Слишком мало товара '" << prod << "'" << endl;
		return false;
	}
	void show_stock() {
		for (map<string, int>::iterator i = this->stock.begin(); i != this->stock.end(); i++)
			cout << (*i).first << (*i).second << endl;
	}

	bool add_product(string prod, map<string, int> price) {
		if (this->stock.count(prod) == 1) {
			cout << "this product is already exist" << endl;
			return false;
		}
		this->prices[prod] = price;
		this->stock[prod] = 0;
		return true;
	}
	
};

int main()
{
	cout << "HELLO OWO" << endl;
}