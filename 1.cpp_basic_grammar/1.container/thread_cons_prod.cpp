#include <atomic>
#include <condition_variable>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <string>
#include <thread>
#include <typeinfo>
#include <unordered_map>
#include <vector>



using namespace std;



class Backend{

    typedef std::shared_ptr<Backend> Ptr;
};



int main(){

    Backend::Ptr backend_ = nullptr;

    backend = Backend::Ptr(new Backend);

    return 0;
}