/****************************************************************************
http://retro.moe/unijoysticle2

Copyright 2019 Ricardo Quesada

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/

#ifndef UNI_BLUETOOTH_H
#define UNI_BLUETOOTH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "uni_hid_device.h"

int uni_bt_init(void);

// Public functions
// Safe to call these functions from another task and/or CPU

// List stored Bluetooth keys, created when a device get paired
void uni_bt_list_keys_safe(void);
// Delete stored Bluetooth keys
void uni_bt_del_keys_safe(void);
// Dump all connected devices.
void uni_bt_dump_devices_safe(void);
// Whether to enable new Bluetooth connections.
// When enabled, the device enters into "discovery" mode, and new un-paired devices are accepted.
// When disabled, only devices that have paired before can connect.
void uni_bt_enable_new_connections_safe(bool enabled);
// Disconnects a device
void uni_bt_disconnect_device_safe(int device_idx);

// Private functions.
void uni_bt_packet_handler(uint8_t packet_type, uint16_t channel, uint8_t* packet, uint16_t size);

// Properties
void uni_bt_set_gap_security_level(int gap);
int uni_bt_get_gap_security_level(void);
void uni_bt_set_gap_inquiry_length(int len);
int uni_bt_get_gap_inquiry_lenght(void);
void uni_bt_set_gap_max_peridic_length(int len);
int uni_bt_get_gap_max_periodic_lenght(void);
void uni_bt_set_gap_min_peridic_length(int len);
int uni_bt_get_gap_min_periodic_lenght(void);

#ifdef __cplusplus
}
#endif

#endif  // UNI_BLUETOOTH_H