//
// Created by araul on 28.03.2021.
//

#ifndef A45_ARAULO22_ADMINSERVICE_H
#define A45_ARAULO22_ADMINSERVICE_H
#endif //A45_ARAULO22_ADMINSERVICE_H
#pragma once
#include "Repository.h"
#include <vector>
#include <fstream>
class AdminService {
private:
    Repository& repository;

public:
    AdminService(Repository& repository);
    int adminAddMovie(const std::string& title, const std::string& genre, int yearOfRelease, int numberOfLikes, const std::string& trailer);
    int adminDeleteMovie(const std::string& title);
    int adminUpdateMovie(const std::string& title, const std::string& genre, int yearOfRelease, int numberOfLikes, const std::string& trailer);
    std::vector<Movie> adminGetMovieList();
    void populate();
};