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

int main() {
    ifstream inputFile("books.txt"); // Replace "books.txt" with your actual file name
    ofstream outputFile("sorted_books.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    vector<Book> books;
    Book tempBook;

    // Read book details from the input file
    while (inputFile >> tempBook.book_id >> tempBook.author_name >> tempBook.price >> 
           tempBook.no_of_pages >> tempBook.publisher >> tempBook.year_of_publishing) {
        books.push_back(tempBook);
    }

    // Sort the books based on author_name
    sort(books.begin(), books.end(), compareBooks);

    // Write sorted book details to the output file
    for (const Book& book : books) {
        outputFile << book.book_id << " " << book.author_name << " " 
                   << book.price << " " << book.no_of_pages << " " 
                   << book.publisher << " " << book.year_of_publishing << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Books sorted successfully!" << endl;

    return 0;
}
