#include <iostream>
#include <vector>

using namespace std;

class IFile {
public:
    virtual void Add(IFile file) {
        cout << "no support Add()" << endl;
    }

    virtual void Remove(string name) {
        cout << "no support Remove()" << endl;
    }

    virtual void Print(int depth) = 0;

protected:
    string mFileName;
};

class File : public IFile {
public:
    File(string name) {
        mFileName = name;
    }

    virtual void Add(IFile file) {
        mFiles.push_back(file);
    }

    virtual void Remove(string name) {
        vector<IFile>::iterator it_file;

        for(it_file = mFiles.begin() ; it_file != mFiles.end() ; it_file++) {
            if(it_file->mFileName == name) {
                mFiles.erase(it_file);
            }
        }
    }

    virtual void Print(int depth) {
        vector<IFile>::iterator it_file;
        string dot = "-";

        for(int i = 0 ; i < depth ; i++) {
            dot = dot + "-";
        }

        cout << dot << mFileName << endl;

        for(it_file = mFiles.begin() ; it_file != mFiles.end() ; it_file++) {
            it_file->Print(depth+1);
        }
    }

private:
    vector<IFile> mFiles;
};

class Leaf : public IFile {
public:
    Leaf(string name) {
        mFileName = name;
    }

    virtual void Print(int depth) {
        string dot = "-";

        for(int i = 0 ; i < depth ; i++) {
            dot = dot + "-";
        }

        cout << dot << mFileName << endl;
    }
};

int main(int argc, char **argv) {
    return 0;
}