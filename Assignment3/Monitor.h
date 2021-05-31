/*
*
*	Bachelor of Computer Science (Software Engineering)
*
*				Kyle J. Brookes | 6822794
*
*					 Assignment 3
*
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class User {
private:
	string name;
	int age;
	string gender;
	vector<string> history;
public:
	User();
	User(string, int, string);
	~User();
	User(const User& copyUser);
	string getName();
	int getAge();
	string getGender();
	vector<string> getHistory();
	void setName(string newName);
	void setAge(int newAge);
	void setGender(string newGender);
	void setHistory(vector<string> newHistory);
	int difference();
	int varity();
	int compareTo(User otherUser);
};

class Pool {
private:
	string name;
	vector<User> users;
public:
	Pool();
	Pool(string);
	Pool(string, vector<User>);
	~Pool();
	Pool(const Pool& copyPool);
	string getName();
	vector<User> getUsers();
	void setName(string newName);
	void setUsers(vector<User> newUsers);
	void addUser(User user);
	void removeUser(User user);
	void display();
	void minimumVariety();
	void minimumDifference();
};
