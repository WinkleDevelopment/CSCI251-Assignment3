/*
*
*	Bachelor of Computer Science (Software Engineering)
*
*				Kyle J. Brookes | 6822794
*
*					 Assignment 3
*
*/

#include "Monitor.h"

/* User Class */
User::User() {
	vector<string> tmp;

	this->name = "";
	this->age = NULL;
	this->gender = "";
	this->history = tmp;
}

User::User(string nM, int aG, string gD) {
	vector<string> tmp;

	this->name = nM;
	this->age = aG;
	this->gender = gD;
	this->history = tmp;
}

User::~User() {}

User::User(const User& copyUser) {
	this->name = copyUser.name;
	this->age = copyUser.age;
	this->gender = copyUser.gender;
	this->history = copyUser.history;
}

string User::getName() { return this->name; }

int User::getAge() { return this->age; }

string User::getGender() { return this->gender; }

vector<string> User::getHistory() { return this->history; }

void User::setName(string newName) { this->name = newName; }

void User::setAge(int newAge) { this->age = newAge; }

void User::setGender(string newGender) { this->gender = newGender; }

void User::setHistory(vector<string> newHistory) { this->history = newHistory; }

int User::difference() {}

int User::varity() {}

int User::compareTo(User otherUser) {}

/* Pool Class */
Pool::Pool() {}

Pool::Pool(string nM) {
	vector<User> tmp;

	this->name = nM;
	this->users = tmp;
}

Pool::Pool(string nM, vector<User> uR) {
	this->name = nM;
	this->users = uR;
}

Pool::~Pool() {}

Pool::Pool(const Pool& copyPool) {
	this->name = copyPool.name;
	this->users = copyPool.users;
}

string Pool::getName() {}

vector<User> Pool::getUsers() {}

void Pool::setName(string newName) {}

void Pool::setUsers(vector<User> newUsers) {}

void Pool::addUser(User user) {}

void Pool::removeUser(User user) {}

void Pool::display() {}

void Pool::minimumVariety() {}

void Pool::minimumDifference() {}


/* Main */
int main() {	
	
	return 0;
}