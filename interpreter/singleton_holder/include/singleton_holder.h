#ifndef INTERPRETER_SINGLETON_HOLDER_H
#define INTERPRETER_SINGLETON_HOLDER_H
#include <stdexcept>

template <class InstanceType, template<class> class CreationPolicy>
class SingletonHolder {
public:
    static InstanceType &Instance() {
        static InstanceType instance = CreationPolicy<InstanceType>::Create();
        return instance;
    }

    SingletonHolder(const SingletonHolder &other) = delete;

    SingletonHolder &operator=(const SingletonHolder &other) = delete;

private:
    SingletonHolder() {}

    ~SingletonHolder() {}
};
#endif //INTERPRETER_SINGLETON_HOLDER_H
