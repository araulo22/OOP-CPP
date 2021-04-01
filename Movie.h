//
// Created by araul on 28.03.2021.
//
#ifndef A45_ARAULO22_MOVIE_H
#define A45_ARAULO22_MOVIE_H
#endif //A45_ARAULO22_MOVIE_H
#pragma once
#include <string>
#include <vector>
#include <istream>

class Movie {
private:
    std::string title;
    std::string genre;
    std::string trailer;
    int year{};
    int likes{};
public:
    Movie(const std::string& a = "", const std::string& b = "", const std::string& c = "", int d = 1900, int e = 0);

    const std::string& getTitle() const;
    void setTitle(const std::string &title);
    const std::string& getGenre() const;
    void setGenre(const std::string &genre);
    const std::string& getTrailer() const;
    void setTrailer(const std::string &trailer);
    int getYear() const;
    void setYear(int year);
    int getLikes() const;
    void setLikes(int likes);

    std::string toString() const;

    bool operator==(const Movie& movie) const;
    bool operator!=(const Movie& movie) const;
    void operator=(const Movie& movie);
    friend std::ostream& operator<< (std::ostream& out, const Movie& movie);
};