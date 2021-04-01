//
// Created by araul on 28.03.2021.
//
#include "UI.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>
UI::UI(AdminService& adminService, UserService& userService): adminService { adminService } , userService{ userService }{}

void UI::runApp()
{
    std::string command;
    while (true) {
        std::cout << "Choose: launch / exit\n";
        std::cout << "Command: ";
        std::cin >> command;
        if (command == "launch") {
            std::cout << "Choose: ADMIN / USER\n";
            std::cin >> command;
            if (command == "ADMIN")
                runAdmin();
            else
                if (command == "USER")
                    runUser();
                else
                    std::cout << "Invalid input!\n";
            break;
        }
        else if (command == "exit")
            break;
        else
            std::cout << "Invalid input!\n";
    }
}

void UI::runAdmin()
{
    std::cout << "Administrator mode enabled!\n";
    std::string consoleInput;
    int changeMode = 0;
    while (true && !changeMode) {
        std::cout << "Choose: add / update / delete / list / mode / exit\n";
        std::cout << "Input: ";
        std::cin >> consoleInput;
        if (consoleInput == "add")
            uiAdminAdd();
        else if (consoleInput == "update")
            uiAdminUpdate();
        else if (consoleInput == "delete")
            uiAdminDelete();
        else if (consoleInput == "list")
            uiAdminList();
        else if (consoleInput == "mode") {
            std::string modeToChange;
            std::cout << "Choose: ADMIN / USER\n";
            std::cin >> modeToChange;
            if (modeToChange == "USER") {
                changeMode = 1;
                runUser();
            }
        }
        else if (consoleInput == "exit")
            break;
        else
            std::cout << "Invalid input! \n";
    }

}

void UI::runUser()
{
    std::cout << "User mode enabled!\n";
    userService.listMoviesByGenre("");
    Movie currentMovie;
    std::string consoleInput;
    int changeMode = 0;
    while (true && !changeMode && !inList) {
        std::cout << "Choose: list / next / watchList / save / remove / mode / exit\n";
        std::cout << "Movie format: <title> <genre> <year> <likes> <trailer>\n";
        std::cout << "Input: ";
        std::cin >> consoleInput;
        if (consoleInput == "list") {
            inList = true;
            uiUserList();
        }
        else if (consoleInput == "mode") {
            std::string modeToChange;
            std::cout << "Choose: ADMIN / USER\n";
            std::cin >> modeToChange;
            if (modeToChange == "ADMIN") {
                changeMode = 1;
                runAdmin();
            }
        }
        else if (consoleInput == "next") {
            currentMovie = userService.getCurrentMovie();
            std::cout << currentMovie;
            uiUserNext();
        }
        else if (consoleInput == "watchList")
            uiUserWatchList();
        else if (consoleInput == "save")
            uiUserSave();
        else if (consoleInput == "remove")
            uiUserRemove();
        else if (consoleInput == "exit")
            break;
        else
            std::cout << "Invalid input! \n";
    }
}

void UI::uiAdminAdd()
{
    std::string title, genre, trailer, consoleInput;
    int yearOfRelease, numberOfLikes;
    std::cin >> consoleInput;
    title = consoleInput.substr(0, consoleInput.size() - 1);
    std::cin >> consoleInput;
    genre = consoleInput.substr(0, consoleInput.size() - 1);
    std::cin >> consoleInput;
    yearOfRelease = stoi(consoleInput.substr(0, consoleInput.size() - 1));
    std::cin >> consoleInput;
    numberOfLikes = stoi(consoleInput.substr(0, consoleInput.size() - 1));
    std::cin >> consoleInput;
    trailer = consoleInput;
    int isFunctionSuccessful = adminService.adminAddMovie(title, genre, yearOfRelease, numberOfLikes, trailer);
    if (isFunctionSuccessful == -1) {
        std::cout << "ERROR: Failed to add movie! Check input or already added movies.\n";
    }
}

void UI::uiAdminDelete()
{
    std::cout << "Movie title: \n";
    std::string title, consoleInput;
    getline(std::cin, consoleInput);
    title = consoleInput.substr(1);
    int isFunctionSuccessful = adminService.adminDeleteMovie(title);
    if (isFunctionSuccessful == -1) {
        std::cout << "ERROR: Movie is not in the list!\n";
    }
}

void UI::uiAdminUpdate()
{
    std::string title, genre, trailer, consoleInput;
    int yearOfRelease, numberOfLikes;
    std::cin >> consoleInput;
    title = consoleInput.substr(0, consoleInput.size() - 1);
    std::cin >> consoleInput;
    genre = consoleInput.substr(0, consoleInput.size() - 1);
    std::cin >> consoleInput;
    yearOfRelease = stoi(consoleInput.substr(0, consoleInput.size() - 1));
    std::cin >> consoleInput;
    numberOfLikes = stoi(consoleInput.substr(0, consoleInput.size() - 1));
    std::cin >> consoleInput;
    trailer = consoleInput;
    int isFunctionSuccessful = adminService.adminUpdateMovie(title, genre, yearOfRelease, numberOfLikes, trailer);
    if (isFunctionSuccessful == -1) {
        std::cout << "ERROR: Movie is not in the list!\n";
    }
}

void UI::uiAdminList()
{
    std::vector<Movie>listOfMovies = adminService.adminGetMovieList();
    for (auto & listOfMovie : listOfMovies)
        std::cout << listOfMovie << '\n';
}

void UI::uiUserAdd() {
    int isFunctionSuccessful = userService.addMovieToWatchList();
    if (isFunctionSuccessful == -1)
        std::cout << "ERROR: Failed to add movie!\n";
}

void UI::uiUserWatchList()
{
    std::vector<Movie>listOfMovies = userService.userGetWatchList();
    for (auto & listOfMovie : listOfMovies)
        std::cout << listOfMovie << '\n';
}

void UI::uiUserNext() {
    userService.goToNextMovieByGenre();
}

void UI::uiUserSave()
{
    std::cout << "Movie title: \n";
    std::string title;
    std::cin >> title;
    int isFunctionSuccessful = userService.addMovieToWatchListByTitle(title);
    if (isFunctionSuccessful == -1)
        std::cout << "ERROR: Invalid movie!\n";
}

void UI::uiUserList()
{

    std::string consoleInput, genre;
    Movie currentMovie;
    std::cout << "Specify a genre: \n";
    std::cin >> genre;
    int isFunctionSuccessful = userService.listMoviesByGenre(genre);
    if (isFunctionSuccessful == -1)
        std::cout << "ERROR: Failed to select movies!\n";
    while (isFunctionSuccessful != -1 && inList) {
        try {
            currentMovie = userService.getCurrentMovie();
        }
        catch (std::exception &Exception) {
            std::cout << Exception.what() << '\n';
        }
        std::cout << currentMovie << '\n';
        ShellExecuteA(NULL, "open", userService.getCurrentMovie().getTrailer().c_str(), NULL, NULL, SW_SHOWNORMAL);
        std::cout << "Commands: add / next / exit \n";
        std::cout << "Input: ";
        std::cin >> consoleInput;
        if (consoleInput == "add") {
            uiUserAdd();
            uiUserNext();
        }
        else if (consoleInput == "next")
            uiUserNext();
        else if (consoleInput == "exit")
            inList = false;
        else
            std::cout << "Invalid input!\n";
    }

}

void UI::uiUserRemove() {
    std::cout << "Movie title: \n";
    std::string title, enjoy;
    std::cin >> title;
    std::cout << "Did you enjoy the movie? Type <yes> to add a like!\n";
    std::cin >> enjoy;
    bool liked = false;
    if(enjoy == "yes")
        liked = true;
    int isFunctionSuccessful = userService.removeMovieFromWatchList(title, liked);
    if (isFunctionSuccessful == -1)
        std::cout << "ERROR: Invalid movie!\n";
}
