#include "characterdialog.h"
#include "ui_characterdialog.h"

CharacterDialog::CharacterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CharacterDialog)
{
    ui->setupUi(this);
}

CharacterDialog::~CharacterDialog()
{
    delete ui;
}

void CharacterDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton standart_btn=ui->buttonBox->standardButton(button);
    switch (standart_btn) {
    case QDialogButtonBox::Ok:
        accept();
        qDebug()<<"Accept Button clicked.";
        break;
    case QDialogButtonBox::Save:
        qDebug()<<"Save Button clicked.";
        break;
    case QDialogButtonBox::Open:
        qDebug()<<"Open Button clicked.";
        break;
    case QDialogButtonBox::Close:
        reject();
        qDebug()<<"Close Button clicked.";
        break;
    default:
        break;
    }
}

