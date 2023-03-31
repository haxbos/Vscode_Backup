#include <string>
#include <set>
using namespace std;

class Folder;
class Message{
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const string &str = ""):contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    
    //从给定 Folder 集合中添加/删除文本 Message
    void save(Folder &f);
    void remove(Folder&);

    ~Message();
private:
    string contents;    //实际消息文本
    set<Folder*> folders;
    //拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    //将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};


class Folder{
    friend class Message;
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder &);
    void print_debug();
    ~Folder();    
private:
    set<Message *> msgs;
    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *msg){ msgs.insert(msg); }
    void remMsg(Message *msg){ msgs.erase(msg); }
};