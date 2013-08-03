/************************************************************

Filename: post_pad.h

Description: widget of admin panel that adds posts

Authors: Gauravjeet Singh, Inderpreet SIngh, Shaina Sabarwal

License: GNU GPL V3 

*************************************************************/

#ifndef _POST_PAD_H
#define _POST_PAD_H

#include <Wt/WTextEdit>
#include <Wt/WContainerWidget>
#include <Wt/WPushButton>
#include <Wt/WApplication>
#include <Wt/WLineEdit>
#include <Wt/WJavaScript>
#include <Wt/WTextEdit>
#include <sstream>

#include "../post.h"
#include "../global.h"

using namespace Wt;

class PostPad : public WContainerWidget
{

public:
    PostPad(WContainerWidget *parent);
    void storePost(std::string postContent);
    void getPost();
private:
    WContainerWidget *postEditor;
    WLineEdit *postTitle;
    WPushButton *submitPost;
    
    JSignal<std::string> postContent;

    std::stringstream strm; 
    bool clicked;

};
#endif
