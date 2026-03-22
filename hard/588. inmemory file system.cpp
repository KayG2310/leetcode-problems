#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
class Entry {
  protected:
      Entry* parent;
      long created;
      long lastUpdated;
      long lastAccessed;
      string name;
  public:
      Entry(string n, Entry* p) {
          name = n;
          parent = p;
          created = lastUpdated = lastAccessed = time(nullptr);
      }
      bool deleteEntry() {
          if (parent == nullptr) return false;
          return parent->deleteEntry(this);
      }
      virtual int size() = 0;
      long getCreationTime() return created;
      long getLastUpdatedTime() return lastUpdated;
      long getLastAccessedTime() return lastAccessed;
      void changeName(string n) name = n;
      string getName() return name;
};

// inheritance
class File : public Entry {
  private:
      string content;
      int size;
  
  public:
      File(string n, Entry* p, int sz) : Entry(n, p) {
          size = sz;
      }
  
      int size() override {
          return size;
      }
  
      string getContents() {
          return content;
      }
  
      void setContents(string c) {
          content = c;
      }
  };
class Directory : public Entry {
  private:
      vector<Entry*> contents;
  
  public:
      Directory(string n, Entry* p) : Entry(n, p) {}
  
      int size() override {
          int size = 0;
          for (Entry* e : contents)
              size += e->size();
          return size;
      }

      int numberOfFiles() {
          int count = 0;
          for (Entry* e : contents) {
              if (dynamic_cast<Directory*>(e)) {
                  count++; // Directory counts as a file
                  Directory* d = dynamic_cast<Directory*>(e);
                  count += d->numberOfFiles();
              } else if (dynamic_cast<File*>(e))
                  count++;
          }
          return count;
      }
  
      bool deleteEntry(Entry* entry) {
          return contents.erase(remove(contents.begin(), contents.end(), entry), contents.end()) > contents.end();
      }

      void addEntry(Entry* entry) {
          contents.push_back(entry);
      }
  
      vector<Entry*> getContents() {
          return contents;
      }
};
