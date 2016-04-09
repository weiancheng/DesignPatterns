#include <iostream>
#include <vector>

// Interface
class IFile 
{
public:
    IFile(void) {}
    virtual ~IFile(void) {}

    virtual void Print(const int depth = 0) = 0;

    virtual void Add(IFile * file)
    {
        std::cout << "no support Add() !!!" << std::endl;
    }

    virtual void Remove(std::string name)
    {
        std::cout << "no support Remove() !!!" << std::endl;
    }

    virtual std::string Name(void)
    {
        return mName;
    }

protected:
    std::string mName;
};

// Composite
class File : public IFile
{
public:
    File(std::string name)
    {
        mName = name;
    }

    ~File(void) {}

    void Add(IFile *file)
    {
        mFiles.push_back(file);
    }

    void Remove(std::string name)
    {
        for(int i = 0 ; i < mFiles.size() ; i++)
        {
            if(mFiles[i]->Name().compare(name) == 0)
            {
                mFiles.erase(mFiles.begin() + i);
                break;
            }
        }
    }

    virtual void Print(const int depth)
    {
        std::string dot("-");

        for(int i = 0 ; i < depth ; i++)
        {
            dot += std::string("-");
        }

        std::cout << dot << mName << std::endl;

        for(int i = 0 ; i < mFiles.size() ; i++)
        {
            mFiles[i]->Print(depth + 1);
        }
    }

private:
    std::vector<IFile *> mFiles;
};

// Leaf
class NodeFile : public IFile
{
public:
    NodeFile(std::string name)
    {
        mName = name;
    }

    void Print(const int depth)
    {
        std::string dot("-");

        for(int i = 0 ; i < depth ; i++)
        {
            dot += std::string("-");
        }

        std::cout << dot << mName << std::endl;
    }
};

int main(int argc, char **argv)
{
    IFile *root = new File(std::string("File System"));
    
    IFile *w = new File(std::string("Windows"));
    IFile *l = new File(std::string("Linux"));
    IFile *i = new File(std::string("MacOS"));

    root->Add(w);
    root->Add(l);
    root->Add(i);

    IFile *we = new File(std::string("EXE"));
    IFile *wd = new File(std::string("DLL"));

    w->Add(we);
    w->Add(wd);

    IFile *lb = new File(std::string("BIN"));
    IFile *ls = new File(std::string("SO"));

    l->Add(lb);
    l->Add(ls);

    IFile *il = new File(std::string("Library"));
    IFile *it = new File(std::string("TXT"));

    i->Add(il);
    i->Add(it);

    root->Print();
    std::cout << std::endl;
    root->Remove(std::string("MacOS"));
    root->Print();

    std::cout << std::endl;
    i->Print();

    delete we;
    delete wd;
    delete lb;
    delete ls;
    delete il;
    delete it;
    delete w;
    delete l;
    delete i;
    delete root;
    
    return 0;
}
