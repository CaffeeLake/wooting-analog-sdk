/* This is a generated header file providing the common items to everything related to the Analog SDK */

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <new>

enum class WootingAnalog_DeviceEventType {
  /// Device has been connected
  WootingAnalog_DeviceEventType_Connected = 1,
  /// Device has been disconnected
  WootingAnalog_DeviceEventType_Disconnected,
};

enum class WootingAnalog_DeviceType {
  /// Device is of type Keyboard
  WootingAnalog_DeviceType_Keyboard = 1,
  /// Device is of type Keypad
  WootingAnalog_DeviceType_Keypad,
  /// Device
  WootingAnalog_DeviceType_Other,
};

enum class WootingAnalog_KeycodeType {
  /// USB HID Keycodes https://www.usb.org/document-library/hid-usage-tables-112 pg53
  WootingAnalog_KeycodeType_HID,
  /// Scan code set 1
  WootingAnalog_KeycodeType_ScanCode1,
  /// Windows Virtual Keys
  WootingAnalog_KeycodeType_VirtualKey,
  /// Windows Virtual Keys which are translated to the current keyboard locale
  WootingAnalog_KeycodeType_VirtualKeyTranslate,
};

enum class WootingAnalogResult {
  WootingAnalogResult_Ok = 1,
  /// Item hasn't been initialized
  WootingAnalogResult_UnInitialized = -2000,
  /// No Devices are connected
  WootingAnalogResult_NoDevices,
  /// Device has been disconnected
  WootingAnalogResult_DeviceDisconnected,
  /// Generic Failure
  WootingAnalogResult_Failure,
  /// A given parameter was invalid
  WootingAnalogResult_InvalidArgument,
  /// No Plugins were found
  WootingAnalogResult_NoPlugins,
  /// The specified function was not found in the library
  WootingAnalogResult_FunctionNotFound,
  /// No Keycode mapping to HID was found for the given Keycode
  WootingAnalogResult_NoMapping,
  /// Indicates that it isn't available on this platform
  WootingAnalogResult_NotAvailable,
};

/// The core `DeviceInfo` struct which contains all the interesting information
/// for a particular device. This is for use internally and should be ignored if you're
/// trying to use it when trying to interact with the SDK using the wrapper
struct WootingAnalog_DeviceInfo;

using WootingAnalog_DeviceID = uint64_t;

/// The core `DeviceInfo` struct which contains all the interesting information
/// for a particular device. This is the version which the consumer of the SDK will receive
/// through the wrapper. This is not for use in the Internal workings of the SDK, that is what
/// DeviceInfo is for
struct WootingAnalog_DeviceInfo_FFI {
  /// Device Vendor ID `vid`
  uint16_t vendor_id;
  /// Device Product ID `pid`
  uint16_t product_id;
  /// Device Manufacturer name
  char *manufacturer_name;
  /// Device name
  char *device_name;
  /// Unique device ID, which should be generated using `generate_device_id`
  WootingAnalog_DeviceID device_id;
  /// Hardware type of the Device
  WootingAnalog_DeviceType device_type;
};

extern "C" {

/// Drops the given `DeviceInfo`
void drop_device_info(WootingAnalog_DeviceInfo *device);

/// Create a new device info struct. This is only for use in Plugins that are written in C
/// Rust plugins should use the native constructor
/// The memory for the struct has been allocated in Rust. So `drop_device_info` must be called
/// for the memory to be properly released
WootingAnalog_DeviceInfo *new_device_info(uint16_t vendor_id,
                                          uint16_t product_id,
                                          char *manufacturer_name,
                                          char *device_name,
                                          WootingAnalog_DeviceID device_id,
                                          WootingAnalog_DeviceType device_type);

} // extern "C"
