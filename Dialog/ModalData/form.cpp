#include <QtGui>
#include <iostream>
#include <sstream>

#include "form.h"
#include "dialog.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
{
  setupUi(this);
}

void Form::on_btnShowModal_clicked()
{
  // Modal - Using this, the user can only interact (not the calling widget) with the dialog until it is closed.
  // This is how you would get a filename before proceeding or something like that.
  Dialog* myDialog(new Dialog);
  myDialog->exec();

  int result = myDialog->result();
  if(result) // The user clicked 'ok'
    {
    std::stringstream ss;
    ss << result;
    this->lblModalResult->setText(myDialog->GetUserText().c_str());
    }
  else
    {
    // The user clicked 'cancel' or closed the dialog
    this->lblModalResult->setText("invalid");
    }
}
