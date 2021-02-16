#ifndef BEANFACTORY_H
#define BEANFACTORY_H

/**
* @brief:
* @author zhangxianyi qq-1724920805@qq.com
* @date:  2020-11-02
* project OrderMealSystemPro
* describle:  注册BeanRegistrar 最好和beanFactory 共同作用域
*             保证 通过int 识别的map 不会导致重复
*             静态区域析构的时候 会直接释放map  所以不用担心注册信息的销毁问题 虽然栈对象的地址还在 当不要访问即可
*/


#include <QString>
#include <QMap>




/* 注册的接口模板类*/
template<class AbstractBean_t>
class IRegistrar
{
public:
    virtual AbstractBean_t* createBean() = 0;
protected:
    /*防止外部构造和析构 但是子类可以构造以及析构*/
    IRegistrar( ){}
    virtual ~IRegistrar(){}
private:
    /*防止外部 复制 以及拷贝*/
    IRegistrar(const IRegistrar& ){}
    const IRegistrar& operator=(const IRegistrar &);
};





/* 单例模板工厂*/
template<class AbstractBean_t>
class BeanFactory
{
public:
    /*工厂单例*/
    static BeanFactory<AbstractBean_t>& getInstance()
    {
        static BeanFactory<AbstractBean_t> instance;
        return instance;
    }
    ~BeanFactory<AbstractBean_t>()
    {
        //由于父类是系统类型 保护的析构函数 无法析构
    }
    /*将model 类型 注册到 工厂单例中中*/
    bool registrarBean(IRegistrar<AbstractBean_t>* registrar,const QString& id)
    {
        m_registryMap[id] = registrar;
        return true;
    }

    /*根据name  找到注册的register 然后通过registrar 创建对象*/
    AbstractBean_t* createBean(const QString& id)
    {
        /*find 返回迭代器指向当前查找元素的位置 否则返回map::end()位置*/
        if(m_registryMap.find(id) != m_registryMap.end())
        {
            return m_registryMap[id]->createBean();
        }
        else
        {
            /*未找到*/
            return nullptr;
        }
    }

private:
   // 禁止外部构造和虚构
   BeanFactory() {}

   // 禁止外部拷贝和赋值操作
   BeanFactory(const BeanFactory &);
   const BeanFactory &operator=(const BeanFactory &);

   // 保存注册过的产品，key:class name , value:产品类型
   QMap<QString,IRegistrar<AbstractBean_t>*> m_registryMap;
};




/*model 注册的 模板实现类*/
template<class AbstractBean_t,class BeanImpl_t>
class BeanRegistrar:public IRegistrar<AbstractBean_t>
{
public:
    virtual ~BeanRegistrar(){}
    /*将产品直接注册到单例模板工厂中*/
    explicit BeanRegistrar(const QString& id)
    {
        BeanFactory<AbstractBean_t>::getInstance().registrarBean(this,id);
    }

    AbstractBean_t* createBean() override
    {
        return new BeanImpl_t;
    }
};

#endif // BEANFACTORY_H
