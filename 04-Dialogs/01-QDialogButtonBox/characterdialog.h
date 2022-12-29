#ifndef CHARACTERDIALOG_H
#define CHARACTERDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class CharacterDialog;
}

class CharacterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CharacterDialog(QWidget *parent = nullptr);
    ~CharacterDialog();

    QString name() const;

    QString fav_char() const;

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    QString m_name;
    QString m_fav_char;
    Ui::CharacterDialog *ui;

};

#endif // CHARACTERDIALOG_H
