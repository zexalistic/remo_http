#ifndef _WORKMODE_DEFINE__
#define __WORKMODE_DEFINE__

/***************************workmode*start***************************************/
//  product main-workmode enum 
typedef enum Remo_WORKMODE_MASTER
{
    WORKMODE_PHOTO  = 0,
    WORKMODE_MULTIPHOTO  = 1,
    WORKMODE_RECORD  = 2,
    WORKMODE_PLAYBACK = 3,
    WORKMODE_BUTT
} WORKMODE_MASTER;

// product photo sub-mode enum
typedef enum Remo_PHOTOMODE
{
    PHOTOMODE_SINGLE = 0,
    PHOTOMODE_DELAY,
    PHOTOMODE_RAW,
    PHOTOMODE_BUTT
} PHOTOMODE;


//  product multi-photo sub-mode enum
typedef enum Remo_MULTIPHOTOMODE
{
    MULTIPHOTOMODE_BURST = 0,
    MULTIPHOTOMODE_LAPSE,
    MULTIPHOTOMODE_CONTINUOUS,
    MULTIPHOTOMODE_BUTT
} MULTIPHOTOMODE;


// product record sub-mode enum
typedef enum Remo_RECORDMODE
{
    RECMODE_NORMAL = 0,
    RECMODE_LOOP,
    RECMODE_LAPSE,
    RECMODE_RECSNAP,
    RECMODE_SLOW,
    RECMODE_BUTT
} RECORDMODE;


//  product workmode information  
typedef struct Remo_WORKMODE
{
    WORKMODE_MASTER workmode_master; /**<main workmode */
    union
    {
        PHOTOMODE photomode;
        MULTIPHOTOMODE multiphotomode;
        RECORDMODE recmode;
    }workmode_slave; /**<sub workmode */
} WORKMODE;
/***************************workmode*end****************************************/
/****************************type*start***************************************/
// product configure item enum in record-mode
typedef enum RECMODE_CONF_E
{
    RECMODE_CONF_VIDEOMODE = 0, /**<video mode */
    /**<lapse record interval in lapse-record-mode or lapse photo interval in recsnap-mode  */
    RECMODE_CONF_LAPSE_INTERVAL,
    RECMODE_CONF_RECSNAP_MODE = 6, /**<recsnap mode */
    RECMODE_CONF_LOOPTYPE = 7, /**<loop record type */
    RECMODE_CONF_BUTT
} RECMODE_CONF_E;


/**
  *  product configure item enum in photo-mode
  */
typedef enum PHOTOMODE_CONF_E
{
    PHOTOMODE_CONF_IMAGEMODE = 0, /**<image mode */
    PHOTOMODE_CONF_DELAY, /**<delay photo time */
    PHOTOMODE_CONF_SCENE, /**<photo scene */
    PHOTOMODE_CONF_BUTT
} PHOTOMODE_CONF_E;


/**
  * product configure item enum in multi-photo-mode
  */
typedef enum MULTIPHOTOMODE_CONF_E
{
    MULTIPHOTOMODE_CONF_IMAGEMODE = 0, /**<image mode */
    MULTIPHOTOMODE_CONF_BURST_TYPE, /**<burst photo rate mode */
    MULTIPHOTOMODE_CONF_LAPSE_INTERVAL, /**<lapse photo interval */
    MULTIPHOTOMODE_CONF_CONTINUOUS_RATE, /**<continuous photo framerate */
    MULTIPHOTOMODE_CONF_BUTT
} MULTIPHOTOMODE_CONF_E;

/****************************type*end***************************************/
/****************************value*start***************************************/
//remo video mode
typedef enum Remo_VIDEO_MODE_E
{
    VIDEO_MODE_720P_120_REC = 0,
    VIDEO_MODE_720P_240_REC,
    VIDEO_MODE_1080P_60_REC,
    VIDEO_MODE_1080P_60_REC_SNAP,
    VIDEO_MODE_1080P_120_REC,
    VIDEO_MODE_1440P_60_REC,
    VIDEO_MODE_1440P_60_REC_SNAP,
    VIDEO_MODE_4K2K_30_REC,
    VIDEO_MODE_4K2K_30_REC_SNAP,
    VIDEO_MODE_4K2K_SNAP,
    VIDEO_MODE_12M_SNAP,
    VIDEO_MODE_16M_SNAP,
    VIDEO_MODE_4K2K_MULTISNAP,// 12
    VIDEO_MODE_12M_MULTISNAP,// 13
    VIDEO_MODE_16M_MULTISNAP,// 14
    VIDEO_MODE_1440P_30_REC,
    VIDEO_MODE_1440P_30_REC_SNAP,
    VIDEO_MODE_BUTT,
} HI_VIDEO_MODE_E;
/***************************value*end***************************************/
/***************************action in bootaction*start***********************/
typedef enum hisnet_WORKMODE_E
{
    HISNET_WORKMODE_RECORD,     /*录像*/
    HISNET_WORKMODE_RECORDLOOP,
    HISNET_WORKMODE_RECORDSLOW,
    HISNET_WORKMODE_RECORDLAPSE,
    HISNET_WORKMODE_RECORDSNAP,
    HISNET_WORKMODE_LAPSE,      /*定时抓拍*/
    HISNET_WORKMODE_TIMER,      /*延时抓拍*/
    HISNET_WORKMODE_IDLE,       /*空闲*/
    HISNET_WORKMODE_BUTT
} HISNET_WORKMODE_E;
/***************************action in bootaction*end***********************/
/******************************channel*type*start**************************/
typedef enum hisnet_CHN_TYPE_E
{
    HISNET_CHN_TYPE_VENC     = 0,  /*视频编码通道*/
    HISNET_CHN_TYPE_VI          ,  /*vi通道*/
    HISNET_CHN_TYPE_VO          ,  /*vo通道*/
    HISNET_CHN_TYPE_AENC        ,  /*音频编码通道*/
    HISNET_CHN_TYPE_ADEC        ,  /*音频解码通道*/
    HISNET_CHN_TYPE_PTZ         ,  /*云台通道*/
    HISNET_CHN_TYPE_ALARMIN     ,  /*告警输入通道*/
    HISNET_CHN_TYPE_ALARMOUT    ,  /*告警输出通道*/
    HISNET_CHN_TYPE_CUSTOM1     ,  /*自定义通道1(用于扩展)*/
    HISNET_CHN_TYPE_CUSTOM2     ,  /*自定义通道2(用于扩展)*/
    HISNET_CHN_TYPE_CUSTOM3     ,  /*自定义通道3(用于扩展)*/
    HISNET_CHN_TYPE_BUTT           /*非法值*/
} HISNET_CHN_TYPE_E;
/******************************channel*type*end**************************/
typedef struct hisnet_ENC_VENC_ATTR_S
{

    HI_BOOL benable;                        /*是否开启码流，第1个码流不允许关闭*/
    HI_S32  s32mode;                        /*0:正常情况下的视频编码参数
                                              1:事件触发情况下的视频编码参数*/
    HISNET_VIDEO_FORMAT_E enVeFormat;       /*编码类型:VS_VIDEO_FORMAT_E*/
    HI_U32  u32fps;                         /*码流帧率:1~30 单位Hz*/
    HISNET_VIDEO_RATECRTL_E enBRMode;       /*视频码率控制方式:VS_VIDEO_RATECRTL_E*/
    HI_U32  u32bps;                         /*码流比特率:单位kbps*/
    HI_U32  u32iqp;                         /*编码I帧qp*/
    HI_U32  u32pqp;                         /*P帧的qp*/
    HISNET_RESOLUTION_E enResolution;       /*视频分辨率:VS_RESOLUTION_E*/
    HI_S32  s32VideoHeight;                 /*自定义模式下图象高 24～576*/
    HI_S32  s32VideoWidth;                  /*自定义模式下图象宽 32～720*/
    HISNET_VIDEO_PRIORITY_E enPriority;     /*优先级
                              当帧率优先时表示视频流畅度,
                                  当码率优先时表示画质级别,*/
    HI_U32  u32QLevel;                      /*video quality level,画质[0,5],值越小图象质量越好*/
    HI_BOOL bIConstraint;                   /*是否开启I帧平滑*/
    HI_U32  u32Gop;                             /* interval of I frame(0-32767), change freedom */
} HISNET_ENC_VENC_ATTR_S;

/*********************************audio*start**********************************/
typedef struct hisnet_AUDIOENCODE_ATTR_S
{
    HI_BOOL bAudioEnable;               /*音频码流是否开启 1-开启0-关闭*/
    HISNET_AUDIO_FORMAT_E enAencType;   /*音频编码类型*/
    HI_U32 u32Bitrate;                  /*比特率 单位kbps*/
    HI_U32 u32SampleRate;               /*采样率 单位kHz*/
    HI_U32 u32BitWidth;                 /*位宽*/
    HI_U32 u32Gain;                     /*音量增益*/
} HISNET_AUDIOENCODE_ATTR_S;

typedef enum hisnet_AUDIO_FORMAT_E
{
    HISNET_AUDIO_FORMAT_G711A   = 1,   /* G.711 A            */
    HISNET_AUDIO_FORMAT_G711Mu  = 2,   /* G.711 Mu           */
    HISNET_AUDIO_FORMAT_ADPCM   = 3,   /* ADPCM              */
    HISNET_AUDIO_FORMAT_G726    = 4,   /* G.726              */
    HISNET_AUDIO_FORMAT_AMR     = 5,   /* AMR encoder format */
    HISNET_AUDIO_FORMAT_AMRDTX  = 6,   /* AMR encoder formant and VAD1 enable */
    HISNET_AUDIO_FORMAT_AAC     = 7,   /* AAC encoder        */
    HISNET_AUDIO_FORMAT_WAV     = 8,   /* WAV encoder        */
    HISNET_AUDIO_FORMAT_MP3     = 9,   /* MP3 encoder */
    HISNET_AUDIO_FORMAT_BUTT
} HISNET_AUDIO_FORMAT_E;

typedef struct hisnet_AUDIODECODE_ATTR_S
{
    HISNET_AUDIO_FORMAT_E enAdecType;           /*音频解码类型*/
    HI_U32 u32Bitrate;                          /*比特率 单位kbps*/
    HI_U32 u32SampleRate;                       /*采样率 单位kHz*/
    HI_U32 u32BitWidth;                         /*位宽*/
    HI_U32 u32Volume;                           /*音量大小*/
} HISNET_AUDIODECODE_ATTR_S;
/*********************************audio*end*************************************/
/*********************************wifi*start************************************/
typedef struct hisnet_WIFI_ATTR_S
{
    HI_BOOL bWifiEnable;                              /*是否启用WIFI, 1打开,0关闭*/
    HI_CHAR aszWifiSsid[HISNET_MAX_WIFI_SSID_LEN];    /*WIFI SSID*/
    HISNET_SECRETMODE_TYPE_E enSecretMode;            /*加密模式*/
    HI_U32 u32WifiWhichKey;                           /*wep模式下4个key中的哪一个,wpa2模式下值为0*/
    HI_CHAR aszWifiKey[HISNET_MAX_PASSWORD_LEN];      /*WIFI密码*/
    HI_BOOL bWifiLinkStatus;                          /*WIFI连接状态,connect=1,disconnect=0*/
} HISNET_NET_WIFI_ATTR_S;
/*WIFI加密模式*/
typedef enum hisnet_SecretMode_E
{
    HISNET_SECRETMODE_TYPE_WEP,  /*WEP加密模式*/
    HISNET_SECRETMODE_TYPE_WPA2, /*WPA2加密模式*/
    HISNET_SECRETMODE_TYPE_BUTT
} HISNET_SECRETMODE_TYPE_E;

/*********************************wifi*end*************************************/
/*********************************time****************************************/
typedef enum hisnet_SYS_TIMEZONE_E
{
    HISNET_Pacific_Majuro = 1,              /*马朱罗*/
    HISNET_Pacific_Midway,                  /*中途岛*/
    HISNET_Pacific_Honolulu,                /*檀香山*/
    HISNET_America_Anchorage,               /*安克雷奇*/
    HISNET_America_Los_Angeles,             /*美国太平洋时间 (洛杉矶)*/
    HISNET_America_Tijuana,                 /*美国太平洋时间 (提华纳)*/
    HISNET_America_Phoenix,                 /*美国山区时间 (凤凰城)*/
    HISNET_America_Chihuahua,               /*奇瓦瓦*/
    HISNET_America_Denver,                  /*美国山区时间 (丹佛)*/
    HISNET_America_Costa_Rica,            /*美国中部时间 (哥斯达黎加)*/
    HISNET_America_Chicago,               /*美国中部时间 (芝加哥)*/
    HISNET_America_Mexico_City,           /*美国中部时间 (墨西哥城)*/
    HISNET_America_Regina,                /*美国中部时间 (里贾纳)*/
    HISNET_America_Bogota,                    /*哥伦比亚时间 (波哥大)*/
    HISNET_America_New_York,                /*美国东部时间 (纽约)*/
    HISNET_America_Caracas,               /*委内瑞拉时间 (加拉加斯)*/
    HISNET_America_Barbados,                  /*大西洋时间 (巴巴多斯)*/
    HISNET_America_Manaus,                /*亚马逊标准时间 (马瑙斯)*/
    HISNET_America_Santiago,                 /*圣地亚哥*/
    HISNET_America_St_Johns,                 /*纽芬兰时间 (圣约翰)*/
    HISNET_America_Sao_Paulo,                /*圣保罗*/
    HISNET_America_Argentina_Buenos_Aires, /*布宜诺斯艾利斯*/
    HISNET_America_Godthab,              /*戈特霍布*/
    HISNET_America_Montevideo,           /*乌拉圭时间 (蒙得维的亚)*/
    HISNET_Atlantic_South_Georgia,       /*南乔治亚*/
    HISNET_Atlantic_Azores,              /*亚述尔群岛*/
    HISNET_Atlantic_Cape_Verde,          /*佛得角 */
    HISNET_Africa_Casablanca,                /*卡萨布兰卡*/
    HISNET_Europe_London,                    /*格林尼治标准时间 (伦敦)*/
    HISNET_Europe_Amsterdam,                 /*中欧标准时间 (阿姆斯特丹)*/
    HISNET_Europe_Belgrade,              /*中欧标准时间 (贝尔格莱德)*/
    HISNET_Europe_Brussels,              /*中欧标准时间 (布鲁塞尔)*/
    HISNET_Europe_Sarajevo,              /*中欧标准时间 (萨拉热窝)*/
    HISNET_Africa_Windhoek,              /*温得和克*/
    HISNET_Africa_Brazzaville,           /*西部非洲标准时间 (布拉扎维)*/
    HISNET_Asia_Amman,                   /*东欧标准时间 (安曼)*/
    HISNET_Europe_Athens,                    /*东欧标准时间 (雅典)*/
    HISNET_Asia_Beirut,                  /*东欧标准时间 (贝鲁特)*/
    HISNET_Africa_Cairo,                     /*东欧标准时间 (开罗)*/
    HISNET_Europe_Helsinki,              /*东欧标准时间 (赫尔辛基)*/
    HISNET_Asia_Jerusalem,                   /*以色列时间 (耶路撒冷)*/
    HISNET_Europe_Minsk,                     /*明斯克*/
    HISNET_Africa_Harare,                    /*中部非洲标准时间 (哈拉雷)*/
    HISNET_Asia_Baghdad,                     /*巴格达*/
    HISNET_Europe_Moscow,                    /*莫斯科*/
    HISNET_Asia_Kuwait,                      /*科威特*/
    HISNET_Africa_Nairobi,                   /*东部非洲标准时间 (内罗毕)*/
    HISNET_Asia_Tehran,                      /*伊朗标准时间 (德黑兰)*/
    HISNET_Asia_Baku,                        /*巴库*/
    HISNET_Asia_Tbilisi,                     /*第比利斯*/
    HISNET_Asia_Yerevan,                     /*埃里温*/
    HISNET_Asia_Dubai,                       /*迪拜*/
    HISNET_Asia_Kabul,                       /*阿富汗时间 (喀布尔)*/
    HISNET_Asia_Karachi,                     /*卡拉奇*/
    HISNET_Asia_Oral,                        /*乌拉尔*/
    HISNET_Asia_Yekaterinburg,               /*叶卡捷林堡*/
    HISNET_Asia_Calcutta,                    /*加尔各答*/
    HISNET_Asia_Colombo,                     /*科伦坡*/
    HISNET_Asia_Katmandu,                    /*尼泊尔时间 (加德满都)*/
    HISNET_Asia_Almaty,                      /*阿拉木图*/
    HISNET_Asia_Rangoon,                     /*缅甸时间 (仰光)*/
    HISNET_Asia_Krasnoyarsk,                 /*克拉斯诺亚尔斯克*/
    HISNET_Asia_Bangkok,                     /*曼谷*/
    HISNET_Asia_Shanghai,                    /*中国标准时间 (北京)*/
    HISNET_Asia_Hong_Kong,                   /*香港时间 (香港)*/
    HISNET_Asia_Irkutsk,                     /*伊尔库茨克时间 (伊尔库茨克)*/
    HISNET_Asia_Kuala_Lumpur,                /*吉隆坡*/
    HISNET_Australia_Perth,                  /*佩思*/
    HISNET_Asia_Taipei,                      /*台北时间 (台北)*/
    HISNET_Asia_Seoul,                       /*首尔*/
    HISNET_Asia_Tokyo,                       /*日本时间 (东京)*/
    HISNET_Asia_Yakutsk,                     /*雅库茨克时间 (雅库茨克)*/
    HISNET_Australia_Adelaide,               /*阿德莱德*/
    HISNET_Australia_Darwin,                 /*达尔文*/
    HISNET_Australia_Brisbane,               /*布里斯班*/
    HISNET_Australia_Hobart,                 /*霍巴特*/
    HISNET_Australia_Sydney,                 /*悉尼*/
    HISNET_Asia_Vladivostok,                 /*海参崴时间 (符拉迪沃斯托克)*/
    HISNET_Pacific_Guam,                     /*关岛*/
    HISNET_Asia_Magadan,                     /*马加丹时间 (马加丹)*/
    HISNET_Pacific_Auckland,                 /*奥克兰*/
    HISNET_Pacific_Fiji,                     /*斐济*/
    HISNET_Pacific_Tongatapu,                /*东加塔布*/
    HISNET_TIMEZONE_BUTT
} HISNET_SYS_TIMEZONE_E;
                    \t--timezone:       \tPacific Majuro=                   \t1\n\ 
                                        \tPacific Midway=                   \t2\n\
                                        \tPacific Honolulu=                 \t3\n\
                                        \tAmerica Anchorage=                \t4\n\
                                        \tAmerica Los Angeles=              \t5\n\
                                        \tAmerica Tijuana=                  \t6\n\
                                        \tAmerica Phoenix=                  \t7\n\
                                        \tAmerica Chihuahua=                \t8\n\
                                        \tAmerica Denver=                   \t9\n\
                                        \tAmerica Costa Rica=               \t10\n\
                                        \tAmerica Chicago=                  \t11\n\
                                        \tAmerica Mexico City=              \t12\n\
                                        \tAmerica Regina=                   \t13\n\
                                        \tAmerica Bogota=                   \t14\n\
                                        \tAmerica New York=                 \t15\n\
                                        \tAmerica Caracas=                  \t16\n\
                                        \tAmerica Barbados=                 \t17\n\
                                        \tAmerica Manaus=                   \t18\n\
                                        \tAmerica Santiago=                 \t19\n\
                                        \tAmerica St Johns=                 \t20\n\
                                        \tAmerica Sao Paulo=                \t21\n\
                                        \tAmerica Argentina Buenos Aires=   \t22\n\
                                        \tAmerica Godthab=                  \t23\n\
                                        \tAmerica Montevideo=               \t24\n\
                                        \tAtlantic South Georgia=           \t25\n\
                                        \tAtlantic Azores=                  \t25\n\
                                        \tAtlantic Cape Verde=              \t26\n\
                                        \tAfrica Casablanca=                \t27\n\
                                        \tEurope London=                    \t28\n\
                                        \tEurope Amsterdam=                 \t29\n\
                                        \tEurope Belgrade=                  \t30\n\
                                        \tEurope Brussels=                  \t31\n\
                                        \tEurope Srajevo=                   \t32\n\
                                        \tAfrica Windhoek=                  \t33\n\
                                        \tAfrica Brazzaville=               \t34\n\
                                        \tAsia Amman=                       \t35\n\
                                        \tEurope Athens=                    \t36\n\
                                        \tAsia Beirut=                      \t37\n\
                                        \tAfrica Cairo=                     \t38\n\
                                        \tEurope Helsinki=                  \t39\n\
                                        \tAsia Jerusalem=                   \t40\n\
                                        \tEurope Minsk=                     \t41\n\
                                        \tAfrica Harare=                    \t42\n\
                                        \tAsia Baghdad=                     \t43\n\
                                        \tEurope Moscow=                    \t44\n\
                                        \tAsia Kuwait=                      \t45\n\
                                        \tAfrica Nairobi=                   \t46\n\
                                        \tAsia Tehran=                      \t47\n\
                                        \tAsia Baku=                        \t48\n\
                                        \tAsia Tbilisi=                     \t49\n\
                                        \tAsia Yerevan=                     \t50\n\
                                        \tAsia Dubai=                       \t51\n\
                                        \tAsia Kabul=                       \t52\n\
                                        \tAsia Karachi=                     \t53\n\
                                        \tAsia Oral=                        \t54\n\
                                        \tAsia Yekaterinburg=               \t55\n\
                                        \tAsia Calcutta=                    \t56\n\
                                        \tAsia Colombo=                     \t57\n\
                                        \tAsia Katmandu=                    \t58\n\
                                        \tAsia Almaty=                      \t59\n\
                                        \tAsia Rangoon=                     \t60\n\
                                        \tAsia Krasnoyarsk=                 \t61\n\
                                        \tAsia Bangkok=                     \t62\n\
                                        \tAsia Shanghai=                    \t63\n\
                                        \tAsia HongKong=                    \t64\n\
                                        \tAsia Irkutsk=                     \t65\n\
                                        \tAsia Kuala Lumpur=                \t66\n\
                                        \tAsia Australia Perth=             \t67\n\
                                        \tAsia Taipei=                      \t68\n\
                                        \tAsia Seoul=                       \t69\n\
                                        \tAsia Tokyo=                       \t70\n\
                                        \tAsia Yakutsk=                     \t71\n\
                                        \tAustralia Adelaide=               \t72\n\
                                        \tAustralia Darwin=                 \t73\n\
                                        \tAustralia Brisbane=               \t74\n\
                                        \tAustralia Hobart=                 \t75\n\
                                        \tAustralia Sydney=                 \t76\n\
                                        \tAsia Magadan=                     \t77\n\
                                        \tPacific Auckland=                 \t78\n\
                                        \tPacific Fiji=                     \t79\n\
                                        \tPacific Tongatapu=                \t80\n\ 

typedef struct hisnet_TIME_ATTR_S
{
    HI_CHAR aszTime[HISNET_MAX_TIMESIZE];       /*时间"20120608110426"*/
    HISNET_SYS_TIMEFORMAT_E enTimeFormat;       /*日期格式*/
    HISNET_SYS_TIMEZONE_E enTimeZone;           /*时区*/
} HISNET_TIME_ATTR_S;

/*日期格式*/
typedef enum hisnet_SYS_TIMEFORMAT_E
{
    HISNET_TIMEFORMAT_DEFAULT,    /*缺省格式*/
    HISNET_TIMEFORMAT_WESTERN,    /*格式为:MM/DD/YYYY*/
    HISNET_TIMEFORMAT_EASTERN,    /*格式为:YYYY-MM-DD*/
    HISNET_TIMEFORMAT_BUTT
} HISNET_SYS_TIMEFORMAT_E;
/*****************************************************************************/

#endif
