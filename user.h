/**
User.h file for creating a presistence class for User and mapping authinfo with user. 
*/
#ifndef USER_H_
#define USER_H_

#include <Wt/Dbo/Dbo>
#include <Wt/Auth/Dbo/AuthInfo>
/**
Wt::Dbo is a C++ ORM for making database driven applications with Witty
*/

namespace dbo = Wt::Dbo;

class User;

/**
mapping AuthInfo with our User Class and for the ease referring it to as AuthInfo 
*/

typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

/**
Definition of class User
*/

class User {

private:
	std::string name;

public:

/** 
adding a persist function, persist function is used to create tables in database,
*/
	User();
	
	template <class Action>
	void persist(Action& a)
	{
		dbo::field(a, name, "name" );	
	}
};

#endif
