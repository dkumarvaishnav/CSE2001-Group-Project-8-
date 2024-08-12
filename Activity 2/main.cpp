#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to store book details
struct Book {
    int book_id;
    string author_name;
    double price;
    int no_of_pages;
    string publisher;
    int year_of_publishing;
};

// Custom comparison function for sorting based on author_name
bool compareBooks(const Book& book1, const Book& book2) {
    return book1.author_name < book2.author_name;
}
