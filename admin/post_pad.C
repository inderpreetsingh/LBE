/************************************************************

Filename: post_pad.C

Description: widget of admin panel that adds posts

Authors: Gauravjeet Singh, Inderpreet Singh, Shaina Sabaarwal

License: GNU GPL V3

*************************************************************/

#include "post_pad.h"

PostPad :: PostPad (WContainerWidget *parent)
        : WContainerWidget(parent)
{
    WApplication::instance()->require("../resources/epic_editor/js/epiceditor.js");
    strm<<"var editor = new EpicEditor().load();";
    WApplication::instance()->doJavaScript(strm.str());
    postEditor = new WContainerWidget(this);
    postEditor->setId("epiceditor");    
    submitPost = new WPushButton("Submit", this);
    submitPost->clicked().connect(this,&PostPad::storePost);	
}

void PostPad :: storePost()
{
    if(clicked == false)
    {
      clicked = true;
      strm<<"editor.getElement('editor').body.innerHTML;";
      WApplication::instance()->doJavaScript(strm.str());
     // new WText("that works",this);
    }
}  
 


