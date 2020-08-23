//This file contains commands to be included when initializing.And the basic structure.
#include "remo.h"

void Remo_init(){
    Remo_Test_RegisterCommand("file",               file,               "Description:DV file management");
    Remo_Test_RegisterCommand("wifi",               wifi,               "Description:wifi options");
    Remo_Test_RegisterCommand("sdcommand",          sdcommand,          "Description:options for sd card");
    Remo_Test_RegisterCommand("system",             system,             "Description:system miscellaneous options");
    Remo_Test_RegisterCommand("parameter",          parameter,          "Description:set and get the parameter of board");
    Remo_Test_RegisterCommand("workmode",           workmode,           "Description:set and get the current workmode");
    Remo_Test_RegisterCommand("bootaction",         bootaction,         "Description:bootaction settings");
    Remo_Test_RegisterCommand("media",              media,              "Description:media miscellaneous options");
    Remo_Test_RegisterCommand("record",             record,             "Description:start and stop record");
}


void Remo_finish(){
    Remo_Test_UnRegisterCommand("getfilelist",        getfilelist,        "Description:getfilelist");
    Remo_Test_UnRegisterCommand("parameter",          parameter,          "Description:parameter");
    Remo_Test_UnRegisterCommand("workmode",           workmode,           "Description:workmode");
    Remo_Test_UnRegisterCommand("getfileinfo",        getfileinfo,        "Description:getfileinfo");
    Remo_Test_UnRegisterCommand("bootaction",         bootaction,         "Description:bootaction");
    Remo_Test_UnRegisterCommand("getdevcapabilities", getdevcapabilities, "Description:getdevcapabilities");
    Remo_Test_UnRegisterCommand("timeosd",            timeosd,            "Description:timeosd");
    Remo_Test_UnRegisterCommand("record",             record,             "Description:record");
    Remo_Test_UnRegisterCommand("photo",              photo,              "Description:photo");
}

