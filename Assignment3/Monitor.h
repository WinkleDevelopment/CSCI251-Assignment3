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

};
