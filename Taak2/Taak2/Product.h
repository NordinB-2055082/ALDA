// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#pragma once
#include <string>
using namespace std;

struct Product {
    string asin;
    string title;
    string imgUrl;
    string productURL;
    double stars;
    int reviews;
    double price;
    double listPrice;
    int category_id;
    bool isBestSeller;
    int boughtInLastMonth;
    int discount;
};
