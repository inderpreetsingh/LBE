#include "category_pannel.h"

CategoryPannel::CategoryPannel(WContainerWidget *parent):WContainerWidget(parent)
{
	categorycontainer = new WContainerWidget(this);
	WText *t = new WText("categories coming soon", categorycontainer);
	/*{
	  dbo::Transaction t(session_);
	  cat_pannel = session_.find<Category>();
	  for(auto k: cat_pannel)
	  {
	        		
		CategoryNames = new WAnchor(WLink(WLink::InternalPath,(k)->categoryname), (k)->categoryname, categorycontainer);
		categorycontainer->addWidget(new WBreak());
	  } 
	  t.commit();
	}*/
}
