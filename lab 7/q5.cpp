#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media(string title, string publicationDate, string uniqueID, string publisher)
        : title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    virtual void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    virtual void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    virtual bool searchByTitle(const string& searchTitle) {
        return title == searchTitle;
    }

    virtual bool searchByPublisher(const string& searchPublisher) {
        return publisher == searchPublisher;
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string title, string publicationDate, string uniqueID, string publisher, string author, string ISBN, int numberOfPages)
        : Media(title, publicationDate, uniqueID, publisher), author(author), ISBN(ISBN), numberOfPages(numberOfPages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }

    bool searchByAuthor(const string& searchAuthor) {
        return author == searchAuthor;
    }

    ~Book() {}
};

class DVD : public Media {
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string title, string publicationDate, string uniqueID, string publisher, string director, int duration, string rating)
        : Media(title, publicationDate, uniqueID, publisher), director(director), duration(duration), rating(rating) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }

    bool searchByDirector(const string& searchDirector) {
        return director == searchDirector;
    }

    ~DVD() {}
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string title, string publicationDate, string uniqueID, string publisher, string artist, int numberOfTracks, string genre)
        : Media(title, publicationDate, uniqueID, publisher), artist(artist), numberOfTracks(numberOfTracks), genre(genre) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }

    bool searchByArtist(const string& searchArtist) {
        return artist == searchArtist;
    }

    ~CD() {}
};

class Magazine : public Media {
private:
    string issueNumber;
    string editor;

public:
    Magazine(string title, string publicationDate, string uniqueID, string publisher, string issueNumber, string editor)
        : Media(title, publicationDate, uniqueID, publisher), issueNumber(issueNumber), editor(editor) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Editor: " << editor << endl;
    }

    bool searchByIssueNumber(const string& searchIssueNumber) {
        return issueNumber == searchIssueNumber;
    }

    ~Magazine() {}
};

void searchByTitle(vector<Media*>& mediaCollection, const string& title) {
    for (auto media : mediaCollection) {
        if (media->searchByTitle(title)) {
            media->displayInfo();
        }
    }
}

void searchByPublisher(vector<Media*>& mediaCollection, const string& publisher) {
    for (auto media : mediaCollection) {
        if (media->searchByPublisher(publisher)) {
            media->displayInfo();
        }
    }
}

int main() {
    Book* book1 = new Book("The Great Gatsby", "1925-04-10", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD* dvd1 = new DVD("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD* cd1 = new CD("Abbey Road", "1969-09-26", "C001", "Apple Records", "The Beatles", 17, "Rock");
    Magazine* mag1 = new Magazine("National Geographic", "2023-03-01", "M001", "National Geographic Society", "0323", "Susan Goldberg");

    vector<Media*> mediaCollection;
    mediaCollection.push_back(book1);
    mediaCollection.push_back(dvd1);
    mediaCollection.push_back(cd1);
    mediaCollection.push_back(mag1);

    cout << "Displaying all media:\n";
    for (auto media : mediaCollection) {
        media->displayInfo();
        cout << endl;
    }

    cout << "Search for media by title 'Inception':\n";
    searchByTitle(mediaCollection, "Inception");

    cout << "Search for media by publisher 'Apple Records':\n";
    searchByPublisher(mediaCollection, "Apple Records");

    cout << "\nChecking out and returning media:\n";
    dvd1->checkOut();
    dvd1->returnItem();
    dvd1->returnItem();

    delete book1;
    delete dvd1;
    delete cd1;
    delete mag1;

    return 0;
}
