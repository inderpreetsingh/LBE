/************************************************************

Filename: category_pannel.h

Description: Containes declarations for category display widget 
	     in pannel

Authors: Shaina Sabarwal, Gauravjeet Singh, Inderpreet Singh

License: GNU GPL V3

*************************************************************/

#ifndef _CATEGORYPANNEL_H
#define _CATEGORYPANNEL_H

#include <Wt/WContainerWidget>
#include <Wt/WAnchor>
#include <Wt/WText>
#include <Wt/WBreak>

#include "../user.h"
#include "../post.h"
#include "../global.h"
//! This class provides the link of various categories
/*!
    This class facilitates the user to see all the posts related to a particular category
*/
class CategoryPannel :public WContainerWidget
{
  public:
  //! It retrieves the names of the categories from the category table in the database and display as links 
  CategoryPannel(WContainerWidget *parent);
  //! This container contains the category links
  WContainerWidget *categorycontainer;
  
  private:
  //! It creates the Anchor of category names
  WAnchor *CategoryNames;
  //! A dbo collection pointer 
  dbo::collection <dbo::ptr<Category> > cat_pannel;
  Session session_;
};
#endif
 
