#include "core.h"

/*  初始化游戏*/
void INIT_GAME()
{
    //载入装备数据
    Write_Equip();
    // 分配怪物
    CreateMonster();
    //给地图分配商店
    CreateStore();
}


//游戏运行核心
void GameCore()
{
    /*  判断系统类型*/
    OperatorSystem();
    /*  设置程序标题*/
    SetTitle("笑傲江湖之精忠报国");

    // 初始化游戏
    INIT_GAME();
    //登录账号
    Login();

    ///***游戏开始***/
    //载入游戏界面
    ShowGUI();
}





