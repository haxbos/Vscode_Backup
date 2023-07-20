#include <iostream>
#include <memory>
using namespace std;

class VideoSite{
public:
    virtual void freeMovie() = 0;
    virtual void vipMovie() = 0;
    virtual void couponMovie() = 0;
};

//委托类
class FixBugVideoSite : public VideoSite{
public:
    void freeMovie() override{
        cout << "watch free Moive" << endl;
    }
    void vipMovie() override{
        cout << "watch vip Moive" << endl;
    }
    void couponMovie() override{
        cout << "use coupon to see the movie" << endl;
    }
};

//proxy class, proxy free costomer
class FreeVideoSiteProxy : public VideoSite{
public:
    FreeVideoSiteProxy():pvs(make_unique<FixBugVideoSite>()){}
    ~FreeVideoSiteProxy(){}
    //通过代理对象的freeMovie，来访问委托对象的freeMovie
    void freeMovie() override{
        pvs->freeMovie();
    }
    void vipMovie() override{
        cout << "sorry, you aren't vip costomer!" << endl;
    }
    void couponMovie() override{
        cout << "sorry, you don't have a coupon!" << endl;
    }
private:
    unique_ptr<VideoSite>  pvs;
};

//proxy class, proxy vip costomer
class VipVideoSiteProxy : public VideoSite{
public:
    VipVideoSiteProxy():pvs(make_unique<FixBugVideoSite>()){}
    ~VipVideoSiteProxy(){}
    void freeMovie(){
        pvs->freeMovie();
    }
    void vipMovie(){
        pvs->vipMovie();
    }
    void couponMovie(){
        cout << "sorry, you don't have a coupon!" << endl;
    }
private:
    unique_ptr<VideoSite> pvs;
};

void watchMovie(unique_ptr<VideoSite> &pvs){
    pvs->freeMovie();
    pvs->vipMovie();
    pvs->couponMovie();
}

int main(){
    //客户直接访问代理对象
    unique_ptr<VideoSite> pvs1(new FreeVideoSiteProxy());
    unique_ptr<VideoSite> pvs2(new VipVideoSiteProxy());
    watchMovie(pvs1);
    watchMovie(pvs2);
}
