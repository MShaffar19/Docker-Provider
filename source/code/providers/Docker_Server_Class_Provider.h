/* @migen@ */
#ifndef _Docker_Server_Class_Provider_h
#define _Docker_Server_Class_Provider_h

#include "Docker_Server.h"
#ifdef __cplusplus
# include <micxx/micxx.h>
# include "module.h"
# include "cJSON.h"
MI_BEGIN_NAMESPACE

/*
**==============================================================================
**
** Docker_Server provider class declaration
**
**==============================================================================
*/

class Docker_Server_Class_Provider
{
/* @MIGEN.BEGIN@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
private:
    Module* m_Module;

public:
    Docker_Server_Class_Provider(
        Module* module);

    ~Docker_Server_Class_Provider();

    void Load(
        Context& context);

    void Unload(
        Context& context);

    void EnumerateInstances(
        Context& context,
        const String& nameSpace,
        const PropertySet& propertySet,
        bool keysOnly,
        const MI_Filter* filter);

    void GetInstance(
        Context& context,
        const String& nameSpace,
        const Docker_Server_Class& instance,
        const PropertySet& propertySet);

    void CreateInstance(
        Context& context,
        const String& nameSpace,
        const Docker_Server_Class& newInstance);

    void ModifyInstance(
        Context& context,
        const String& nameSpace,
        const Docker_Server_Class& modifiedInstance,
        const PropertySet& propertySet);

    void DeleteInstance(
        Context& context,
        const String& nameSpace,
        const Docker_Server_Class& instance);

/* @MIGEN.END@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
};

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _Docker_Server_Class_Provider_h */

