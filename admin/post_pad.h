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

#include <sstream>

using namespace Wt;

class PostPad : public WContainerWidget
{
public:
    PostPad(WContainerWidget *parent);
    void storePost();
private:
    WContainerWidget *postEditor;
    WPushButton *submitPost;
    std::stringstream strm;    
    bool clicked;
};
#endif
