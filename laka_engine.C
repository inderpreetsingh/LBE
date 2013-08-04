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

   headerContainer = new WContainerWidget(root());

   postLoop = new PostLoop(container);

   main = new WTemplate(root());
   main->setTemplateText(mainTemplate);
   main->bindString("tagline",    taglineString);
   main->bindString("title",      titleString);
   main->bindWidget("postloop",   postLoop);

   internalPathChanged().connect(this, &LakaEngine::handlePathChange);

   authButton = new WPushButton("Login/Register", headerContainer);
   authButton->clicked().connect( this, &LakaEngine::authFormLoader);

   authForm = new AuthForm(headerContainer);
   main->bindWidget("authForm", authForm);

   main->bindWidget("loginbutton",authButton);
   
   handlePathChange(); 
}

void LakaEngine::authFormLoader()
{
  new WText("that works", root());
}

void LakaEngine::handlePathChange()
{
    std::string path = internalPath();
   if(path == "/")
    {
       container->clear();
       postLoop = new PostLoop(container);
       main->bindWidget("postloop",   postLoop);
    }
   else 
    {
      postLoop->handlePath();
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
		server.addEntryPoint(Wt::Application, createApplication);

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
