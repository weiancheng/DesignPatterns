#include <iostream>

enum ELANGUAGE {
    EENGLISH = 1,
    ECHINESS = 2,
    EJAPANESE = 3,
};

class Book {
public:
    virtual ~Book(void) {}

    virtual void setName(std::string name) = 0;
    virtual void setPages(int page) = 0;
    virtual void setLanguage( ELANGUAGE language ) = 0;
    virtual void showDetail(void) = 0;
    virtual Book * clone(void) = 0;

protected:
    std::string mName;
    int mPages;
    ELANGUAGE mLanguage;
};

class Magazine : public Book {
public:
    virtual void setName(std::string name) {
        mName = name;
    }

    virtual void setPages(int page) {
        mPages = page;
    }

    virtual void setLanguage(ELANGUAGE language) {
        mLanguage = language;
    }

    virtual void showDetail(void) {
        std::cout << "Book Type: Magazine" << std::endl;
        std::cout << "Book Name: " << mName << std::endl;
        std::cout << "Book Page: " << mPages << std::endl;
        std::cout << "Book Language: ";
        switch (mLanguage) {
            case ECHINESS:
                std::cout << "Chiness" << std::endl;
                break;

            case EENGLISH:
                std::cout << "English" << std::endl;
                break;

            case EJAPANESE:
                std::cout << "Japanese" << std::endl;
                break;

            default:
                std::cout << "Other" << std::endl;
        }
    }

    virtual Book * clone(void) {
        Book * book = new Magazine();
        book->setName(this->mName);
        book->setPages(this->mPages);
        book->setLanguage(this->mLanguage);

        return book;
    }

    Magazine operator=(const Magazine &m) {
        Magazine new_m;

        new_m.setName(this->mName);
        new_m.setPages(this->mPages);
        new_m.setLanguage(this->mLanguage);

        return new_m;
    }
};

class Novel : public Book {
public:
    virtual void setName(std::string name) {
        mName = name;
    }

    virtual void setPages(int page) {
        mPages = page;
    }

    virtual void setLanguage(ELANGUAGE language) {
        mLanguage = language;
    }

    virtual void showDetail(void) {
        std::cout << "Book Type: Novel" << std::endl;
        std::cout << "Book Name: " << mName << std::endl;
        std::cout << "Book Page: " << mPages << std::endl;
        std::cout << "Book Language: ";
        switch (mLanguage) {
            case ECHINESS:
            std::cout << "Chiness" << std::endl;
                break;

            case EENGLISH:
            std::cout << "English" << std::endl;
                break;

            case EJAPANESE:
            std::cout << "Japanese" << std::endl;
                break;

            default:
            std::cout << "Other" << std::endl;
        }
    }

    virtual Book * clone(void) {
        Book * book = new Novel();
        book->setName(this->mName + " Copy");
        book->setPages(this->mPages);
        book->setLanguage(this->mLanguage);

        return book;
    }
};

int main(int argc, char **argv) {
    Book * HarryPotter = new Novel();
    Book * HarryBatter = nullptr;

    HarryPotter->setName("Harry Potter");
    HarryPotter->setLanguage(EENGLISH);
    HarryPotter->setPages(500);
    HarryPotter->showDetail();

    HarryBatter = HarryPotter->clone();
    std::cout << std::endl;
    HarryBatter->showDetail();

    delete(HarryPotter);
    delete(HarryBatter);

    std::cout << std::endl;
    Book * science = new Magazine();
    Book * new_science = new Magazine();
    science->setName("Science");
    science->setPages(50);
    science->setLanguage(EENGLISH);

    std::string aa("aaaa");
    std::string bb("bbbb");

    aa = bb;

    aa = "ggg";

    std::cout << "aa: " << &aa << " " << aa << std::endl;
    std::cout << "bb: " << &bb << " " << bb << std::endl;

    new_science = science;
    new_science->showDetail();

    delete science;

    return 0;
}
