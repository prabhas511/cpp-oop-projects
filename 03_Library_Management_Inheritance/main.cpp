#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LibraryItem {
protected:
    int id;
    string title;

public:
    LibraryItem(int itemId, const string& itemTitle)
        : id(itemId), title(itemTitle) {}

    virtual void display() const {
        cout << "ID: " << id << " | Title: " << title << '\n';
    }

    virtual string getType() const {
        return "Library Item";
    }

    virtual ~LibraryItem() = default;
};

class Book : public LibraryItem {
private:
    string author;

public:
    Book(int itemId, const string& itemTitle, const string& bookAuthor)
        : LibraryItem(itemId, itemTitle), author(bookAuthor) {}

    void display() const override {
        cout << "Book | ID: " << id
             << " | Title: " << title
             << " | Author: " << author << '\n';
    }

    string getType() const override {
        return "Book";
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(int itemId, const string& itemTitle, int issue)
        : LibraryItem(itemId, itemTitle), issueNumber(issue) {}

    void display() const override {
        cout << "Magazine | ID: " << id
             << " | Title: " << title
             << " | Issue: " << issueNumber << '\n';
    }

    string getType() const override {
        return "Magazine";
    }
};

int main() {
    vector<LibraryItem*> items;

    items.push_back(new Book(101, "C++ Fundamentals", "Example Author"));
    items.push_back(new Book(102, "Object Oriented Design", "Example Author"));
    items.push_back(new Magazine(201, "Technology Monthly", 42));

    cout << "--- Library Items ---\n";
    for (const LibraryItem* item : items) {
        item->display();  // Runtime polymorphism
    }

    for (LibraryItem* item : items)
        delete item;

    return 0;
}
