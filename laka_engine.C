/************************************************************** 
 Purpose : main app file of Laka Engine 

 Author  : Gauravjeet Singh, Inderpreet Singh, Shaina Sabarwal

 License : GNU GPL V3

***************************************************************/
#include "laka_engine.h"
#include "admin/setting_pannel.h"

#include <Wt/WLink>
#include <Wt/WStackedWidget>

LakaEngine::LakaEngine(const WEnvironment &env)
    :WApplication(env)
{
   setTitle(titleString);
   new WText(taglineString, root());

   stack = new WStackedWidget(root());
   stack->setStyleClass("stack");
   
   useStyleSheet("resources/default.css");

   clicked = false;
   
   postLoop = new PostLoop(stack);
   authForm = new AuthForm(stack);

   authButton = new WPushButton("Login/Register",root());
   authButton->setLink(WLink(WLink::InternalPath, "/login.lml"));
   
   handlePathChange();
   
   internalPathChanged().connect(this, &LakaEngine::handlePathChange);
}

void LakaEngine::handlePathChange()
{
    std::string path = internalPath();
    if(path == "/login.lml")
      authFormLoader();
    else
      posts();
}

void LakaEngine::posts()
{
   stack->setCurrentWidget(postLoop);
   clicked = false;
}

void LakaEngine::authFormLoader()
{
    if (!clicked)
     {
	clicked = true;
         root()->removeWidget(authButton);
        stack->setCurrentWidget(authForm);
     }
}

WApplication *createApplication(const WEnvironment &env)
{
    return new LakaEngine(env);
}


int main(int argc, char **argv)
{
   try{
		Wt::WServer server(argv[0]);

		server.setServerConfiguration(argc,argv, WTHTTP_CONFIGURATION);
		server.addEntryPoint(Wt::Application, createApplication, "");

		Session::configureAuth();

		if(server.start()){
			Wt::WServer::waitForShutdown();
			server.stop();
		}
	} catch (Wt::WServer::Exception& e) {
		std::cerr << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr<< "exception" << e.what() <<std::endl;
	}
 }

