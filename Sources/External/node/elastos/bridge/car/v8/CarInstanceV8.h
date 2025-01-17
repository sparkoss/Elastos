#ifndef __CARINSTANCEV8_H__
#define __CARINSTANCEV8_H__

#include <elastos.h>

#if ENABLE(CAR_BRIDGE)

#include "CarInstance.h"

#include "CarClassV8.h"

namespace JSC {
namespace Bindings {

class CarInstanceV8 : public CarInstance
{
public:
    CarInstanceV8(CobjectWrapper* objectWrapper, bool requireAnnotation);

    virtual CarKlass* getClass() const;
    virtual void invokeMethod(const CarMethod*, CarValue* args, bool* didRaiseUncaughtException);
    virtual CarValue getField(const CarField*);
    virtual void begin();
    virtual void end();

    IInterface* carInstance() const;

    CobjectWrapper* getInstance() const {
        ASSERT(mInstance);
        return mInstance->get();
    }

    virtual bool hasInterface(IInterfaceInfo* interfaceInfo);

    virtual CarInstance* getClassInstance();

protected:
    RefPtr<CobjectWrapper> mInstance;
    mutable OwnPtr<CarKlass> mClass;
    bool mRequireAnnotation;

    typedef WTF::HashMap<WTF::String, CarValue> DynamicFieldMap;
    DynamicFieldMap mDynamicFields;
};

} // namespace Bindings
} // namespace JSC

#endif // ENABLE(CAR_BRIDGE)

#endif //__CARINSTANCEV8_H__