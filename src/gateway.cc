#include <stdio.h>
#include <node.h>
#include <v8.h>
#include "sapnwrfc.h"

v8::Handle<v8::Value> Connector(const v8::Arguments &args){
    v8::HandleScope scope;
    
    RFC_CONNECTION_PARAMETER loginParams[6];
    RFC_CONNECTION_HANDLE connection;
    RFC_ERROR_INFO errorInfo;
    RFC_FUNCTION_DESC_HANDLE funcHandle;
    RFC_FUNCTION_HANDLE createFunc;
    RFC_RC rc = RFC_OK;
    RFC_INT number;
    
    char returned[15];
    v8::Local<v8::String> returnedResults;
    int inputData;
    
    inputData = args[0]->IntegerValue();
    
    loginParams[0].name = cU("ashost");
    loginParams[0].value = cU("uxciebj.wdf.sap.corp");
    loginParams[1].name = cU("sysnr");
    loginParams[1].value = cU("15");
    loginParams[2].name = cU("client");
    loginParams[2].value = cU("001");
    loginParams[3].name = cU("user");
    loginParams[3].value = cU("DEYSUB");
    loginParams[4].name = cU("passwd");
    loginParams[4].value = cU("******");
    loginParams[5].name = cU("lang");
    loginParams[5].value = cU("EN");
    
    connection = RfcOpenConnection(loginParams,6,&errorInfo);
    
    if(connection==NULL){
        // error not able to connect to SAP System
    }else{
        funcHandle = RfcGetFunctionDesc(connection, cU("ZTESTNEWFM"), &errorInfo);
        createFunc = RfcCreateFunction(funcHandle, &errorInfo);
        RfcSetInt(createFunc,cU("ZINP"),inputData, &errorInfo);
        rc = RfcInvoke(connection,createFunc, &errorInfo);
        
        if(rc==RFC_OK){
            RfcGetInt(createFunc,cU("ZEXP"), &number, &errorInfo);
            sprintf(returned,"%d", number);
            returnedResults = v8::String::New(returned);
        }else{
            // error not able to execute the RFC Enabled function module
        }
    }
    
    return scope.Close(returnedResults);
}

void Init(v8::Handle<v8::Object> exports) {
    v8::Local<v8::Function> connector = v8::FunctionTemplate::New(Connector)->GetFunction();
    exports->Set(v8::String::NewSymbol("connector"), connector);
}

NODE_MODULE(gateway,Init);
