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

void CharacterDialog::on_ok_button_clicked()
{
    QString user_name=ui->name_line_edit->text();

    if (!user_name.isEmpty()) {
        m_name=user_name;

        if (ui->goku_button->isChecked()) {
            m_fav_char="Goku";
        }
        if (ui->ichigo_button->isChecked()) {
            m_fav_char="Ichigo";
        }
        if (ui->luffy_button->isChecked()) {
            m_fav_char="Luffy";
        }

        accept();

    }else {
        reject();
    }

}


void CharacterDialog::on_cancel_button_clicked()
{
    reject();
}

QString CharacterDialog::fav_char() const
{
    return m_fav_char;
}

QString CharacterDialog::name() const
{
    return m_name;
}

