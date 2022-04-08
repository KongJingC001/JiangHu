#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //字符串函数
#include <ctype.h>      //实现大小写转换
#include <windows.h>    //Windows API
#include <time.h>       //获取系统时间
#include <conio.h>      //无缓冲输入
#include <process.h>    //多线程

/*  装备最高等级*/
#define EQUIP_MAX_LEVEL 9
/*  统一最大数组长度*/
#define UNIFORM_MAX_LENGTH 16
/*  左留白*/
#define MARGIN_LEFT 25
/*  游戏界面长度*/
#define GUI_LENGTH 78
/*  登录界面的高*/
#define LOGIN_HEIGHT 7
/*  登录界面的菜单开始行数*/
#define LOGIN_MENU_LINE (LOGIN_HEIGHT + 2)
/*  门派数*/
#define SCHOOL_COUNT 20
/*  门派列表高度*/
#define SCHOOL_LIST_HEIGHT 4
/*  门派列表宽度度*/
#define SCHOOL_LIST_WIDTH 5
/*  门派信息打印开始行数*/
#define SCHOOL_DESCRI_LINE (LOGIN_MENU_LINE + SCHOOL_LIST_HEIGHT + 3)
/*  游戏地图打印开始行数*/
#define MAP_LINE 3
/*  地图行数*/
#define MAP_ROWS 8
/*  地图列数*/
#define MAP_COLS 8
/*  信息界面开始打印行数*/
#define INFO_GUI_LINE (MAP_LINE + MAP_ROWS + 1)
/*  信息界面高度*/
#define INFO_HEIGHT 8
/*  游戏主菜单开始打印行数*/
#define GAME_MENU_LINE (INFO_GUI_LINE + INFO_HEIGHT + 2)
/*  招式数量*/
#define SKILL_COUNT 100
/*  分隔符，长度为78*/
#define SEPARATOR "------------------------------------------------------------------------------"
/*  清空符，为清空当前行*/
#define CLEAR "                                                                              "

/********************************数据结构*************************************/

/*  装备类型*/
typedef enum _EquipKind
{
    hp_prop = 3,   //回血道具
    ip_prop = 4,   //回复内力道具
    weapon = 1, //武器
    armor = 2   //防具
}EquipKind;

/*  装备数据结构*/
typedef struct _Equip
{
    int id;                         //装备id
    char name[UNIFORM_MAX_LENGTH];  //装备名称
    int level;                      //装备级别
    EquipKind kind;                 //装备种类
    union                        //装备特有属性
    {
        int attack;     //武器的攻击力
        int defense;    //防具的防御力
        int value;      //药瓶的回复值
    };
    int price;                      //装备价格
    char * descri;                  //装备描述
}Equip;

/*  背包数据结构*/
typedef struct _Backpack
{
    int count;      //背包容量
    Equip equip[UNIFORM_MAX_LENGTH];    //对应装备
}Backpack;

/*  门派正邪*/
typedef enum _SchoolKind
{
    shodow, //亦正亦邪
    good,   //正派
    evil    //邪派
}SchoolKind;

/*  门派数据结构*/
typedef struct _School
{
    int id;         //门派id
    char name[UNIFORM_MAX_LENGTH];  //门派名
    SchoolKind kind;    //门派正邪
    COORD coord;        //门派坐标
    char * descri;      //门派描述
}School;

/*  玩家等级结构体*/
typedef struct _RoleLevel
{
    int level;              //级别
    char name[UNIFORM_MAX_LENGTH];  //等级别称
    int exp;                //级别对应经验值
    int attack;             //攻击力
    int defense;            //防御力
    int healthPoint;        //玩家生命值
    int internalForceUP;    //玩家内力上限
    int money;              //升级赠送金币
}RoleLevel;

/*  角色数据结构*/
typedef struct _Role
{
    char name[UNIFORM_MAX_LENGTH];          //角色昵称
    char id[UNIFORM_MAX_LENGTH];            //登录ID
    char password[UNIFORM_MAX_LENGTH];      //登录密码
    int attack;         //玩家攻击力
    int defense;        //玩家防御力
    RoleLevel roleLevel;      //玩家等级
    int exp;            //玩家经验值
    School school;      //玩家门派
    int healthPoint;    //玩家生命值
    int internalForce;  //玩家内力
    int money;          //玩家所持金币
    int reputation;     //声望
    Equip weapon;       //武器
    Equip armor;        //防具
    Backpack backpack;  //背包
    COORD coord;        //玩家当前位置
}Role;

/*  怪物的生死*/
typedef enum _State
{
    death,
    live
}State;

/*  怪物结构体*/
typedef struct _Monster
{
    int id;         //怪物ID
    char name[UNIFORM_MAX_LENGTH];  //怪物名称
    int level;      //怪物级别
    int healthPoint;            //怪物生命值
    int attack;                 //怪物攻击力
    int defense;                //怪物防御力
    int minMoney;   //掉落金币最小值
    int maxMoney;   //掉落金币最大值
    int exp;        //杀死后玩家所得经验值
    State state;      //怪物状态
}Monster;

/*  游戏地图结构体*/
typedef struct _Map
{
    int id;     //地图标识符
    char name[UNIFORM_MAX_LENGTH];  //地图名
    int level;          //地图等级
    COORD coord;        //地图坐标
    char * descri;      //地图描述
    Monster monster[UNIFORM_MAX_LENGTH];    //地图怪物
    Backpack store;      //道具店
}Map;

/********************************属性函数*************************************/
/*  光标位置设置*/
void SetPosition(int X, int Y);
/*  前后景设置
    0 = 黑色       8 = 灰色
    1 = 蓝色       9 = 淡蓝色
    2 = 绿色       A = 淡绿色
    3 = 浅绿色     B = 淡浅绿色
    4 = 红色       C = 淡红色
    5 = 紫色       D = 淡紫色
    6 = 黄色       E = 淡黄色
    7 = 白色       F = 亮白色
    */
void SetColor(int foreColor, int backColor);
/*  默认前后景设置*/
void DefaultColor();
/*  设置程序标题*/
void SetTitle(char * title);
/*  设置游戏窗口大小*/
void SetGUISize(int height, int width);

/********************************过程函数*************************************/
/*  登录游戏*/
void Login();
/*  登录账号*/
int LoginAccount();
/*  注册账号*/
void SignUp();
/*  写入玩家信息*/
void Write_INFO(Role role);
/*  读取玩家信息*/
void Read_INFO();
/*  读取装备*/
Equip Read_Equip(int id);
/*  写入装备*/
void Write_Equip();
/*  打印游戏主菜单*/
void ShowMenu();
/*  游戏界面加载*/
void ShowGUI();
/*  给地图中分配怪物*/
void CreateMonster();
/*  判断玩家是否升级，升级则修改属性*/
void isUpgrade();
/*  给地图分配道具，生成道具店*/
void CreateStore();

#endif // GUI_H_INCLUDED
