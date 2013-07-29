/************************************************************** 
 Purpose : main app file of Laka Engine 

 Author  : Gauravjeet Singh, Inderpreet Singh, Shaina Sabarwal

 License : GNU GPL V3

***************************************************************/
#include "laka_engine.h"
#include <Wt/WLink>

static const string url = "/laka";

LakaEngine::LakaEngine(const WEnvironment &env)
    :WApplication(env)
{
   container = new WContainerWidget(root());
   container->setStyleClass("container");
   
   useStyleSheet("resources/default.css");

   clicked = false;
   
   authButton = new WPushButton("Login/Register",container);
   authButton->setLink(WLink(WLink::InternalPath, "/login.lml"));

   postLoop = new PostLoop(container);
 
   internalPathChanged().connect(this, &LakaEngine::handlePathChange); 	
}

void LakaEngine::handlePathChange()
{
    std::string path = internalPath();
    if(path == "/login.lml")
      authFormLoader();
}

void LakaEngine::authFormLoader()
{
    if (clicked == false)
     {
	clicked = true;
        new AuthForm(container);
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
		server.addEntryPoint(Wt::Application, createApplication, url);

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

