//
// Created by araul on 28.03.2021.
//

#ifndef A45_ARAULO22_USERSERVICE_H
#define A45_ARAULO22_USERSERVICE_H
#endif //A45_ARAULO22_USERSERVICE_H
#pragma once
#include "Repository.h"

class UserService
{
private:
    Repository& repository;
    std::vector<Movie> currentMoviesByGenre;
    int currentMoviePosition;
public:
    UserService(Repository& repository, int currentMoviePosition = 0);
    std::vector<Movie> userGetMovieList();
    std::vector<Movie> userGetWatchList();
    int listMoviesByGenre(const std::string& genreGiven);
    int addMovieToWatchList();
    int addMovieToWatchListByTitle(const std::string& titleOfTheMovieToAdd);
    void goToNextMovieByGenre();
    Movie getCurrentMovie();
    int removeMovieFromWatchList(const std::string& title, bool liked);
    int getWatchListLength();
};