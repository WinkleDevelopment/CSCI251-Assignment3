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

template <typename T>
class User {
private:
	string name;
	int age;
	string gender;
	vector<int> history;
public:
	User();
	User(string, int, string);
	~User();
	User(const User& copyUser);
	string getName();
	int getAge();
	string getGender();
	vector<int> getHistory();
	void setName(string);
	void setAge(int);
	void setGender(string);
	void setHistory(vector<int>);
	int difference(User<T>);
	int varity();
};

template <typename T>
class Pool {
private:
	string name;
	vector<T> users;
public:
	Pool();
	Pool(string);
	Pool(string, vector<T>);
	~Pool();
	Pool(const Pool& copyPool);
	string getName();
	vector<T> getUsers();
	void setName(string);
	void setUsers(vector<T>);
	void addUser(User<T>);
	void removeUser(User<T>);
	void display();
	void minimumVariety();
	void minimumDifference();
};
