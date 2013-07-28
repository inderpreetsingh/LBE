/************************************************************************
FileName:  auth.C

Description: Holds the definition of class for Authentication widget

Details:
auth.C files contains a definition of class named AuthForm that is inherited 
from WContainer widget, this class is then used in main WApplication for creating 
an auth form.

Author: Gauravjeet Singh, Shaina Sabarwal, Inderpreet Singh

License: GNU GPL V3

**************************************************************************/
#include "auth.h"
#include "global.h"

AuthForm::AuthForm(WContainerWidget *parent)
	:WContainerWidget(parent)
	{
		session_.login().changed().connect(this,&AuthForm::authEvent);


		Wt::Auth::AuthWidget *authWidget
		= new Wt::Auth::AuthWidget(Session::auth(), session_.users(),
						session_.login());
		
		authWidget->model()->addPasswordAuth(&Session::passwordAuth());
		authWidget->setRegistrationEnabled(true);

		authWidget->processEnvironment();

		this->addWidget(authWidget);
	}

	void AuthForm::authEvent() {
	if(session_.login().loggedIn()){
		Wt::log("notice") << "User" << session_.login().user().id()
					<<"logged in.";
		
	}
	else
		Wt::log("notice") << "User logged out.";
	}



