/************************************************************
FileName: post_loop.h

Description: Contains Declarations for post loop

Authors: Gauravjeet Singh, Shaina Sabarwal, Inderpreet SIngh

License: GNU GPL V3

*************************************************************/

#ifndef POST_LOOP_H_
#define POST_LOOP_H_

#include <Wt/WContainerWidget>
#include <vector>
#include <Wt/WTemplate>

#include "post.h"
#include "global.h"

using namespace Wt;
namespace dbo = Wt::Dbo;
//! Class for traversing through all the posts
/*!
    This class is inherited from WContainerWidget with purpose of making a widget that can be used to display all the posts at one time. 
This traversal is done through a loop so the name post loop
*/

class PostLoop : public Wt::WContainerWidget
{
public:
	
	PostLoop(Wt::WContainerWidget * parent);
	//! theLoop is the main loop that traverses through all the posts in the blog.
	void theLoop();
private:
	//! allPosts is a container where all the posts are stored
	PostCollection allPosts;
};
#endif
