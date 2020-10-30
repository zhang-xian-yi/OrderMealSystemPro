#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include <QString>
#include <map>

namespace  ModelTypeSpace{
    enum ModelType
    {
        SERVICE_LISTVIEW_MODEL = 0,
        COOKER_LISTVIEW_MODEL
    };
}


/*model 注册的接口模板类*/
template<class AbstractModel_t>
class IModelRegistrar
{
public:
    virtual AbstractModel_t* createModelBean() = 0;
protected:
    /*防止外部构造和析构 但是子类可以构造以及析构*/
    IModelRegistrar( ){}
    virtual ~IModelRegistrar(){}
private:
    /*防止外部 复制 以及拷贝*/
    IModelRegistrar(const IModelRegistrar& ){}
    const IModelRegistrar& operator=(const IModelRegistrar &);
};





/*model 单例模板工厂*/
template<class AbstractModel_t>
class ModelFactory
{
public:
    /*工厂单例*/
    static ModelFactory<AbstractModel_t>& getInstance()
    {
        static ModelFactory<AbstractModel_t> instance;
        return instance;
    }
    /*将model 类型 注册到 工厂单例中中*/
    bool registrarModel(IModelRegistrar<AbstractModel_t>* registrar,const int& id)
    {
        m_ModelRegistry[id] = registrar;
        return true;
    }

    /*根据name  找到注册的register 然后通过registrar 创建对象*/
    AbstractModel_t* createModelBean(const int& id)
    {
        /*find 返回迭代器指向当前查找元素的位置 否则返回map::end()位置*/
        if(m_ModelRegistry.find(id) != m_ModelRegistry.end())
        {
            return m_ModelRegistry[id]->createModelBean();
        }
        else
        {
            /*未找到*/
            return nullptr;
        }
    }

private:
   // 禁止外部构造和虚构
   ModelFactory() {}
   ~ModelFactory() {}

   // 禁止外部拷贝和赋值操作
   ModelFactory(const ModelFactory &);
   const ModelFactory &operator=(const ModelFactory &);

   // 保存注册过的产品，key:model index , value:产品类型
   std::map<int, IModelRegistrar<AbstractModel_t> *> m_ModelRegistry;
};




/*model 注册的 模板实现类*/
template<class AbstractModel_t,class ModelImpl_t>
class ModelRegistrar:public IModelRegistrar<AbstractModel_t>
{
public:
    /*将产品直接注册到单例模板工厂中*/
    explicit ModelRegistrar(const int& id)
    {
        ModelFactory<AbstractModel_t>::getInstance().registrarModel(this,id);
    }

    AbstractModel_t* createModelBean() override
    {
        return new ModelImpl_t;
    }
};


#endif // MODELFACTORY_H
