/*
Strong ownership:
A document and its pages

In a document editor like Microsoft Word, a Document is composed of multiple Page
objects. The pages cannot exist without the document, and if the document is deleted,
the pages are also deleted.
*/

#include <iostream>
#include <vector>
#include <string>

class Page {
private:
    std::string m_content;
public:
    Page(const std::string& text): m_content(text) {}
    void display() const {
        std::cout << "Page Content: " << m_content << std::endl;
    }
};

class Document {
private:
    std::vector<Page> m_pages; //composition: document owns pages.
public:
    void addPage(const std::string& text) {
        m_pages.emplace_back(text);
    }

    void display() const {
        for (const auto& page: m_pages) {
            page.display();
        }
    }
};

int main() {
    Document doc;
    doc.addPage("Title Page");
    doc.addPage("Introduction");
    doc.addPage("Conclusion");
    doc.display();
    return 0;
}