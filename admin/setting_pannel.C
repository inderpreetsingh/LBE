/************************************************************

Filename: setting_pannel.C

Description: Provides with a settings widget in admin pannel

Authors: Gauravjeet Singh, Inderpreet Singh, Shaina Sabaarwal

License: GNU GPL V3

*************************************************************/

#include "setting_pannel.h"
#include <Wt/WBreak>
#include <Wt/WApplication>

std::string titleString, taglineString;

settingPannel::settingPannel(WContainerWidget *parent):WContainerWidget(parent)
{
  settingContainer = new WContainerWidget(this);

  new WText("Title of Blog: ", settingContainer);
  title = new WLineEdit(settingContainer); 
//  title->setEmptyText("some catchy title");

  settingContainer->addWidget(new WBreak());
  
  new WText("Tagline of Blog: ", settingContainer);
  tagline = new WLineEdit(settingContainer);
//  tagline->setEmptyText("Some cheesy tagline");

  saveButton = new WPushButton("Save", settingContainer);
  saveButton->clicked().connect(this, &settingPannel::saveSettings);
}

void settingPannel::saveSettings()
{
  titleString  = title->text().toUTF8();
  taglineString = tagline->text().toUTF8();
  new WText("Settings saved", this); 
}
