//
// Created by araul on 28.03.2021.
//
#include <iostream>
#include "UI.h"
#include "Tests.h"

using namespace std;

int main()
{
    //Tests test;
    //test.runAllTests();
    Repository repo{};
    AdminService adminService{repo};
    UserService userService{repo};
    UI ui{adminService, userService};
    ui.runApp();
    return 0;
}