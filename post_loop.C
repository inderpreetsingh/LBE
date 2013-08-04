/*******************************************************

FileName: post_loop.C

Description: Holds the definition of class for posts widget

Author: Gauravjeet Singh, Shaina Sabarwal, Inderpreet Singh

License GNU GPL V3

***********************************************************/ 

#include "post_loop.h"
#include "add_theme.h"

#include <Wt/WLink>
#include <Wt/WAnchor>

string loopTemplate;
string postTemplate;

PostLoop::PostLoop(WContainerWidget *parent)
    :WContainerWidget(parent)
{
    postContainer = new WContainerWidget(this);
    {
      dbo::Transaction T(session_);
      allPosts = session_.find<Post>();
      theLoop();
      T.commit();
    }
}

void PostLoop::theLoop()
{
     handleThemeFile();
     for (auto i:allPosts)
	{
          WAnchor *singlePostName = new WAnchor(WLink(WLink::InternalPath,(i)->permalink), (i)->postName, postContainer);
	  WTemplate* loop = new WTemplate(postContainer);
	  loop->setTemplateText(loopTemplate);
	  loop->bindWidget("post-title",singlePostName);
	  loop->bindString("post-content",(i)->postContent);
        }
}

void PostLoop::handlePath()
{
   postContainer->clear();
   singlePostTemplate = new WTemplate(this);
   singlePostTemplate->setTemplateText(postTemplate);

   postPath = WApplication::instance()->internalPath();
   {
    dbo::Transaction t(session_);
    dbo::ptr<Post> postPtr = session_.find<Post>().where("permalink = ?").bind(postPath);
    singlePostTemplate->bindString("post-name",    postPtr->postName);
    singlePostTemplate->bindString("post-content", postPtr->postContent);
    t.commit();
   }
}
