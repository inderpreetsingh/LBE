/************************************************************

Filename: laka_engine.h

Description: Header file for the main file of laka_engine

Authors: Gauravjeet Singh, Inderpreet Singh, Shaina Sabarwal

License: GNU GPL V3

*************************************************************/
#ifndef LAKA_ENGINE_H_
#define LAKA_ENGINE_H_

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WServer>
#include <Wt/WPushButton>

#include "global.h"
#include "auth.h"
#include "post_loop.h"

Session session_; //! a globally shared application wide session object.

using namespace Wt;

//! LakaEngine is the main class of Laka Engine. 
/*!
    This class is inherited from WApplication.
    LakaEngine is the main class of Laka Blogging Engine.
    It attatches the authentication module, theme module, session to the app.
    It is a class where all the pieces of puzzle stick together.
*/
class LakaEngine : public Wt::WApplication
{
public:
	//! Constructor for LakaEngine class.
	/*!
	    Adds the grand parent container division to the front end, adds style, title etc. to the app.
	    Connects authentication module by calling authFormLoader() using a WPushButton authButton.
	    It Loads all the posts in your blog.  
	*/
	LakaEngine(const WEnvironment &env);
	//! Loads the authentication forms viz Registeration form, Lost Password Form, Login Form.
	void authFormLoader();
        //! Handles the change in internal Path
        void handlePathChange();
        //! Loads the published posts
        void posts();
	
private:
	//! Checks whether authPushButton is clicked or not?
	bool clicked;
	//! The Grand Parent Widget for all the widgets inside LakaEngine.
	WStackedWidget *stack;
	//! The authPushButton that invokes authentication forms.
	WPushButton *authButton;
        //! Form for Authentication
        AuthForm *authForm;
	//! Post loop loads all the posts from the database. 
	PostLoop *postLoop;
};
#endif

