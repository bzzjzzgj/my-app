//
// Created by ChengQi on 2025/4/7.
//

#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include <any>
#include <unordered_map>

#define MYSERVICE(Type) MyCore::GLobal::ServiceLocator::Get<Type>()

namespace MyCore::Global {
    class ServiceLocator {
    public:
        /**
         * 在服务定位器中注册一个服务
         * @tparam T 服务类型
         * @param p_service 服务
         */
        template<typename T>
        static void Provide(T &p_service) {
            __SERVICES[typeid(T).hash_code()] = std::any(&p_service);
        }

        /**
         * 返回给定类型的服务（请确保在调用此方法之前已提供服务）。
         * @tparam T 服务类型
         * @return 服务
         */
        template<typename T>
        static T &Get() {
            return *std::any_cast<T *>(__SERVICES[typeid(T).hash_code()]);
        }

    private:
        static std::unordered_map<size_t, std::any> __SERVICES;
    };
}

#endif //SERVICE_LOCATOR_H
