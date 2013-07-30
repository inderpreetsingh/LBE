/*******************************************************

FileName: post_loop.C

Description: Holds the definition of class for posts widget

Author: Gauravjeet Singh, Shaina Sabarwal, Inderpreet Singh

License GNU GPL V3

***********************************************************/ 

#include "post.h"
#include "post_loop.h"
#include "global.h"
#include "add_theme.h"

string tempText;
PostLoop::PostLoop(WContainerWidget *parent)
    :WContainerWidget(parent)
{
    {
      dbo::Transaction T(session_);
      Post *post = new Post();
      post->postName = "Title goes here";
      post->postContent = "Content goes here";
      dbo::ptr<Post> newPost = session_.add(post);
      T.commit();
    }

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
	  WTemplate* loop = new WTemplate(this);
	  loop->setTemplateText(tempText);
	  loop->bindString("post-title",(i)->postName);
	  loop->bindString("post-content",(i)->postContent);
        }
}
