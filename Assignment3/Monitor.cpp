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
#include "Urlgeneration.h"

/* User Class */
template <typename T>
User<T>::User() {
	vector<string> tmp;

	this->name = "";
	this->age = NULL;
	this->gender = "";
	this->history = tmp;
}

template <typename T>
User<T>::User(string nM, int aG, string gD) {
	vector<string> tmp;

	this->name = nM;
	this->age = aG;
	this->gender = gD;
	this->history = tmp;
}

template <typename T>
User<T>::~User() {}

template <typename T>
User<T>::User(const User& copyUser) {
	this->name = copyUser.name;
	this->age = copyUser.age;
	this->gender = copyUser.gender;
	this->history = copyUser.history;
}

template <typename T>
string User<T>::getName() { return this->name; }

template <typename T>
int User<T>::getAge() { return this->age; }

template <typename T>
string User<T>::getGender() { return this->gender; }

template <typename T>
vector<int> User<T>::getHistory() { return this->history; }

template <typename T>
void User<T>::setName(string newName) { this->name = newName; }

template <typename T>
void User<T>::setAge(int newAge) { this->age = newAge; }

template <typename T>
void User<T>::setGender(string newGender) { this->gender = newGender; }

template <typename T>
void User<T>::setHistory(vector<int> newHistory) { this->history = newHistory; }

template <typename T>
int User<T>::difference(User oUser) {
	
	vector<int> userHistory = oUser.getHistory();
	int d = 0;

	for (int cnt = 0; cnt < history.size(); cnt++) {
		if (history[cnt] != userHistory[cnt]) {
			d++;
		}
	}

	return d;

}

template <typename T>
int User<T>::varity() {

	vector<int> webCheck;
	int v = 0;

	for (vector<int>::const_iterator cnt = history.cbegin(); cnt != history.cend(); cnt++) {
		if (find(webCheck.cbegin(), webCheck.cend(), ^cnt) == webCheck.cend()) {
			webCheck.push_back(^ cnt);
			v++;
		}
	}

	return v;

}

/* Pool Class */
template <typename T>
Pool<T>::Pool() {
	vector<User> tmp;

	this->name = "";
	this->users = tmp;
}

template <typename T>
Pool<T>::Pool(string nM) {
	vector<User> tmp;

	this->name = nM;
	this->users = tmp;
}

template <typename T>
Pool<T>::Pool(string nM, vector<T> uR) {
	this->name = nM;
	this->users = uR;
}

template <typename T>
Pool<T>::~Pool() {}

template <typename T>
Pool<T>::Pool(const Pool& copyPool) {
	this->name = copyPool.name;
	this->users = copyPool.users;
}

template <typename T>
string Pool<T>::getName() { return this->name; }

template <typename T>
vector<T> Pool<T>::getUsers() { return this->users; }

template <typename T>
void Pool<T>::setName(string newName) { this->name = newName; }

template <typename T>
void Pool<T>::setUsers(vector<T> newUsers) { this->users = newUsers; }

template <typename T>
void Pool<T>::addUser(User<T> user) { this->getUsers().push_back(user); }

template <typename T>
void Pool<T>::removeUser(User<T> user) {
	auto idx = find(this->getUsers().begin(), this->getUsers().end(), user);
	if (idx != this->getUsers().end()) {
		this->getUsers().erase(idx);
	} else {
		cout << "User doesn't exist!";
	}
}

template <typename T>
void Pool<T>::display() {
	minimumVariety();
	minimumDifference();
}

template <typename T>
void Pool<T>::minimumVariety() {

	User<T> tmp = users[0];
	int v = tmp.varity();
	User<T> lowest = users[0];

	for (int cnt = 1; cnt < users.size(); cnt++ ) {
		tmp = users[cnt];
		if (tmp.varity < v) {
			lowest = tmp;
		}
	}

	cout << "Minimum Varity is: " << lowest.varity() << endl;

}

template <typename T>
void Pool<T>::minimumDifference() {
	
	User<T> tmp = users[0];
	User<T> lowest = users[0];
	int d = 0;

	for (int cnt = 1; cnt < users.size(); cnt++) {
		tmp = users[cnt];
		if (tmp.difference(tmp[cnt-1]) < tmp.difference(tmp[cnt])) {
			d = tmp.difference(tmp[cnt - 1]);
			lowest = tmp;
		}
	}

	cout << "Minimum Difference is: " << d << endl;

}


/* Main */
template <typename T>
int main() {	
	
	Urlgeneration generator;

	vector<T> users;
	vector<int> tmpHistory;

	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());

	User<T> user1 = new User<T>("User 1", 18, "Male", tmpHistory);
	
	tmpHistory.clear();

	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());


	User<T> user2 = new User<T>("User 2", 19, "Female", tmpHistory);

	tmpHistory.clear();

	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());

	User<T> user3 = new User<T>("User 3", 20, "Male", tmpHistory);

	tmpHistory.clear();

	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());
	tmpHistory.push_back(generator.generateNumber());

	User<T> user4 = new User<T>("User 4", 21, "Female", tmpHistory);

	users.push_back(user1);
	users.push_back(user2);
	users.push_back(user3);
	users.push_back(user4);

	Pool<T> pool = new Pool<T>("User Pool",users);

	pool.display();

	return 0;
}