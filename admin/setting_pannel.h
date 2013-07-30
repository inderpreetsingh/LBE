/************************************************************

Filename: setting_pannel.h

Description: Containes declarations for settings widget in
             pannel

Authors: Gauravjeet Singh, Inderpreet Singh, Shaina Sabaarwal

License: GNU GPL V3

*************************************************************/

#ifndef SETTING_PANNEL_H
#define SETTING_PANNEL_H

#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>

using namespace Wt;

//! Strings for storing the title and tagline
extern std::string titleString, taglineString;

//! Class providing the user with various general settings
/*!
   This class allows user to customize the blog. It gives user power to control it's own blog.
   It consist of various things like changing the title, theme, etc.
*/
class settingPannel: public WContainerWidget
{
public:
//! It renders all the things required to take input from user
     settingPannel(WContainerWidget *parent);
//! It saves all the provided settings
     void saveSettings();

private:
//! Parent Container to all the settings widgets
     WContainerWidget *settingContainer;
//! Input field to input main title
     WLineEdit *title;
//! Input field to add tagline
     WLineEdit *tagline;
//! Button to save all the changes
     WPushButton *saveButton;
};
#endif
