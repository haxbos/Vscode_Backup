#include <iostream>
#include <memory>
using namespace std;

class AVG{
public:
    virtual void play() = 0;
};
class TV01: public AVG{
public:
    void play() override{
        cout << "Connect the projector through the avg interface to watch the video" << endl;
    }
};

class Computer{
public:
    //电脑只能通过AVG接口连接投影仪查看视频
    void playVideo(AVG *pavg){
        pavg->play();
    }
};

/*现在我只有一个HDMI接口的投影仪*/
//方法一：对代码进行重构，使它支持HDMI
//方法二：使用适配器，能够把AVG信号转换成HDMI信号（即:添加适配器类）

class HDMI{
public:
    virtual void play() = 0;
};
class TV02 : public HDMI{
public:
    void play() override{
        cout << "Connect the projector through the HDMI interface to watch the video" << endl;
    }
};

class AVGToHDMIAdapter : public AVG{
public:
    AVGToHDMIAdapter(HDMI *phdmi): _phdmi(phdmi){}
    void play() override{
        _phdmi->play();
    }
    
private:
    HDMI *_phdmi;
};

void test_AVG(){
    unique_ptr<Computer> cptr(new Computer());
    cptr->playVideo(new TV01());
}

void test_adapter(){
    unique_ptr<Computer> cptr(new Computer());
    cptr->playVideo(new AVGToHDMIAdapter(new TV02()));
}

int main(){
    test_AVG();
    test_adapter();
}