/* @migen@ */
#include <MI.h>
#include "Docker_Container_Class_Provider.h"
#include "DockerRemoteApi.h"
#include "cJSON_Extend.h"
#define api_get_container_info(id)  string("GET /containers/"+id+"/json HTTP/1.1\r\n\r\n")

MI_BEGIN_NAMESPACE

Docker_Container_Class_Provider::Docker_Container_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

Docker_Container_Class_Provider::~Docker_Container_Class_Provider()
{
}

void Docker_Container_Class_Provider::Load(
        Context& context)
{
    context.Post(MI_RESULT_OK);
}

void Docker_Container_Class_Provider::Unload(
        Context& context)
{
    context.Post(MI_RESULT_OK);
}



void Docker_Container_Class_Provider_set(Docker_Container_Class& inst,cJSON* response) {
    inst.CreationClassName_value("Docker");
    inst.Name_value(cJSON_Get(response, "Name")->valuestring);
    inst.InstanceID_value(cJSON_Get(response, "Id")->valuestring);
    string status = string("Running:") + cJSON_Get_Int_As_String(response, "State.Running");
    inst.Status_value(status.c_str());
    inst.Image_value(cJSON_Get(response, "Image")->valuestring);
    inst.Command_value((cJSON_GetArray(response, "Config.Cmd") + cJSON_GetArray(response, "Config.Entrypoint")).c_str());
    string port = cJSON_GetChildName(cJSON_Get(response, "Config.ExposedPorts"));
    inst.Ports_value(port.c_str());
}

void Docker_Container_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    try {
        vector<string> containers = listContainer(true);
        vector<string > request = vector<string >();
        for (unsigned int i = 0; i < containers.size(); i++) {
            request.push_back(api_get_container_info(containers[i]));
        }
        vector<cJSON*> response =  getResponse(request);
        for (unsigned int i = 0; i < containers.size(); i++) {
            if (response[i]) {
                Docker_Container_Class inst;
                Docker_Container_Class_Provider_set(inst, response[i]);
                cJSON_Delete(response[i]);
                context.Post(inst);
            }
        }
    }
    catch (string& e) {
        context.Post(MI_RESULT_FAILED,e.c_str());
        return;
    }
    context.Post(MI_RESULT_OK);
}

void Docker_Container_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const Docker_Container_Class& instanceName,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void Docker_Container_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const Docker_Container_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void Docker_Container_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const Docker_Container_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void Docker_Container_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const Docker_Container_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void Docker_Container_Class_Provider::Invoke_RequestStateChange(
    Context& context,
    const String& nameSpace,
    const Docker_Container_Class& instanceName,
    const Docker_Container_RequestStateChange_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void Docker_Container_Class_Provider::Invoke_SetPowerState(
    Context& context,
    const String& nameSpace,
    const Docker_Container_Class& instanceName,
    const Docker_Container_SetPowerState_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
