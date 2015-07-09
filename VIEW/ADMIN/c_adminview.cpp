#include<VIEW/ADMIN/c_adminview.h>

C_AdminView::C_AdminView(QObject *parent, Admin* model_, AdminView* view_) :
    QObject(parent), model(model_), view(view_)
{
    c_admincontent=new C_AdminContent(this,model,view->getAdminContent());
}

C_AdminView::~C_AdminView(){
    delete c_admincontent;
}
