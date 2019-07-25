#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#if defined(_WIN32) || defined(WIN32)
#ifdef ANALOGSDK_EXPORTS
#define ANALOGSDK_API __declspec(dllexport)
#else
#define ANALOGSDK_API __declspec(dllimport)
#endif
#else
#define ANALOGSDK_API
#endif

typedef uint64_t DeviceID;

typedef struct DeviceInfo {
    uint16_t vendor_id;
    uint16_t product_id;
    const char* manufacturer_name;
    const char* device_name;
    DeviceID device_id;
} DeviceInfo;

typedef enum {
    Connected = 1,
    Disconnected
} DeviceEventType;

typedef enum AnalogSDKError  {
    Ok = 1,
    UnInitialized = -2000,
    NoDevices,
    DeviceDisconnected,
    //Generic Failure
    Failure,
    InvalidArgument,
    NoPlugins,
    FunctionNotFound,
    //No Keycode mapping to HID was found for the given Keycode
    NoMapping

} AnalogSDKError;

typedef void(*device_event)(DeviceEventType, DeviceInfo*);

ANALOGSDK_API const char* c_name();
ANALOGSDK_API bool is_initialised();
ANALOGSDK_API AnalogSDKError initialise();
ANALOGSDK_API void unload();
ANALOGSDK_API int c_read_full_buffer(uint16_t code_buffer[], float analog_buffer[], int len, DeviceID device);
ANALOGSDK_API int c_device_info(DeviceInfo* buffer[], int len);
ANALOGSDK_API float read_analog(uint16_t code, DeviceID device);
ANALOGSDK_API AnalogSDKError set_device_event_cb(device_event cb);
ANALOGSDK_API AnalogSDKError clear_device_event_cb();