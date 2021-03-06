#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

int botLevel = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    QApplication::processEvents();
    this->setFixedSize(this->size());
    QPixmap pix(":img/background_menu.png");
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background, pix);
    this->setPalette(pal);
    QPixmap titlePixmap(":img/title.png");
    titlePixmap = titlePixmap.scaled(ui->lbl_title->size());
    ui->lbl_title->setPixmap(titlePixmap);
    QPixmap mainToadPixmap(":img/toad_main");
    mainToadPixmap = mainToadPixmap.scaled(ui->lbl_toad_main->size());
    ui->lbl_toad_main->setPixmap(mainToadPixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_level_clicked()
{
    if (botLevel == 1){
        botLevel = 2;
        ui->btn_level->setText("LEVEL: MEDIUM");
    } else if (botLevel == 2){
        botLevel = 3;
        ui->btn_level->setText("LEVEL: HARD");
    } else if (botLevel == 3){
        botLevel = 1;
        ui->btn_level->setText("LEVEL: EASY");
    }
}


void MainWindow::on_btn_startGame_clicked()
{
    this->setVisible(false);

    Game * gameWindow = new Game(this);
    gameWindow->open();
    QApplication::processEvents();

    this->setVisible(true);
}
