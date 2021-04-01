//
// Created by araul on 28.03.2021.
//

#ifndef A45_ARAULO22_UI_H
#define A45_ARAULO22_UI_H
#endif //A45_ARAULO22_UI_H

#pragma once
#include "AdminService.h"
#include "UserService.h"
#include <fstream>
#include <string>
class UI
{
private:
    AdminService& adminService;
    UserService& userService;
    bool inList = false;
public:
    UI(AdminService& adminService, UserService& userService);
    void runAdmin();
    void runUser();
    void runApp();
    void uiAdminAdd();
    void uiAdminDelete();
    void uiAdminUpdate();
    void uiAdminList();
    void uiUserAdd();
    void uiUserWatchList();
    void uiUserNext();
    void uiUserSave();
    void uiUserList();
    void uiUserRemove();
};