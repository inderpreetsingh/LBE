/************************************************************

Filename: post_pad.C

Description: widget of admin panel that adds posts

Authors: Gauravjeet Singh, Inderpreet Singh, Shaina Sabarwal

License: GNU GPL V3

*************************************************************/

#include "post_pad.h"

PostPad :: PostPad (WContainerWidget *parent)
        : WContainerWidget(parent),
	postContent(this,"getPostContent")
{
    WApplication::instance()->require("../resources/epic_editor/js/epiceditor.js");
    strm<<"var editor = new EpicEditor().load();";
    WApplication::instance()->doJavaScript(strm.str());

    postTitle = new WLineEdit(this);
    postTitle->setEmptyText("Title of post");

    postEditor = new WContainerWidget(this);
    postEditor->setId("epiceditor");    
    submitPost = new WPushButton("Submit", this);
    submitPost->clicked().connect(this,&PostPad::getPost);
    postContent.connect(this, &PostPad::storePost);
}

void PostPad :: getPost()
{  
    strm<<postContent.createCall("editor.getElement('editor').body.innerHTML");
    WApplication::instance()->doJavaScript(strm.str());  
}

void PostPad :: storePost(std::string postContentStr)
{
    {
      dbo::Transaction t(session_);
      Post *newPost = new Post();
      newPost->postName = postTitle->text().toUTF8();
      newPost->postContent = postContentStr;
      dbo::ptr<Post> postPtr = session_.add(newPost);     
      t.commit();
    }
}
 


