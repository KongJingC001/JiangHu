#include "gui.h"

//玩家角色
Role role;

/*  地图*/
Map map[8][8] =
{
    {
        {1, "天山",   1, {0, 0}, "据《穆天子传》记载，3000年前的周朝穆王曾乘坐\"八骏马车\"西行天山，西王母在天池接见了他。穆王赠送大批锦绸美绢等中原特产，西王母则回赠了天山的奇珍瑰宝，并邀请穆王游览天山名胜。穆王亲书\"西王母之山\"，留作纪念。临别时，西王母劝饮再三，即席歌曰:\"祝君长寿，愿君再来。\""},
        {2, "楼兰",   1, {1, 0}, "东通敦煌，西北到焉耆、尉犁，西南到若羌、且末。古代“丝绸之路”的南、北两道从楼兰分道。"},
        {3, "白驼山", 1, {2, 0}, "这可是当年大魔头欧阳锋的发家之地。今天的白驼山却很安静。。。"},
        {4, "野猪林", 1, {3, 0}, "野猪林里到处都是野猪。。。嗖！嗖！嗖！搜！。。。四只小野猪围了过来。喝过8个巨无霸后，领头的野猪朗声道：俗套！"},
        {5, "水晶洞", 1, {4, 0}, "走进一个洞中，洞中的景色马上呈现在眼前，这里真是太美了。一低头，发现脚边有一块石碑，上面写着：水晶洞。"},
        {6, "天蚕洞", 1, {5, 0}, "天蚕洞满地蚕茧，满地飞蛾。噗噜噜！噗噜噜！拨开飞蛾，踢开蚕蛹。。。但见一绝色女尼正坐在你的面前@！@！闭眼闭眼！"},
        {7, "黑风寨", 1, {6, 0}, "黑风寨只有狂风在不停地吹。突然，一条东瀛狼狗疯狂地扑了上来，一阵乱咬。"},
        {8, "冰火岛", 1, {7, 0}, "冰火岛上只有火球、冰块。快跑，轰隆隆----火山爆发了！咦，怎么只有烟，没有火？"}
    },
    {
        {9, "迷宫",    1, {0, 1}, "这里是高昌迷宫，也是一个十分神秘的地方，连江湖阅历及其丰富的老侠客都不知道这会发生什么事情。"},
        {10, "凌霄城", 1, {1, 1}, "凌霄城只有哆嗦，没人。"},
        {11, "轩辕岭", 1, {2, 1}, "一条山岭，绿油油的，不过从远处看去，岭上透出一层杀气，问过路人才知道，这里就是早有耳闻的轩辕岭！"},
        {12, "华山",   1, {3, 1}, "自古华山一条路，只许上，不许撤。如同风景介绍一般，五岳派总舵岂是邪魔歪道们随便来去之地？不过如果是君子，那就大可放心了。"},
        {13, "嵩山",   1, {4, 1}, "在雄伟的嵩山上，有一个江湖上名声响亮的寺庙：少林寺。如果说桂林山水甲天下，那么少林武功甲天下并不为过。"},
        {14, "紫禁城", 1, {5, 1}, "大内高手云集的地方。谁要赶来这里闹事，得罪的不光是大内锦衣卫，还有当今的皇上。"},
        {15, "快活林", 1, {6, 1}, "快活林快活林，有钱才能快乐！"},
        {16, "神龙岛", 1, {7, 1}, "这一上岛来，就能听到不知是韦小宝还是周星驰发出的笑声：啊哈哈哈哈哈哈哈！！这就是神龙教的总舵：神龙岛了。"}
    },
    {
        {17, "西域",   1, {0, 2}, "西域大漠的风沙吹得人和牲畜都睁不开眼睛。这里没有水，没有树，没有草，死一般的像个地狱。"},
        {18, "葫芦谷", 1, {1, 2}, "葫芦峪里似乎只有葫芦。远看还真像只大葫芦。"},
        {19, "唐门",   1, {2, 2}, "这里是唐家堡，从外面看这只是一个大宅院，与其他的富家宅院没有什么两样，但却是藏龙卧虎之地。"},
        {20, "终南山", 1, {3, 2}, "这里是终南山，全真教总舵。两旁丛丛耸耸的长满了各种树木，大道的尽头出现一座道观，几个小道士边聊天边请扫道观。"},
        {21, "石窟",   1, {4, 2}, "这里是龙门石窟，一个个的石窟自有一种神秘感。"},
        {22, "客栈",   1, {5, 2}, "地处交通要道的龙门客栈可是名扬四海，老帮娘金香玉的名头也是世人皆知，今天她在店里吗？"},
        {23, "玉皇顶", 1, {6, 2}, "一个永远不会安定的地方：泰山玉皇顶。这里是一个充满着厮杀的地方，无时无刻不充斥着暴力、仇杀的地方。"},
        {24, "灵蛇岛", 1, {7, 2}, "到处都是蛇的岛，这就是灵蛇岛。在这里，恐怖的故事层出不穷，令人毛骨悚然。不过要是喜欢吃蛇的人来到这里，可是该高兴死了。"}
    },
    {
        {25, "光明顶", 1, {0, 3}, "所谓三十六峰者，骈列舒张，横绝天表，众岫叠岭，效奇献秀，尽在一览。"},
        {26, "摩天崖", 1, {1, 3}, "这里是摩天崖，陡峭的石壁，就连猿猴上下都不可能，真是太险了。真难以想象当年谢烟客是如何在上面生存而又可以叱咤风云的。"},
        {27, "聚贤庄", 1, {2, 3}, "聚贤庄大家今日都很忙。虽然现在没人，不过无所谓！"},
        {28, "后山",   1, {3, 3}, "终终南后山的景色就是不一般，到处盛开着叫不上名字的各色小花，几只蜜蜂在花间飞舞，沿着一条花间小路来到一个古墓前，上面写着：活死人墓。"},
        {29, "武当山", 1, {4, 3}, "武当山只有火工道人在打盹。红卫兵刚刚来过！道士全都拉走批斗了！"},
        {30, "开封府", 1, {5, 3}, "宋朝时的都城，因有包青天而世人皆知。同时也是武林人士活动的要地。"},
        {31, "二十四桥", 1, {6, 3}, "今天没人乐意走二十四桥，不如坐下来喝点茶，寂寞高手嘛！"},
        {32, "蓬莱仙境", 1, {7, 3}, "云雾缭绕的蓬莱仙境自古以来都似乎隐藏着天大的秘密，谁能真正揭开这里的迷呢？也许你可以，也许他额可以。"}
    },
    {
        {33, "擂鼓山", 1, {0, 4}, "这里是擂鼓山，一点也想不到这座山为什么要起这个名字，看到的是这么美丽的景致，听到的却是个并不美丽的名字。"},
        {34, "峨眉山", 1, {1, 4}, "峨眉金顶只有几个扫山尼姑。尼姑当然寂寞！寂寞的人当然想说话！说了乱七八糟后，并没有提供什么有用的信息。"},
        {35, "迷踪林", 1, {2, 4}, "这里是迷踪林，人们总说这片树林不要轻易走进，因为它十分危险，据说有不少人走进去就再也没有出来过。"},
        {36, "五虎岭", 1, {3, 3}, "五虎岭素以五条猛虎闻名，每年都有许多不自量力的捕虎人成群进入，但从来都是一去无回，五虎真的如此厉害？"},
        {37, "天宁寺", 1, {4, 4}, "佛家地天宁寺，每天前来进香之人络绎不绝。可从进香之人求愿灵验的程度上让人不得不产生怀疑。"},
        {38, "积善堂", 1, {5, 4}, "积善堂今天没卖出一张彩票。此时已是深夜，不如早些睡了吧！"},
        {39, "镇江府", 1, {6, 4}, "从两百里以外就可以闻到一股酸味，这就是镇江府，盛产镇江醋。"},
        {40, "桃花岛", 1, {7, 4}, "桃花岛今天没人来偷桃，愉快的花工正躺在花下。"}
    },
    {
        {41, "恶人谷",     1, {0, 5}, "恶人善人都不在谷里。只有小鱼儿在睡觉！这家伙，抗倭一点都不积极。"},
        {42, "大理",       1, {1, 5}, "大理城里只有大理平民，平民最好打交道!"},
        {43, "百花谷",     1, {2, 5}, "哇，这里太美了，这里的很多花都叫不上名字！"},
        {44, "孔雀山庄",   1, {3, 5}, "这里金湖碧波荡漾，典型的傣式建筑掩映在茂密的森林之中，孔雀争相开屏、鸵鸟欢唱迎宾，梅花鹿湖畔戏水，人与自然和谐相融。"},
        {45, "五霸岗",     1, {4, 5}, "如果有人问：哪里能交上武林朋友？那答案肯定是五霸岗。此地虽怪石嶙峋、寸草不生，但却是天下英雄汇聚的地方。"},
        {46, "万仞堂",     1, {5, 5}, "万仞堂，顾名思义，十八般兵刃样样俱全。最近该堂还搞了点副业，外卖防具、药丸，有意者敬请光顾。"},
        {47, "栖霞古刹",   1, {6, 5}, "栖霞古刹今天没人来拜佛，倭寇究竟在哪里呢？不仅仰天长叹。"},
        {48, "六合塔",     1, {7, 5}, "六合塔里阴森森的。空调可够足的！"}
    },
    {
        {49, "玩偶山庄", 1, {0, 6}, "来到了玩偶山庄，这里好像什么东西都与其他地方有些不同，这是一个十分特别的地方，不知进庄之后还能有什么与众不同的东西。"},
        {50, "黑木崖", 1, {1, 6}, "黑木崖今天没人来会任我行。突然间，飞来一只黑鸽，徐徐盘旋而下。"},
        {51, "蝴蝶谷", 1, {2, 6}, "为何蝴蝶谷中会有如此众多的蝴蝶？是不是因为发生了什么不可告人的事情？看来只有有缘人才能知道了。"},
        {52, "铁花堡", 1, {3, 6}, "神秘的铁花堡，曾经是飞龙帮在三百年前的总舵。自从飞龙帮最后一任帮主争夺武林盟主失败自杀后，如今已是一片凋零。如今的铁花堡，多的是制造铁工艺品的工匠。"},
        {53, "霹雳堂", 1, {4, 6}, "江湖雷家曾把这里建立成唯一可以与唐门暗器抗衡的雷家火器大本营。"},
        {54, "关帝庙", 1, {5, 6}, "一到关帝庙，就会看到无数乞丐。他们虽乞讨，但真实的任务却是习武练功，除暴安良。"},
        {55, "麒麟庄", 1, {6, 6}, "麒麟庄的人都被麒麟给吓跑了。"},
        {56, "销魂宫", 1, {7, 6}, "销魂宫现在没人消化灵魂。不如跟小姐们聊聊！群中的眼睛是雪亮的！头牌秦可卿柔声道：大兄弟做个大保健吧！"}
    },
    {
        {57, "石府",   1, {0, 7}, "天机石府里只有石头。石头当然不会是乱放的。可惜，石头太多怎么办？"},
        {58, "金三角", 1, {1, 7}, "金三角里看来没有别人。只有只老狗悻悻的靠在罂粟田头吸着什么。。。"},
        {59, "忏悔崖", 1, {2, 7}, "忏悔崖上没人在忏悔，却有人在宣传倭寇！"},
        {60, "通吃岛", 1, {3, 7}, "通吃岛上只有“此岛危险！当心被吃”几个字。"},
        {61, "通天观", 1, {4, 7}, "一个普普通通、其貌不扬的小小通天观，有意者都可以进来玩玩。观内有一颗很高的大树，从来没有人能够爬到树顶。据说它是通天的。"},
        {62, "紫霞亭", 1, {5, 7}, "紫霞亭现在空着，亭中有一盘棋。棋子不合棋法，但对你却有用！"},
        {63, "天弃庵", 1, {6, 7}, "天弃庵是空空荡荡的小尼姑庵。我想进去，但人家不让。"},
        {64, "侠客岛", 1, {7, 7}, "侠客岛没人钻研侠客神功。卖门票的女子百无聊赖。"}
    }
};

/* 门派 */
const School school[SCHOOL_COUNT] =
{
    {1,     "少林派",   good, {4, 1},  "中华武学的泰斗，明末，少林众多的人才中，以悟空和箭神二人排为一等。其中，悟空出家为僧，箭神乃俗家弟子。当时江湖人称少林双绝。少林寺中众僧在两大长老的带领下参加了江浙沿海抗击倭寇的战斗，在各路应募兵马中表现得最为骁勇。但正因抗倭之事，也使江湖中的众多门派产生了矛盾，其中首推少林和日月神教。悟空、箭神曾几度带领江湖同仁攻上光明顶，但由于日月神教和血河两派结为同盟，更何况邪派中高手如云，所以几次围剿未果而终，黑白两道都损失惨重"},
    {2,     "武当派",   good, {4, 3},  "武当在江湖上与少林齐名，有‘北崇少林’‘南尊武当’之说。 武当新一代的首领人物，是一位谦谦君子，一张轮廓分明的脸上总是带着爽朗的笑容，就连他的仇敌都不能不承认他是条少见的男子汉。凡人从十八岁崛起江湖，身经大小三十三战，至今从未败过一次。凡人一生中最不能忍受的两件事就是失败和错误。 "},
    {3,     "丐帮",     good, {6, 2},  "丐帮是中原武林中人数最为众多的一个门派，也是天下第一大帮派，以遍布天下乞丐的乞丐组成，分为污衣帮和净衣帮。丐帮中人大多都是社会地位比较低的人，但他们各个铮铮硬骨，品格高尚，很少出现卑劣之人。丐帮新一代众多弟子以天葵为首，除暴安良、行侠丈义、抑强扶弱，所作所为为天下人所津津乐道。"},
    {4,     "全真教",   good, {3, 2},  "全真属于道教的分支之一。现今全真教中最有权威的人是一个瘦瘦小小的人，长着一双冷冷淡淡好象永远不会有什么变化的眼睛，看起来仿佛是灰色的。但他又是一个非常讲究的人，他喜欢紫色，喜欢名马佳人华衣美酒，喜欢享受。对每一件事情他都非常的挑剔，做的每一件事都经过精密计划，绝不肯多浪费一分力气，也不会有一点疏忽。这就是全真海雅。"},
    {5,     "五岳剑派", good, {3, 1},  "泰山派，恒山派，衡山派，华山派，嵩山派结为同气枝连的的五岳剑派，在江湖上扬名立万。五派中人一向面和心不和，所以五派的式微不是由于外敌入侵，而纯粹是内部矛盾激化走向内耗的结果，内部的勾心斗角虽然常常以抗倭为借口出现，实则是为了掌握五岳生杀大权。"},
    {6,     "四川唐门", good, {2, 2},  "唐门在江湖上以暗器闻名。但自从唐门的唐老太太过世后唐家堡一度家道中落，加之唐甜为称霸武林挑起纷争，又使唐门陷入了再度的浩劫，几乎一蹶不振。在这种危难的时刻唐门出现了一群新生力量：唐纾、唐斩、唐缺、唐玉。他们整顿内务，肃清奸佞，打出了匡复武林正义的旗帜，并且在江湖上行侠仗义，挽回了唐门的声誉，使唐门成为了江湖上的名门正派。"},
    {7,     "大理段氏", good, {1, 5},  "大理段氏人丁众多，高手如云。其中有一位名扬江湖顶尖女侠——香雪儿。香雪儿面相灵秀，肤色白皙，但微显瘦弱，看上去弱不禁风却身怀绝世武功，已深得大理武功心得。"},
    {8,     "天山派",   good, {0, 0},  "天山派是名门正派，也是目前江湖中最为团结的一个门派。天山派也是江湖中女弟子最为众多的一个门派，且各个武功造诣不凡，相貌清秀。"},
    {9,     "古墓派",   good, {3, 3},  "古墓派这一代的传人名叫暄雯，是一女子，来历不明。暄雯生性娴静，长相俊美，举止飘逸，但做事情却不似师祖小龙女，倒颇有一点杨过的风格，武功修为深不可测，同样喜穿白衣。此派轻功卓越，剑法、拳法灵动妙绝，更是全真教的克星。古墓传人的处世原则是“事不关己，高高挂起”，过着与世无争的日子，但是如果有人冒犯了古墓传人，那他一定会死得很惨。"},
    {10,    "名捕门",   good, {5, 1},  "名捕门历属与官府，但其中也不乏在江湖上闯出名堂的武林高手。名捕门一等一的人才中有一位绰号叫‘惊天泣鬼’的，此人从不以真面目视人，总是在幕后策划一些事情。"},
    {11,    "日月神教",evil, {1, 6},  "由于该教高手众多，并彼此互不相服，所以教务混杂。教中弟子多为邪恶之徒，专与名门正派作对，杀人良多，罪恶昭彰，故被江湖正派之人贬为魔教。"},
    {12,    "权力帮",  evil, {6, 6},  "邪派之一，目前派中最高首脑为一叫阿飞的年轻人。阿飞，一个表面上异常忧悒的人。没有与其交过手的武林高手，无法想象他那弱不禁风的身躯隐藏着那么大的潜力，更不能想象他是如何用支撑起权利帮的担子的。"},
    {13,    "五毒教",  evil, {0, 2},  "一个以使毒为专长的门派，派中人各个都是用毒高手。此派高手人称梦魇，其人使毒已入化境，令人难以琢磨，江湖同道对其莫不绕道而行。此人品行时好时坏，但坚韧卓绝，嗜武成痴。"},
    {14,    "神龙教",  evil, {7, 2},  "神龙教是江湖邪派，由于教址远离中原，所以不大干预中原武林的血腥杀戮。目前神龙教有两位高手一为刀神，此人武功高深莫测，性格孤僻冷傲，不喜与人接近。二为恶龙，武功高强但脾气暴躁，做事没有耐性。"},
    {15,    "青龙会",  evil, {6, 5},  "江湖上绵延数百年的一个神秘组织。青龙会下分十二堂，分别以月为代号。"},
    {16,    "桃花岛",  shodow, {7, 4},  "自从东邪黄药师扬名立万于此后，他的传人就在这里绵延不绝，竟将桃花岛建成了门派的总舵。桃花岛黄药师的关门弟子程英一生未嫁，在岛上收了几个徒弟，桃花岛的武功因此得到延续和发扬。"},
    {17,    "锦衣卫",  shodow, {5, 3},  "大内锦衣卫中人才济济，尤其是雷神，此人野心勃勃，自幼练得一身大力金刚功，号称刀枪不入，武功实是深不可测。而且为人机智，精通兵法，行兵时能将千军万马人使得如同数十万般威力十足。"},
    {18,    "血河派",  shodow, {4, 2},  "自从血河派的掌门一代大侠方歌吟飘然而去后，血河派日益衰落。血河派活动的范围也越来越少，基本上只限与龙门石窟。而江湖上的九大门派已经把血河派视为邪魔歪道。并已传出英雄令，只要九大门派的门人遇上血河派的人，一律格杀无论。在江湖上已经没有什么血河派的人在行走。除了无恨！没有人知道他来自何方，人们只知道他来自血河派。没有人知道他的武功有多高，因为看见他的剑的人都已经......无恨是武林中的一个谜，现隐居在天山，相传是为了一名叫若寒的女子。相传血河弟子花无缺已深得无恨真传，在无恨隐居江湖期间代理血河的一切帮中事务。花无缺为人善良真诚，在江湖上人缘甚好，并将血河派内外事务打理得井井有条。"},
    {19,    "通通吃",  shodow, {3, 7},  "江湖上一个神秘的门派，创始人，武功不祥。总舵设在通吃岛，教中首领人物——辉翰。此人手段严酷，以威服人。平常不轻易踏足中原武林，潜心修炼武功。"},
    {20,    "玩偶山庄", shodow, {6, 0}, "江湖上一个神秘的门派，创始人，武功不祥。总舵就在玩偶山庄，教中首领人物——阳光。玩偶山庄门人众多，但大都绝迹江湖，只有阳光经常独自浪迹江湖并闯出了名堂，所以武林中人才知有这么一个门派存在。"}
};

/**< 玩家等级 */
const RoleLevel LEVEL[] =
{
    /**< 级别、等级别称、经验值、攻击力、防御力、玩家生命值、玩家内力上限、升级赠送金币*/
    {1, "初出茅庐", 10,   20,     20,     200,    2000,   200},
    {2, "粗通皮毛", 120,   25,     25,     300,    2050,   300},
    {3, "略有小成", 130,   30,     30,     500,    2150,   500},
    {4, "心领神会", 150,   60,     60,     1000,   2500,   1000},
    {5, "出类拔萃", 200,   100,    100,    1500,   3000,   1500},
    {6, "所向无敌", 300,   200,    200,    2000,   3500,   2000},
    {7, "天人和一", 500,   1000,    500,    2500,   4000,   2500}
};


///* 游戏中的怪物 */
const Monster monsters[] =
{
    {1, "牛头怪",     1,   100,  5,   5,     1,     3,   10,  live},
    {2, "吸血鬼",     2,   200,  8,   12,    1,     8,   11,  live},
    {3, "僵尸",       3,   300,  10,  10,    3,     8,   20,  live},
    {4, "恶龙",       4,   500,  16,  16,    6,     15,  30,  live},
    {5, "亡灵法师",   5,   1000, 60,  60,    30,    50,  50,  live},
    {6, "魂吕布",     6,   2000, 100, 100,   30,    100, 100, live},
    {7, "钢铁巨兽",   7,   2000, 130, 130,   40,    120, 200, live},
    {8, "泰坦",       8,   5000, 170, 170,   100,   300, 300, live},
    {9, "秦始皇",     9,   5000, 400, 400,   120,   400, 400, live}
};

/* 游戏道具 */
const Equip equip[] =
{
    {1, "一字长蛇剑", 1, weapon, .attack=5,   1000, "犹如巨蟒出击，攻击凌厉！"},
    {2, "二龙汲水珠", 2, weapon, .attack=10,  2000, "高度的灵活性，玄妙无比！"},
    {3, "三叉海神戟", 3, weapon, .attack=15,  3000, "重达十万八千斤，威力无穷！"},
    {4, "四方苦禅杖", 4, weapon, .attack=20,  4000, "极度彰显了少林作为中原武林第一大派和佛门贵地的崇高地位。"},
    {5, "五虎攒羊锤", 5, weapon, .attack=25,  5000, "唯有能与元素沟通的人可以唤醒它的真正力量。"},
    {6, "六合迎风枪", 6, weapon, .attack=30,  6000, "当年兵器谱排名第二，第一是小李他妈的飞刀！"},
    {7, "七星斩将矛", 7, weapon, .attack=40,  7000, "矛尖有如白蛇吐信，是令敌将闻风丧胆的象征！"},
    {8, "八卦金锁鞭", 8, weapon, .attack=50,  8000, "打在身上，仿佛是幻影涰连，遮日蔽天！"},
    {9, "九转乾坤圈", EQUIP_MAX_LEVEL, weapon, .attack=90,  10000, "金色镯子，可翻江倒海，震荡乾坤！"},
    {100, "辟邪犀", 1, armor, .defense=5,   1000, "一块能解天下百毒的透明佩玉。"},
    {101, "乌蚕裙", 2, armor, .defense=15,  2000, "极其坚韧，刀枪不入，水火不侵！"},
    {102, "英姿带", 3, armor, .defense=20,  3000, "穿后精气饱满，神采飞扬，姿态英勇威风！"},
    {103, "天罡指", 4, armor, .defense=25,  4000, "飘忽不定，防东西至，防西东至！"},
    {104, "紫鲛衫", 5, armor, .defense=30,  5000, "海蛟皮制成，装备后可在水下呼吸！"},
    {105, "碧麟披", 6, armor, .defense=40,  6000, "上撰：上古南火朱雀之子,曾云字！"},
    {106, "金钟罩", 7, armor, .defense=45,  7000, "装备后有如金铸之钟覆罩全身，刀剑难损！"},
    {107, "防弹衣", 8, armor, .defense=60,  8000, "闯荡武林、居家必备！"},
    {108, "软猬甲", EQUIP_MAX_LEVEL, armor, .defense=70,  10000, "刀枪不入还可保暖，穿在身上，妙用无穷。桃花岛的镇岛之宝！"},
    {200, "人参", 1, hp_prop, .value=200,  2500, "一次性回复200点生命值。"},
    {201, "枸杞", 1, ip_prop, .value=100,  2000, "一次性回复100点内力值。"}
};

/*  欢迎信息*/
const char * LOGIN_WORDS[] =
{
    "欢迎来到大型单击角色扮演游戏 -《笑傲江湖之精忠报国》",
    "本游戏的内容不涉及政治、文化、经济，教育等严肃话题",
    "抵制不良游戏 拒绝盗版游戏",
    "注意自我保护 谨防受骗上当",
    "适度游戏益脑 沉迷游戏伤身",
    "合理安排时间 享受健康生活",
    "本游戏仅供娱乐，如有侵权立刻删除"
};


/*  攻击招式名称，以下信息均来自转载（黑虎阿福）*/
const char * const SKILL_NAME[] =
{
    "暴龙振翅飞翔", "笨驴踢腿", "仓鼠上车轮", "豺狼捕兔", "超行星燃烧", "打虎式", "大象拳", "大象踢腿",
    "袋鼠跳", "地震拳", "电眼逼人", "饿狼前进", "二龙戏珠", "飞鹤捕虾", "飞龙在天", "飞天陲",
    "飞天猴巧夺宝盒", "飞象踩老鼠", "飞鹰展翅", "愤怒的章鱼", "凤凰奔月", "弗拉明戈舞步", "黑虎捕食困小羊", "黑虎掠过秃鹰",
    "黑虎掏心", "轰雷拳", "猴子爬树", "虎落鹰背", "虎爪吃布丁", "火山烧农场", "鲸鱼摆尾", "巨斧砍大树",
    "飓风踢", "老鼠偷奶酪", "老鼠走迷宫", "老鹰展翅", "莲花飘", "镰刀扫地", "猎豹飞奔", "羚羊飞跃",
    "羚羊起跳", "流星毁灭", "流星连打山", "龙卷风摧毁停车场", "龙虾爪", "龙抓手", "骡子踢腿", "螺丝卷",
    "马尾拍苍蝇", "猫抖水", "猫落地", "猫转身", "牡蛎壳", "脑袋砸核桃", "怒鸦飞行", "怒鸦起飞",
    "劈山掌", "泼猴发功", "青鱼绝杀", "扫堂腿", "鲨鱼吃鱼", "鲨鱼吞饵", "山羊爬山", "蛇拳出动",
    "蛇形步", "狮子拜天", "树獭踢腿", "双风贯耳", "水牛打老鼠", "睡熊猛醒", "碎瓜拳", "泰山压顶",
    "螳螂拳", "腾空飞脚", "土拨鼠掷鼬鼠", "兔子拳", "顽猴神功", "螳螂神拳", "狡兔出击", "我成了瘸腿鹅",
    "乌龟拳", "乌鸦坐飞机", "犀牛狂奔", "小行星带", "小鱼水中游", "蝎子掌", "猩猩折枝", "熊掌出击",
    "熊捉鲑鱼", "眼镜蛇", "鹞鹰落地", "一虎杀两羊", "鹰爪功", "长臂在天", "蜘蛛吃苍蝇", "月色血风暴",
    "黯然销魂掌", "雷霆半月斩", "金色天际线", "八极崩"
};

/*  光标位置设置*/
void SetPosition(int X, int Y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {X, Y};
    SetConsoleCursorPosition(handle, coord);
}

/*  前后景设置*/
void SetColor(int foreColor, int backColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, foreColor + backColor * 0x10);
}

/*  默认前后景设置*/
void DefaultColor()
{
    SetColor(7, 0);
}

/*  设置程序标题*/
void SetTitle(char * title)
{
    SetConsoleTitle(title);
}

//登录游戏的欢迎界面
void Login_Welcome()
{
    int i;
    SetPosition(MARGIN_LEFT, 0);
    printf(SEPARATOR);
    for(i = 0; i < LOGIN_HEIGHT; i++)
    {
        SetPosition(MARGIN_LEFT, i + 1);
        printf("|");
        SetPosition(MARGIN_LEFT + 15, i + 1);
        printf(LOGIN_WORDS[i]);
        SetPosition(MARGIN_LEFT + GUI_LENGTH - 1, i + 1);
        printf("|");
    }
    SetPosition(MARGIN_LEFT, LOGIN_HEIGHT + 1);
    printf(SEPARATOR);
}

//登录游戏的菜单
int Login_Menu()
{
    int choice; //玩家的选择
    do
    {
        //打印欢迎界面
        Login_Welcome();
        //打印菜单
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE);
        printf("游戏菜单：");
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 1);
        printf("1、老玩家回归");
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 2);
        printf("2、新玩家登录");
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 3);
        printf("3、退出游戏");
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 4);
        printf("请选择：");
        if(scanf("%d", &choice) && (choice == 1 || choice == 2 || choice == 3))
        {
            fflush(stdin);
            break;
        }
        fflush(stdin);
        /*  错误输入就清空*/
        system("cls");
    }
    while(1);
    return choice;
}

//登录游戏
void Login()
{
    //用户的选择、登录结果
    int choice, result;
    //设置默认前后景色
    DefaultColor();
    //选择菜单
    choice = Login_Menu();
    //清屏，进入登录或注册页面
    system("cls");
    //打印欢迎菜单
    Login_Welcome();
    switch(choice)
    {
    case 1: //1、流程1-老玩家登录
        result = LoginAccount();
        //登录失败就退出游戏
        if(result == 0)
        {
            exit(0);
        }
        break;
    case 2: //2、流程2-新玩家注册
        SignUp();
        break;
    case 3: //3、流程3-退出游戏
        exit(0);
        break;
    }
}

/*  登录账号，成功返回1，失败返回0*/
int LoginAccount()
{
    int i, j = 0;
    //临时录入字符串
    char id[UNIFORM_MAX_LENGTH], password[UNIFORM_MAX_LENGTH];
    /** 验证帐号前先读取老用户所有信息*/
    Read_INFO();
    //登录，最多只能输入三次
    for(i = 0; i < 3; i++)
    {
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE);
        printf("第%d次输入（共3次）", i + 1);
        ///  1、输入id*/
        /*  打印提示信息*/
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 1);
        printf("请输入您的账号id：");
        /*  从键盘录入字符串*/
        scanf("%s", id);
        fflush(stdin);
        //验证是否为老用户，即id是否正确
        if(strcmp(id, role.id) == 0)
        {
            ///  2、输入密码*/
            /*  打印提示信息*/
            SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 2);
            printf("%s大侠，请输入您的账号密码：", role.name);
            /*  从键盘录入字符串*/
            do{
                password[j] = _getch();
                /*  按回车键结束输入*/
            }while(password[j++] != 13);
            /*  最后一个回车键改为'\0'*/
            password[j - 1] = '\0';
            //验证密码是否正确
            if(strcmp(password, role.password) == 0)
            {
                //登录成功，打印欢迎信息
                system("cls");
                Login_Welcome();
                SetPosition(MARGIN_LEFT + 20, LOGIN_MENU_LINE + 1);
                printf("%s大侠, 欢迎回到江湖！", role.name);
                Sleep(2000);
                return 1;  //管理员1身份验证成功则返回1
            }
        }
        //输入错误，打印错误信息
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 3);
        printf("账号或密码错误！！！");
        //清屏重新打印
        Sleep(2000);
        system("cls");
        Login_Welcome();
    }
    return 0;
}

/*  局部函数：打印门派信息,在登录界面区打印*/
int Show_School(int X, int Y)
{
    int i, j;
    //打印的门派ID，初始化第一个ID
    int id = school[0].id;
    //打印帮派名称列表信息，在登录界面区打印
    for(i = 0; i < SCHOOL_LIST_HEIGHT; i++)
    {
        SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + i);
        printf("|");
        SetPosition(MARGIN_LEFT + 10, LOGIN_MENU_LINE + i);
        for(j = 0; j < SCHOOL_LIST_WIDTH; j++)
        {
            //当前门派位置
            if(i == Y && j == X)
            {
                SetColor(7, 6);
                //获取要打印描述的门派ID
                id = school[i * 5 + j].id;
            }
            printf("%-13s", school[i * 5 + j].name);
            //回归默认颜色
            DefaultColor();
        }
        SetPosition(MARGIN_LEFT + GUI_LENGTH - 1, LOGIN_MENU_LINE + i);
        printf("|");
    }
    SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + SCHOOL_LIST_HEIGHT);
    printf(SEPARATOR);
    //在下一行打印提示信息
    SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + SCHOOL_LIST_HEIGHT + 1);
    //换种颜色显示提示
    SetColor(4, 0);
    printf("通过键盘上的方向键选择门派，按Enter键确定！");
    //恢复默认颜色
    DefaultColor();
    /*  打印分隔符*/
    SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + SCHOOL_LIST_HEIGHT + 2);
    printf(SEPARATOR);
    //打印对应ID的门派描述
    SetPosition(MARGIN_LEFT + 14, SCHOOL_DESCRI_LINE);
    for(i = 0, j = 0; i < (int)strlen(school[id - 1].descri); i++)
    {
        //逐字符打印门派描述
        printf("%c", school[id - 1].descri[i]);
        //换行，首行缩进
        if(i == 56 || (((i - 56) % 60) == 0 && i > 60))
        {
            j++;
            SetPosition(MARGIN_LEFT + 10, SCHOOL_DESCRI_LINE + j);
        }
    }
    return id;
}

/*  局部函数：选择帮派*/
School Choice_School()
{
    /*  获取打印字符*/
    char ch;
    /*  获取门派ID*/
    int id;
    /*  初始化打印行列坐标*/
    int X = 0, Y = 0;
    //打印门派信息
    do
    {
        //重新打印信息
        system("cls");
        //打印欢迎界面
        Login_Welcome();
        //通过行列坐标打印门派信息，高亮显示（X，Y）的门派
        id = Show_School(X, Y);
        //无缓冲输入
        ch = _getch();
        //更替坐标值
        switch(ch)
        {
        case VK_UP:     //方向上键
        case 72:
        case 'w':
        case 'W':
            Y--;
            if(Y == -1)
                Y = SCHOOL_LIST_HEIGHT - 1;
            break;
        case VK_DOWN:   //方向下键
        case 80:
        case 's':
        case 'S':
            Y++;
            if(Y == SCHOOL_LIST_HEIGHT)
                Y = 0;
            break;
        case VK_LEFT:   //方向左键
        case 75:
        case 'a':
        case 'A':
            X--;
            if(X == -1)
                X = SCHOOL_LIST_WIDTH - 1;
            break;
        case VK_RIGHT:  //方向右键
        case 77:
        case 'd':
        case 'D':
            X++;
            if(X == SCHOOL_LIST_WIDTH)
                X = 0;
            break;
        }
    }
    while(ch != 13);    //按回车结束循环
    //根据id获取门派
    return school[id - 1];
}

/*  注册账号*/
void SignUp()
{
    int i = 0;
    /*  临时录入字符串*/
    char tempString[UNIFORM_MAX_LENGTH];
    //填写注册信息
    ///  1、输入昵称*/
    SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE);
    printf("请输入您的侠客昵称：");
    fgets(tempString, UNIFORM_MAX_LENGTH, stdin);
    /**  清除fgets()留下的换行符， 下同*/
    tempString[strlen(tempString) - 1] = '\0';
    /**  录入昵称*/
    strcpy(role.name, tempString);
    ///  2、输入id*/
    SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 1);
    printf("请输入ID：");
    fgets(tempString, UNIFORM_MAX_LENGTH, stdin);
    tempString[strlen(tempString) - 1] = '\0';
    /**  录入id*/
    strcpy(role.id, tempString);
    ///  3、输入密码*/
    SetPosition(MARGIN_LEFT, LOGIN_MENU_LINE + 2);
    printf("请输入密码：");
    /*  从键盘录入字符串*/
    do{
        tempString[i] = _getch();
        //按回车键结束输入
    }while(tempString[i++] != 13);
    //最后一个回车键改为'\0'
    tempString[i - 1] = '\0';
    /**  录入密码*/
    strcpy(role.password, tempString);
    ///  4、选择游戏帮派，并写入帮派坐标于玩家坐标中*/
    role.school = Choice_School();
    role.coord = role.school.coord;
    ///  5、初始化角色属性*/
    /*  新建账号初始化基本属性*/
    /*  武器、防具给予新手道具（1级）*/
    role.weapon = Read_Equip(1);
    role.armor = Read_Equip(100);
    /*  初始化背包，一些回血回蓝药*/
    role.backpack.count = 0;    //初始化背包为空，在进行赋值
    role.backpack.equip[0] = Read_Equip(200);
    role.backpack.count++;
    role.backpack.equip[1] = Read_Equip(201);
    role.backpack.count++;
    /*
    *  1、初始化玩家经验值为0
    *  2、则等级为1级
    *  3、初始化玩家金币为一级赠送金币
    *  4、初始化玩家内力为0
    *  5、初始化玩家声望为0
    *  6、通过经验值计算玩家的剩余属性
    */
    role.exp = 0;
    role.roleLevel = LEVEL[6];
    role.money = 2000;
    role.internalForce = 0;
    role.reputation = 0;
    /*  ->通过等级计算玩家攻击力，防御力*/
    role.attack = role.roleLevel.attack;
    role.defense = role.roleLevel.defense;
    /*  ->->加上装备的属性*/
    role.attack += role.weapon.attack;
    role.defense += role.armor.defense;
    /*  ->->->通过等级计算玩家生命值*/
    role.healthPoint = role.roleLevel.healthPoint;
    //所有信息注册完毕，将新注册玩家所有信息首次写入文件中
    Write_INFO(role);
    return;
}

/*  写入玩家信息，直接录入结构体变量*/
void Write_INFO(Role role)
{
    FILE * fp;
    //写入信息的文件
    fp = fopen("account.dat", "wt");
    fwrite(&role, sizeof(Role), 1, fp);
    //关闭文件
    fclose(fp);
    return;
}

/*  从文件中读取玩家信息，直接读取结构体变量*/
void Read_INFO()
{
    FILE * fp;
    if((fp = fopen("account.dat", "r")) == NULL)
    {
        /*  文件不存在则退出游戏*/
        printf("数据丢失！游戏即将退出");
        Sleep(100);
        exit(0);
    }
    //从文件中读取玩家信息
    fread(&role, sizeof(Role), 1, fp);
    //关闭文件
    fclose(fp);
}

/*  读取装备*/
Equip Read_Equip(int id)
{
    /*  临时装备寄存器*/
    Equip tempEquip;
    FILE * fp;
    if((fp = fopen("equip.dat", "r")) == NULL)
    {
        /*  文件不存在则退出游戏*/
        printf("游戏装备数据包损坏，游戏即将退出！请找管理员重新生成数据。。。");
        Sleep(1000);
        exit(0);
    }
    /*  读取对应ID的装备*/
    do
    {
        fread(&tempEquip, sizeof(Equip), 1, fp);
    }
    while(tempEquip.id != id && !feof(fp));
    //关闭文件
    fclose(fp);
    return tempEquip;
}

/*  初始化游戏装备，写入文件中*/
void Write_Equip()
{
    int i = 0;
    FILE * fp;
    //写入信息的文件
    fp = fopen("equip.dat", "wt");
    for(i = 0; i < (int)(sizeof(equip) / sizeof(Equip)); i++)
    {
        fwrite(&equip[i], sizeof(Equip), 1, fp);
    }
    //关闭文件
    fclose(fp);
}

/*  打印游戏标语*/
void ShowTopic()
{
    //上分隔符
    SetPosition(MARGIN_LEFT, 0);
    printf(SEPARATOR);
    SetPosition(MARGIN_LEFT, 1);
    printf("|");
    //居中打印标语
    SetPosition(MARGIN_LEFT + GUI_LENGTH / 3, 1);
    printf("欢迎来到《笑傲江湖之精忠报国》");
    SetPosition(MARGIN_LEFT + GUI_LENGTH - 1, 1);
    printf("|");
    //下分隔符
    SetPosition(MARGIN_LEFT, 2);
    printf(SEPARATOR);
    return;
}

/*  打印地图，高亮显示（X，Y）所在位置*/
void ShowMap(int X, int Y)
{
    int i, j;
    for(i = 0; i < MAP_ROWS; i++)
    {
        SetPosition(MARGIN_LEFT, i + MAP_LINE);
        printf("|");
        for(j = 0; j < MAP_COLS; j++)
        {
            //如果横纵坐标相等，即为所在区域
            if(X == j && Y == i)
            {
                //高亮显示
                SetColor(7, 2);
            }
            SetPosition(MARGIN_LEFT + 4 + j * 9, i + MAP_LINE);
            printf("%s", map[i][j].name);
            //恢复地图默认颜色
            SetColor(6, 0);
        }
        SetPosition(MARGIN_LEFT + GUI_LENGTH - 1, i + MAP_LINE);
        printf("|");
    }
    //打印分隔符
    SetPosition(MARGIN_LEFT, MAP_LINE + MAP_ROWS);
    printf(SEPARATOR);
    return;
}

void ShowMapDescri()
{
    int i, j;
    //这里二维数组和坐标刚好相反[i][j] <-> (j, i)
    char * descri = map[role.coord.Y][role.coord.X].descri;
    //如果当前位置是总舵位置，则打印总舵信息
    if(role.coord.X == role.school.coord.X && role.coord.Y == role.school.coord.Y)
    {
        descri = role.school.descri;
    }
    //打印地图信息
    SetPosition(MARGIN_LEFT + 10, INFO_GUI_LINE);
    for(i = 0, j = 0; i < (int)strlen(descri); i++)
    {
        //逐字符打印门派描述
        printf("%c", descri[i]);
        //换行，首行缩进
        if(i == 64 || (((i - 64) % 68) == 0 && i > 60))
        {
            j++;
            SetPosition(MARGIN_LEFT + 6, INFO_GUI_LINE + j);
        }
    }
}

/*  打印玩家信息*/
void ShowRoleINFO()
{
    int i = 0;
    /*  打印玩家信息*/
    SetPosition(MARGIN_LEFT + 2, INFO_GUI_LINE);
    printf("您的个人资料如下：");
    /*  第一行：编号、姓名、级别、经验值*/
    SetPosition(MARGIN_LEFT + 6, INFO_GUI_LINE + 1);
    printf("编号：%s", role.id);
    SetPosition(MARGIN_LEFT + 24, INFO_GUI_LINE + 1);
    printf("姓名：%s", role.name);
    SetPosition(MARGIN_LEFT + 42, INFO_GUI_LINE + 1);
    printf("级别：%s", role.roleLevel.name);
    SetPosition(MARGIN_LEFT + 60, INFO_GUI_LINE + 1);
    printf("经验值：%d", role.exp);
    /*  第二行：门派、生命值、内力值、金币*/
    SetPosition(MARGIN_LEFT + 6, INFO_GUI_LINE + 2);
    printf("门派：%s", role.school.name);
    SetPosition(MARGIN_LEFT + 24, INFO_GUI_LINE + 2);
    printf("生命值：%d", role.healthPoint);
    SetPosition(MARGIN_LEFT + 42, INFO_GUI_LINE + 2);
    printf("内力值：%d", role.internalForce);
    SetPosition(MARGIN_LEFT + 60, INFO_GUI_LINE + 2);
    printf("金币：%d金", role.money);
    /*  第三行：武器、防具*/
    SetPosition(MARGIN_LEFT + 6, INFO_GUI_LINE + 3);
    printf("武器：%s【攻击力%d/%d级】", role.weapon.name, role.attack, role.weapon.level);
    SetPosition(MARGIN_LEFT + 42, INFO_GUI_LINE + 3);
    printf("防具：%s【防御力%d/%d级】", role.armor.name, role.defense, role.armor.level);
    /*  第四~七行：背包*/
    SetPosition(MARGIN_LEFT + 6, INFO_GUI_LINE + 4);
    printf("背包：");
    if(role.backpack.count == 0)
    {
        SetPosition(MARGIN_LEFT + 16, INFO_GUI_LINE + 6);
        printf("当前背包为空，快去购买一些装备吧！");
    }
    else
    {
        /*  打印背包信息*/
        for(i = 0; i < role.backpack.count; i++)
        {
            //换行打印，一行打印4个
            SetPosition(MARGIN_LEFT + 6 + (i % 4) * 18, INFO_GUI_LINE + 5 + (i / 4));
            printf("%d.%s", i + 1, role.backpack.equip[i].name);
        }
    }
    return;
}

/*  功能一、自我欣赏和使用道具*/
void UseEquip()
{
    int i;
    /*  玩家的输入*/
    char input;
    /*  玩家选择的道具，交换变量*/
    Equip * choiceEquip, tempEquip;
    do
    {
        /*  打印玩家信息*/
        ShowRoleINFO();
        /*  玩家背包为空，直接退出*/
        if(role.backpack.count == 0)
        {
            break;
        }
        /*  打印提示信息*/
        SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
        printf("请输入要选择的装备（按0退出）：");
        /*  捕获用户输入，刷新输入流*/
        input = _getch();
        fflush(stdin);
        if(input == '0')
        {
            //玩家选择退出
            break;
        }
        //用户输入错误
        if(!('1' <= input && input <= role.backpack.count + '0'))
        {
            /*  打印错误提示信息*/
            SetPosition(MARGIN_LEFT + 31, GAME_MENU_LINE - 2);
            printf("输入错误，请重新输入！");
            Sleep(1000);
            /*  覆盖提示信息*/
            SetPosition(MARGIN_LEFT + 31, GAME_MENU_LINE - 2);
            printf("                      ");
            continue;
        }
        //用户输入正确，选择该道具
        /*  通过用户的输入找到该道具，装备对应数组下标 = 序号 - 1*/
        choiceEquip = &role.backpack.equip[input - '0' - 1];
        //用户选择使用或者丢弃该道具
        /*  打印提示信息*/
        SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
        printf("您已选择道具【%s】——U（使用）、L（丢弃）、R（重新选择）", choiceEquip->name);
        do
        {
            /*  获得用户的进一步选择，转换为大写*/
            input = toupper(_getch());
            /*  刷新输入流*/
            fflush(stdin);
            /*  当用户的选择既不是U也不是L，且不是R就退出*/
        }
        while(input != 'U' && input != 'L' && input != 'R');
        /*  覆盖上述提示信息*/
        SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
        for(i = 0; i < GUI_LENGTH; i++)
        {
            printf(" ");
        }
        /*  处理用户的选择*/
        if(input == 'R')
        {
            /*  玩家选择重新选择道具*/
            continue;
        }
        else if(input == 'L')
        {
            /*  用户选择丢弃该道具*/
            for(i = input - '0'; i < role.backpack.count - '0' - 2; i++)
            {
                /*  往前填充*/
                role.backpack.equip[i] = role.backpack.equip[i + 1];
            }
            /*  背包道具数减一*/
            role.backpack.count--;
            /*  打印丢弃道具信息*/
            SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
            printf("您已丢弃道具【%s】", choiceEquip->name);
        }
        else
        {
            /*  玩家选择使用（装备）该道具*/
            switch(choiceEquip->kind)
            {
            case weapon:
                /*
                *  玩家选择武器
                *  则与玩家装备的武器进行交换
                */
                tempEquip = *choiceEquip;
                *choiceEquip = role.weapon;
                role.weapon = tempEquip;
                /*  更新玩家攻击力*/
                role.attack = LEVEL[role.roleLevel.level - 1].attack + role.weapon.attack;
                /*  打印装备武器信息*/
                SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
                printf("您已装备武器【%s】，【当前攻击力：%d】", role.weapon.name, role.attack);
                break;
            case armor:
                /*
                *  玩家选择防具
                *  则与玩家装备的防具进行交换
                */
                tempEquip = *choiceEquip;
                *choiceEquip = role.armor;
                role.armor = tempEquip;
                /*  更新玩家防御力*/
                role.defense = LEVEL[role.roleLevel.level - 1].defense + role.armor.defense;
                /*  打印装备防具信息*/
                SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
                printf("您已装备防具【%s】，【当前防御力：%d】", role.armor.name, role.defense);

                break;
            case hp_prop:
                /*  玩家选择回复生命值的道具*/
                role.healthPoint += choiceEquip->value;
                /*  玩家回复的血量超过当前等级上限血量*/
                if(role.healthPoint > LEVEL[role.roleLevel.level - 1].healthPoint)
                {
                    role.healthPoint = LEVEL[role.roleLevel.level - 1].healthPoint;
                }
                /*  使用完之后，该类道具消失*/
                for(i = input - '0'; i < role.backpack.count - '0' - 2; i++)
                {
                    /*  往前填充*/
                    role.backpack.equip[i] = role.backpack.equip[i + 1];
                }
                /*  背包道具数减一*/
                role.backpack.count--;
                /*  打印使用消耗品信息*/
                SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
                printf("您已使用道具【%s】，恢复生命值%d点【当前生命值%d点】", choiceEquip->name, choiceEquip->value, role.healthPoint);
                break;
            case ip_prop:
                /*  玩家选择回复内力的道具*/
                role.internalForce += choiceEquip->value;
                /*  玩家回复的内力超过当前等级上限内力*/
                if(role.internalForce > LEVEL[role.roleLevel.level - 1].internalForceUP)
                {
                    role.internalForce = LEVEL[role.roleLevel.level - 1].internalForceUP;
                }
                /*  使用完之后，该类道具消失*/
                for(i = input - '0'; i < role.backpack.count - '0' - 2; i++)
                {
                    /*  往前填充*/
                    role.backpack.equip[i] = role.backpack.equip[i + 1];
                }
                /*  背包道具数减一*/
                role.backpack.count--;
                /*  打印使用消耗品信息*/
                SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
                printf("您已使用道具【%s】，恢复内力%d点【当前内力%d点】", choiceEquip->name, choiceEquip->value, role.internalForce);
                break;
            }// close switch()
        }// close else
        /*  选择丢弃（使用）完道具后暂停*/
        SetPosition(MARGIN_LEFT + 50, INFO_GUI_LINE);
        system("pause");
        /*  重新打印*/
        system("cls");
        ShowTopic();
        ShowMap(role.coord.X, role.coord.Y);
        ShowMenu();
        /*  刷新玩家属性*/
    }
    while(1);
    //回置光标于菜单处
    SetPosition(MARGIN_LEFT + 24, GAME_MENU_LINE + 7);
    return;
}

/*  通过ID找到对应怪物进行PK，胜利返回1，失败返回0，没有此怪物返回-1*/
int PK(int id)
{
    int i, j;
    /*  玩家要挑战的怪物下标*/
    int index = 0, monsterSum = 0;
    /*  是否存在该怪物*/
    int isExist = FALSE;
    /*  对战的轮数，PK结果*/
    int count = 1, result;
    /*  玩家获胜获取的金币及经验*/
    int money, exp;
    /*  获取怪物的副本数据*/
    Monster monster;
    /*  统计该地图怪物数目*/
    for(i = 0; i < UNIFORM_MAX_LENGTH; i++)
    {
        //统计存活的怪物，也就是state = live
        if(map[role.coord.Y][role.coord.X].monster[i].state == live)
        {
            monsterSum++;
        }
    }
    /*  找到对应ID且存活的怪物下标、怪物副本*/
    for(i = 0, j = 0; i < monsterSum; j++)
    {
        //找到当前地图存活的怪物
        if(map[role.coord.Y][role.coord.X].monster[j].state == live)
        {
            //对应ID的怪物
            if(map[role.coord.Y][role.coord.X].monster[j].id == id)
            {
                /*  获得怪物副本*/
                monster = map[role.coord.Y][role.coord.X].monster[j];
                /*  记录下标*/
                index = j;
                /*  找到该怪物*/
                isExist = TRUE;
                break;
            }
            //找到下一个存活的怪物
            i++;
        }
    }
    if(!isExist)
    {
        //没有此怪物
        return -1;
    }
    money = rand() % (monster.maxMoney - monster.minMoney + 1) + monster.minMoney;
    exp = monster.exp;
    /*  打印对战信息*/
    SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 5);
    printf("《%s之战》 - %s vs %s", map[role.coord.Y][role.coord.X].name, role.name, monster.name);
    //PK开始
    while(1)
    {
        /*  打印对战轮数*/
        SetPosition(MARGIN_LEFT + 30, INFO_GUI_LINE + 5);
        printf("第%d回合", count);
        //1、玩家出手攻击，攻击算法（扣除血量 = 对方攻击力 * (1 - 当前防御力 / (当前防御力 + 100)) ）
        monster.healthPoint -= role.attack * (1 - monster.defense / (monster.defense + 100) );
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 6);
        printf("%s一记%s打出伤害%d，", role.name, SKILL_NAME[rand() % SKILL_COUNT], role.attack * (1 - monster.defense / (monster.defense + 100) ) );
        /*  怪物死亡，血量为0,奖励玩家经验和金币，以及高等级怪物特有的声望*/
        if(monster.healthPoint <= 0)
        {
            /*  修改怪物状态为death*/
            printf("%s剩余血量为0！", monster.name);
            map[role.coord.Y][role.coord.X].monster[index].state = death;
            //打印玩家获胜信息
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 8);
            printf("大侠%s获得胜利，获取经验值%d，%d金币！", role.name, exp, money);
            //更改玩家属性值
            role.money += money;
            role.exp += exp;
            /*  玩家获得声望
            *  获取条件：怪物等级大于等于5
            *  怪物对应声望公式：获得声望 = 怪物等级 % 5
            */
            if(monster.level >= 5)
            {
                role.reputation += monster.level % 5;
            }
            /*  玩家获胜返回1，结束对战循环*/
            result = 1;
            break;
        }
        /*  若怪物未死，打印怪物剩余血量*/
        printf("%s剩余血量为%d！", monster.name, monster.healthPoint);
        /*  暂缓程序，显示对战信息*/
        Sleep(500);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 7);
        printf(CLEAR);
        //2、怪物出手、算法同上
        role.healthPoint -= monster.attack * (1 - role.defense / (role.defense + 100) );
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 7);
        printf("%s打出一招%s伤害%d，", monster.name, SKILL_NAME[rand() % SKILL_COUNT], monster.attack * (1 - role.defense / (role.defense + 100) ) );
        /*  玩家死亡，血量为0，扣除玩家经验和金币，扣除玩家一半的声望*/
        if(role.healthPoint <= 0)
        {
            printf("玩家%s剩余血量为0！", role.name);
            role.healthPoint = 0;
            //打印获胜信息
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 8);
            printf("玩家%s被%s杀死在%s，扣除经验值%d，%d金币，没想到%s的掌门把他救回了总舵。。。", role.name, monster.name, map[role.coord.Y][role.coord.X].name, exp, money, role.school.name);
            //更改属性值
            role.money -= money;
            /*  玩家金币不足以扣除*/
            if(role.money < 0)
            {
                role.money = 0;
            }
            role.exp -= exp;
            /*  玩家经验值不足以扣除*/
            if(role.exp < 0)
            {
                role.exp = 0;
            }
            /*  扣除玩家一半声望*/
            role.reputation /= 2;
            /*  玩家失败返回0，结束对战循环*/
            result = 0;
            break;
        }
        /*  玩家剩余血量*/
        printf("玩家%s剩余血量为%d！", role.name, role.healthPoint);
        /*  暂缓程序，显示对战信息*/
        Sleep(500);
        /*  清除该轮对战信息*/
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 6);
        printf(CLEAR);
        /* 计数器加一*/
        count++;
    }
    //对战结束，打印提示信息
    SetPosition(MARGIN_LEFT + 50, INFO_GUI_LINE + 5);
    system("pause");
    /**< PK结束后，如果玩家升级，重新计算玩家属性 */
    isUpgrade();
    return result;
}

/*  打印当前地图怪物信息，不打印最高等级怪物，通过举目四望完成*/
void ShowCurrentMapMonsterINFO()
{
    int i, j;
    /*  当前地图怪物数目*/
    int count = 0;
    /*  获取当前地图信息*/
    Map * currentMap = &map[role.coord.Y][role.coord.X];
    /*  得到当前地图怪物数量*/
    for(i = 0; i < UNIFORM_MAX_LENGTH; i++)
    {
        //统计存活的怪物(除去最高等级怪物)，也就是state = live
        if(currentMap->monster[i].state == live && currentMap->monster[i].id != monsters[sizeof(monsters) / sizeof(Monster) - 1].id)
        {
            count++;
        }
    }
    /*  没有怪物打印，结束打怪*/
    if(count == 0)
    {
        SetPosition(MARGIN_LEFT + 10, INFO_GUI_LINE);
        printf("这里没有一个怪物。。。");
        return;
    }
    //存在怪物
    /*  打印所有存活怪物的信息，最多打印12个*/
    for(i = 0, j = 0; j < count && j < 12; i++)
    {
        if(currentMap->monster[i].state == live)
        {
            /*  换行打印，一行最多打印3个*/
            SetPosition(MARGIN_LEFT + 2 + (j % 3) * 26, INFO_GUI_LINE + j / 3);
            /*  怪物id，名讳*/
            printf("(%d)%s", currentMap->monster[i].id, currentMap->monster[i].name);
            /*  统一打印位置，+12的意思为打印名称后再打印等级*/
            SetPosition(MARGIN_LEFT + 2 + (j % 3) * 26 + 12, INFO_GUI_LINE + j / 3);
            /*  怪物级别*/
            printf("（等级：%d）", currentMap->monster[i].level);
            /*  打印存活的怪物序号加1*/
            j++;
        }
    }
    return;
}

/*  功能二、探查（打怪）*/
void BrushStrange()
{
    /*  玩家的选择以及对战结果*/
    int choice, result;
    /*  进入打怪循环*/
    do
    {
        /*  1、打印当前地图怪物信息*/
        ShowCurrentMapMonsterINFO();
        /*  打印分隔符，为战斗信息区*/
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 4);
        printf(SEPARATOR);
        /*  2、选择怪物进行PK*/
        /*  打印提示信息*/
        SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
        printf("请选择攻击目标（按0退出）：");
        //用户键入无效按键
        if(1 != scanf("%d", &choice))
        {
            /*  打印错误信息*/
            SetPosition(MARGIN_LEFT + 27, GAME_MENU_LINE - 2);
            printf("输入无效信息，请重新输入！");
            /*  清空缓冲区*/
            fflush(stdin);
            Sleep(1000);
            /*  打印空格覆盖错误提示信息，以便重新输入*/
            SetPosition(MARGIN_LEFT + 27, GAME_MENU_LINE - 2);
            printf("                          ");
            continue;
        }
        else if(choice == 0)
        {
            //按0退出
            break;
        }
        /**
        *  用户键入有效按键，开始PK，传入用户选择的序号
        *  得到对战的结果
        *  返回值为1则玩家胜利，返回值为0则玩家死亡
        *  返回值为-1则输入错误
        */
        result = PK(choice);
        //玩家胜利
        if(result == 1)
        {

        }
        //玩家死亡，无法继续打怪，送回总舵
        else if(result == 0)
        {
            //为使用该函数又不破坏代码布局结构，在此处给出函数定义
            void GoBackSchool();
            GoBackSchool();
            return;
        }
        else
        {
            //没有该怪物，需重新输入
            /*  打印错误信息*/
            SetPosition(MARGIN_LEFT + 27, GAME_MENU_LINE - 2);
            printf("没有该怪物！！！");
            /*  清空缓冲区*/
            fflush(stdin);
            Sleep(1000);
            /*  打印空格覆盖错误提示信息，以便重新输入*/
            SetPosition(MARGIN_LEFT + 27, GAME_MENU_LINE - 2);
            printf("                          ");
            continue;
        }
        //当前对战结束后，重新打印怪物信息
        system("cls");
        ShowTopic();
        ShowMap(role.coord.X, role.coord.Y);
        ShowMenu();
    }
    while(1);
    //回置光标于菜单处
    SetPosition(MARGIN_LEFT + 24, GAME_MENU_LINE + 7);
    return;
}

/*  功能三、回总部*/
void GoBackSchool()
{
    //重置玩家坐标，和血量
    role.coord = role.school.coord;
    role.healthPoint = 100;
    //重新打印地图和地图信息，等待下次输入
    system("cls");
    ShowTopic();
    ShowMap(role.coord.X, role.coord.Y);
    ShowMapDescri();
    ShowMenu();
    return;
}

/*  交易*/
int Trade(Equip goods)
{
    int i, j;
    /*  交换排序寄存器*/
    Equip tempEquip;
    /*  找到当前道具店*/
    Backpack * currentStore = &map[role.coord.Y][role.coord.X].store;
    //如果玩家的金钱小于商品额单价，即金额不足，交易失败
    if(role.money < goods.price)
    {
        SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
        printf("大侠，你钱不够啊！");
        /*  清空缓冲区*/
        fflush(stdin);
        Sleep(1000);
        //覆盖错误信息，重新输入
        SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
        printf("                  ");
        return FALSE;
    }
    /*  玩家背包已满，交易失败*/
    if(role.backpack.count == UNIFORM_MAX_LENGTH - 1)
    {
        SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
        printf("提示：您的背包已满！");
        /*  清空缓冲区*/
        fflush(stdin);
        Sleep(1000);
        //覆盖错误信息，重新输入
        SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
        printf("                    ");
        return FALSE;
    }
    //成功交易，将商品放入玩家背包中
    role.backpack.equip[role.backpack.count] = goods;
    role.backpack.count++;
    /*  扣除玩家金额*/
    role.money -= goods.price;
    //在商店中去掉玩家购买的装备，重新排序
    for(i = 0; i < currentStore->count; i++)
    {
        /*  把购买的装备和库存最后一个位置的装备交换，然后库存减一
        *  这里最后一个位置为【count - 1】，装备数为1时，count = 1
        */
        if(goods.id == currentStore->equip[i].id)
        {
            tempEquip = currentStore->equip[i];
            currentStore->equip[i] = currentStore->equip[currentStore->count - 1];
            currentStore->equip[currentStore->count - 1] = tempEquip;
            break;
        }
    }
    /*  商店库存减一*/
    currentStore->count--;
    /*  重新排序商店装备*/
    for(i = 0; i < currentStore->count - 1; i++)
    {
        for(j = 0; j < currentStore->count - i - 1; j++)
        {
            /*  交换*/
            if(currentStore->equip[j].id > currentStore->equip[j + 1].id)
            {
                tempEquip = currentStore->equip[j];
                currentStore->equip[j] = currentStore->equip[j + 1];
                currentStore->equip[j + 1] = tempEquip;
            }
        }
    }//close BubbleSort
    /*  打印消费信息*/
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
    printf("交易成功！您在《%s道具店》购买一件%s，消费%d金【余额%d金】", map[role.coord.Y][role.coord.X].name, goods.name, goods.price, role.money);
    /*  按任意键继续*/
    SetPosition(MARGIN_LEFT + 50, INFO_GUI_LINE);
    system("pause");
    return TRUE;
}

/*  功能四、购买装备*/
void BuyEquip()
{
    int i;
    /*  该装备是否存在*/
    int isExist = FALSE;
    /*  用户的输入，以及用户交易的结果*/
    int choice, result;
    /*  获得当前道具店名讳*/
    const char * const storeName = map[role.coord.Y][role.coord.X].name;
    /*  找到当前道具店*/
    Backpack * currentStore = &(map[role.coord.Y][role.coord.X].store);
    /*  用户购买的装备*/
    Equip goods;
    do
    {
        //打印道具店信息
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE);
        printf("欢迎来到【%s道具店】：", storeName);
        /*  道具店库存为0，即视为没有道具店，结束装备购买*/
        if(currentStore->count == 0)
        {
            SetPosition(MARGIN_LEFT + 20, INFO_GUI_LINE + 4);
            printf("没想到《%s道具店》已经关门大吉了。。。", storeName);
            break;
        }
        /*  打印装备信息，最多打印12个*/
        for(i = 0; i < currentStore->count && i < 12; i++)
        {
            /*  换行打印，一行最多打印2个*/
            SetPosition(MARGIN_LEFT + 2 + (i % 2) * (GUI_LENGTH / 2), INFO_GUI_LINE + 1 + i / 2);
            printf("%d.%s", currentStore->equip[i].id, currentStore->equip[i].name);
            SetPosition(MARGIN_LEFT + 20 + (i % 2) * (GUI_LENGTH / 2), INFO_GUI_LINE + 1 + i / 2);
            printf("【价格：%d金】", currentStore->equip[i].price);
        }
        SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 3);
        printf(SEPARATOR);
        /*  打印提示信息*/
        SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 2);
        printf("请输入你要购买的装备ID（输入0退出）：");
        /*  用户输入要购买的装备ID*/
        if(1 != scanf("%d", &choice))
        {
            //用户输入错误
            SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
            printf("您输入了无效ID！");
            /*  清空缓冲区*/
            fflush(stdin);
            Sleep(1000);
            //覆盖错误信息，重新输入
            SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
            printf("                ");
            continue;
        }
        else if(choice == 0)
        {
            //用户选择退出，结束循环
            SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
            printf("大侠，欢迎下次光临！");
            Sleep(1000);
            break;
        }
        //用户输入正确ID
        fflush(stdin);
        /*  找到对应的装备*/
        for(i = 0; i < currentStore->count; i++)
        {
            //找到该装备
            if(currentStore->equip[i].id == choice)
            {
                goods = currentStore->equip[i];
                isExist = TRUE;
                break;
            }
        }
        /*  没有此装备*/
        if(isExist == FALSE)
        {
            /*  打印错误提示信息*/
            SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
            printf("小店没有该装备出售！");
            /*  清空缓冲区*/
            fflush(stdin);
            Sleep(1000);
            //覆盖错误信息，重新输入
            SetPosition(MARGIN_LEFT + 37, GAME_MENU_LINE - 2);
            printf("                    ");
            continue;
        }
        //找到该装备、进行交易
        result = Trade(goods);
        if(!result)
        {
            //交易失败
            continue;
        }
        //交易成功，进行下次交易
        system("cls");
        ShowTopic();
        ShowMap(role.coord.X, role.coord.Y);
        ShowMenu();
    }
    while(1);
    //回置光标于菜单处，接受用户新的菜单指令
    SetPosition(MARGIN_LEFT + 24, GAME_MENU_LINE + 7);
    return;
}

/*  绘制感谢状*/
void DrawCommendation(const char * const name)
{
    SetPosition(MARGIN_LEFT + 55, INFO_GUI_LINE);
    printf("*********************");
    SetPosition(MARGIN_LEFT + 55, INFO_GUI_LINE + 1);
    printf("*");
    SetPosition(MARGIN_LEFT + 75, INFO_GUI_LINE + 1);
    printf("*");
    SetPosition(MARGIN_LEFT + 55, INFO_GUI_LINE + 2);
    printf("*");
    SetPosition(MARGIN_LEFT + 75, INFO_GUI_LINE + 2);
    printf("*");
    SetPosition(MARGIN_LEFT + 55, INFO_GUI_LINE + 3);
    printf("*********************");
    /*  打印嘉奖令内容*/
    SetPosition(MARGIN_LEFT + 57, INFO_GUI_LINE + 1);
    printf("《扫黑除恶感谢状》");
    SetPosition(MARGIN_LEFT + 57, INFO_GUI_LINE + 2);
    printf("——%s百姓献上", name);
}

/*  查询当前坐标的地图是否含有最高等级Boss
*  有则返回TRUE，没有返回FALSE
*/
int isHasBoss(int X, int Y)
{

    int i;
    /*  结果*/
    int result = FALSE;
    /*  遍历完整个数组*/
    for(i = 0; i < UNIFORM_MAX_LENGTH; i++)
    {
        /*  该地图存在存活的Boss*/
        if(map[Y][X].monster[i].id == monsters[sizeof(monsters) / sizeof(Monster) - 1].id && map[Y][X].monster[i].state == live)
        {
            result = TRUE;
            break;
        }
    }
    return result;
}

/*  功能五丶举目四望，刷最高等级Boss*/
void ExploreMap()
{
    /*  玩家的对战结果*/
    int result;
    /*  玩家的选择*/
    char choice;
    /*  如果不存在Boss，回到主菜单*/
    if(!isHasBoss(role.coord.X, role.coord.Y))
    {
        /*  打印信息*/
        SetPosition(MARGIN_LEFT + 5, INFO_GUI_LINE + 3);
        printf("%s探查了一下%s，发现这里还是与往常一样，枯燥且无味。。。", role.name, map[role.coord.Y][role.coord.X].name);
        //回置光标于菜单处，接受用户新的菜单指令
        SetPosition(MARGIN_LEFT + 24, GAME_MENU_LINE + 7);
        return;
    }
    /*  存在Boss，打印Boss信息*/
    SetPosition(MARGIN_LEFT + 5, INFO_GUI_LINE);
    printf("经过少侠一番探查，居然发现了Boss-%s（等级：%d）", monsters[sizeof(monsters) / sizeof(Monster) - 1].name, monsters[sizeof(monsters) / sizeof(Monster) - 1].level);
    /*  玩家是否选择与Boss进行PK*/
    /*  打印对战分隔符*/
    SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 4);
    printf(SEPARATOR);
    /*  打印提示信息*/
    SetPosition(MARGIN_LEFT + 5, INFO_GUI_LINE + 2);
    printf("是否要进行战斗?（Y/N）");
    do
    {
        /*  获取玩家输入，转换为大写字符*/
        choice = toupper(_getch());
        /*  清空缓冲区*/
        fflush(stdin);
    }
    while(choice != 'Y' && choice != 'N');  //当用户输入的既不是也不是N时继续输入
    /*  用户输入Y，即选择与怪物对战*/
    if(choice == 'Y')
    {
        /*  玩家和Boss进行PK*/
        result = PK(monsters[sizeof(monsters) / sizeof(Monster) - 1].id);
        /*  玩家PK输*/
        if(result == 0)
        {
            /*  玩家被传送回总舵，接受下次输入*/
            GoBackSchool();
            return;
        }
        else
        {
            /*  玩家击败当前地图Boss，当地百姓给予嘉奖令*/
            DrawCommendation(map[role.coord.Y][role.coord.X].name);
            /*  玩家声望再加10，PK()函数中已经计算过声望*/
            role.reputation += 10;
            //回置光标于菜单处，接受用户新的菜单指令
            SetPosition(MARGIN_LEFT + 24, GAME_MENU_LINE + 7);
        }
    }
    else
    {
        /*  用户输入N，即退出战斗*/
        SetPosition(MARGIN_LEFT + 5, GAME_MENU_LINE - 4);
        printf("%s当地的百姓连连叹气，直呼何时才能降伏这个魔头，过上安生日子。。。", map[role.coord.Y][role.coord.X].name);
        //回置光标于菜单处，接受用户新的菜单指令
        SetPosition(MARGIN_LEFT + 24, GAME_MENU_LINE + 7);
        return;
    }
}

/*  计算玩家声望得到的结果*/
int ReputationAward(int reputation)
{
    /*  玩家没有声望，大婶可怜为他恢复1%的血量，大叔有概率拿出传家宝（顶级装备）*/
    if(role.reputation <= 0)
    {
        return 0;
    }
    /*  如果玩家声望[1, 10)，百姓尊他为游侠，大婶会为他恢复20%血量*/
    else if(role.reputation < 10)
    {
        return 1;
    }
    /*  如果玩家声望[10, 25)，百姓尊他为大侠，老大夫会为他恢复30%血量，且老奸商有概率送他低级装备（1级）*/
    else if(role.reputation < 25)
    {
        return 2;
    }
    /*  如果玩家声望[25, 50)，百姓把他当家人，老大夫会为他恢复60%血量，且商行老板送他一件低级装备（1~3）*/
    else if(role.reputation < 50)
    {
        return 3;
    }
    /*  如果玩家声望[50, MAX_VALUE)，百姓尊他为守护神，老大夫会为他恢复100%血量，且衙门有概率送他一件高级装备（3~5）*/
    else
    {
        return 4;
    }
}

/*  功能六、到此一游*/
void VisitHere()
{
    /*  玩家到此一游的结果*/
    int result = ReputationAward(role.reputation);
    /*  恢复的血量，赠送的装备*/
    int value;
    Equip presentEquip;
    /*  随机种子*/
    srand(time(0));
    /*  打印玩家信息*/
    SetPosition(MARGIN_LEFT, INFO_GUI_LINE);
    printf("声望：%d", role.reputation);
    SetPosition(MARGIN_LEFT + 10, INFO_GUI_LINE);
    printf("大侠%s前往《%s》百姓家中拜访，想结识一些侠义之人", role.name, map[role.coord.Y][role.coord.X].name);
    /*  打印分割符*/
    SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 1);
    printf(SEPARATOR);
    switch(result)
    {
    case 0: //1%血量，有概率最高级装备（id为9/108）
        value = (int)(role.healthPoint * 0.01);
        SetPosition(MARGIN_LEFT + 5, INFO_GUI_LINE + 2);
        printf("大婶第一次见到你，觉得你十分可怜，为你恢复了%d点血量", value);
        /*  概率为1%*/
        if(rand() % 2 == 0)
        {
            /*  获赠的装备ID，9或108*/
            int EquipID = rand() % 2 == 1? 9: 108;
            presentEquip = Read_Equip(EquipID);
            /*  打印情节*/
            Sleep(1000);
            SetPosition(MARGIN_LEFT + 5, INFO_GUI_LINE + 3);
            printf("不一会儿，大叔拿着一个古老的盒子走了出来。。。");
            Sleep(1000);
            SetPosition(MARGIN_LEFT + 5, INFO_GUI_LINE + 4);
            printf("大叔说到：这是我家的传家宝！！！看你是个有缘人，这宝物便赠与你，希望你能把它发扬光大");
            Sleep(1000);
            SetPosition(MARGIN_LEFT + 5, INFO_GUI_LINE + 5);
            printf("你打开盒子，里面竟是%s（级别：%d）", presentEquip.name, presentEquip.level);
        }
        break;
    case 1: //20%血量
        value = (int)(role.healthPoint * 0.2);
        /*  打印情节*/
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 2);
        printf("没想到一来《%s》，路上就有一些人称你为游侠，向你问候", map[role.coord.Y][role.coord.X].name);
        Sleep(1000);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 3);
        printf("走进一间房屋之后，一看是位体贴的大婶，为你恢复了%d的血量", value);
        break;
    case 2: //30%血量，有概率一级装备(id为1/100)
        value = (int)(role.healthPoint * 0.3);
        /*  打印情节*/
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 2);
        printf("来到《%s》后，街上有好多人尊称你为大侠，纷纷向你示好", map[role.coord.Y][role.coord.X].name);
        Sleep(1000);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 3);
        printf("眼前是一家医馆，进去之后里面的老大夫非常热心，免费为你治疗了身上的旧伤，恢复血量%d点", value);
        /*  概率20%*/
        if(rand() % 5 == 0)
        {
            /*  获得的一级装备*/
            presentEquip = Read_Equip(rand() % 2 == 1? 1: 100);
            /*  打印情节*/
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 4);
            printf("医馆里又跑进了一个大腹便便的胖子，身后居然有几个小混混追进了医馆，嘴里还骂骂咧咧的");
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 5);
            printf("这时你出手解决了几个混混，不一会儿，官兵来了带走了这几个混混。。");
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 6);
            printf("这胖子对你说到：大侠，感谢你的出手，我是个下海的商人，得罪了这几个混混");
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 7);
            printf("接着把一件木质的盒子交给你，便匆匆离去了。你打开盒子，里面是一件%s（级别：%d）", presentEquip.name, presentEquip.level);
        }
        break;
    case 3: //60%血量，一到三级装备(id: 1、2、3、100、101、102)
        value = (int)(role.healthPoint * 0.6);
        /*  rand() % 3 + 1 <-> [1, 3] + rand() % 2 == 1? 0: 99 <-> 0 or 99 = [1, 3] or [100, 102]*/
        presentEquip = Read_Equip(rand() % 3 + 1 + rand() % 2 == 1? 0: 99);
        /*  打印情节*/
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 2);
        printf("一进入《%s》，便有很多人跟你亲切的问候，都争抢着拉你回家做客", map[role.coord.Y][role.coord.X].name);
        Sleep(1000);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 3);
        printf("你还是来到了一家医馆，没想到老大夫也对你像自家人一样，为你治好了前些天的重伤，恢复生命值%d点", value);
        Sleep(1000);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 4);
        printf("治好了伤口之后走出医馆，对面就是一家商行，你走进商行。。。");
        Sleep(1000);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 5);
        printf("没想到商行老板出手阔气，给了你一件%s（级别：%d）", presentEquip.name, presentEquip.level);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 6);
        printf("并嘱咐你在外要注意安全。。。");
        break;
    case 4: //100%血量，有概率三到五级装备(id为3、4、5、103、104、105)
        value = role.healthPoint;
        /*  打印情节*/
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 2);
        printf("还未进入《%s》正街，便有一大群百姓在恭迎你的到来，小孩子都说你是%s的守护神", map[role.coord.Y][role.coord.X].name, map[role.coord.Y][role.coord.X].name);
        Sleep(1000);
        SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 3);
        printf("为首走出一个老大夫拉你进了医馆，给你吃了一颗大补丸，恢复生命值%d点", value);
        /*  概率为50%*/
        if(rand() % 2 == 1)
        {
            /*  获取装备，rand() % 3 + 3 <-> [3, 5] + rand() % 2 == 1? 0: 100 <-> 0 or 100 = [3, 5] or [103, 105]*/
            presentEquip = Read_Equip(rand() % 3 + 3 + rand() % 2 == 1? 0: 100);
            /*  打印情节*/
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 4);
            printf("刚辞别老大夫走出医馆，就在门口遇见两个身穿官服的衙门官员，要请你去衙门做客");
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 5);
            printf("来到衙门后，钦差老爷便热情的招待你，吩咐手下拿出了一个精致的檀香盒");
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 6);
            printf("钦差老爷：这是上面给我的宝物，我也用不上，给你行走江湖刚好合适");
            Sleep(1000);
            SetPosition(MARGIN_LEFT, INFO_GUI_LINE + 6);
            printf("你打开盒子，里面是一件上等的宝物，%s（级别：%d）", presentEquip.name, presentEquip.level);
        }
        break;
    }   // close switch
    /*  加上血量*/
    role.healthPoint += value;
    /*  加入赠送的装备*/
    //成功交易，将商品放入玩家背包中
    role.backpack.equip[role.backpack.count] = presentEquip;
    role.backpack.count++;
    /*  玩家血量超过等级上限*/
    if(role.healthPoint > role.roleLevel.healthPoint)
    {
        role.healthPoint = role.roleLevel.healthPoint;
    }
    /*  按任意键继续*/
    SetPosition(MARGIN_LEFT + 70, INFO_GUI_LINE);
    system("pause");
    //回置光标于菜单处
    SetPosition(MARGIN_LEFT + 24, GAME_MENU_LINE + 7);
    return;
}

/*  功能七、退出游戏*/
void ExitGame()
{
    //退出前写入玩家信息
    Write_INFO(role);
    exit(0);
}
/*  处理用户输入*/
void DealInput(char ch)
{
    switch(ch)
    {
    case '1':   //1、自我欣赏
        UseEquip();
        break;
    case '2':   //2、探查（打怪）
        BrushStrange();
        break;
    case '3':   //3、回总部
        GoBackSchool();
        break;
    case '4':   //4、购买装备
        BuyEquip();
        break;
    case '5':   //5、举目四望
        ExploreMap();
        break;
    case '6':   //6、到此一游
        VisitHere();
        break;
    case '7':   //7、退出游戏
        ExitGame();
        break;
    default:
        ShowMapDescri();
        break;
    }
}

/*  打印游戏主菜单*/
void ShowMenu()
{
    //打印分隔符
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE - 1);
    printf(SEPARATOR);
    //打印菜单
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE);
    printf("1、自我欣赏");
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE + 1);
    printf("2、探查（打怪）");
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE + 2);
    printf("3、回总部");
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE + 3);
    printf("4、购买装备");
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE + 4);
    printf("5、举目四望");
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE + 5);
    printf("6、到此一游");
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE + 6);
    printf("7、退出游戏");
    SetPosition(MARGIN_LEFT, GAME_MENU_LINE + 7);
    printf("请输入选择或四方向移动：");
}

/*  游戏界面加载*/
void ShowGUI()
{
    /*  用户输入变量寄存器*/
    char ch = 0;
    /*  设置全局游戏颜色*/
    SetColor(6, 0);
    while(1)
    {
        ///重新打印，清除屏幕
        system("cls");
        //Part1、打印游戏标题
        ShowTopic();
        //Part2、打印地图
        ShowMap(role.coord.X, role.coord.Y);
        //Part4、打印游戏主菜单，这里要先打印菜单，因为菜单是固定的
        ShowMenu();
        //Part3、游戏信息界面，通过用户输入获取要打印的信息
        DealInput(ch);
        //无缓冲输入
        ch = _getch();
        //玩家进行移动，更改玩家坐标
        switch(ch)
        {
        case VK_UP:     //方向上键
        case 72:
        case 'w':       //W or w
        case 'W':
            role.coord.Y--;
            if(role.coord.Y == -1)
                role.coord.Y = MAP_ROWS - 1;
            break;
        case VK_DOWN:   //方向下键
        case 80:
        case 's':       //s or S
        case 'S':
            role.coord.Y++;
            if(role.coord.Y == MAP_ROWS)
                role.coord.Y = 0;
            break;
        case VK_LEFT:   //方向左键
        case 75:
        case 'a':       //a or A
        case 'A':
            role.coord.X--;
            if(role.coord.X == -1)
                role.coord.X = MAP_COLS - 1;
            break;
        case VK_RIGHT:  //方向右键
        case 77:
        case 'd':       //d or D
        case 'D':
            role.coord.X++;
            if(role.coord.X == MAP_COLS)
                role.coord.X = 0;
            break;
        default:
            //不是进行移动
            break;
        }
    }   //while() close
}

/*  给地图中分配怪物*/
void CreateMonster()
{
    int i, j, k, l;
    /*  利用时间函数获取随机种子*/
    srand(time(0));
    /*  最高等级Boss个数*/
    unsigned BossCount = 0;
    //生成怪物数，以及该地图的怪物随机最大生成数
    int count = 0, randCount;
    /*  临时寄存变量，用于交换排序*/
    Monster tempMonster;
    //给每个地图生成不定的怪物
    for(i = 0; i < MAP_ROWS; i++)
    {
        for(j = 0; j < MAP_COLS; j++)
        {
            /*  一个地图最多生成UNIFORM_MAX_LENGTH个怪物*/
            randCount = rand() % UNIFORM_MAX_LENGTH;
            while(count < randCount)
            {
                /*  随机赋予怪物，这里最高等级怪物并不出现*/
                map[i][j].monster[count] = monsters[rand() % (sizeof(monsters) / sizeof(Monster)) - 1];
                count++;
            }
            /*  随机刷最高等级Boss，不超过十个*/
            if(randCount < UNIFORM_MAX_LENGTH - 1 && rand() % 2 == 1 && BossCount < 10)
            {
                map[i][j].monster[count] = monsters[sizeof(monsters) / sizeof(Monster) - 1];
                BossCount++;
            }
            //循环结束后重置count为0
            count = 0;
            //生成怪物之后通过ID进行排序，冒泡排序
            for(k = 0; k < randCount - 1; k++)
            {
                for(l = 0; l < randCount - k - 1; l++)
                {
                    /*  交换*/
                    if(map[i][j].monster[l].id > map[i][j].monster[l + 1].id)
                    {
                        tempMonster = map[i][j].monster[l];
                        map[i][j].monster[l] = map[i][j].monster[l + 1];
                        map[i][j].monster[l + 1] = tempMonster;
                    }
                }
            }//close BubbleSort
        }//close inner for()
    }//close for()
    return;
}

/*  玩家升级则重新计算玩家的属性*/
void isUpgrade()
{
    int i;
    /*  未计算前等级，计算后等级*/
    int frontLevel = role.roleLevel.level, currentLevel;
    //1、先计算玩家等级，通过玩家经验值来计算当前玩家等级
    /*  等级数组长度*/
    unsigned length = sizeof(LEVEL) / sizeof(RoleLevel);
    for(i = 0; i < length - 1; i++)
    {
        if(role.exp < LEVEL[0].exp)
        {
            //玩家经验值低于最低等级升级水平
            role.roleLevel = LEVEL[0];
            break;
        }
        if(role.exp >= LEVEL[length - 1].exp)
        {
            //玩家经验值超过最高等级所需经验值
            role.roleLevel = LEVEL[length - 1];
            break;
        }
        if(LEVEL[i].exp <= role.exp && role.exp < LEVEL[i + 1].exp)
        {
            role.roleLevel = LEVEL[i];
            break;
        }
    }
    /*  获取当前级别*/
    currentLevel = role.roleLevel.level;
    //2、升级则修改属性、赠送金币
    if(currentLevel > frontLevel)
    {
        //1、通过等级计算玩家攻击力，防御力
        role.attack = role.roleLevel.attack;
        role.defense = role.roleLevel.defense;
        /*  加上装备的属性*/
        role.attack += role.weapon.attack;
        role.defense += role.armor.defense;
        //2、通过等级计算玩家生命值
        role.healthPoint = role.roleLevel.healthPoint;
        //3、赠送金币
        role.money += role.roleLevel.money;
    }
    return;
}

/*  给地图分配道具，生成道具店*/
void CreateStore()
{
    int i, j, k, l;
    srand(time(0));
    //该地图商店道具随机最大生成数
    int randCount;
    /*  临时寄存装备变量，用于分配装备、交换排序*/
    Equip tempEquip;
    //给每个地图生成不定的装备
    for(i = 0; i < MAP_ROWS; i++)
    {
        for(j = 0; j < MAP_COLS; j++)
        {
            /*  给每个商店的库存初始化为0*/
            map[i][j].store.count = 0;
            /*  一个地图的道具店最多生成UNIFORM_MAX_LENGTH个装备*/
            randCount = rand() % UNIFORM_MAX_LENGTH;
            while(map[i][j].store.count < randCount)
            {
                /*  随机赋予道具店装备，不分配最顶级装备*/
                tempEquip = equip[rand() % (sizeof(equip) / sizeof(Equip))];
                /*  如果是最高等级装备，重新筛选*/
                if(tempEquip.level == EQUIP_MAX_LEVEL)
                {
                    continue;
                }
                map[i][j].store.equip[map[i][j].store.count] = tempEquip;
                map[i][j].store.count++;
            }
            //生成装备之后通过ID进行排序，冒泡排序
            for(k = 0; k < randCount - 1; k++)
            {
                for(l = 0; l < randCount - k - 1; l++)
                {
                    /*  交换*/
                    if(map[i][j].store.equip[l].id > map[i][j].store.equip[l + 1].id)
                    {
                        tempEquip = map[i][j].store.equip[l];
                        map[i][j].store.equip[l] = map[i][j].store.equip[l + 1];
                        map[i][j].store.equip[l + 1] = tempEquip;
                    }
                }
            }//close BubbleSort
        }//close inner for()
    }//close for()
    return;
}
