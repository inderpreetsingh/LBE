/************************************************************** 
 Purpose : main app file of Laka Engine 

 Author  : Gauravjeet Singh, Inderpreet Singh, Shaina Sabarwal

 License : GNU GPL V3

***************************************************************/
#include "laka_engine.h"
#include "admin/setting_pannel.h"
#include "add_theme.h"

#include <Wt/WLink>
#include <Wt/WStackedWidget>

string mainTemplate;

LakaEngine::LakaEngine(const WEnvironment &env)
    :WApplication(env)
{
   if(titleString == "")
   titleString = "Laka";

   if(taglineString == "")
   taglineString="Just another awesome blog";
   
   setTitle(titleString);
   useStyleSheet("resources/default.css");
   clicked = false;

   container = new WContainerWidget(root());
   container->setStyleClass("container");

   main = new WTemplate(root());

   main->setTemplateText(mainTemplate);
   main->bindString("tagline",    taglineString);
   main->bindString("title",      titleString);

   postLoop = new PostLoop(container);
   main->bindWidget("postloop",   postLoop);

   authButton = new WPushButton("Login/Register", root());
   authButton->setLink(WLink(WLink::InternalPath, "/login"));

   main->bindWidget("loginbutton",authButton);
   
   handlePathChange();
   internalPathChanged().connect(this, &LakaEngine::handlePathChange);
}

void LakaEngine::handlePathChange()
{
    std::string path = internalPath();
    
    if(path == "/login")
      authFormLoader();
    else if(path == "/laka-admin")
      container->removeWidget(postLoop);
}

void LakaEngine::authFormLoader()
{
   if(!clicked) {
     clicked = true;
     authForm = new AuthForm(container);
     root()->removeWidget(authButton);
     container->removeWidget(postLoop);
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
