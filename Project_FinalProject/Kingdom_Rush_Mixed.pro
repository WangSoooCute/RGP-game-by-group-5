#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T21:27:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kingdom_Rush_Mixed
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        window.cpp \
    abstract_obj.cpp \
    live_player.cpp \
    princess.cpp \
    enemy_monster.cpp \
    iceball.cpp \
    thrown_obj.cpp \
    enemy_wolf.cpp \
    constant.cpp \
    button.cpp \
    scene_transition.cpp \
    scene_startup.cpp \
    scene_home.cpp \
    stable_obj.cpp \
    arrow.cpp \
    enemy_firewolf.cpp \
    guard_archer.cpp \
    missile.cpp \
    enemy_boss_a.cpp \
    scene_bag.cpp \
    scene_battle.cpp \
    enemy_cavalry_wolf.cpp \
    enemy_firecow.cpp \
    enemy_firewizard.cpp \
    enemy_pigsoldier.cpp \
    fireball.cpp \
    fireball2.cpp \
    fireball3.cpp \
    orangeball.cpp \
    enemy_boss_b.cpp \
    enemy_woodmonster.cpp \
    enemy_spider.cpp \
    mymissile.cpp \
    shooter.cpp \
    enemy_greenmonster.cpp \
    greenstone.cpp \
    bullet.cpp \
    icecone.cpp \
    icefrozen.cpp \
    lightning.cpp \
    enemy_firemonster.cpp

HEADERS += \
        window.h \
    abstract_obj.h \
    live_player.h \
    princess.h \
    enemy_monster.h \
    constant.h \
    iceball.h \
    thrown_obj.h \
    enemy_wolf.h \
    button.h \
    scene_transition.h \
    scene_home.h \
    scene_startup.h \
    stable_obj.h \
    arrow.h \
    enemy_firewolf.h \
    guard_archer.h \
    enemy_boss_a.h \
    missile.h \
    scene_bag.h \
    scene_battle.h \
    enemy_cavalry_wolf.h \
    enemy_firecow.h \
    enemy_firewizard.h \
    enemy_pigsoldier.h \
    fireball.h \
    fireball2.h \
    fireball3.h \
    orangeball.h \
    enemy_boss_b.h \
    enemy_spider.h \
    enemy_woodmonster.h \
    mymissile.h \
    shooter.h \
    enemy_greenmonster.h \
    greenstone.h \
    bullet.h \
    icecone.h \
    icefrozen.h \
    lightning.h \
    enemy_firemonster.h

FORMS += \
        window.ui

RESOURCES += \
    resource.qrc

CONFIG += \
    resources_big
